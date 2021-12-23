#pragma once
#include <iostream>

using namespace std;

class Persona {
	private:
		string nombre;
		string apellido;
	public:
		Persona() = default;
		Persona(string, string);
		string getNombre();
		string getApellido();
		void setNombre(string);
		void setApellido(string);
		void mostrar();
};

