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
    double AddAll();
    float media();
    int mayor();
    int menor();
    void recorrer();
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
    int aux;
    bool a = 1;
    cout << "Ingrese el valor 1" << endl;
    cin >> aux;
    L.crear(aux);
    while (a)
    {
        cout << "1: Ingresar nuevo valor || 2: Suma || 3: Promedio || 4: Mayor || 5: Menor || 0: Salir"<<endl;
        cin >> aux;
        switch (aux)
        {
        case 1:
            cout << "_Dato sig: " << endl;
            cin >> aux;
            L.insertarDesp(aux);
            break;
        case 2:
            cout<<"SUMA: "<<L.AddAll()<<endl;
            break;
        case 3:
            cout<<"PROM: "<<L.media()<<endl;
            break;
        case 4:
            cout<<"MAY: "<<L.mayor()<<endl;
            break;
        case 5:
            cout<<"MEN: "<<L.menor()<<endl;
            break;
        case 0:
            a = 0;
            break;
        }
    }
}