#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Menu {

	public:
		Menu() = default;
		void imprimir();
		void ingresarIn(string);
		void ingresarPre(string);
		void ingresarPost(string);
};