#pragma once
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include "Utilidades.h"
#include "Nodo.h"
#include "Funcion.h"
#include "Definicion.h"

using namespace std;

class Expresion {

	public:

		Expresion() = default;

		funct::RPN notacionPolacaInversa(const char* eqn);
		funct::RPN preToPost(string str);
		Nodo::Nodo* pasar(funct::RPN rpn);
		double evaluarArbol(Nodo::Nodo* arbol);


};