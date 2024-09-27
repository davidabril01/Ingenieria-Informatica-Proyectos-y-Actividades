#include <iostream>
using namespace std;


class pila
{
private:
    nodo *raiz;

public:
    pila() {
        raiz = NULL;
    }
    void poner(int Dato);
    int sacar();
};

void pila::poner(int Dato)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(raiz);
    raiz = nuevo;
}

int pila::sacar()
{
    int aux=0;
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        aux = raiz->getdato();
        raiz = raiz->getpuntero();
    }
    return aux;
}