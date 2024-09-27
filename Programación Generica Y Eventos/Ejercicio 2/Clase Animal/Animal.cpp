#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal() {
}

Animal::~Animal() {
}

void Animal::Comer() {
    cout << "El animal está comiendo." << endl;
}

void Animal::Dormir() {
    cout << "El animal está durmiendo." << endl;
}
