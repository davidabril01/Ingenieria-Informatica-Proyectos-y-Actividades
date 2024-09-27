#include <iostream>
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
    nodo *getraiz(){
        return raiz;
    }
    nodo *getultimo(){
        return ultimo;
    }
    void insertarDesp(int Dato);
    void insertarAnte(int Dato);
    void insertarEntr(int Dato, int pos);
    void recorrer();
    void eliminar(int pos);
    int sacarAnte();
};

void listas::insertarDesp(int Dato)
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
void listas::insertarAnte(int Dato)
{
    nodo *nuevo = new nodo;
    nuevo->setdato(Dato);
    
    if (raiz == NULL)
    {
        nuevo->setpuntero(NULL);
        raiz = nuevo;
        ultimo = nuevo;
    }
    else
    {
        nuevo->setpuntero(raiz);
        raiz = nuevo;
    }
}

void listas::insertarEntr(int Dato, int pos){
    nodo *nuevo;
    nodo *recor=raiz;
    nuevo=new nodo;
    nuevo->setdato(Dato);
    for (int i = 0; i < pos-1; i++)
    {
        recor = recor->getpuntero();
    }
    nuevo->setpuntero(recor->getpuntero());
    recor->setpuntero(nuevo);
}

void listas::recorrer(){
    nodo *recor=raiz;
    while (recor != NULL){
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

int listas::sacarAnte()
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
        raiz = raiz->getpuntero();
    }
    return aux;
}
