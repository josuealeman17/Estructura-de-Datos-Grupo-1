#include <iostream>
#include <cstdlib>
#include "Arreglo.h"

using namespace std;


int main(int argv, char** arcg) {

	cout << "EJERCICIO 8.4.2" << endl << endl;

	int dim = 30;
	Arreglo<int> arreglo(dim);

	int opc;
	do {
		cout << "1. Ingresar" << endl;
		cout << "2. Buscar" << endl;
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
				int buscador;
				arreglo.imprimir();
				cout << "Ingrese el dato que va a buscar:"; cin >> buscador;
				buscador = arreglo.buscar(buscador);
				if (buscador != -1)
					cout << "Elemento encontrado!: " << buscador << endl;
				else
					cout << "Elemento no encontrado" << endl;
			}
			break;
		case 3:
			exit(0);
		}
	} while (opc != 3);


	return 0;
}