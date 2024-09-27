#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class prueba
{
private:
    string material;
    int id_componente;
    int medicion;

public:
    prueba()
    {
        material = "a";
        id_componente = 0;
        medicion = 0;
    }
    void setMaterial(string m) { material = m; }
    string getmaterial() { return material; }
    void setid(int id) { id_componente = id; }
    int getid() { return id_componente; }
    void setmedicion(int med) { medicion = med; }
    int getmedicion() { return medicion; }
};
class nodo
{
private:
    prueba dato;
    nodo *puntero;

public:
    nodo() { puntero = NULL; }
    void setdato(prueba d) { dato = d; }
    prueba getdato() { return dato; }
    void setpuntero(nodo *p) { puntero = p; }
    nodo *getpuntero() { return puntero; }
};

class Cola
{
private:
    nodo *raiz;

public:
    Cola()
    {
        raiz = NULL;
    }
    void insertar(prueba *Dato);
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
        prueba nuevo;
        return nuevo;
    }
    else
    {
        aux = raiz->getdato();
        nodo *temp = raiz;
        raiz = raiz->getpuntero();
        delete temp;
    }
    return aux;
}

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
        ArchLista >> Basura >> Basura >> Basura;
        ArchLista >> Dato1;

        while (!ArchLista.eof())
        {
            prueba *nuevo1 = new prueba;
            nuevo1->setMaterial(Dato1);
            ArchLista >> Dato1;
            Dato = stoi(Dato1);
            nuevo1->setid(Dato);
            ArchLista >> Dato1;
            Dato = stoi(Dato1);
            nuevo1->setmedicion(Dato);
            C.insertar(nuevo1);
            ArchLista >> Dato1;
        }
        return C;
    }
};
const int compCant[3][2] = {{150, 20}, {250, 50}, {300, 65}};
class EvaluarRes
{
private:
    

public:
    EvaluarRes() {}
    void Evaluacion()
    {
        
        ofstream Arch("Evaluaciones.txt");
        
        float correccion;
        while (A.getid() != 0)
        {

            Arch << A.getmaterial() << " " << A.getid() << " " << A.getmedicion();
            for (int i = 0; i < 3; i++)
            {
                if (A.getid() == compCant[i][0])
                {
                    float comp=compCant[i][1];
                    if (((comp / 100) * 95) > A.getmedicion())
                    {
                        Arch << " Medicion Incorrecta ";
                        correccion=comp - A.getmedicion();
                        Arch << "+" <<correccion;
                    }
                    else if(A.getmedicion() > ((comp / 100) * 105)){
                        Arch << " Medicion Incorrecta";
                        correccion=comp - A.getmedicion();
                        Arch << correccion;
                    }else
                    {
                        Arch << " Medicion Correcta";
                    }
                }
            }
            A = C.sacar();
            Arch<<endl;
        }
    }
};

class TotalM
{
private:
    CargaCola T1;
    Cola T;
    prueba A;

public:
    TotalM() {}
    void Suma()
    {
        ofstream Arch1("Total.txt");
        T = T1.ColaCargada();
        A = T.sacar();
        string l="ñ",p="ñ";
        int aux=0;
        Cola Extra = T;
        while (A.getid() != 0 && l!=A.getmaterial()){
            A = T.sacar();
        }
        l=A.getmaterial();
        Arch1<<"TOTAL "<<l<<": ";
        while (A.getid() != 0)
        {
            if(A.getmaterial()==l){
                aux=aux+A.getmedicion();
            }
            A = T.sacar();
        }
        Arch1<<aux;
    }
};

int main()
{
    CargaCola C1;
    Cola C;
    prueba A;
    C = C1.ColaCargada();
    A = C.sacar();
    EvaluarRes X;
    X.Evaluacion();
    TotalM M;
    M.Suma();
}
