#ifndef reference_string_h
#define reference_string_h

#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <typeinfo>
//g++ -o referenceString referenceString.cpp

using namespace std;

vector<int> generateReferenceString(const vector<string>& log);

vector<string> getLog(string trace);

#endif