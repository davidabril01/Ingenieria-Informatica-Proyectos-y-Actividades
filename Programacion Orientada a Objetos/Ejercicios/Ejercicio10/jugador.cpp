#include <iostream>
#include "jugador.h"
using namespace std;

Jugador::Jugador() : velocidad(0), fuerza(0), nombre("") {}

void Jugador::setVelocidad(int vel)
{
  velocidad = vel;
}

int Jugador::getVelocidad()const
{
  return velocidad;
}

void Jugador::setFuerza(int fza)
{
  fuerza = fza;
}

int Jugador::getFuerza()const
{
  return fuerza;
}

void Jugador::setNombre(string nom)
{
  nombre = nom;
}

string Jugador::getNombre()const
{
  return nombre;
}

ostream& operator<<(ostream &os, const Jugador &jugador) {
  os << "Nombre: " << jugador.getNombre()
     << ", Velocidad: " << jugador.getVelocidad()
     << ", Fuerza: " << jugador.getFuerza() << endl;
  return os;
}

Jugador::~Jugador() {}
