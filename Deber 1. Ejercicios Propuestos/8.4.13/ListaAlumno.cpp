#include "ListaAlumno.h"
#include "Orden.h"

void ListaAlumno::mostrarAlumnos()
{
	Nodo<Alumno>* p;
	p = primero;

	for (int i = 0; i < size; i++) {
		p->dato.mostrarNotas();
		p = p->siguiente;
	}
}

void ListaAlumno::mediaAsignaturas() {

	Nodo<Alumno>* p;
	p = primero;

	float cont = 0;

	for (int i = 0; i < size; i++) {
		cont += *((p->dato.getNotas()) + 0);
		p = p->siguiente;
	}

	cout << "Media Fisica: " << cont / size << endl;

	cont = 0;
	p = primero;

	for (int i = 0; i < size; i++) {
		cont += *((p->dato.getNotas()) + 1);
		p = p->siguiente;
	}

	cout << "Media Historia: " << cont / size << endl;

	cont = 0;
	p = primero;

	for (int i = 0; i < size; i++) {
		cont += *((p->dato.getNotas()) + 2);
		p = p->siguiente;
	}

	cout << "Media Matematicas: " << cont / size << endl;

	cont = 0;
	p = primero;

	for (int i = 0; i < size; i++) {
		cont += *((p->dato.getNotas()) + 3);
		p = p->siguiente;
	}

	cout << "Media Lenguaje: " << cont / size << endl;

	cont = 0;
	p = primero;

	for (int i = 0; i < size; i++) {
		cont += *((p->dato.getNotas()) + 4);
		p = p->siguiente;
	}

	cout << "Media Quimica: " << cont / size << endl;

}

void ListaAlumno::mediaClase()
{
	Nodo<Alumno>* p;
	p = primero;

	float cont = 0;
	for (int i = 0; i < size; i++) {
		cont += p->dato.calcularMedia();
		p = p->siguiente;
	}

	cout << "La media de toda la clase es: " << cont / size << endl;
}

void ListaAlumno::mediaAlumnos()
{
	Nodo<Alumno>* p;
	p = primero;

	for (int i = 0; i < size; i++) {
		cout << "La media de " << p->dato.getNombre() << " es: " << p->dato.calcularMedia() << endl;
		p = p->siguiente;
	}

}

void ListaAlumno::ordenar()
{
	Orden orden;
	Nodo<Alumno>* p;
	p = primero;

	float* notasIndividuales = (float*)calloc(size, sizeof(float));
	for (int i = 0; i < size; i++) {
		*(notasIndividuales + i) = p->dato.calcularMedia();
		p = p->siguiente;
	}
	notasIndividuales = orden.shellSort(notasIndividuales, size);
	
	p = primero;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < size; j++) {
			if (*(notasIndividuales + i) == p->dato.calcularMedia()) {
				cout << "Estudiante: " << p->dato.getNombre() << endl << "Nota: " << *(notasIndividuales + i) << endl << endl;
				break;
			} 
			p = p->siguiente;
		}
		p = primero;
	}
}
