#include <iostream>
using namespace std;

void cargarMatriz(float matriz[3][3]) {
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			cout << "Ingrese el dato numero " << i << ", " << j << " del conjunto de datos.\n";
			cin >> matriz[i][j];
		}
	}
}

void divMatriz(float matriz[3][3]) {
	float a;
	cout << "Ingrese el numero por el cual desea dividir cada elemento de la matriz: ";
	cin >> a;
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			matriz[i][j] = matriz[i][j] / a;
		}
	}
}

void rellArreglo(float matriz[3][3], float vector[9], int& a) {
	a = 0;
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			if (matriz[i][j] < 1) {
				vector[a] = matriz[i][j];
				a++;
			}
		}
	}
}

void imprimirMatriz(float matriz[3][3]) {
	cout << "La matriz resultante es: \n";
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << "\n";
	}
}

void imprimirArreglo(float vector[9], int a) {
	cout << "Los valores menores a uno son: \n";
	for (size_t j = 0; j < a; j++)
	{
		cout << vector[j] << " ";
	}
}

int main() {
	float matriz[3][3], vector[9];
	int a;
	cargarMatriz(matriz);
	divMatriz(matriz);
	rellArreglo(matriz, vector, a);
	imprimirMatriz(matriz);
	imprimirArreglo(vector, a);
}