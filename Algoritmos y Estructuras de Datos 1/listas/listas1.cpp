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
        double AddAll();
        float media();
        int mayor();
        int menor();
        void eliminar(int pos);
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

void listas::eliminar(int pos){
    nodo *anterior=raiz, *siguiente=raiz;

    for (int i = 1; i < pos-1; i++)
    {
        anterior = anterior->getpuntero();
    }
    for (int i = 1; i < pos+1; i++)
    {
        siguiente = siguiente->getpuntero();
    }
    if(pos>1){anterior->setpuntero(siguiente);}else{raiz=raiz->getpuntero();}
    
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

float listas::media(){
    nodo *recor=raiz;
    float aux=0;
    int cont=0;
    while (recor != NULL){
        aux=aux + recor->getdato();
        cont++;
        recor = recor->getpuntero();
    }
    return aux/cont;
}

int listas::mayor(){
    nodo *recor=raiz;
    int may=recor->getdato();
    recor = recor->getpuntero();
    while (recor != NULL){
        if((recor->getdato())>may){
            may=recor->getdato();
        }
        recor = recor->getpuntero();
    }
    return may;
}

int listas::menor(){
    nodo *recor=raiz;
    int men=recor->getdato();
    recor = recor->getpuntero();
    while (recor != NULL){
        if((recor->getdato())<men){
            men=recor->getdato();
        }
        recor = recor->getpuntero();
    }
    return men;
}

int main(){
    listas L;
    L.crear(5);
    L.insertarDesp(10);
    L.insertarDesp(9);
    L.insertarDesp(100);
    L.insertarAnte(6);
    L.insertarAnte(4);
    L.insertarEntr(500,2);
    L.insertarEntr(1, 3);
    L.eliminar(8);
    L.recorrer();
    cout<<L.AddAll();
    cout<<"-"<<L.media();
    cout<<"-"<<L.mayor();
    cout<<"-"<<L.menor();
    return 0;
}