#pragma once
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <list>
#include <cstdlib>
#include <thread>
#include <chrono> 
using namespace std;
#include "Producto.h"

class Inventario
{
private:
    list<Producto> Productos;
    void CallbackNuevoProducto(Producto NuevoProd);
public:
    Inventario();
    void RunEventLoop();
    void Crear();
    void Leer();
    void Actualizar();
    void Borrar();
    ~Inventario();
};

#endif // INVENTARIO_H
