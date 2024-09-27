#ifndef PERRO_H
#define PERRO_H

#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

class Perro : public Animal {
public:
    Perro();
    ~Perro();
    void Ladrar();
};

#endif // PERRO_H
