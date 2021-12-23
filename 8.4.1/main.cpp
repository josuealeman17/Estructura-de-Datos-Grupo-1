#include <iostream>
using namespace std;
/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Ejercicio 1
 * Autor:  Josue Aleman, Luis Espinoza, Jorge Nasimba
 * Fecha de creacion: Viernes, Diciembre 22, 2021 
 * Fecha de modificacion: Viernes, Diciembre 22, 2021 
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 ***********************************************************************/
void ingresarDatos(int *,int arr[]);
void QuicksortA(int *,int ,int );
void QuicksortD(int *,int ,int );
void imprimir(int *);

int main(int argc, char** argv) {
	int *arreglo=new int[14];
    int arr[14]={33,45,67,8,12,32,56,7,9,10,22,45,98,9};
    
    ingresarDatos(arreglo,arr);
	cout<<"\tArreglo a Ordenar\n";
	imprimir(arreglo);
	
	cout<<"\n\n\n\tArreglo Ordenado Ascendete\n";
	QuicksortA(arreglo,0,13);//menor a mayor
	imprimir(arreglo);
	
	cout<<"\n\n\n\tArreglo Ordenado Descendete\n";
	QuicksortD(arreglo,13,0);//mayor a menor
	imprimir(arreglo);
	cout<<"\n";
	cout<<"\n";
	system("pause");
	return 0;
}

void ingresarDatos(int *arr,int arreglo[])
{
	for(int i=0;i<15;i++)
    {
    	*(arr+i)=arreglo[i];
	}
}

void QuicksortA(int *arr,int izq,int der)
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

void QuicksortD(int *arr,int ultimo,int primero)
{
	int i,j,central,pivote;
	
	central=(primero+ultimo)/2;
	pivote=*(arr+central);
	i=primero;
	j=ultimo;
	do
	{
		while(*(arr+i)>pivote)
			i++;
		while(*(arr+j)<pivote)
			j--;
		
		if(i<=j)
		{
			float tmp;
			tmp=*(arr+i);
			*(arr+i)=*(arr+j);
			*(arr+j)=tmp;
			i++;
			j--;
		}	
	}while(i<=j);
	
	if(primero<j)
		QuicksortD(arr,j,primero);
	if(i<ultimo)
		QuicksortD(arr,ultimo,i);
}

void imprimir(int *arr)
{
	for(int i=0;i<14;i++)
	{
		cout<<*(arr+i)<<" ";
	}
}