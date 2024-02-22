#include "LRU.h"
#include "OPT.h"
#include "referenceString.h"
#include <iostream>
#include <vector>

using namespace std;
// g++ LRU.cpp OPT.cpp referenceString.cpp main.cpp -o main


int main(int argc, char const *argv[])
{
    // for (size_t i = 1; i <= 4; i++) {
        vector<string> log = getLog(to_string(4));
        // vector<string> log = getLog(to_string(i));
        vector<int> reference_string = generateReferenceString(log);

        // for (int j = 4; j <= 32; j *= 2) {
        cout << reference_string.size() << endl;
        // cout << "LRU Misses: " << lruAlgorithm(reference_string, j);
        OPT memory(16);
        // OPT memory(j);
        cout << "OPT Misses: " << memory.count_misses(reference_string) << endl;
        // }   
    // }
    return 0;
}
