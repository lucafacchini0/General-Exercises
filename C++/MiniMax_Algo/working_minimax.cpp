#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

// Funzione per stampare il tabellone
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << "|";
        }
        cout << endl;
    }
}

// Controlla se c'è una vittoria
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

// Controlla se il tabellone è pieno
bool isFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == EMPTY) return false;
        }
    }
    return true;
}

// Funzione Minimax
int minimax(vector<vector<char>>& board, bool isMaximizing) {
    if (checkWin(board, PLAYER_X)) return -1; // X vince
    if (checkWin(board, PLAYER_O)) return 1;  // O vince
    if (isFull(board)) return 0; // Pareggio

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O; // Simula mossa
                    int score = minimax(board, false);
                    board[i][j] = EMPTY; // Ripristina la mossa
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X; // Simula mossa
                    int score = minimax(board, true);
                    board[i][j] = EMPTY; // Ripristina la mossa
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

// Funzione principale
int main() {
    vector<vector<char>> board(3, vector<char>(3, EMPTY));
    int row, col;
    
    while (true) {
        printBoard(board);
        
        // Turno del giocatore X
        cout << "Inserisci la riga (0, 1, 2) e la colonna (0, 1, 2) per X: ";
        cin >> row >> col;

        // Controlla se la mossa è valida
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != EMPTY) {
            cout << "Mossa non valida, riprova!" << endl;
            continue;
        }

        board[row][col] = PLAYER_X; // Applica la mossa del giocatore

        // Controlla se il giocatore X ha vinto
        if (checkWin(board, PLAYER_X)) {
            printBoard(board);
            cout << "Hai vinto! Complimenti!" << endl;
            break;
        }

        // Controlla se il tabellone è pieno
        if (isFull(board)) {
            printBoard(board);
            cout << "È un pareggio!" << endl;
            break;
        }

        // Turno del giocatore O (computer)
        int bestScore = numeric_limits<int>::min();
        int moveRow = -1, moveCol = -1;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O; // Simula mossa
                    int score = minimax(board, false);
                    board[i][j] = EMPTY; // Ripristina la mossa
                    if (score > bestScore) {
                        bestScore = score;
                        moveRow = i;
                        moveCol = j;
                    }
                }
            }
        }

        // Esegui la migliore mossa trovata
        board[moveRow][moveCol] = PLAYER_O;

        // Controlla se il computer O ha vinto
        if (checkWin(board, PLAYER_O)) {
            printBoard(board);
            cout << "Il computer O ha vinto! Riprova!" << endl;
            break;
        }

        // Controlla se il tabellone è pieno
        if (isFull(board)) {
            printBoard(board);
            cout << "È un pareggio!" << endl;
            break;
        }
    }
    
    return 0;
}
