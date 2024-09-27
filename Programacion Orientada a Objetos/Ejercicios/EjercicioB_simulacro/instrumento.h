#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>

class Instrumento {
public:
    Instrumento(const QString& marca, double precio);
    virtual ~Instrumento() {}
    virtual void afinar() = 0;

    QString getMarca() const;
    double getPrecio() const;

private:
    QString marca;
    double precio;
};

#endif // INSTRUMENTO_H
