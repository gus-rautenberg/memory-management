#include "LRU.h"
#include "OPT.h"
#include "referenceString.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
// g++ LRU.cpp OPT.cpp referenceString.cpp main.cpp -o main

int main(int argc, char const *argv[])
{
    vector<int> reference_string;
    vector<string> log = getLog("1"); // mudar frames aqui
    reference_string = generateReferenceString(log);

    int LRUmiss = lruAlgorithm(reference_string, 4); // mudar número de frames aqui aqui
    cout << "LRU Misses: " << LRUmiss << endl;
    OPT memory(4); // mudar número de frames aqui
    int OPTmiss = memory.count_misses(reference_string);
    cout << "OPT Misses from trace " << 1 << " with " << 4 << " pages: " << OPTmiss << endl; // mudar log e frames aqui

    return 0;
}