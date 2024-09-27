#include "random.h"
#include <cstdlib>
#include <ctime>

Random::Random(int lower, int upper)
{
    if (lower > upper)
    {
        int aux = lower;
        lower = upper;
        upper = aux;
    }
    lower_limit = lower;
    upper_limit = upper;
}

int Random::GenerateRandom()
{
    int a = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    return a;
}
