#include <iostream>
using namespace std;

#ifndef JUGADOR_H
#define JUGADOR_H
class Jugador
{
public:
  Jugador();
  void setVelocidad(int vel);
  int getVelocidad()const;
  void setFuerza(int fza);
  int getFuerza()const;
  void setNombre(string nom);
  string getNombre() const;

  friend ostream& operator<<(ostream &os, const Jugador &Jugador);
  ~Jugador();

private:
  int velocidad, fuerza;
  string nombre;
};

#endif // JUGADOR_H
