/*
Michael Porter
Dr. Yampolskiy
Fri, November 8
3D TicTacToe
Description: A game of TicTacToe on a 3-Dimensional plane. Singleplayer game where the program randomly decides who goes first and calculates win conditions at the end
	including win that span all 3 planes.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread> // Include for sleep functionality

using namespace std;

// Extended Class for 3D Tic-Tac-Toe Board
class Board3D {
private:
    char cells[3][3][3]; // 3x3x3 grid for 3D Tic-Tac-Toe

public:
    Board3D() {
        reset();
    }

    // Reset the board
    void reset() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cells[i][j][k] = '*';
                }
            }
        }
    }

    // Display the 3D board in a side-by-side format
    void display() {
        cout << "\n   Layer 1       Layer 2       Layer 3\n";
        for (int i = 0; i < 3; i++) {
            for (int layer = 0; layer < 3; layer++) {
                cout << "   ";
                for (int j = 0; j < 3; j++) {
                    cout << cells[layer][i][j];
                    if (j < 2) cout << " | ";
                }
                if (layer < 2) cout << "   "; // Space between layers
            }
            cout << "\n";
            if (i < 2) cout << "  -----------   -----------   -----------\n";
        }
        cout << "\n";
    }

    // Make a move on the 3D board
    bool makeMove(int layer, int row, int col, char symbol) {
        layer--; row--; col--; // Adjust to 0-based index
        if (layer < 0 || layer > 2 || row < 0 || row > 2 || col < 0 || col > 2) {
            return false; // Out of bounds
        }
        if (cells[layer][row][col] == '*') {
            cells[layer][row][col] = symbol;
            return true;
        }
        return false; // Cell already occupied
    }

    // Check if the board is full
    bool isFull() {
        for (int layer = 0; layer < 3; layer++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    if (cells[layer][row][col] == '*') {
                        return false; // Found an empty cell
                    }
                }
            }
        }
        return true; // No empty cells found
    }

    // Count the number of 3-in-a-row for a given symbol
    int countThreeInRow(char symbol) {
        int count = 0;

        // Check rows, columns, and layers
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Check rows in each layer (layer, row, column)
                if (cells[i][j][0] == symbol && cells[i][j][1] == symbol && cells[i][j][2] == symbol) count++;
                // Check columns in each layer (layer, column, row)
                if (cells[i][0][j] == symbol && cells[i][1][j] == symbol && cells[i][2][j] == symbol) count++;
                // Check layers in each row and column (layer, row, column)
                if (cells[0][i][j] == symbol && cells[1][i][j] == symbol && cells[2][i][j] == symbol) count++;
            }
        }

        // Check diagonals within each layer (layer, row, column)
        for (int layer = 0; layer < 3; layer++) {
            // Diagonals within each layer (top-left to bottom-right, top-right to bottom-left)
            if (cells[layer][0][0] == symbol && cells[layer][1][1] == symbol && cells[layer][2][2] == symbol) count++;
            if (cells[layer][0][2] == symbol && cells[layer][1][1] == symbol && cells[layer][2][0] == symbol) count++;
        }

        // Check cross-layer diagonals (layer, row, column)
        // Diagonal from (0,0,0) to (2,2,2)
        if (cells[0][0][0] == symbol && cells[1][1][1] == symbol && cells[2][2][2] == symbol) count++;
        // Diagonal from (0,0,2) to (2,2,0)
        if (cells[0][0][2] == symbol && cells[1][1][1] == symbol && cells[2][2][0] == symbol) count++;
        // Diagonal from (0,2,0) to (2,0,2)
        if (cells[0][2][0] == symbol && cells[1][1][1] == symbol && cells[2][0][2] == symbol) count++;
        // Diagonal from (2,0,0) to (0,2,2)
        if (cells[2][0][0] == symbol && cells[1][1][1] == symbol && cells[0][2][2] == symbol) count++;

        return count;
    }

};

// Main function for the game
int main() {
    srand(time(0)); // Seed random number generator
    Board3D game3d;
    game3d.reset();

    // Randomly decide who goes first
    bool isPlayerTurn = rand() % 2;  // Randomly decide: 0 or 1
    cout << (isPlayerTurn ? "Player goes first.\n" : "Computer goes first.\n");

    int layer, row, col;
    char playerSymbol = 'X';
    char computerSymbol = 'O';

    while (true) {
        if (game3d.isFull()) {
            // Count the number of 3-in-a-rows for both players
            int playerScore = game3d.countThreeInRow(playerSymbol);
            int computerScore = game3d.countThreeInRow(computerSymbol);

            cout << "Player 3-in-a-rows: " << playerScore << "\n";
            cout << "Computer 3-in-a-rows: " << computerScore << "\n";

            if (playerScore > computerScore) {
                cout << "You win!\n";
            } else if (computerScore > playerScore) {
                cout << "Computer wins!\n";
            } else {
                cout << "It's a draw!\n";
            }
            break;
        }

        game3d.display();

        if (isPlayerTurn) {
            // Player's turn
            cout << "Your turn (Enter Layer, Row, Column): ";
            cin >> layer >> row >> col;

            // Move validation
            if (layer < 1 || layer > 3 || row < 1 || row > 3 || col < 1 || col > 3) {
                cout << "Invalid move! Please enter a valid Layer, Row, and Column between 1 and 3.\n";
                continue;
            }
            if (!game3d.makeMove(layer, row, col, playerSymbol)) {
                cout << "Invalid move! Cell already occupied. Try again.\n";
                continue;
            }
        } else {
            // Computer's turn
            cout << "Computer's turn...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate thinking
            int attempts = 0;
            while (attempts < 50) {
                layer = rand() % 3 + 1;
                row = rand() % 3 + 1;
                col = rand() % 3 + 1;
                if (game3d.makeMove(layer, row, col, computerSymbol)) break;
                attempts++;
            }
        }

        // Switch turns
        isPlayerTurn = !isPlayerTurn;
    }

    return 0;
}
