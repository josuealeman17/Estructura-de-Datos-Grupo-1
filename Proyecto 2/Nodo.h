#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <cmath>
#include "Funcion.h"
#include "Utilidades.h"

using namespace std;


namespace Nodo {

	class Nodo
	{
		public:
			Nodo(string nombre, bool esFuncion)
				: nombre(nombre), esFuncion(esFuncion) {}

			double eval(double x = 0, double y = 0);
			string nombre;
			bool esFuncion;
			Nodo* derecha;
			Nodo* izquierda;
	};

	class NodoFunc : public Nodo {
		public:
			NodoFunc(string nombre)
				:Nodo(nombre, true) {}

			void setUnaria(bool esUnaria) {
				this->esUnaria = esUnaria;
				this->func = esUnaria ? funct::funciones_unarias.at(nombre) : funct::funciones_binarias.at(nombre);
			}

			double eval(double x, double y = 0) {
				return this->func.eval(x, y);
			}

		bool esUnaria;
		funct::Funcion func;
	};


	class NodoNumero : public Nodo {
		public:
			NodoNumero(string nombre)
				: Nodo(nombre, false){}

			double eval(double x = 0, double y = 0) {
				return Utilidades::getValorNumerico(nombre.c_str());
			}

	};

}

