#include <iostream>
#include <string>
#include <vector>

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = '0';

using std::string;
using std::vector;


bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        
         // Controlla righe e colonne
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

// passo referenza per non fare una copia ogni volta
void printBoard(const vector<vector<char>>& board) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "  " << board[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}
int main() {
    // Creo la mia tabella. 
    // UN VETTORE (RIGHE) CHE CONTIENE 3 VETTORI (COLONNE)

    // [ [EMPTY EMPTY EMPTY] [EMPTY EMPTY EMPTY] [EMPTY EMPTY EMPTY] ]
    vector<vector<char>> board(3, vector<char>(3, EMPTY));

    int row, col;

    while(true) {
        printBoard(board);
 
       std::cout << "Inserisci riga (0, 1, 2) e la colonna (0, 1, 2):" << std::endl;
       std::cin >> row >> col;

                // Controlla se la mossa è valida
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != EMPTY) {
            std::cout << "Mossa non valida, riprova!" << std::endl;
            continue;
        }


    }
    
}



