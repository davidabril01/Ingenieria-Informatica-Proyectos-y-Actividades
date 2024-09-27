#include <iostream>
#include <vector>
#include "jugador.h"
using namespace std;

int main(){
  vector<Jugador> jugadores(10);

      for(int i = 0; i < 10; ++i){
          jugadores[i].setNombre("Jugador " + to_string(i + 1));
          jugadores[i].setVelocidad((i + 1) * 10);
          jugadores[i].setFuerza((i + 1) * 5);
      }

      for(const auto& jugador : jugadores){
          cout << jugador;
      }
}
