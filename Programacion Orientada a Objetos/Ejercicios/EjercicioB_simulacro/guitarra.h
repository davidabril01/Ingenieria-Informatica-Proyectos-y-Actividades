#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento {
public:
    Guitarra(const QString& marca, double precio, int cantidad_de_cuerdas);
    void afinar();

    int getCantidadDeCuerdas() const;

private:
    int cantidad_de_cuerdas;
};

#endif // GUITARRA_H
