#include "../Ejercicio06/computadora.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compararPorRam(const Computadora& comp1, const Computadora& comp2) {
    return comp1.GbRam < comp2.GbRam;
}

int main(){

  vector<Computadora> computadoras;
  Computadora comp1("Intel i7", "Dell", 16);
  Computadora comp2("AMD Ryzen 5", "HP", 8);
  Computadora comp3("Intel Core i5", "Lenovo", 12);
  Computadora comp4("AMD Ryzen 7", "Asus", 32);
  Computadora comp5("Intel Core i9", "Acer", 64);
  computadoras.push_back(comp1);
  computadoras.push_back(comp2);
  computadoras.push_back(comp3);
  computadoras.push_back(comp4);
  computadoras.push_back(comp5);
  sort(computadoras.begin(), computadoras.end(), compararPorRam);

  for(int i = 0; i < 5; i++){
      cout << "Computadora " << i+1 << ":" << endl;
      cout << "Procesador: " << computadoras[i].Procesador << endl;
      cout << "Marca: " << computadoras[i].Marca << endl;
      cout << "RAM: " << computadoras[i].GbRam << "GB" << endl << endl;
    }

  return 0;
}
