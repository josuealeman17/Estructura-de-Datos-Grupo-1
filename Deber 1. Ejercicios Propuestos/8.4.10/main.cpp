/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Ejercicio 8.4.10
 * Autor:  Josue Aleman, Luis Espinoza, Jorge Nasimba
 * Fecha de creacion: Sabado, Enero 01, 2022
 * Fecha de modificacion: Sabado, Enero 01, 2022
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 ***********************************************************************/
#include <iostream>
#include <cstdlib>
#include "Arreglo.h"

using namespace std;

void definirDimension(int&);

int main(int argv, char** arcg) {

	cout << "EJERCICIO 8.4.10" << endl << endl;

	int dim;
	definirDimension(dim);

	Arreglo<int> arreglo(dim);

	int opc;
	do {
		cout << "1. Ingresar" << endl;
		cout << "2. Calcular Mediana" << endl;
		cout << "3. Salir"; cin >> opc;
		switch (opc) {
		case 1:
			arreglo.ingresar();
			arreglo.imprimir();
			break;
		case 2:
			if (arreglo.estaVacio())
				cout << "El arreglo esta vacio, ingrese datos primero";
			else {
				arreglo.ordenar();
				arreglo.imprimir();
				int mediana = arreglo.calcularMediana();
				cout << "La mediana del arreglo es:  " << mediana << endl;
			}
			break;
		case 3:
			exit(0);
		}
	} while (opc != 3);


	return 0;
}

void definirDimension(int& dim) {

	do {
		cout << "Ingrese la dimension de su arreglo: "; cin >> dim;
		if ((dim % 2) == 0)
			cout << "Por favor, solo dimensiones impares!" << endl;
	} while ((dim % 2) == 0);

}