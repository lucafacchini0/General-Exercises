#include <iostream>
#include <cmath>

int main() {
    int numero1 = 50;
    int numero2 = 20;
    int numero3 = 102;

    std::cout << "Somma: " << numero1 + numero2 << std::endl;
    std::cout << "Moltiplicazione: " << numero1 * numero2 << std::endl;

    double media = (static_cast<double>(numero1) + numero2 + numero3) / 3;
    std::cout << "Media" << media << std::endl;

    int numero5 = pow(numero2, 2);
    std::cout << numero5 << std::endl;

    double numero6 = sqrt(numero1);
    std::cout << numero6 << std::endl;
    
}

