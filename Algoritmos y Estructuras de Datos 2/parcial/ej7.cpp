#include <iostream>
#include <vector>
#include <chrono>
#include "graphAnaliser.cpp"

using namespace std;

int main() {



    graphAnaliser grafo({
        {0, 1, 0, 4, 0, 0},
        {1, 0, 1, 0, 4, 0},
        {0, 1, 0, 3, 0, 1},
        {4, 0, 3, 0, 1, 0},
        {0, 4, 0, 1, 0, 4},
        {0, 0, 1, 0, 4, 0}
        });
    auto start = std::chrono::high_resolution_clock::now();

    grafo.primMST();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << std::endl;
    
    
    auto start = std::chrono::high_resolution_clock::now();

    grafo.findMinimumSpanningTreeKruskal();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << std::endl;
    return 0;
}
