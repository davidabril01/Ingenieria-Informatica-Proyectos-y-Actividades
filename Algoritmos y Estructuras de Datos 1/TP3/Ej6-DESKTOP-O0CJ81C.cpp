#include <iostream>
#include "nodos.cpp"
#include "cola.cpp"
#include "pila.cpp"
#include "lista.cpp"
using namespace std;
class colaOrd : public Cola
{
private:
public:
    colaOrd()
    {
    }
    Cola OrdCola(pila P)
    {
        listas L;
        int anterior;
        anterior = P.sacar();
        while (anterior != 0)
        {
            nodo *recor = L.getraiz();
            int cont = 0;

            while (recor != nullptr)
            {
                if (anterior >= recor->getdato())
                {
                    cont++;
                    recor = recor->getpuntero();
                }
                else
                {
                    L.insertarEntr(anterior, cont);
                    break;
                }
            }

            if (recor == nullptr)
            {
                L.insertarDesp(anterior);
            }

            anterior = P.sacar();
        }
        Cola C;
        nodo *recor = L.getraiz();
        while (recor != NULL)
        {
            C.insertar(recor->getdato());
            recor = recor->getpuntero();
        }
        return C;
    }
};
int main()
{
    
    pila P;

    P.poner(6);
    P.poner(3);
    P.poner(5);
    P.poner(8);
    P.poner(2);
    P.poner(1);
    cout << P.sacar() << P.sacar() << P.sacar() << P.sacar() << P.sacar() << P.sacar() << endl;
    P.poner(6);
    P.poner(3);
    P.poner(5);
    P.poner(8);
    P.poner(2);
    P.poner(1);
    colaOrd CO;
    Cola C = CO.OrdCola(P);
    cout << C.sacar() << C.sacar() << C.sacar() << C.sacar() << C.sacar() << C.sacar() << endl;
}
 