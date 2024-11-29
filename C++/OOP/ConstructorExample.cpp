#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Studente {
    private:
        char nome[50];
        int eta;
    public:
        Studente(char ilNome[], int quantoVecchio) {
            strcpy(nome, ilNome);
            eta = quantoVecchio;
        }

        void stampa() {
            std::cout << "Nome: " << nome << std::endl;
            std::cout << "Eta: " << eta << std::endl;
        }
};

int main() {
    Studente studente1("Luca", 50);
    studente1.stampa();
}