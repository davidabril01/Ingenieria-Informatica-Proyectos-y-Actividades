#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"

class Teclado : public Instrumento {
public:
    Teclado(const QString& marca, double precio, int cantidad_de_teclas);
    void afinar();

    int getCantidadDeTeclas() const;

private:
    int cantidad_de_teclas;
};

#endif // TECLADO_H
