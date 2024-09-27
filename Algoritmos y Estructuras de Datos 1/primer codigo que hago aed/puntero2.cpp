#include <iostream>
using namespace std;

struct piezas {
    int nro, Lote;
    float Medida;
};

int main()
{
    piezas unaPieza, *p;
    p=&unaPieza;
    cout<<"Ingrese el Nro de Pieza: ";
    cin>>p->nro;
    cout<<endl<<"Ingrese el Lote: ";
    cin>>p->Lote;
    cout<<endl<<"Ingrese el Medida: ";
    cin>>p->Medida;
    cout<<"La pieza Nro "<<p->nro;
    cout<<" del Lote "<<p->Lote;
    cout<<" Mide "<<p->Medida;
    return 0;
}