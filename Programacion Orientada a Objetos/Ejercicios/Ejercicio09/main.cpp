#include <iostream>
#include "ordenar.h"

using namespace std;

int main() {
    int arrayInt[] = {9, 4, 6, 7, 1};
    int cantidadInt = sizeof(arrayInt) / sizeof(arrayInt[0]);

    float arrayFloat[] = {6.6, 1.2, 4.3, 9.7, 10.4};
    int cantidadFloat = sizeof(arrayFloat) / sizeof(arrayFloat[0]);

    cout << "Numeros Float" << endl;
    imprimir(arrayFloat, cantidadFloat, true);
    imprimir(arrayFloat, cantidadFloat, false);
    cout << endl;

    cout << "Numeros enteros:" << endl;
    imprimir(arrayInt, cantidadInt, true);
    imprimir(arrayInt, cantidadInt, false);

    return 0;
}
