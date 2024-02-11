#include "referenceString.h"

vector<int> generateReferenceString(const vector<string>& log) {
    vector<int> reference_string;
    // cout << log << endl;
    for (size_t i = 0; i < log.size(); ++i) {
        unsigned int decimalValue;
        try {
            decimalValue = stoul(log[i], nullptr, 16);
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

vector<string> getLog(string trace) {
    string file = "../Data/trace";
    file.append(trace);
    ifstream in(file);
    if (!in.is_open())  {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(2);  // Saída com código de erro
    }

    string line;
    
    vector<string> log;
    while (getline(in, line)) {
        while (line.size() < 8) line = "0" + line;
        log.push_back(line);
    }

    in.close();
    return log;
}