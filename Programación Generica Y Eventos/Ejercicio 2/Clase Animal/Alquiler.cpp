#include "Alquiler.h"

Alquiler::Alquiler(Pelicula p, int dias)
    : pelicula(p), diasAlquiler(dias) {}

double Alquiler::calcularCosto() const {
    double costoBase = 5; 
    double costoTotal = costoBase * diasAlquiler;

    if (pelicula.getGenero() == "Estreno") {
        costoTotal += 2 * diasAlquiler; 
    }

    return costoTotal;
}

// Getters
int Alquiler::getDiasAlquiler() const {
    return diasAlquiler;
}

Pelicula Alquiler::getPelicula() const {
    return pelicula;
}
