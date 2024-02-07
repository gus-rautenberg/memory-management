#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream arquivo("teste.txt");
    std::string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            std::cout << linha << '\n';
        }
        arquivo.close();
    } else {
        std::cout << "Não foi possível abrir o arquivo";
    }

    return 0;
}
