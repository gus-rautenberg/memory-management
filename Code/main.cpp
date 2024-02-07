#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;

vector<int> generate_reference_string(const vector<string>& log) {
    vector<int> reference_string;
    for (size_t i = 0; i < log.size(); ++i) {
        unsigned int decimalValue = stoi(log[i], 0, 16);
        bitset<32> binaryValue(decimalValue);
        string binaryString = binaryValue.to_string();
        binaryString = binaryString.substr(0, 20);
        int decimalResult = bitset<20>(binaryString).to_ulong();

        reference_string.push_back(decimalResult);
    }
    return reference_string;
}

int main() {
    ifstream file("trace1.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;  // Saída com código de erro
    }
    // int pageSize = 4096;
    
    vector<string> log;
    string line;
    while (getline(file, line)) {
        while (line.size() < 8) line = "0" + line;
        log.push_back(line);
    }

    vector<int> reference_string = generate_reference_string(log);
    return 0;
}