#include <iostream>
#include "nodos.cpp"
using namespace std;

class pila
{
private:
    nodo *raiz;

public:
    pila() : raiz(nullptr) {}
    void poner(int Dato);
    void sacar();
    void recorrer();
    pila obtener_invertida();
};

void pila::poner(int Dato)
{
    nodo *nuevo;
    nuevo=new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(raiz);
    raiz=nuevo;
}

void pila::sacar()
{
    raiz=raiz->getpuntero();
}


void pila::recorrer()
{
    nodo *recor=raiz;
    cout << "Contenido de la pila: ";
    while (recor != NULL){
        cout << recor->getdato() << "-";
        recor = recor->getpuntero();
    }
    cout << endl;
}

pila pila::obtener_invertida()
{
    pila pila_invertida;
    nodo *recor = raiz;
    while (recor != nullptr) {
        pila_invertida.poner(recor->getdato());
        recor = recor->getpuntero();
    }
    return pila_invertida;
}

int main(){
    pila P;
    P.poner(9);
    P.poner(10);
    P.poner(12);
    P.poner(3);
    P.recorrer();
    pila P_invertida = P.obtener_invertida();
    P_invertida.recorrer();
}
