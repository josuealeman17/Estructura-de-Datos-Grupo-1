#pragma once
#include "Lista.h"
#include "Alumno.h"


class ListaAlumno : public Lista<Alumno> {

	public:
		void mostrarAlumnos();
		void mediaAsignaturas();
		void mediaClase();
		void mediaAlumnos();
		void ordenar();
		void sort();
		
};