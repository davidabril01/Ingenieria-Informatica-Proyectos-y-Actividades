#include <iostream>
#include <fstream>
#include <string>
#include "nodos.cpp"
#include "cola.cpp"
#include "pila.cpp"
#include "lista.cpp"
using namespace std;

class CargaLista : public listas
{
public:
    CargaLista() {}
    listas ListaCargada()
    {
        string Dato1;
        ifstream ArchLista("Arreglo.txt");
        listas L;
        int Dato;
        ArchLista >> Dato1;
        Dato = stoi(Dato1);
        while (!ArchLista.eof())
        {
            nodo *recor = L.getraiz();
            int cont = 0;

            while (recor != nullptr)
            {
                if (Dato >= recor->getdato())
                {
                    cont++;
                    recor = recor->getpuntero();
                }
                else
                {
                    L.insertarEntr(Dato, cont);
                    break;
                }
            }

            if (recor == nullptr)
            {
                L.insertarDesp(Dato);
            }

            ArchLista >> Dato1;
            Dato = stoi(Dato1);
        }
        return L;
    }
};

class CargaPilaPar : public pila
{
public:
    CargaPilaPar()
    {
    }
    pila cargarPares(listas L)
    {
        nodo *recor = L.getraiz();
        pila Paux;
        while (recor != nullptr)
        {
            if (recor->getdato() % 2 == 0)
            {
                Paux.poner(recor->getdato());
            }
            recor = recor->getpuntero();
        }
        return Paux;
    }
};

class ColaMen10 : public Cola{
    public:
    ColaMen10(){}
    Cola cargarCola(listas L){
        nodo *recor = L.getraiz();
        Cola Caux;
        while (recor != nullptr)
        {
            if (recor->getdato()<10){
                Caux.insertar(recor->getdato());
            }
            recor = recor->getpuntero();
        }
        return Caux;
    }
};

int main()
{

    CargaLista K;
    listas L = K.ListaCargada();
    L.recorrer();
    CargaPilaPar S;
    pila P = S.cargarPares(L);
    cout << endl << P.sacar() << " " << P.sacar() << endl;
    ColaMen10 M;
    Cola C = M.cargarCola(L);
    cout << C.sacar()<< " "  << C.sacar()<< " "  << C.sacar()<< " "  << C.sacar() << endl;
}
