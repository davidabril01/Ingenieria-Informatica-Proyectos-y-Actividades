#include "linea.h"


Linea::Linea() : x_inicial(0), y_inicial(0), x_final(0), y_final(0) {}

int Linea::get_x_inicial() const {
    return x_inicial;
}

int Linea::get_y_inicial() const {
    return y_inicial;
}

int Linea::get_x_final() const {
    return x_final;
}

int Linea::get_y_final() const {
    return y_final;
}

void Linea::set_x_inicial(const int& nuevo_x_inicial) {
    x_inicial = nuevo_x_inicial;
}

void Linea::set_y_inicial(const int& nuevo_y_inicial) {
    y_inicial = nuevo_y_inicial;
}

void Linea::set_x_final(const int& nuevo_x_final) {
    x_final = nuevo_x_final;
}

void Linea::set_y_final(const int& nuevo_y_final) {
    y_final = nuevo_y_final;
}
