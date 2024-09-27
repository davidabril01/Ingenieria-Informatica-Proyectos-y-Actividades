#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "moda.h"
#include "../Ejercicio01/random.h"
using namespace std;

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  vector<int> numeros;
  srand(static_cast<unsigned int>(time(nullptr)));
  for(int i=0; i<30; i++){
      Random random(1, 15);
      numeros.push_back(random.GenerateRandom());
    }
  Moda moda;
  int mode = moda.findMode(numeros);
  cout << "La moda es: " << mode;
  return a.exec();
}
