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

class pila
{
private:
    nodo *raiz;

public:
    pila(){}
    void poner(int Dato);
    void sacar();
    pila invertir();
    void recorrer();
};

void pila::poner(int Dato)
{
    nodo *nuevo;
    nuevo=new nodo;
    nuevo->setdato(Dato);
    nuevo->setpuntero(raiz);
    raiz=nuevo;
}
void pila::sacar(){
    raiz=raiz->getpuntero();
}
pila pila::invertir(){
    pila pilaAux;
    nodo *recor=raiz;
    while (recor != NULL){
        pilaAux.poner(recor->getdato());
        recor = recor->getpuntero();
    }
    return pilaAux;
}

void pila::recorrer(){
    nodo *recor=raiz;
    cout << "Contenido de la pila: ";
    while (recor != NULL){
        cout << recor->getdato() << "-";
        recor = recor->getpuntero();
    }
    cout << endl;
}

int main(){
    pila P;
    P.poner(9);
    P.poner(10);
    P.poner(12);
    P.poner(3);
    P.invertir(); // Invierte la pila original
    P.recorrer(); // Imprime la pila invertida
    return 0;
}
