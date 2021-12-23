#pragma once
#include <iostream>

using namespace std;

template <class T>
class Arreglo {

	private:
		int dimension;
		T* arr;
	public:
		Arreglo(int);
		void imprimir();
		void ingresar();
		int buscar(T);
		bool estaVacio();
};

template<class T>
Arreglo<T>::Arreglo(int dim)
{
	this->dimension = dim;
	this->arr = (T*)calloc(dim, sizeof(T));
}

template<class T>
void Arreglo<T>::imprimir()
{
	for (int i = 0; i < dimension; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl << endl;
}

template<class T>
void Arreglo<T>::ingresar()
{

	for (int i = 0; i < dimension; i++) {
		cout << "Ingrese el " << i + 1 << " elemento:"; 
		cin >> *(arr + i);
	}
	cout << endl << endl;
}

template<class T>
int Arreglo<T>::buscar(T buscador)
{
	bool encontrado = false;
	int i;
	for (i = 0; i < dimension; i++) {
		if (*(arr + i) == buscador) {
			encontrado = true;
			break;
		}
	}

	if (encontrado)
		return i + 1;
	else
		return -1;
}

template<class T>
bool Arreglo<T>::estaVacio()
{
	return arr == 0;
}

