#include <iostream>
#include <string>

int main() {
    // Esercizio 1
    int numero1 = 5;
    double numero2 = numero1;
    std::cout << numero2 << std::endl;

    // Esercizio 2
    double numero1_d = 3.14;
    int numero2_i = static_cast<int>(numero1_d);
    std::cout << numero2_i << std::endl;

    // Esercizio 3
    int numero1_int = 10;
    char numero2_char = static_cast<char>(numero1_int);
    std::cout << numero2_char << std::endl;

    // Esercizio 4
    std::string numero1_str = "15";
    int numero2_int_from_str = std::stoi(numero1_str);
    std::cout << numero2_int_from_str << std::endl;

    // Esercizio 5
    int numero1_to_str = 25;
    std::string numero2_str = std::to_string(numero1_to_str);
    std::cout << numero2_str << std::endl;

    return 0;
}