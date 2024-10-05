#include <iostream>
#include <string>

int main() {
    // Esercizio 1
    int eta = 25;

    // Esercizio 2
    char iniziale = 'M';

    // Esercizio 3
    double peso = 68.5;

    // Esercizio 4
    bool isSoleggiato = false;

    // Esercizio 5
    std::string citta = "Roma";

    // Esercizio 6
    int numeri[5];

    // Esercizio 7
    const float PI = 3.14159;
    float raggio = 5.0;
    float areaCerchio = PI * raggio * raggio;

    // Esercizio 8
    enum MesiAnno {
        Gennaio,
        Febbraio,
        Marzo,
        Aprile,
        Maggio,
        Giugno,
        Luglio,
        Agosto,
        Settembre,
        Ottobre,
        Novembre,
        Dicembre
    };

    MesiAnno meseCorrente = Maggio;

    // Esercizio 9
    long popolazione = 7894561230;

    // Output per verificare i valori
    std::cout << "Eta: " << eta << std::endl;
    std::cout << "Iniziale: " << iniziale << std::endl;
    std::cout << "Peso: " << peso << std::endl;
    std::cout << "Is Soleggiato: " << std::boolalpha << isSoleggiato << std::endl;
    std::cout << "Citta: " << citta << std::endl;
    std::cout << "Area del cerchio: " << areaCerchio << std::endl;
    std::cout << "Mese corrente: " << meseCorrente << std::endl;
    std::cout << "Popolazione: " << popolazione << std::endl;

    return 0;
}