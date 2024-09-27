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
        void insertarAnte(int Dato);
        void recorrer();
        listas invertir();
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

void listas::recorrer(){
    nodo *recor=raiz;
    while (recor != NULL){
        cout << recor->getdato() << "-";
        recor = recor->getpuntero();
    }
}

listas listas::invertir(){
    listas lista_invertida;
    nodo *actual = raiz;
    while(actual != NULL){
        int dato_actual = actual->getdato();
        lista_invertida.insertarAnte(dato_actual);
        actual = actual->getpuntero();
    }
    return lista_invertida;
}

 int main(){
    listas L;
    L.crear(2);
    L.insertarDesp(3);
    L.insertarAnte(1);
    L.insertarDesp(4);
    cout<<"Lista 1: ";
    L.recorrer();
    listas LInv = L.invertir();
    cout<<"Lista 2: ";
    LInv.recorrer();
 }