#include <iostream>
#include "Animal.h"
#include "Perro.h"
#include "Gato.h"
#include "Peliculas.h"
#include "Alquiler.h"

using namespace std;

void gestionarAnimales()
{    Perro perro;
    Gato gato;

    int opcion;

    do
    {
        cout << "===========================" << endl;
        cout << "  Gestion de Animales" << endl;
        cout << "===========================" << endl;
        cout << "1. Hacer que el perro coma, duerma y ladre" << endl;
        cout << "2. Hacer que el gato coma, duerma y maulle" << endl;
        cout << "3. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Eligio la opcion hacer que el perro coma, duerma y ladre" << endl;
            perro.Comer();
            perro.Dormir();
            perro.Ladrar();
            break;
        case 2:
            cout << "Eligio la opcion hacer que el gato coma, duerma y maulle" << endl;
            gato.Comer();
            gato.Dormir();
            gato.Maullar();
            break;
        case 3:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
}

void gestionarPeliculas()
{
    string titulo, director, genero;
    int duracion, diasAlquiler;

    cout << "===========================" << endl;
    cout << "  Gestión de Peliculas" << endl;
    cout << "===========================" << endl;

    cout << "Ingrese el titulo de la pelicula: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Ingrese el director de la pelicula: ";
    getline(cin, director);
    cout << "Ingrese el género de la pelicula: ";
    getline(cin, genero);
    cout << "Ingrese la duración de la pelicula (en minutos): ";
    cin >> duracion;

    Pelicula miPelicula(titulo, director, genero, duracion);

    cout << "Ingrese la cantidad de dias de alquiler: ";
    cin >> diasAlquiler;

    Alquiler miAlquiler(miPelicula, diasAlquiler);

    cout << "===========================" << endl;
    cout << "   Resumen del Alquiler" << endl;
    cout << "===========================" << endl;
    cout << "Pelicula: " << miAlquiler.getPelicula().getTitulo() << endl;
    cout << "Director: " << miAlquiler.getPelicula().getDirector() << endl;
    cout << "Genero: " << miAlquiler.getPelicula().getGenero() << endl;
    cout << "Duracion: " << miAlquiler.getPelicula().getDuracion() << " minutos" << endl;
    cout << "Costo del alquiler por " << miAlquiler.getDiasAlquiler() << " dias: $"
         << miAlquiler.calcularCosto() << endl;
}

int main()
{
    int opcion;

    do
    {
        cout << "===========================" << endl;
        cout << "       Menu Principal" << endl;
        cout << "===========================" << endl;
        cout << "1. Gestion de Animales" << endl;
        cout << "2. Gestion de Películas y Alquileres" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            gestionarAnimales();
            break;
        case 2:
            gestionarPeliculas();
            break;
        case 3:
            cout << "Saliendo del programa. ¡Gracias por usarlo!" << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}
