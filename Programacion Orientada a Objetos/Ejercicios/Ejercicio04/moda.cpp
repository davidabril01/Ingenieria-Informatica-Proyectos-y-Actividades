#include "moda.h"
#include <unordered_map>
using namespace std;

int Moda::findMode(const vector<int>& numbers) {
    unordered_map<int, int> frequencyMap;

    for (int num : numbers) {
        frequencyMap[num]++;
    }
    int mode = numbers[0];
    int maxCount = 0;
    for (const auto& pair : frequencyMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}
