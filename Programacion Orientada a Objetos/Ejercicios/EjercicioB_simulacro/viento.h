#ifndef VIENTO_H
#define VIENTO_H

#include "instrumento.h"

class Viento : public Instrumento {
public:
    Viento(const QString& marca, double precio, const QString& metal_usado);
    void afinar();

    QString getMetalUsado() const;

private:
    QString metal_usado;
};

#endif // VIENTO_H
