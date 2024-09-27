#include "guitarra.h"
#include <iostream>
#include <QDebug>
using namespace std;

Guitarra::Guitarra(const QString& marca, double precio, int cantidad_de_cuerdas)
    : Instrumento(marca, precio), cantidad_de_cuerdas(cantidad_de_cuerdas) {}

void Guitarra::afinar(){
    qDebug() << "Afinando guitarra" << endl;
}

int Guitarra::getCantidadDeCuerdas() const {
    return cantidad_de_cuerdas;
}
