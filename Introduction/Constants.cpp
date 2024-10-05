#include <iostream>
#include <string>

using std::string;

int main() {
    const int numero = 10;
    std::cout << "Numero" << numero << std::endl;

    const float numeroFloat = 69.420;
    std::cout << "numeroFloat" << numeroFloat << std::endl;

    const string nome = "Luca";
    std::cout << "Nome" << nome << std::endl;

    const double numero2 = 50;
    std::cout << "Operazione: " << numero2 + 50 << std::endl;

    const char carattere = 'A';
    std::cout << "Carattere: " << carattere << std::endl;

    if(carattere == 'A') {
        std::cout << "Il carattere è A" << std::endl;
    }

    const bool isLucaGorgeous = true;

    if(isLucaGorgeous) {
        std::cout << "Luca è bellissimo" << std::endl;
    }

    for(int i = 0; i < numero; i++) {
        std::cout << "Iterazione:" << i << std::endl;
    }

    const long long int numeroGrande = 1000000000000000000;
    std::cout << "Numero grande: " << numeroGrande << std::endl;
}