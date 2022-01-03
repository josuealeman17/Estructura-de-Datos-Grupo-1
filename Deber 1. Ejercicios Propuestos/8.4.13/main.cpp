#include <iostream>
#include <cstdlib>
#include "ListaAlumno.h"
#include "Alumno.h"


using namespace std;


int main(int argv, char** argc) {


	cout << "EJERCICIO 8.4.13" << endl;
	cout << "COLEGIO LOS TIGRES TAMBIEN LLORAN" << endl;
	system("pause");
	system("cls");

	ListaAlumno alumnos;


	int opc;

	do {
		cout << "1. Alumnos" << endl;
		cout << "2. Asignaturas" << endl;
		cout << "3. Salir" << endl; cin >> opc;
		system("cls");
		switch (opc) {

			case 1:
				int alumn;
				int dim;
				do {
					cout << "1. Ingresar alumnos" << endl;
					cout << "2. Ver lista de alumnos" << endl;
					cout << "3. Calcular media de alumnos" << endl;
					cout << "4. Ver media de la clase" << endl;
					cout << "5. Ordenar alumnos" << endl;
					cout << "6. Regresar" << endl; cin >> alumn;
					system("cls");
					if (alumn == 1) {
						cout << "Cuantos alumnos vas a ingresar?"; cin >> dim;
						Alumno alumno;
						for (int i = 0; i < dim; i++) {
							alumno.ingresarAlumno();
							alumno.ingresarNotas();
							alumnos.push(alumno);
						}
					}
					if (alumn == 2) alumnos.mostrarAlumnos();
					if (alumn == 3) alumnos.mediaAlumnos();
					if (alumn == 4) alumnos.mediaClase();
					if (alumn == 5) alumnos.ordenar();
					system("pause");
					system("cls");
				} while (alumn != 6);

				break;

			case 2:
				int asig;
				do {
					cout << "1. Ver Media" << endl;
					cout << "2. Regresar" << endl; cin >> asig;
					if (asig == 1) alumnos.mediaAsignaturas();
				} while (asig != 2);
				system("pause");
				system("cls");
				break;
			case 3:
				exit(0);
		}

	} while (opc != 3);

	return 0;

}

