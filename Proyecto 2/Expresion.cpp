#include "Expresion.h"


funct::RPN Expresion::notacionPolacaInversa(const char* eqn)
{

	vector<string> queue;
	stack<string> stack;

	string obj = "";
	TokenTipos type = TokenTipos::otro;
	TokenTipos prevType = TokenTipos::otro; // negative sign detection

	bool aceptaDecimal = true;
	bool aceptaNegativo = true;

	// token reading and detection
	for (int i = 0, eqLen = (int)strlen(eqn); i < eqLen; i++) {
		char t = eqn[i];

		// skip spaces and commas
		if (t == ' ' || t == ',') {
			//prevType = TokenTypes::ELSE;
			continue;
		}

		// classify token
		if (Utilidades::esNumero(t)) {
			type = TokenTipos::constante;
			if (t == '.') {
				aceptaDecimal = false;
			}
			else if (t == '-') {
				aceptaNegativo = false;
			}

			int startI = i;
			if (i < eqLen - 1) {
				while (Utilidades::esNumero(eqn[i + 1], aceptaDecimal, aceptaNegativo)) {
					i++;
					if (i >= eqLen - 1) {
						break;
					}
				}
			}
			obj = string(eqn).substr(startI, i - startI + 1);

			// subtraction sign detection
			if (obj == "-") {
				type = TokenTipos::operador;
			}
		}
		else {
			obj = Utilidades::buscarElemento(i, eqn, expdef::funciones);
			if (obj != "") {
				// found valid object
				type = Utilidades::estaVacio<char>(expdef::operadores, obj[0]) ? TokenTipos::operador : TokenTipos::funcion;
			}
			else {
				obj = Utilidades::buscarElemento(i, eqn, expdef::nombreConstantes);
				if (obj != "") {
					// found valid object
					type = TokenTipos::constante;
				}
				else {
					obj = Utilidades::buscarElemento(i, eqn, Utilidades::llaves<double>(expdef::variables));
					if (obj != "") {
						type = TokenTipos::constante;
					}
					else if (Utilidades::estaVacio<char>(expdef::izqParenteris, t)) {
						type = TokenTipos::parenIzq;
						obj = "(";
					}
					else if (Utilidades::estaVacio<char>(expdef::derParentesis, t)) {
						type = TokenTipos::parenDer;
						obj = ")";
					}
					else {
						type = TokenTipos::otro;
					}
				}
			}
			i += obj.size() - 1;
		}

		// do something with the token
		const char* last_stack = (stack.size() > 0) ? stack.top().c_str() : "";
		switch (type) {
		case TokenTipos::constante:
			queue.push_back(obj);
			break;
		case TokenTipos::funcion:
			stack.push(obj);
			break;
		case TokenTipos::operador:
			if (stack.size() != 0) {
				while (((Utilidades::estaVacio<string>(expdef::funciones, last_stack) &&
							!Utilidades::estaVacio<char>(expdef::operadores, last_stack[0])) ||
								funct::getJerarquia(last_stack) > funct::getJerarquia(obj) ||
									((funct::getJerarquia(last_stack) == funct::getJerarquia(obj)) &&
										funct::esAsociativaIzq(last_stack))
							) && (!Utilidades::estaVacio<char>(expdef::izqParenteris, last_stack[0]))) {


								queue.push_back(stack.top());
								stack.pop();

								if (stack.size() == 0) {
									break;

					}

					last_stack = stack.top().c_str();
				}
			}
			stack.push(obj);
			break;
		case TokenTipos::parenIzq:
			stack.push(obj);
			break;
		case TokenTipos::parenDer:
			while (last_stack[0] != '(') {
				// pop from the stack to the queue
				queue.push_back(stack.top());
				stack.pop();
				last_stack = stack.top().c_str();
			}
			stack.pop();
			break;
		default:
			return queue;
		}

		// reset type
		prevType = type;
	}

	while (stack.size() > 0) {
		// pop from the stack to the queue
		queue.push_back(stack.top());
		stack.pop();
	}

	return queue;
}

Nodo::Nodo* Expresion::pasar(funct::RPN rpn)
{

	stack<Nodo::Nodo*> stack;

	for (string item : rpn) {
		if (Utilidades::esNumero(item.c_str())) {
			// push number node
			stack.push(new Nodo::NodoNumero(item));
		}
		else {
			// function
			Nodo::NodoFunc* f = new Nodo::NodoFunc(item);
			if (Utilidades::estaVacio<string>(expdef::funciones_binarias, item)) {
				f->setUnaria(false);
				// set children of node

				// right child is second argument
				f->derecha = stack.top();
				stack.pop();

				// left child is first argument
				f->izquierda = stack.top();
				stack.pop();
			}
			else if (Utilidades::estaVacio<string>(expdef::funciones_unarias, item)) {
				f->setUnaria(true);
				// set child of node
				f->izquierda = stack.top();
				stack.pop();
			}
			stack.push(f);
		}
	}

	if (stack.size() == 0) {
		return nullptr;
	}

	return stack.top();
}

double Expresion::evaluarArbol(Nodo::Nodo* arbol)
{
	if (arbol->esFuncion) {
		Nodo::NodoFunc* ftree = (Nodo::NodoFunc*)arbol;
		if (ftree->esUnaria) {
			// evaluate child recursively and then evaluate with return value
			return ftree->eval(evaluarArbol(arbol->izquierda));
		}
		else {
			// evaluate each child recursively and then evaluate with return value
			return ftree->eval(evaluarArbol(arbol->izquierda), evaluarArbol(arbol->derecha));
		}
	}
	else {
		// number node
		return ((Nodo::NodoNumero*)arbol)->eval();
	}
}
