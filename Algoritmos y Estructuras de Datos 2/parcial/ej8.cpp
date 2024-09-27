#include <iostream>
#include <vector>
#include "graphAnaliser.cpp"

using namespace std;

int main() {



    graphAnaliser grafo({
        {0, 1, 0, 4, 0, 2, 0, 3},
        {1, 0, 1, 0, 4, 0, 0, 0},
        {0, 1, 0, 3, 0, 0, 0, 2},
        {4, 0, 3, 0, 1, 0, 1, 1},
        {0, 4, 0, 1, 0, 4, 0, 0},
        {2, 0, 0, 0, 4, 0, 1, 0},
        {0, 0, 0, 1, 0, 1, 0, 1},
        {3, 0, 2, 1, 0, 0, 1, 0},
        });
        grafo.matrixToList();
        grafo.primMST();
}