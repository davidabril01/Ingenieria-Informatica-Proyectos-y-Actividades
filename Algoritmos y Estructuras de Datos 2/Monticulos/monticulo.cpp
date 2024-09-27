#include <iostream>
#include <cstdlib>
#include "monticulo.h"
using namespace std;

int main()
{
    Monticulo M(10);
    M.Insertar(4);
    M.Insertar(2);
    M.Insertar(1);
    M.Insertar(5);
    M.Insertar(6);
    M.Insertar(3);
    M.Insertar(9);
    M.Insertar(7);
    M.Insertar(8);
    M.Insertar(0);
    M.Mostrar();

    cout<<endl;
    cout<<"Extrae elementos de la estructura: ";

    cout << M.ExtraerMaximo()<<endl;
    cout << M.ExtraerMaximo()<<endl;
    cout << M.ExtraerMaximo()<<endl;
    cout << M.ExtraerMaximo()<<endl;
    cout << M.ExtraerMaximo()<<endl;
    cout << M.ExtraerMaximo()<<endl;
    cout << M.ExtraerMaximo()<<endl;
    cout << M.ExtraerMaximo()<<endl;
    cout << M.ExtraerMaximo()<<endl;
    cout << M.ExtraerMaximo()<<endl;
    return 0;
}
