#include <iostream>
using namespace std;

struct piezas {
    int nroLoteMedida[3], *p;
};

int main(){
    piezas unaPieza;
    unaPieza.p=&unaPieza.nroLoteMedida[0];
    cout<<"Ingrese el Nro de Pieza: ";
    cin>>*unaPieza.p;
    unaPieza.p++;
    cout<<endl<<"Ingrese el Lote: ";
    cin>>*unaPieza.p;
    unaPieza.p++;
    cout<<endl<<"Ingrese el Medida: ";
    cin>>*unaPieza.p;
    unaPieza.p-=2;
    cout<<"La pieza Nro "<<*unaPieza.p;
    unaPieza.p++;
    cout<<" del Lote "<<*unaPieza.p;
    unaPieza.p++;
    cout<<" Mide "<<*unaPieza.p;
}