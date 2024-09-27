#include "computadora.h"
#include <iostream>
#include <QDebug>
#include <QCoreApplication>
using namespace std;

Computadora::Computadora(QString procesador, QString marca, int gbRam): Procesador(procesador), Marca(marca), GbRam(gbRam)
{
}

ostream& operator<<(ostream &os, const Computadora &computadora) {
  os << "Computadora con "
     << computadora.getRam()
     << "Gb de ram y lleva el procesador "
     << computadora.getProcesador().toStdString()
     << " y esta contruida por la marca "
     << computadora.getMarca().toStdString();
  return os;
}
