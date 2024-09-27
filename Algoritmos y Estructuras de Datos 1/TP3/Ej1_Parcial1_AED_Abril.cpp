#include <iostream>
#include "nodos.cpp"
#include "cola.cpp"
#include "pila.cpp"
#include "lista.cpp"
using namespace std;
class promPila
{
private:
public:
    int prom(pila P)
    {
        int aux = 0, auxProm = 0, cont = 0;
        pila Paux;
        aux = P.sacar();
        while (aux != 0)
        {
            auxProm = auxProm + aux;
            cont++;
            Paux.poner(aux);
            aux = P.sacar();
        }
        return aux/cont;
        P = Paux;
    }
};

int main()
{
    pila P;
    P.poner(23);
    P.poner(22);
    P.poner(45);
    P.poner(40);
    P.poner(44);
    P.poner(39);
    P.poner(41);
    P.poner(17);
    promPila Prom;
    cout<<Prom.prom(P);
}