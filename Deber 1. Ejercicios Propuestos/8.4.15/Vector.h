#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector {

private:
	int dimension;
	T *arr;
	T *aux;
	T *final;
	
	
public:
	Vector(int);
	void imprimir(int);
	void ingresar(int);
	bool estaVacio();
	void ordenar();
	void QuicksortA(T *,int ,int );
	void eliminarR(int);
	T* getArr();
	T* getFinal();
};

template<class T>
Vector<T>::Vector(int dim)
{
	this->dimension = dim;
	this->arr = (T*)calloc(dim, sizeof(T));
	this->aux = (T*)calloc(dim, sizeof(T));
	this->final = (T*)calloc(dim, sizeof(T));
}

template<class T>
bool Vector<T>::estaVacio()
{
	bool bandera = false;

	for (int i = 0; i < dimension; i++) {
		if (*(arr + i) == 0)
			bandera=true;
		else
			bandera=false;
	}

	return bandera;


}
template<class T>
void Vector<T>::ingresar(int dim)
{

	for (int i = 0; i < dim; i++) {
		cout << "Ingrese el " << i + 1 << " elemento:";
		cin >> *(arr + i);
	}
	cout << endl << endl;
}

template<class T>
void Vector<T>::imprimir(int dim)
{
	for (int i = 0; i < dim; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl << endl;
}

template<class T>
T* Vector<T>::getArr()
{

	return arr;
}

template<class T>
T* Vector<T>::getFinal()
{

	return final;
}

template<class T>
void Vector<T>::QuicksortA(T *arr,int izq,int der)
{
	int i=izq,j=der,tmp;
	int p=arr[(izq+der)/2];
	
	while(i<=j)
	{
		while(*(arr+i)<p)i++;
		while(*(arr+j)>p)j--;
		if(i<=j)
		{
			tmp=*(arr+i);
			*(arr+i)=*(arr+j);
			*(arr+j)=tmp;
			i++;
			j--;
		}
	}
	if(izq<j)
		QuicksortA(arr,izq,j);
	if(i<der)
		QuicksortA(arr,i,der);
}

template<class T>
void Vector<T>::eliminarR(int dim)
{
	int i,j=0,z=0,k,cont,num;
	for(i=0;i<dim;i++)
	{
		cont=0;
		num=*(arr+i);
		*(aux+j)=num;
		j++;
		for(k=0;k<dim;k++)
		{
			if(*(aux+k)==num)
			{
				cont++;
			}					
		}
		
		if(cont==1)
		{
			*(final+z)=num;	
			z++;
		}			
	}
	
	for(i=0;i<z;i++)
	{
		cout<<*(final+i)<<" ";
	}
}
