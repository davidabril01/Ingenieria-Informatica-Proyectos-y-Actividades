#include "teclado.h"
#include <iostream>
#include <QDebug>
using namespace std;

Teclado::Teclado(const QString& marca, double precio, int cantidad_de_teclas)
    : Instrumento(marca, precio), cantidad_de_teclas(cantidad_de_teclas) {}

void Teclado::afinar() {
    qDebug() << "Afinando teclado";
}

int Teclado::getCantidadDeTeclas() const {
    return cantidad_de_teclas;
}
