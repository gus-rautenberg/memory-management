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
using namespace std;

int lruAlgorithm(vector<int>& vetorReferenceString, int numFrames){
    struct frames{
        int espacoLivre;
        int count;
    };
    int numFalhas = 0;
    int variavel = 0;
    int teste = 0;
    vector<frames> vetorFrames;

    if(vetorReferenceString.size() < numFrames){
        variavel = vetorReferenceString.size();
    }
    else{
        variavel = numFrames;
    }

    for(int i = 0, t = 0; i < variavel && t < vetorReferenceString.size(); i++, t++){
        
        frames frame;
        frame.espacoLivre = vetorReferenceString[t];
        frame.count = 0;
        vetorFrames.push_back(frame);
        teste += 1;
        for(frames& frame : vetorFrames){
            frame.count++;
        }
        for(int j = 0; j < numFrames; j++){
            if(vetorFrames[j].espacoLivre == vetorReferenceString[t+1]){
                //cout << "t + 1 " << vetorReferenceString[t+1] << endl;
                while(vetorFrames[j].espacoLivre == vetorReferenceString[t+1]){
                    t++;
                }

            }
        }

    };   
    cout << teste << endl;

    for(int i= 0; i <vetorFrames.size(); i++){
        cout << "Frame " << i << ": espacoLivre = " << vetorFrames[i].espacoLivre << ", count = " << vetorFrames[i].count << endl;
    }

    for(int i  = numFrames  ; i < vetorReferenceString.size(); i++){
        // cout << vetorReferenceString.size() << endl;
        for(int i= 0; i <vetorFrames.size(); i++){
        cout << "Frame " << i << ": espacoLivre = " << vetorFrames[i].espacoLivre << ", count = " << vetorFrames[i].count << endl;
        }
        bool notFalha = false;
        for(int j = 0; j < numFrames; j++){
            if(vetorFrames[j].espacoLivre == vetorReferenceString[i]){
                notFalha = true;
                vetorFrames[j].count = 0;
                cout << "entrou aqui quando i era: " << i << endl;
                //cout << "vetor frames: "<< vetorFrames[j].espacoLivre << endl;
                //cout << "vetor referenceString: "<< vetorReferenceString[i] << endl;
                break;
            }
        }  
            if(notFalha){
                //cout << "ja tinha " << endl;
                for(frames& frame : vetorFrames){
                    frame.count++;
                }
            }

            else{
                frames* maiorCount = &vetorFrames[0];
                for(int i = 1;i < vetorFrames.size(); i++){
                    if(vetorFrames[i].count > maiorCount->count){
                        maiorCount = &vetorFrames[i];
                        cout <<"maior count achado soq dentro do for : " << maiorCount->espacoLivre << endl;
                    }
                    cout <<"maior Count achado : " << maiorCount->espacoLivre << endl;
                }
                maiorCount->espacoLivre = vetorReferenceString[i];
                cout << "substituto do maior count: " << maiorCount->espacoLivre << endl;
                maiorCount->count = 0;
                numFalhas += 1;
                cout << "numero de falhas: " << numFalhas << endl;
                for(frames& frame : vetorFrames){
                    frame.count++;
                }
            }  
    }   
    return numFalhas + (teste);
}

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



int main(){

    ifstream file("../Data/teste.txt");
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
    vector<int> reference_string = generateReferenceString(log);


    // exemplo professor numeros: 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1. Frames = 3.

    vector<int> numeros = {745074, 745074, 425389, 745074, 745074, 602425, 193313, 657935, 72722, 949371};

    cout << lruAlgorithm(numeros, 4) << endl;

    // for(int i = 0; i<reference_string.size(); i++){
    //     cout << i << ": " << reference_string[i] << endl << endl;
    // }


    return 0;
    file.close();

}
    
