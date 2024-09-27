#include <iostream>
#include "graphAnaliser.cpp"
using namespace std;

int main()
{
    graphAnaliser grafo({
                    {0, 1, 0, 1, 0, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 0, 0, 1, 0}, 
                    {0, 1, 0, 1, 0, 1, 0, 0, 1}, 
                    {1, 0, 1, 0, 1, 0, 1, 0, 0}, 
                    {0, 1, 0, 1, 0, 1, 0, 1, 0},
                    {0, 0, 1, 0, 1, 0, 1, 0, 1},
                    {1, 0, 0, 1, 0, 1, 0, 1, 0},
                    {0, 1, 0, 0, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 0, 1, 0, 1, 0},
                    });
    grafo.matrixToList();
}