#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo
{
public:
    Rectangulo(int x = 0, int y = 0, int ancho = 100, int alto = 100);

    // Getters
    int getX() const;
    int getY() const;
    int getAncho() const;
    int getAlto() const;

    // Setters
    void setX(int nuevoX);
    void setY(int nuevoY);
    void setAncho(int nuevoAncho);
    void setAlto(int nuevoAlto);

private:
    int x, y, ancho, alto;
};

#endif // RECTANGULO_H
