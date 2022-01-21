#pragma once
#include "Token.h"
#include "Utilidades.h"
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

namespace Funcion {

	Utilidades utils;

	typedef vector<string> RPN;
	typedef double(*funcUnariaEval)(double x);
	typedef double(*funcBinariaEval)(double x, double y);


	class Funcion {

	public:
		Funcion()
			: tipo(TokenTipos::operador), jerarquia(0), izq(true), unario(true), u_eval(nullptr), b_eval(nullptr) {}


		Funcion(funcUnariaEval eval, TokenTipos tipo = TokenTipos::funcion, short jerarquia = 0, bool izq = true)
			: Funcion(tipo, jerarquia, izq, true) {

			u_eval = eval;
		}

		Funcion(funcBinariaEval eval, TokenTipos tipo = TokenTipos::funcion, short jerarquia = 0, bool izq = true)
			: Funcion(tipo, jerarquia, izq, false) {

			b_eval = eval;
		}

		double eval(double x, double y = 0) {
			return this->unario ? u_eval(x) : b_eval(x, y);
		}


		funcUnariaEval u_eval;
		funcBinariaEval b_eval;
		TokenTipos tipo;
		short jerarquia;
		bool izq;
		bool unario;

	private:

		Funcion(TokenTipos tipo, short jerarquia, bool izq, bool unario)
			: tipo(tipo), jerarquia(jerarquia), izq(izq), unario(unario), u_eval(nullptr), b_eval(b_eval) {}

	};




	//REFERENCIAS

	map<string, Funcion> funciones_unarias = {
	{"sin", Funcion(sin)},
	{"cos", Funcion(cos)},
	{"tan", Funcion(tan)}
	};

	map<string, Funcion> funciones_binarias = {
		{ "+", Funcion([](double x, double y) -> double { return x + y; }, TokenTipos::operador, 2) },
		{ "-", Funcion([](double x, double y) -> double { return x - y; }, TokenTipos::operador, 2) },
		{ "*", Funcion([](double x, double y) -> double { return x * y; }, TokenTipos::operador, 3) },
		{ "/", Funcion([](double x, double y) -> double { return x / y; }, TokenTipos::operador, 3) },
		{ "^", Funcion(pow, TokenTipos::operador, 4, false) }
	};

	map<string, double> constantes = {
		{"pi", atan(1) * 4}
	};


	vector<char> operadores = { '+', '-', '/', '*', '^' };

	vector<char> izqParenteris = { '(', '{', '[' };

	vector<char> derParentesis = { ')', '}', ']' };

	vector<string> funciones = utils.llaves<Funcion>(funciones_unarias, funciones_binarias);

	vector<string> nombreConstantes = utils.llaves<double>(constantes);

	map<string, double> variables;

}
