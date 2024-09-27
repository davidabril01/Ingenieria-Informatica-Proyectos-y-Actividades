#include <iostream>
#include "graphAnaliser.cpp"
using namespace std;


int main()
{
    graphAnaliser Analise({
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}
        });

    Analise.findCycles();
    Analise.removeDuplicateCycles();
    Analise.printCycles();

    return 0;
}

{{0, 0}}

{{0 ,0},
{0 ,0}}

{
{0 ,0 ,0},
{0 ,0 ,0},
{0 ,0 ,0}
}