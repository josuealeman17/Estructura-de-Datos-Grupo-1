#include "Menu.h"
#include "Expresion.h"
#include "Funcion.h"
#include "Nodo.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Menu::imprimir() {

	cout << "Seleccione el tipo de notacion por la que quiere ingresar la expresion: " << endl;
	int opc;
	string expresion;

	do {
		cout << "1. IN-FIJA" << endl;
		cout << "2. PRE-FIJA" << endl;
		cout << "3. POST-FIJA" << endl;
		cout << "4. SALIR" << endl; cin >> opc;
		cin.clear();
		cin.ignore(9999,'\n');

		switch (opc) {
			case 1:
				system("cls");
				ingresarIn(expresion);

				break;
			case 2:
				system("cls");
				ingresarPre(expresion);

				break;
			case 3:
				system("cls");
				ingresarPost(expresion);

				break;
			case 4:
				system(0);
		}

	} while (opc != 4);
}

void Menu::ingresarIn(string expresion) {
	Expresion exp;
	
	cout << "Ingresando en INFIJA" << endl;
	getline(std::cin, expresion);

	funct::RPN rpn = exp.notacionPolacaInversa(expresion.c_str());

	Nodo::Nodo* nodo = exp.pasar(rpn);
	double result = exp.evaluarArbol(nodo);

	cout << result;
	cout << endl;


	system("pause");
	system("cls");

}

void Menu::ingresarPre(string expresion) {
	cout << "Ingresando en PREFIJA" << endl; cin >> expresion;

	system("pause");
	system("cls");
}

void Menu::ingresarPost(string expresion) {

	Expresion exp;
	funct::RPN rpn;

	cout << "Ingresando en POSTFIJA" << endl; 
	getline(cin, expresion);
	stringstream ss(expresion);
	string token;

	while (getline(ss, token, ' ')) {

		rpn.push_back(token);
	}
	Nodo::Nodo* nodo = exp.pasar(rpn);
	double result = exp.evaluarArbol(nodo);


	system("pause");
	system("cls");
}
