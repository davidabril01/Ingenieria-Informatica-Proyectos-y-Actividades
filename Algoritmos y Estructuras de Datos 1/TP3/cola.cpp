#include <iostream>
using namespace std;

class Cola
{
private:
    int cantidad;
    nodo *raiz;

public:
    Cola()
    {
        raiz = NULL;
    }
    void insertar(int Dato);
    int sacar();
    void recorrer();
};

void Cola::insertar(int Dato)
{
    nodo *nuevo = new nodo;
    nuevo->setdato(Dato);
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


int Cola::sacar()
{
    int aux;
    if (raiz == NULL)
    {
        cout << "La cola esta vacia";
        return 0;
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
