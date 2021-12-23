#pragma once
#include "Lista.h"
#include "Persona.h"

class ListaPersonas : public Lista<Persona> {

	public:
		void mostrarPersonas();
		void ordenarPersonas();
};