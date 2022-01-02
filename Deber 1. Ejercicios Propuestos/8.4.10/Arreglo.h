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
		int calcularMediana();
		bool estaVacio();
		void ordenar();
		void intercambiar(T&, T&);


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
void Arreglo<T>::ingresar() {

	for (int i = 0; i < dimension; i++) {
		cout << "Ingrese el " << i + 1 << " elemento:";
		cin >> *(arr + i);
	}
}

template<class T>
int Arreglo<T>::calcularMediana()
{
	int i = (dimension - 1) / 2;

	return *(arr + i);
}

template<class T>
bool Arreglo<T>::estaVacio()
{
	return(calcularMediana() == 0);
}

template<class T>
void Arreglo<T>::ordenar()
{
	for (int i = 0; i < dimension - 1; i++) {
		for (int j = i + 1; j < dimension; j++) {
			if (*(arr + i) > *(arr + j)) {
				intercambiar(*(arr + i), *(arr + j));
			}
		}
	}

}

template<typename T>
void Arreglo<T>::intercambiar(T& v1, T& v2) {
	T aux = v1;
	v1 = v2;
	v2 = aux;
}

template<class T>
T* Arreglo<T>::getArr()
{
	return arr;
}
