#include <iostream>
#include <vector>
#include "graphAnaliser.cpp"

using namespace std;

int main() {



    graphAnaliser grafo({
        {0, 7, 9, 0, 0, 0},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
        });
        grafo.dijkstra(1, 5);
        return 0;
}