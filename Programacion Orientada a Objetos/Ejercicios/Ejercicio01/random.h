#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>

class Random
{
public:
    Random(int lower, int upper);
    int GenerateRandom();
private:
    int lower_limit;
    int upper_limit;
};

#endif // RANDOM_H
