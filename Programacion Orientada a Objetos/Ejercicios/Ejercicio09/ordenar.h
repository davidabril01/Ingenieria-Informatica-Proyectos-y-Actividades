#ifndef ORDENAR_H
#define ORDENAR_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class Ordenar>
void imprimir(Ordenar* v, int cantidad, bool mayor_a_menor) {
    vector<Ordenar> vec(v, v + cantidad);

    if (mayor_a_menor) {
        sort(vec.begin(), vec.end(), greater<Ordenar>());
        cout << "Ordenado de mayor a menor: ";
    } else {
        sort(vec.begin(), vec.end());
        cout << "Ordenado de menor a mayor: ";
    }

    for (const Ordenar& valor : vec) {
        cout << valor << " ";
    }
    cout << endl;
}

#endif // ORDENAR_H
