/*
Michael Porter
Dr. Yampolskiy
Mon, Oct 28, 2024 - Fri, Nov 1, 2024
Tic Tac Toe Program
Description: A TicTacToe program featuring a singleplayer experience where the program decides who goes first and the opponent decides where to move completely at random. The program
	After playing the game, the program will announce who is the winner.
Side Note: Sorry for completeing this so late, I was in the middle of working on it when I had gotten sick and am still very sick.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread> // Include for sleep functionality

using namespace std;

// Class representing the Tic-Tac-Toe board
class Board {
private:
    char cells[3][3]; // 3x3 grid for Tic-Tac-Toe

public:
    Board() {
        reset();
    }

    // Method to reset the board with wildcards
    void reset() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cells[i][j] = '*';
            }
        }
    }

    // Method to display the board with 1-based row and column numbers
    void display() {
        cout << "\n   1   2   3\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << "  ";
            for (int j = 0; j < 3; j++) {
                cout << cells[i][j];
                if (j < 2) cout << " | ";
            }
            if (i < 2) cout << "\n  -----------\n";
        }
        cout << "\n\n";
    }

    // Method to place a move on the board (row and col in 1-3 range)
    bool makeMove(int row, int col, char symbol) {
        row--; col--; // Adjust to 0-based index
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            return false; // Out of bounds
        }
        if (cells[row][col] == '*') {
            cells[row][col] = symbol;
            return true;
        }
        return false; // Cell already occupied
    }

    // Method to check if there's a winner
    bool checkWin(char symbol) {
        for (int i = 0; i < 3; i++) {
            if ((cells[i][0] == symbol && cells[i][1] == symbol && cells[i][2] == symbol) || // Row check
                (cells[0][i] == symbol && cells[1][i] == symbol && cells[2][i] == symbol)) { // Column check
                return true;
            }
        }
        // Diagonal checks
        if ((cells[0][0] == symbol && cells[1][1] == symbol && cells[2][2] == symbol) ||
            (cells[0][2] == symbol && cells[1][1] == symbol && cells[2][0] == symbol)) {
            return true;
        }
        return false;
    }

    // Method to check if the board is full (for a draw)
    bool isFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cells[i][j] == '*') return false;
            }
        }
        return true;
    }
};

// Class representing a player (user or computer)
class Player {
public:
    char symbol;

    Player(char sym) : symbol(sym) {}

    // Method to get a player's move with separate row and column input
    void getMove(int &row, int &col) {
        cout << "Enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> col;
    }
};

// Class representing the computer player
class Computer : public Player {
public:
    Computer(char sym) : Player(sym) {}

    // Method to make a random move for the computer with random delay
    void getMove(int &row, int &col, Board &board) {
        // Generate a random delay between 1 and 3 seconds
        int delay = rand() % 3 + 1;
        cout << "Computer is thinking...\n";
        std::this_thread::sleep_for(std::chrono::seconds(delay)); // Pause for random delay

        // Generate random move within 1-3 range
        do {
            row = rand() % 3 + 1;
            col = rand() % 3 + 1;
        } while (!board.makeMove(row, col, symbol)); // Repeat until an empty cell is found
        cout << "Computer chose row " << row << " and column " << col << ".\n";
    }
};

// Class representing the Tic-Tac-Toe game
class Game {
private:
    Board board;
    Player user;
    Computer computer;
    bool isUserTurn;

public:
    Game() : user('X'), computer('O') {
        srand(time(0));
        isUserTurn = rand() % 2;
        cout << "Starting Tic-Tac-Toe game...\n";
        cout << (isUserTurn ? "User" : "Computer") << " goes first.\n";
    }

    // Method to play the game
    void play() {
        int row, col;
        while (true) {
            board.display();
            if (isUserTurn) {
                cout << "Your turn.\n";
                while (true) {
                    user.getMove(row, col);
                    if (board.makeMove(row, col, user.symbol)) break;
                    cout << "Invalid move. Cell already occupied or out of bounds. Try again.\n";
                }
            } else {
                cout << "Computer's turn.\n";
                computer.getMove(row, col, board);
            }

            // Check if current player has won
            char currentSymbol = isUserTurn ? user.symbol : computer.symbol;
            if (board.checkWin(currentSymbol)) {
                board.display();
                cout << (isUserTurn ? "You win!" : "Computer wins!") << "\n";
                break;
            }

            // Check if the game is a draw
            if (board.isFull()) {
                board.display();
                cout << "It's a draw!\n";
                break;
            }

            // Switch turn to the other player
            isUserTurn = !isUserTurn;
        }
    }
};

// Main function to start the game
int main() {
    Game game;
    game.play();
    return 0;
}
