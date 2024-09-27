#ifndef GATO_H
#define GATO_H

#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

class Gato : public Animal {
public:
    Gato();
    ~Gato();
    void Maullar();
};

#endif // GATO_H
