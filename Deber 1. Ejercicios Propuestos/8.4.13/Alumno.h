#pragma once
#include <iostream>
using namespace std;

class Alumno {

	private:

		string nombre;
		float* notas;

	public:

			Alumno();
			Alumno(string);
			void ingresarAlumno();
			void mostrarNotas();
			void ingresarNotas();
			float calcularMedia();
		

			string getNombre();
			float* getNotas();
};