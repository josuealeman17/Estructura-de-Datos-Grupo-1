#pragma once
#include <iostream>
#include <cstdlib>

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