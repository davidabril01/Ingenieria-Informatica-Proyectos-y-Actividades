#include <iostream>
#include <vector>
#include "graphAnaliser.cpp"
using namespace std;

int main()
{
    graphAnaliser grafo({
                        {0, 1, 1, 0, 0},
                        {1, 0, 1, 0, 1},
                        {1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 1},
                        {0, 1, 0, 1, 0}
    });
    grafo.findCycles();
    grafo.removeDuplicateCycles();
    grafo.findCycleLength(3);
    grafo.printCycles();
    cout << "Número de caminos simples entre el vértice " << 1 << " y el vértice " << 4 << ": " << grafo.countingSimplePaths(1, 4) << endl;
    return 0;
}