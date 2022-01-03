#pragma once
#include "Nodo.h"
class Arbol
{
private:
	Nodo* arbol = NULL;
public:
	void setArbol(Nodo*);
	Nodo* getArbol();
	Nodo* crearNodo(int);
	void insertarNodo(Nodo*&, int);
	void mostrar(Nodo*, int);
	bool buscar(Nodo*, int);
	void preOrden(Nodo*);
	void inOrden(Nodo*);
	void postOrden(Nodo*);
};

void Arbol::setArbol(Nodo* _arbol) {
	arbol = _arbol;
}
Nodo* Arbol::getArbol() {
	return arbol;
}
Nodo* Arbol::crearNodo(int dato) {
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->setDato(dato);
	nuevoNodo->setDerecha(NULL);
	nuevoNodo->setIzquierda(NULL);
	return nuevoNodo;
}
void Arbol::insertarNodo(Nodo*& arbol, int dato) {
	if (arbol == NULL) {
		Nodo* nuevoNodo = crearNodo(dato);
		arbol = nuevoNodo;
	}
	else {
		int raiz = arbol->getDato();
		if (dato < raiz) {
			insertarNodo(arbol->getIzquierda(), dato);
		}
		else {
			insertarNodo(arbol->getDerecha(), dato);
		}
	}
}

void Arbol::mostrar(Nodo* arbol, int contador) {
	if (arbol == NULL) {
		return;
	}
	else {
		mostrar(arbol->getDerecha(), contador + 1);
		for (int i = 0; i < contador; i++) {
			cout << " ";
		}
		cout << arbol->getDato() << endl;
		mostrar(arbol->getIzquierda(), contador + 1);
	}
}

bool Arbol::buscar(Nodo* arbol, int dato) {
	if (arbol == NULL) {
		return false;
	}
	else if (arbol->getDato() == dato) {
		return true;
	}
	else if (dato < arbol->getDato()) {
		buscar(arbol->getIzquierda(), dato);
	}
	else {
		buscar(arbol->getDerecha(), dato);
	}
}

void Arbol::preOrden(Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		cout << arbol->getDato() << " ";
		preOrden(arbol->getIzquierda());
		preOrden(arbol->getDerecha());
	}
}

void Arbol::inOrden(Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		inOrden(arbol->getIzquierda());
		cout << arbol->getDato() << " ";
		inOrden(arbol->getDerecha());
	}
}

void Arbol::postOrden(Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		postOrden(arbol->getIzquierda());
		postOrden(arbol->getDerecha());
		cout << arbol->getDato() << " ";
	}
}

