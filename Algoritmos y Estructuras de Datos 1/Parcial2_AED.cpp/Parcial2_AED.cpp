#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Cola
{
private:
    nodo *raiz;

public:
    Cola()
    {
        raiz = NULL;
    }
    void insertar(prueba Dato);
    prueba sacar();
};

void Cola::insertar(prueba *Dato)
{
    nodo *nuevo = new nodo;
    nuevo->setdato(*Dato);
    nuevo->setpuntero(NULL);

    if (raiz == NULL)
    {
        raiz = nuevo;
    }
    else
    {
        nodo *recor = raiz;
        while (recor->getpuntero() != NULL)
        {
            recor = recor->getpuntero();
        }
        recor->setpuntero(nuevo);
    }
}


prueba Cola::sacar()
{
    prueba aux;
    if (raiz == NULL)
    {
        cout << "La cola esta vacia";
        return;
    }
    else
    {
        aux = raiz->getdato();
        nodo* temp = raiz;
        raiz = raiz->getpuntero();
        delete temp;
    }
    return aux;
}

class nodo
{
    private:
        prueba dato;
        nodo *puntero;
    public:
        nodo() { puntero = NULL; }
        void setdato(prueba d){dato=d;}
        prueba getdato(){return dato;}
        void setpuntero(nodo *p){puntero=p;}
        nodo *getpuntero(){return puntero;}
};

class prueba
{
    private:
    string material;
    int id_componente;
    int medicion;
    public:
        prueba() {}
        void setMaterial(string m){material=m;}
        string getdato(){return material;}
        void setid(int id){id_componente=id;}
        int getid(){return id_componente;}
        void setmedicion(int med){medicion=med;}
        int getmedicion(){return medicion;}
};
class CargaCola : public Cola
{
public:
    CargaCola() {}
    Cola ColaCargada()
    {
        string Dato1, Basura;
        ifstream ArchLista("datostp1.txt");
        Cola C;
        int Dato;
        ArchLista >> Basura>> Basura>> Basura;
        ArchLista >> Dato1;
        
        while (!ArchLista.eof())
        {
        prueba *nuevo1 = new prueba;
        nuevo1->setMaterial(Dato1);
        ArchLista >> Dato1;
        Dato= stoi(Dato1);
        nuevo1->setid(Dato);
        ArchLista >> Dato1;
        Dato= stoi(Dato1);
        nuevo1->setmedicion(Dato);
        C.insertar(nuevo1);
        }
        return C;
    }
};
int compCant[3][2] = {{150, 20}, {250, 50}, {300, 65}};
int main(){
    CargaCola C1;
    Cola C = C1.ColaCargada();
    cout<<C.sacar().material;
}

