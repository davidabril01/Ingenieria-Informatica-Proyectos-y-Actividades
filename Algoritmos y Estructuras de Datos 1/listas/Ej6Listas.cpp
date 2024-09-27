#include <iostream>
#include "nodos.cpp"
using namespace std;

class Lista
{
private:
    int cantidad;
    nodo *inicio, *ultimo;

public:
    Lista()
    {
    }
    Lista(bool i)
    {
        cantidad = 0;
        inicio = NULL;
        ultimo = NULL;
        int n, dato;
        cout << "Ingrese cantidad de elementos de la lista 1: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Ingrese elemento " << i + 1 << " de la lista 1: ";
            cin >> dato;
            insertarDesp(dato);
        }
    }

    void crear(int Dato)
    {
        nodo *n = new nodo;
        n->setdato(Dato);
        n->setpuntero(NULL);
        inicio = n;
        ultimo = n;
    }
    void insertarDesp(int Dato)
    {
        nodo *nuevo = new nodo;
        nuevo->setdato(Dato);
        nuevo->setpuntero(NULL);
        if (inicio == NULL)
        {
            inicio = nuevo;
            ultimo = nuevo;
        }
        else
        {
            ultimo->setpuntero(nuevo);
            ultimo = nuevo;
        }
    }

    void imprimir()
    {
        nodo *aux = inicio;
        while (aux != NULL)
        {
            cout << aux->getdato() << " ";
            aux = aux->getpuntero();
        }
        cout << endl;
    }

    Lista operator+(const Lista &listass)
    {
        Lista listaResultado;
        nodo *aux1 = inicio;
        nodo *aux2 = listass.inicio;
        while (aux1 != NULL && aux2 != NULL)
        {
            int suma = aux1->getdato() + aux2->getdato();
            listaResultado.insertarDesp(suma);
            aux1 = aux1->getpuntero();
            aux2 = aux2->getpuntero();
        }
        return listaResultado;
    }
};

int main()
{
    Lista lista1(0), lista2(0);

    Lista listaResultado =  lista2 + lista1;

    cout << "Lista 1: ";
    lista1.imprimir();

    cout << "Lista 2: ";
    lista2.imprimir();

    cout << "Lista Resultante: ";
    listaResultado.imprimir();

}