#include "instrumento.h"

Instrumento::Instrumento(const QString& marca, double precio)
    : marca(marca), precio(precio) {}

QString Instrumento::getMarca() const {
    return marca;
}

double Instrumento::getPrecio() const {
    return precio;
}
