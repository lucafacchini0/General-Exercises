#include <iostream>
#include <string>

using std::string;

int main() {
    string nome = "LuuL";
    bool palindrome = true;

    for(int i = 0; i < nome.length(); i++) {
        if(nome[i] != nome[nome.length() - 1 - i]) {
            palindrome = false;
            break;
        }
    }

    std::cout << palindrome << std::endl;
}