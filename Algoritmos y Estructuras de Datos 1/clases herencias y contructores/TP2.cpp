#include <iostream>
using namespace std;
#include "TP2.h"

int profesional::tarjeta()
{
}

void cuenta::CrearCuenta()
{
}
void cuenta::IngresoEgreso()
{
}

void SistMainBanco::AltaBaja()
{
}

int SistMainBanco::busquedaDNI(int dni)
{
    for (int i = 0; i < ultimoA; i++)
    {
        if (A[i].getDni() == dni)
        {
            return i;
            i = 101;
        }
    }
    for (int i = 0; i < ultimoP; i++)
    {
        if (P[i].getDni() == dni)
        {
            return i;
            i = 101;
        }
    }
    return 101;
}

void SistMainBanco::Menu()
{

    bool auxbool;
    int auxint;
    string auxstring;
    cout << endl
         << "Buen dia, ingrese su DNI" << endl;
    cin >> auxint;
    if (busquedaDNI(auxint) == 101 || (ultimoA == 0 && ultimoP == 0))
    {
        cout << "Vemos que usted no tiene una cuenta con nosotros." << endl
             << "Desea crearla? s:1/n:0";
        cin >> auxbool;
    }
    if (auxbool)
    {
        cout << "Usted es 0: administrativo o 1: profesional?: ";
        cin >> auxbool;
        if (auxbool)
        {
             
        }else{
            ultimoA=ultimoA+1;
            A[ultimoA].setDni(auxint);
            cout << "Introduzca su Nombre: ";
            cin >> auxstring;
            A[ultimoA].setNom(auxstring);
            cout << "Introduzca su Mail: ";
            cin >> auxstring;
            A[ultimoA].setmail(auxstring);
        }
    }
    
    cout << "_Extracciones" << endl
         << "_Depositos" << endl
         << "_Mis Datos";
}

int main()
{
}