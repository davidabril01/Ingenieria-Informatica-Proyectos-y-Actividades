#include <iostream>
#include <fstream>
#include "nodos.cpp"
#include "lista.cpp"
#include <string>
using namespace std;

class CargaLista : public listas
{
public:
    CargaLista() {}
    listas ListaCargada()
    {
        string Dato1;
        bool a = 0;
        ofstream Error("errores.txt");
        ofstream Rep("repetidos.txt");
        ifstream ArchLista("datostp1.txt");
        listas L;
        int Dato;
        ArchLista >> Dato1;
        Dato = stoi(Dato1);
        while (!ArchLista.eof())
        {
            if (Dato == (-1))
            {
                Error << Dato;
            }
            else
            {
                nodo *recor = L.getraiz();

                while (recor != nullptr && Dato != recor->getdato())
                {
                    recor = recor->getpuntero();
                    if (recor == nullptr)
                    {
                        L.insertarDesp(Dato);
                        recor = L.getraiz();
                        a=0;
                        break;
                    }else{a=1;}
                }
                if (a == 1)
                {
                    Rep<<Dato<<" ";
                    a=0;
                }
                if (recor == nullptr)
                {
                    L.insertarDesp(Dato);
                }
            }
            ArchLista >> Dato1;
            Dato = stoi(Dato1);
        }
        return L;
    }
};

int main()
{
    CargaLista L1;
    listas L = L1.ListaCargada();
    L.recorrer();
}