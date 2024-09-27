#include <iostream>
#include "nodos.cpp"
using namespace std;

class pila
{
private:
    nodo *raiz;

public:
    pila() {}
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
    int aux;
    if (raiz == NULL)
    {
        cout << "La pila esta vacia";
    }
    else
    {
        aux = raiz->getdato();
        raiz = raiz->getpuntero();
    }
    return aux;
}

class Cola
{
private:
    int cantidad;
    nodo *raiz, *ultimo;

public:
    Cola()
    {
    }
    void insertar(int Dato);
    int sacar();
};

void Cola::insertar(int Dato)
{
    nodo *nuevo = new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(NULL);
    if (raiz == NULL)
    {
        raiz = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->setpuntero(nuevo);
        ultimo = nuevo;
    }
}

int Cola::sacar()
{
    int aux;
    if (raiz != nullptr)
    {
        nodo *actual = raiz;
        nodo *anterior = NULL;
        while (actual->getpuntero() != NULL)
        {
            anterior = actual;
            actual = actual->getpuntero();
        }
        if (anterior == NULL)
        {
            raiz = NULL;
            ultimo = NULL;
        }
        else
        {
            aux = actual->getdato();
            anterior->setpuntero(NULL);
            ultimo = anterior;
        }
        delete actual;
        cout << aux << " "; // Modificamos la línea para que se imprima con un espacio después del valor
        return aux;
    }
    else return 0;
}



int main()
{
    pila P;

    P.poner(6);
    P.poner(3);
    P.poner(5);
    P.poner(8);
    P.poner(2);
    P.poner(1);
    cout << P.sacar() << P.sacar() << P.sacar() << P.sacar() << P.sacar() << P.sacar() << endl;
    Cola C;
    C.insertar(6);
    C.insertar(3);
    C.insertar(5);
    C.insertar(8);
    C.insertar(2);
    C.insertar(1);
    cout << C.sacar() << C.sacar() << C.sacar() << C.sacar() << C.sacar() << C.sacar() << endl;
}
