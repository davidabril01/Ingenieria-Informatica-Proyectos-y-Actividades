#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <string>
using namespace std;


class Alumno
{
public:
  Alumno();

private:
  string nombre, apellido;
  int legajo;
};

#endif // ALUMNO_H
