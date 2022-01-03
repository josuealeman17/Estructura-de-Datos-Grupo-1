#include "Alumno.h"

Alumno::Alumno() {
	this->notas = (float*)calloc(5, sizeof(float));
}

Alumno::Alumno(string nombre) {
	this->nombre = nombre;
}

void Alumno::ingresarAlumno()
{
	string nombre;
	cout << "Ingresar el nombre del alumno: "; cin >> nombre;

	this->nombre = nombre;
}

void Alumno::mostrarNotas() {
	cout << "---NOTAS " << getNombre() << endl << endl;
	cout << "Fisica | " << *(notas + 0) << endl;
	cout << "Historia | " << *(notas + 1) << endl;
	cout << "Matematicas | " << *(notas + 2) << endl;
	cout << "Lenguaje | " << *(notas + 3) << endl;
	cout << "Quimica | " << *(notas + 4) << endl;
	cout << "__________________________" << endl;
}

void Alumno::ingresarNotas() {
	float* _notas = (float*)calloc(5, sizeof(float));
	for (int i = 0; i < 5; i++) {
		cout << "Ingrese la nota de la " << i + 1 << " asignatura: ";
		cin >> *(_notas + i);
	}

	this->notas = _notas;
	system("cls");
}

float Alumno::calcularMedia() {
	float cont = 0;
	for (int i = 0; i < 5; i++) {
		cont += *(notas + i);
	}
	return cont / 5;
}

string Alumno::getNombre()
{
	return nombre;
}

float* Alumno::getNotas()
{
	return notas;
}
