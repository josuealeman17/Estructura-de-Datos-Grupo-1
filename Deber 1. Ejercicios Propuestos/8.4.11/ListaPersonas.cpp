#include "ListaPersonas.h"
#include "Persona.h"
#include "Radix.h"

void ListaPersonas::mostrarPersonas()
{
	Nodo<Persona>* p;
	p = primero;
	for (int i = 0; i < size; i++) {
		p->dato.mostrar();
		p = p->siguiente;
	}
}

void ListaPersonas::ordenarPersonas()
{
	Radix radix;

	Nodo<Persona>* p;
	p = primero;
	for (int i = 0; i < size; i++) {
		radix.setPalabra(p->dato.getNombre());
		radix.setTamPalabra(radix.getPalabra().size() + 1);
		radix.insertar(radix, 0);
		p = p->siguiente;
	}
	radix.recorrer(radix, " ");
}

