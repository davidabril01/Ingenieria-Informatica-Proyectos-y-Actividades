#include "rectangulo.h"

Rectangulo::Rectangulo(int x, int y, int ancho, int alto)
    : x(x), y(y), ancho(ancho), alto(alto)
{}

// Getters
int Rectangulo::getX() const {
    return x;
}

int Rectangulo::getY() const {
    return y;
}

int Rectangulo::getAncho() const {
    return ancho;
}

int Rectangulo::getAlto() const {
    return alto;
}

// Setters
void Rectangulo::setX(int nuevoX) {
    x = nuevoX;
}

void Rectangulo::setY(int nuevoY) {
    y = nuevoY;
}

void Rectangulo::setAncho(int nuevoAncho) {
    ancho = nuevoAncho;
}

void Rectangulo::setAlto(int nuevoAlto) {
    alto = nuevoAlto;
}
