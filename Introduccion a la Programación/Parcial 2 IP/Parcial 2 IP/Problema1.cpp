#include <iostream>
using namespace std;

void cargarVector(int vector[12]) {
	for (size_t i = 0; i < 12; i++)
	{
		cout << "Ingrese el dato numero " << i << " del conjunto de datos.\n";
		cin >> vector[i];
	}
}
void contCant(int vector[12], int numeros[3]) {
	for (size_t i = 0; i < 3; i++) {
		numeros[i] = 0;
	}
	for (size_t i = 0; i < 12; i++)
	{
		switch (vector[i]){
		case 0:
			numeros[0]++;
			break;
		case 1:
			numeros[1]++;
			break;
		case 2:
			numeros[2]++;
			break;
		}
	}
}
int main() {
	int vector[12], numeros[3];
	cargarVector(vector);
	contCant(vector, numeros);
	cout << "En el conjunto de datos: \n";
	for (size_t i = 0; i < 3; i++)
	{
		cout << "Aparece " << numeros[i] << " veces el numero " << i << "\n";
	}
}