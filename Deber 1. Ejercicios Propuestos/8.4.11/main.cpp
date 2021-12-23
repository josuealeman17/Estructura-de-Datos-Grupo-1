/***********************************************************************

 * Universidad de las Fuerzas Armadas ESPE
 * Ejercicio 8.4.11
 * Autor:  Josue Aleman, Luis Espinoza, Jorge Nasimba
 * Fecha de creacion: Miercoles, Diciembre 22, 2021
 * Fecha de modificacion: Jueves, Diciembre 23, 2021
 * NRC: 7167
 
 * ESTRUCTURA DE DATOS
 ***********************************************************************/

#include <iostream>
#include <cstdlib>
#include "ListaPersonas.h"
#include "Persona.h"

using namespace std;

void definirDimension(int&);

int main(int argv, char** argc) {


	cout << "RADIX" << endl;
	Persona persona;
	ListaPersonas lista;
	string nombre, apellido;
	int dim;

	int opc;
	do {
		cout << "1. Ingresar Personas" << endl;
		cout << "2. Ordenar" << endl;
		cout << "3. Salir" << endl; cin >> opc;
		system("cls");
		switch (opc) {
			case 1:

				definirDimension(dim);
				for (int i = 0; i < dim; i++) {
					cout << "Ingrese el nombre de la persona: "; cin >> nombre;
					cout << "Ingrese el apellido de la persona: "; cin >> apellido;
					persona = Persona(nombre, apellido);
					lista.push(persona);
					system("cls");
				}

				lista.mostrarPersonas();
				system("pause");
				system("cls");

				break;
			case 2:
				lista.ordenarPersonas();
				system("pause");
				system("cls");
				break;
			case 3:
				exit(0);
		}
	} while (opc != 3);

	return 0;

}

void definirDimension(int& dim) {
	cout << "Cuantas personas desea agregar?: "; cin >> dim;
}