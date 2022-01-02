#pragma once
#include <iostream>

using namespace std;

class Orden {

private:
	float temp;
	int inc, i, j;
public:
	Orden() = default;
	void shellSort(float*, int);
	void mostrar(float*, int);

};


void Orden::shellSort(float* V, int N) {

	for (inc = 1; inc < N; inc = inc * 3 + 1);

	while (inc > 0) {
		for (i = inc; i < N; i++) {
			j = i;
			temp = *(V + i);
			while ((j >= inc) && (*(V + (j - inc)) > temp)) {
				*(V + j) = *(V + (j - inc));
				j = j - inc;
			}
			*(V + j) = temp;
		}
		inc /= 2;
	}

	mostrar(V, N);

}

void Orden::mostrar(float* V, int N) {

	for (int i = N - 1; i >= 0; i--) {
		cout << *(V + i) << " ";
	}
	cout << endl;
}
