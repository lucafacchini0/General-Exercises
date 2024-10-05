#include <iostream>
#include <string>

using std::string;

// Esercizio 1
// Dichiarare una variabile intera chiamata "numero" e assegnarle il valore 10.
// Esercizio 2
// Dichiarare una variabile di tipo float chiamata "altezza" e assegnarle il valore inserito dall'utente da tastiera.
// Esercizio 3
// Dichiarare una variabile costante intera chiamata "lunghezza" e assegnarle il valore 5. Tentare di modificarne il valore e osservare l'errore generato dal compilatore.
// Esercizio 4
// Dichiarare una variabile booleana chiamata "vero" e assegnarle il valore "true".
// Esercizio 5
// Dichiarare una variabile intera chiamata "valore1" e assegnarle il valore 5. Dichiarare una variabile float chiamata "valore2" e assegnarle il valore di "valore1" convertito in float.
// Esercizio 6
// Dichiarare una variabile stringa chiamata "nome" e assegnarle il valore "Alice".

int main() {
    int numero = 10;
 
    
    float altezza;
    std::cout << "Inserisci altezza";
    std::cin >> altezza;

    const int lunghezza = 5;

    bool vero = true;

    int valore1 = 5;
    float valore2 = static_cast<float>(valore1);

    string nome = "Alice";

}