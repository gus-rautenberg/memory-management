#include "LRU.h"
#include "OPT.h"
#include "referenceString.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
// g++ -O2 LRU.cpp OPT.cpp referenceString.cpp main.cpp -o main

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 4; i++)
    {
        vector<int> reference_string;
        vector<string> log = getLog(to_string(i));
        reference_string = generateReferenceString(log);
        double logSize = log.size();
        double refSize = reference_string.size();
        cout << "Proporção RefString/log: " << refSize / logSize << endl;
        cout << "trace " << i << " size: " << reference_string.size() << endl;

        for (int j = 4; j <= 32; j *= 2)
        {
            int LRUmiss = lruAlgorithm(reference_string, j);
            cout << "LRU Misses: " << LRUmiss << endl;
            OPT memory(j);
            int OPTmiss = memory.count_misses(reference_string);
            cout << "OPT Misses from trace " << 1 << " with " << j << " pages: " << OPTmiss << endl;
        }
    }

    return 0;
}