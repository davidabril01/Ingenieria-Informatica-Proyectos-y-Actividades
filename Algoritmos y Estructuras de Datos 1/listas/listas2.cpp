#include <iostream>
using namespace std;

class nodo
{
private:
    int dato;
    nodo *puntero;

public:
    void setdato(int d) { dato = d; }
    int getdato() { return dato; }
    void setpuntero(nodo *p) { puntero = p; }
    nodo *getpuntero() { return puntero; }
};

class listas
{
private:
    nodo *raiz;
    nodo *ultimo;
    nodo *raiz1;
    nodo *ultimo1;

public:
    listas()
    {
        raiz = NULL;
        raiz1 = NULL;
        ultimo = NULL;
        ultimo1 = NULL;
    }
    void insertListas(int d, int d1, int d2, int d3, int d4, int d5, int d6, int d7, bool numList);
    void crear(int Dato);
    void insertarDesp(int Dato);
    void insertarAnte(int Dato);
    void insertarEntr(int Dato, int pos);
    void recorrer(bool listN);
    double AddAll();
    float media();
    int mayor();
    int menor();
    void eliminar(int pos);
};

void listas::insertListas(int d, int d1, int d2, int d3, int d4, int d5, int d6, int d7, bool numList)
{

    nodo *n;
    nodo *nuevo;
    n = new nodo;
    n->setdato(d);
    if (numList){raiz1 = n;}else{raiz = n;}
    nuevo = new nodo;
    n->setpuntero(nuevo);
    nuevo->setdato(d1);
    n = new nodo;
    nuevo->setpuntero(n);
    n->setdato(d2);
    nuevo = new nodo;
    n->setpuntero(nuevo);
    nuevo->setdato(d3);
    n = new nodo;
    nuevo->setpuntero(n);
    n->setdato(d4);
    nuevo = new nodo;
    n->setpuntero(nuevo);
    nuevo->setdato(d5);
    n = new nodo;
    nuevo->setpuntero(n);
    n->setdato(d6);
    nuevo = new nodo;
    n->setpuntero(nuevo);
    nuevo->setdato(d7);
    nuevo->setpuntero(NULL);
    if (numList){ultimo1 = nuevo;}else{ultimo = nuevo;}
}

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

void listas::insertarAnte(int Dato)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(raiz);
    raiz = nuevo;
}

void listas::insertarEntr(int Dato, int pos)
{
    nodo *nuevo;
    nodo *recor = raiz;
    nuevo = new nodo;
    nuevo->setdato(Dato);
    for (int i = 0; i < pos - 1; i++)
    {
        recor = recor->getpuntero();
    }
    nuevo->setpuntero(recor->getpuntero());
    recor->setpuntero(nuevo);
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

void listas::recorrer(bool listN)
{
    if (listN)
    {
        nodo *recor = raiz1;
        while (recor != NULL)
        {
            cout << recor->getdato() << "-";
            recor = recor->getpuntero();
        }
    }
    else
    {
        nodo *recor = raiz;
        while (recor != NULL)
        {
            cout << recor->getdato() << "-";
            recor = recor->getpuntero();
        }
    }
}

double listas::AddAll()
{
    nodo *recor = raiz;
    double aux = 0;
    while (recor != NULL)
    {
        aux = aux + recor->getdato();
        recor = recor->getpuntero();
    }
    return aux;
}

float listas::media()
{
    nodo *recor = raiz;
    float aux = 0;
    int cont = 0;
    while (recor != NULL)
    {
        aux = aux + recor->getdato();
        cont++;
        recor = recor->getpuntero();
    }
    return aux / cont;
}

int listas::mayor()
{
    nodo *recor = raiz;
    int may = recor->getdato();
    recor = recor->getpuntero();
    while (recor != NULL)
    {
        if ((recor->getdato()) > may)
        {
            may = recor->getdato();
        }
        recor = recor->getpuntero();
    }
    return may;
}

int listas::menor()
{
    nodo *recor = raiz;
    int men = recor->getdato();
    recor = recor->getpuntero();
    while (recor != NULL)
    {
        if ((recor->getdato()) < men)
        {
            men = recor->getdato();
        }
        recor = recor->getpuntero();
    }
    return men;
}

int main()
{
    listas L;
    L.insertListas(1, 2, 3, 4, 5, 6, 7, 8, 0);
    L.insertListas(1, 2, 3, 40, 50, 6, 70, 80, 1);
    L.recorrer(1);
    cout << L.AddAll();
    cout << "-" << L.media();
    cout << "-" << L.mayor();
    cout << "-" << L.menor();
    return 0;
}