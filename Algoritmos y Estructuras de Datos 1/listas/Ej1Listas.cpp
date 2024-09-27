#include <iostream>
#include "nodos.cpp"
using namespace std;

class listas
{
private:
    nodo *raiz;
    nodo *ultimo;

public:
    listas()
    {
        raiz = NULL;
        ultimo = NULL;
    }
    void crear(int Dato);
    void insertarDesp(int Dato);
    void recorrer();
};

void listas::crear(int Dato)
{
    nodo *n;
    n = new nodo;
    n->setdato(Dato);
    raiz = n;
    ultimo = n;
    n->setpuntero(NULL);
}

void listas::insertarDesp(int Dato)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(NULL);
    ultimo->setpuntero(nuevo);
    ultimo = nuevo;
}
void listas::recorrer()
{
    nodo *recor = raiz;
    while (recor != NULL)
    {
        cout << recor->getdato() << "-";
        recor = recor->getpuntero();
    }
}

int main()
{
    listas L;
    int aux;
    bool a = 1;
    cout << "Ingrese el valor 1" << endl;
    cin >> aux;
    L.crear(aux);
    while (a)
    {
        cout << "_Dato sig: " << endl;
        cin >> aux;
        L.insertarDesp(aux);
        cout << "0: Mostrar Lista || 1: Ingresar nuevo valor" << endl;
        cin >> a;
    }
    L.recorrer();
}