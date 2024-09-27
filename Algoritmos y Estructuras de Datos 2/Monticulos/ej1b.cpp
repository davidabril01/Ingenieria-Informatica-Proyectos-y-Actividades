#include <iostream>
#include "monticulo1.h"
using namespace std;
int main(){
    Monticulo Mont1(5);
    Mont1.Insertar("Arentina", 46044703, 487);
    Mont1.Insertar("Japon", 125000000, 4940);
    Mont1.Insertar("Holanda", 17530000, 1013);
    Mont1.Insertar("USA", 331900000, 23000);
    Mont1.Insertar("Croacia", 11750000, 1600);
    Mont1.Borrar();
    Mont1.ExtraerMaximo();
    Mont1.ExtraerMaximo();
    Mont1.ExtraerMaximo();
    Mont1.ExtraerMaximo();
    
}