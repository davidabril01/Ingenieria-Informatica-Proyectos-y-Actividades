#ifndef PELICULAS_H
#define PELICULAS_H

#include <string>

using namespace std;

class Pelicula {
private:
    string titulo;    // Título de la película
    string director;  // Director de la película
    string genero;    // Género de la película
    int duracion;     // Duración de la película en minutos

public:
    // Constructor parametrizado
    Pelicula(string tit, string dir, string gen, int dur);

    // Métodos Getters
    string getTitulo() const;
    string getDirector() const;
    string getGenero() const;
    int getDuracion() const;

    // Métodos Setters
    void setTitulo(const string& tit);
    void setDirector(const string& dir);
    void setGenero(const string& gen);
    void setDuracion(int dur);
};

#endif // PELICULAS_H
