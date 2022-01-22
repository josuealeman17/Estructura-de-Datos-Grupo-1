#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

enum class TokenTipos {
	operador,
	constante,
	funcion,
	parenIzq,
	parenDer,
	otro
};

namespace expdef {

	static const map<string, double> constantes = {
		{"pi", atan(1) * 4}
	};

	static const vector<char> operadores = { '+', '-', '/', '*', '^' };

	static const vector<char> izqParenteris = { '(', '{', '[' };

	static const vector<char> derParentesis = { ')', '}', ']' };


	static const vector<string> funciones = {
		"sin",
		"cos",
		"tan",
		"+",
		"-",
		"*",
		"/",
		"^"
	};

	static const vector<string> funciones_unarias = {
		"sin",
		"cos",
		"tan",

	};

	static const vector<string> funciones_binarias = {
		"+",
		"-",
		"*",
		"/",
		"^"
	};

	static const vector<string> nombreConstantes = {
		"pi"
	};

	static const map<string, double> variables;
}
