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
	void ordenar(int, int);

	T* getArr();
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
	int primero = 0;
	int ultimo = dimension - 1;
	int mitad;
	bool encontrado = false;

	while (primero <= ultimo && !encontrado) {
		mitad = (primero + ultimo) / 2;

		if (*(arr + mitad) == buscador)
			encontrado = true;
		else if (*(arr + mitad) < buscador)
			ultimo = mitad - 1;
		else
			primero = mitad + 1;
	}

	if (encontrado)
		return mitad;
	else
		return -1;
}

template<class T>
bool Arreglo<T>::estaVacio()
{
	int contador = 0;

	for (int i = 0; i < dimension; i++) {
		if (*(arr + i) == 0)
			contador++;
	}

	return contador == dimension;


}

template<class T>
void Arreglo<T>::ordenar(int ultimo, int primero)
{
	int central, pivote;

	central = (primero + ultimo) / 2;
	pivote = *(arr + central);

	int i, j;
	i = primero;
	j = ultimo;

	do {
		while (*(arr + i) > pivote)
			i++;
		while (*(arr + j) < pivote)
			j--;

		if (i <= j) {
			int tmp;
			tmp = *(arr + i);
			*(arr + i) = *(arr + j);
			*(arr + j) = tmp;
			i++;
			j--;
		}

	} while (i <= j);

	if (primero < j)
		ordenar(j, primero);
	if (i < ultimo)
		ordenar(ultimo, i);
}

template<class T>
T* Arreglo<T>::getArr()
{

	return arr;
}