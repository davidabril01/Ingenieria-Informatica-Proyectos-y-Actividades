#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <list>
using namespace std;
#include "Producto.h"

class Inventario
{
private:
    list<Producto> Productos;

public:
    Inventario();
    void Crear(void (*callback)(Producto));
    void Leer();
    void Actualizar();
    void Borrar();
    ~Inventario();
};

#endif // INVENTARIO_H
