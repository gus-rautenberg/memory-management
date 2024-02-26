#include "LRU.h"
#include "OPT.h"
#include "referenceString.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> reference_string;
    vector<string> log = getLog("1");
    reference_string = generateReferenceString(log);

    for (int j = 4; j <= 32; j *= 2) {
        int LRUmiss = lruAlgorithm(reference_string, j);
        cout << "LRU Misses: " << LRUmiss << endl;
        OPT memory(j);
        int OPTmiss = memory.count_misses(reference_string);
        cout << "OPT Misses from trace 1 with " << j << " pages: " << OPTmiss << endl;
    }

    return 0;
}