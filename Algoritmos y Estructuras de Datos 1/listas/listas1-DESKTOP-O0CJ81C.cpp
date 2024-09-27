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
        void insertar(int Dato);
        void recorrer();
        double AddAll();
};

void listas::crear(int Dato){
    nodo *n;
    n=new nodo;
    n->setdato(Dato);
    raiz=n;
    ultimo=n;
    n->setpuntero(NULL);
}

void listas::insertar(int Dato){
    nodo *nuevo;
    nuevo=new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(NULL);
    ultimo->setpuntero(nuevo);
    ultimo = nuevo;
}

void listas::recorrer(){
    nodo *recor=raiz;
    while (recor != NULL){
        cout << recor->getdato() << "-";
        recor = recor->getpuntero();
    }
}

double listas::AddAll(){
    nodo *recor=raiz;
    double aux=0;
    while (recor != NULL){
        aux=aux + recor->getdato();
        recor = recor->getpuntero();
    }
    return aux;
}

int main(){
    listas L;
    L.crear(5);
    L.insertar(10);
    L.insertar(9);
    L.insertar(100);
    L.recorrer();
    return 0;
}
