
#include "Peliculas.h"
#include <iostream>
using namespace std;

class Alquiler {
private:
    Pelicula pelicula;
    int diasAlquiler; 

public:
    Alquiler(Pelicula p, int dias);
    
    double calcularCosto() const;

    int getDiasAlquiler() const;
    Pelicula getPelicula() const;
};

