#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

vector<int> generate_reference_string(const vector<string>& log) {
    vector<int> reference_string;
    cout << log[0];
    for (size_t i = 0; i < log.size(); ++i) {
        unsigned int decimalValue;
       try {
            decimalValue = stoi(log[i], nullptr, 16);
        } catch (const std::out_of_range& e) {
            cerr << "Erro ao converter string para inteiro: " << e.what() << endl;
            cerr << "String problemática: " << log[i] << endl;
        }
        bitset<32> binaryValue = bitset<32>(decimalValue);
        string binaryString = binaryValue.to_string();
        binaryString = binaryString.substr(0, 20);
        int decimalResult = bitset<20>(binaryString).to_ulong();

        reference_string.push_back(decimalResult);
    }
    return reference_string;
}

int main() {
    ifstream file("trace1.txt");
    if (!file.is_open())  {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;  // Saída com código de erro
    }
    // int pageSize = 4096;
    string line;
    vector<string> log;
    
    while (getline(file, line)) {
        while (line.size() < 8) line = "0" + line;
        log.push_back(line);
    }

    vector<int> reference_string = generate_reference_string(log);
    printf("%d", reference_string[1]);
    return 0;
    file.close();
}