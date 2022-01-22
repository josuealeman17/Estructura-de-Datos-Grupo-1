#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "Definicion.h"
#include "Utilidades.h"

using namespace std;


namespace funct {

	
	typedef vector<string> RPN;
	typedef double(*funcUnariaEval)(double x); //recibe un double y retorna un double
	typedef double(*funcBinariaEval)(double x, double y);

	class Funcion {

	public:
		
		Funcion()
			: tipo(TokenTipos::operador), jerarquia(0), izq(true), unario(true), u_eval(nullptr), b_eval(nullptr) {}


		Funcion(funcUnariaEval eval, TokenTipos tipo = TokenTipos::funcion, short jerarquia = 0, bool izq = true)
			: Funcion(tipo, jerarquia, izq, true) {

			u_eval = eval;
		}

		/*
		Funcion(funcBinariaEval eval, TokenTipos tipo = TokenTipos::funcion, short jerarquia = 0, bool izq = true)
			: Funcion(tipo, jerarquia, izq, false) {

			b_eval = eval;
		}*/

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


	static const map<string, Funcion> funciones_unarias = {
		{"sin", Funcion(sin)},
		{"cos", Funcion(cos)},
		{"tan", Funcion(tan)}
	};

	static const map<string, Funcion> funciones_binarias = {
		{ "+", Funcion([](double x, double y) -> double { return x + y; }, TokenTipos::operador, 2) },
		{ "-", Funcion([](double x, double y) -> double { return x - y; }, TokenTipos::operador, 2) },
		{ "*", Funcion([](double x, double y) -> double { return x * y; }, TokenTipos::operador, 3) },
		{ "/", Funcion([](double x, double y) -> double { return x / y; }, TokenTipos::operador, 3) },
		{ "^", Funcion(pow, TokenTipos::operador, 4, false) }
	};


	static bool esAsociativaIzq(string str) {
		return funciones_binarias.at(str).izq;
	}

	static short getJerarquia(string str) {
		if (Utilidades::estaVacio<string>(Utilidades::llaves(funciones_binarias), str)) {
			return funciones_binarias.at(str).jerarquia;
		}

		return 0;
	}
}
