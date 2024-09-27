#include "Producto.h"

// Constructor
Producto::Producto(string Nom, int Prec, int C)
    : Nombre(Nom), Precio(Prec), Cant(C)
{
}
Producto::Producto(){}
// Destructor
Producto::~Producto()
{
    // Destructor
}

// Setters
void Producto::setNombre(string Nom)
{
    Nombre = Nom;
}

void Producto::setPrecio(int Prec)
{
    Precio = Prec;
}

void Producto::setCant(int C)
{
    Cant = C;
}

// Getters
string Producto::getNombre() const
{
    return Nombre;
}

int Producto::getPrecio() const
{
    return Precio;
}

int Producto::getCant() const
{
    return Cant;
}
