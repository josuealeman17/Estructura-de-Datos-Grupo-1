#include <iostream>
#include "Vector.h"
using namespace std;
/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Ejercicio 8.4.15
 * Autor:  Josue Aleman, Luis Espinoza, Jorge Nasimba
 * Fecha de creacion: Viernes, Diciembre 23, 2021 
 * Fecha de modificacion: Viernes, Diciembre 23, 2021 
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 ***********************************************************************/
void ingresarDatos(int *,int arr[]);
void QuicksortA(int *,int ,int );
void QuicksortD(int *,int ,int );
void imprimir(int *);

int main(int argc, char** argv) {
	

	int dim;
	Vector<int> vector(dim);

	int opc;
	do {
		system("cls");
		cout << "\tEJERCICIO 8.4.2" << endl << endl;
		cout << "  1. Ingresar" << endl;
		cout << "  2. Eliminar datos repetidos" << endl;
		cout << "  3. Salir: "; cin >> opc;
		switch (opc) {
		case 1:
			system("cls");
			cout<<"Ingrese la dimension: ";
			cin>>dim;
			vector.ingresar(dim);
			system("pause");
			break;
		case 2:
			system("cls");
			if (vector.estaVacio())
				cout << "El arreglo esta vacio, ingrese datos primero" << endl << endl;
			else {
				cout<<"Datos ingresados\n";
				vector.imprimir(dim);
				cout<<"Datos eliminados"<<endl;
				vector.QuicksortA(vector.getArr(),0,dim-1);
				vector.imprimir(dim);
				vector.eliminarR(dim);
				cout<<"\n";
				system("pause");
			}
			break;
		case 3:
			exit(0);
		}
	} while (opc != 3);
	
	system("pause");
	return 0;
}




