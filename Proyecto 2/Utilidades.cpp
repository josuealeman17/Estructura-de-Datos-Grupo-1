#include "Utilidades.h"
#include "Funcion.h"

template<typename T>
bool estaVacio(vector<T> v, T x) {

	return find(v.begin(), v.end(), x) != v.end();
}

template<typename T>
vector<string> llaves(map<string, T> m) {

	vector<string> ret;

	for (auto const& elemento : m) {
		ret.push_back(elemento.first);
	}

	return ret;
}

template<typename T>
vector<string> llaves(map<string, T> m1, map<string, T> m2) {

	vector<string> setLlave1 = llaves<T>(m1);
	vector<string> setLlave2 = llaves<T>(m2);

	setLlave1.insert(setLlave1.end(), setLlave2.begin(), setLlave2.end());

	return setLlave1;
}


bool esNumero(char c, bool aceptaDecimal = true, bool aceptaNegativo = true) {

	if (c >= '0' && c <= '9') {
		return true;
	}

	else if (aceptaDecimal && c == '.') {
		return true;
	}

	else if (aceptaNegativo && c == '-') {
		return true;
	}

	return false;
}


bool esNumero(const char* str) {
	 
	return estaVacio<string>(Funcion::nombreConstantes, str) ||
			estaVacio<string>(llaves<double>(Funcion::variables), str) ||
				contieneNumeros(str);
}


bool contieneNumeros(const char* str) {

	if (strcmp(str, ".") == 0 || strcmp(str, "-") == 0) {
		return false;
	}

	std::string obj = std::string(str);

	// try to prove wrong
	bool aceptaDecimal = true;
	if (esNumero(obj[0], true, true)) {
		// check first character for negative sign
		if (obj[0] == '.') {
			// cannot be any more decimal points
			aceptaDecimal = false;
		}
	}
	else {
		return false;
	}

	for (unsigned int i = 1, len = obj.size(); i < len; i++) {
		// do not accept anymore negative signs
		if (!esNumero(obj[i], aceptaDecimal, false)) {
			return false;
		}

		if (obj[i] == '.') {
			// cannot be any more decimal points
			aceptaDecimal = false;
		}
	}

	return true;
}


double getValorNumerico(const char* str) {

	if (estaVacio<string>(Funcion::nombreConstantes, str)) {
		// is a constant
		return Funcion::constantes[str];
	}
	else if (estaVacio<string>(llaves<double>(Funcion::variables), str)) {
		// is a variable
		return Funcion::variables[str];
	}
	else {
		// is a number
		return atof(str);
	}
}


bool esFuncion(string str) {
	return estaVacio<string>(Funcion::funciones, str);
}


bool esAsociativaIzq(string str) {
	return Funcion::funciones_binarias[str].izq;
}

short getJerarquia(string str) {
	if (estaVacio<string>(llaves(Funcion::funciones_binarias), str)) {
		return Funcion::funciones_binarias[str].jerarquia;
	}
}


string buscarElemento(int i, const char* eqn, vector<string> list) {

	for (string item : list) {
		int n = (int)item.size();
		if (string(eqn).substr(i, n) == item) {
			return item;
		}
	}

	return "";
}