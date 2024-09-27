#include "Peliculas.h"

// Constructor parametrizado
Pelicula::Pelicula(string tit, string dir, string gen, int dur)
    : titulo(tit), director(dir), genero(gen), duracion(dur) {}

// Getters
string Pelicula::getTitulo() const {
    return titulo;
}

string Pelicula::getDirector() const {
    return director;
}

string Pelicula::getGenero() const {
    return genero;
}

int Pelicula::getDuracion() const {
    return duracion;
}

// Setters
void Pelicula::setTitulo(const string& tit) {
    titulo = tit;
}

void Pelicula::setDirector(const string& dir) {
    director = dir;
}

void Pelicula::setGenero(const string& gen) {
    genero = gen;
}

void Pelicula::setDuracion(int dur) {
    duracion = dur;
}
