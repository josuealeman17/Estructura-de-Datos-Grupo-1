#include "Persona.h"
#include <iostream>

using namespace std;


Persona::Persona(string n, string a)
{
	this->nombre = n;
	this->apellido = a;

}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getApellido()
{
	return apellido;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Persona::setApellido(string apellido)
{
	this->apellido = apellido;
}

void Persona::mostrar() {

	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "____________" << endl;

}
