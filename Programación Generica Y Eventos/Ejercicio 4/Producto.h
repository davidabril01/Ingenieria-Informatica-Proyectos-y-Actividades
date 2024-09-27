#pragma once
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
using namespace std;

class Producto
{
private:
    string Nombre;
    int Precio, Cant;

public:
    Producto();
    Producto(string Nom, int Prec, int C);
    ~Producto();

    // Setters
    void setNombre(string Nom);
    void setPrecio(int Prec);
    void setCant(int Cant);

    // Getters
    string getNombre() const;
    int getPrecio() const;
    int getCant() const;
};

#endif // PRODUCTO_H