#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <cmath>

using namespace std;



class Utilidades {

	public:
		template<typename T>
		bool estaVacio(vector<T> v, T x);

		// obtain key list
		template<typename T>
		vector<string> llaves(map<string, T> m);

		// obtain combined key list
		template<typename T>
		vector<string> llaves(map<string, T> m1, map<string, T> m2);

		// determine if character is number
		bool esNumero(char c, bool aceptaDecimal = true, bool aceptaNegativo = true);

		// determine if entire string is number
		bool esNumero(const char* str);

		// determine if string only contains numerical characters
		bool contieneNumeros(const char* str);

		// get numerical value of string
		double getValorNumerico(const char* str);

		// determine if string matches a function
		bool esFuncion(string str);

		// determine if function is left associative
		bool esAsociativaIzq(string str);

		// get function precedence
		short getJerarquia(string str);

		// find element from list in the equation starting at index i
		string buscarElemento(int i, const char* eqn, vector<string> list);
};

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

	return estaVacio<string>(Funcion::constantes, str) || estaVacio<string>(utils.llaves<double>(Funcion::variables), str);
}


bool contieneNumeros(const char* str) {

}


double getValorNumerico(const char* str) {

}


bool esFuncion(string str) {

}


bool esAsociativaIzq(string str) {

}

short getJerarquia(string str) {

}


string buscarElemento(int i, const char* eqn, vector<string> list) {

}


