#include <iostream>
#include "nodos.cpp"

using namespace std;

class listas
{
private:
    nodo *raiz, *ultimo;

public:
    listas()
    {
        raiz = NULL;
        ultimo = NULL;
    }

    void crear(int Dato);
    void insertarDesp(int Dato);
    void crearLista(int n);
    listas multiplicar(int m);
    void recorrer();
    listas operator*(const int &m);
};

void listas::crear(int Dato)
{
    nodo *n = new nodo;
    n->setdato(Dato);
    raiz = n;
    ultimo = n;
    n->setpuntero(NULL);
}

void listas::insertarDesp(int Dato)
{
    nodo *nuevo = new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(NULL);
    ultimo->setpuntero(nuevo);
    ultimo = nuevo;
}

void listas::crearLista(int n)
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << "_Dato: ";
            cin >> aux;
            insertarDesp(aux);
        }
        else
        {
            cout << "Ingrese primer dato: ";
            cin >> aux;
            crear(aux);
        }
    }
}


void listas::recorrer()
{
    nodo *recor = raiz;
    while (recor != NULL)
    {
        cout << recor->getdato() << "-";
        recor = recor->getpuntero();
    }
    cout << endl;
}

listas listas::operator*(const int &m){
    listas listaResultado;
    nodo *aux = raiz, *n;
    n = new nodo;
    listaResultado.raiz = n;
    listaResultado.ultimo = n;
    while (aux != NULL)
    {
        n->setdato(aux->getdato() * m);
        aux = aux->getpuntero();

        if (aux != NULL)
        {
            n = new nodo;
            listaResultado.ultimo->setpuntero(n);
            listaResultado.ultimo = n;
        }
        else
            listaResultado.ultimo->setpuntero(NULL);
    }
    return listaResultado;

}

int main()
{
    listas L1;
    int aux;

    cout << "Ingrese cantidad de elementos de la lista 1: " << endl;
    cin >> aux;
    L1.crearLista(aux);

    cout << "Ingrese valor al cual desea multiplicar la lista 1: " << endl;
    cin >> aux;
    listas L2 = L1 * aux;

    cout << "Lista 1: ";
    L1.recorrer();

    cout << "Lista 2: ";
    L2.recorrer();

}