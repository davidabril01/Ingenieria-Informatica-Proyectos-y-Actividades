#include "viento.h"
#include <iostream>
#include <QDebug>
using namespace std;

Viento::Viento(const QString& marca, double precio, const QString& metal_usado)
    : Instrumento(marca, precio), metal_usado(metal_usado) {}

void Viento::afinar() {
    qDebug() << "Afinando instrumento de viento";
}

QString Viento::getMetalUsado() const {
    return metal_usado;
}
