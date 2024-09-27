#include "computadora.h"
#include <iostream>
using namespace std;

int main(){
  Computadora computadoras[5] = {
    Computadora("Intel i7", "Dell", 16),
    Computadora("AMD Ryzen 5", "HP", 8),
    Computadora("Intel Core i5", "Lenovo", 12),
    Computadora("AMD Ryzen 7", "Asus", 32),
    Computadora("Intel Core i9", "Acer", 64)
  };

  for(int i = 0; i < 5; i++){
    cout << computadoras[i] << endl;
    }

  return 0;
}
