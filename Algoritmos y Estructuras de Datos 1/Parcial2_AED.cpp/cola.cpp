#include <iostream>
using namespace std;

class Cola
{
private:
    nodo *raiz;

public:
    Cola()
    {
        raiz = NULL;
    }
    void insertar(prueba Dato);
    prueba sacar();
};

void Cola::insertar(prueba *Dato)
{
    nodo *nuevo = new nodo;
    nuevo->setdato(*Dato);
    nuevo->setpuntero(NULL);

    if (raiz == NULL)
    {
        raiz = nuevo;
    }
    else
    {
        nodo *recor = raiz;
        while (recor->getpuntero() != NULL)
        {
            recor = recor->getpuntero();
        }
        recor->setpuntero(nuevo);
    }
}


prueba Cola::sacar()
{
    prueba aux;
    if (raiz == NULL)
    {
        cout << "La cola esta vacia";
        return;
    }
    else
    {
        aux = raiz->getdato();
        nodo* temp = raiz;
        raiz = raiz->getpuntero();
        delete temp;
    }
    return aux;
}
