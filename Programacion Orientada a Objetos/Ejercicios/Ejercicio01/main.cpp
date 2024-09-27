#include <iostream>
#include <ctime>
#include "random.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Random randomObj(2, 20);

    for (int i = 0; i < 10; ++i)
    {
        cout << randomObj.GenerateRandom() << " ";
    }
    cout << endl;

    return 0;
}
