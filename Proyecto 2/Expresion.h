#pragma once
#include <iostream>
#include "Funcion.h"
#include "Nodo.h"
#include <stack>
#include <map>
#include <vector>


using namespace std;


class Expresion {

	public:

		Expresion() = default;

		Funcion::RPN notacionPolacaInversa(string str);
		Funcion::RPN preToPost(string str);
		Nodo::Nodo* pasar(Funcion::RPN rpn);
		double eval(Nodo::Nodo* arbol);


};