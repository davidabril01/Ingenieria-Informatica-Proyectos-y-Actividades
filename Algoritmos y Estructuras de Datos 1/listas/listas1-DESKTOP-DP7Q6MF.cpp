#include <iostream>
using namespace std;

class nodo
{
    private:
        int dato;
        nodo *puntero;
    public:
        void setdato(int d){dato=d;}
        int getdato(){return dato;}
        void setpuntero(nodo *p){puntero=p;}
        nodo *getpuntero(){return puntero;}
};

class listas
{
    private:
        nodo *raiz;
        nodo *ultimo;
    public:
        listas(){
            raiz = NULL;
            ultimo = NULL;
        }
        void crear(int Dato);
        void insertarDesp(int Dato);
        void insertarAnte(int Dato);
        void insertarEntr(int Dato, int pos);
        void recorrer();
};

void listas::crear(int Dato){
    nodo *n;
    n=new nodo;
    n->setdato(Dato);
    raiz=n;
    ultimo=n;
    n->setpuntero(NULL);
}

void listas::insertarDesp(int Dato){
    nodo *nuevo;
    nuevo=new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(NULL);
    ultimo->setpuntero(nuevo);
    ultimo = nuevo;
}

void listas::insertarAnte(int Dato){
    nodo *nuevo;
    nuevo=new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(raiz);
    raiz=nuevo;
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

int main(){
    listas L;
    L.crear(5);
    L.insertarDesp(10);
    L.insertarDesp(9);
    L.insertarDesp(100);
    L.insertarAnte(6);
    L.insertarAnte(800);
    L.insertarEntr(500,2);
    L.insertarEntr(1, 3);
    L.recorrer();
    return 0;
}