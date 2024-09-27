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
    void eliminar(int pos);
    void reemplazar(int pos, int Dato);
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
void listas::eliminar(int pos)
{
    nodo *anterior = raiz, *siguiente = raiz;

    for (int i = 1; i < pos - 1; i++)
    {
        anterior = anterior->getpuntero();
    }
    for (int i = 1; i < pos + 1; i++)
    {
        siguiente = siguiente->getpuntero();
    }
    if (pos > 1)
    {
        anterior->setpuntero(siguiente);
    }
    else
    {
        raiz = raiz->getpuntero();
    }
}
void listas::reemplazar(int pos, int Dato)
{
    nodo *r = raiz;

    for (int i = 1; i < pos; i++)
    {
        r = r->getpuntero();
    }
    r->setdato(Dato);
}

int main()
{
    listas L;
    int aux, aux1;
    bool a = 1;
    cout << "Ingrese el valor 1" << endl;
    cin >> aux;
    L.crear(aux);
    while (a)
    {
        cout << "1: Ingresar nuevo valor || 2: Eliminar || 3: Reemplazar || 4: Recorrer || 0: Salir" << endl;
        cin >> aux;
        switch (aux)
        {
        case 1:
            cout << "_Dato sig: " << endl;
            cin >> aux;
            L.insertarDesp(aux);
            break;
        case 2:
            cout << "_Posicion a Eliminar: " << endl;
            cin >> aux;
            L.eliminar(aux);
            break;
        case 3:
            cout << "_Posicion a Reemplazar: " << endl;
            cin >> aux;
            cout << "_Dato: " << endl;
            cin >> aux1;
            L.reemplazar(aux, aux1);
            break;
        case 4:
            L.recorrer();
            cout<<endl;
            break;
        case 0:
            a = 0;
            break;
        }
    }
}