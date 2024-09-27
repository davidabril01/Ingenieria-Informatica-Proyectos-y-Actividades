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
    float prom(pila P)
    {
        int aux = 0, cont = 0;
        float auxProm = 0;
        pila Paux;
        aux = P.sacar();
        while (aux != 0)
        {
            auxProm = auxProm + aux;
            cont++;
            Paux.poner(aux);
            aux = P.sacar();
        }
        P = Paux;
        return auxProm/cont;
    }
};
class CargarLista10 : public listas{
    private:
    promPila prom;
    public:
    listas ListaRango10(pila P){
        int aux = 0;
        float Prom = prom.prom(P);
        pila Paux;
        listas Laux;
        aux = P.sacar();
        while(aux!=0){
            if(aux<(Prom+(Prom/100)*10) && aux>(Prom-(Prom/100)*10)){
                Laux.insertarDesp(aux);
                Paux.poner(aux);
            }else{
                Paux.poner(aux);
            }
            aux = P.sacar();
        }
        P=Paux;
        return Laux;
    }
};

int main()
{
    pila P;
    P.poner(23);
    P.poner(22);
    P.poner(45);
    P.poner(40);
    P.poner(76);
    P.poner(44);
    P.poner(39);
    P.poner(41);
    P.poner(17);
    promPila Prom;
    cout<<Prom.prom(P)<<endl;
    CargarLista10 Listt;
    listas L = Listt.ListaRango10(P);
    cout<<P.sacar()<<" "<<P.sacar()<<" "<<P.sacar()<<" "<<P.sacar()<<" "<<P.sacar()<<" "<<P.sacar()<<" "<<P.sacar()<<" "<<P.sacar()<<" "<<P.sacar()<<" "<<endl;
    L.recorrer();
}