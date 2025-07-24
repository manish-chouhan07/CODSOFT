#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to initialize the game board
void initializeBoard(vector<vector<char>>& board) {
    board = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
}

// Function to display the current game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\nCurrent Board:\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl << endl;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to get valid player move
void getPlayerMove(vector<vector<char>>& board, char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter your move (row and column 1-3): ";
        cin >> row >> col;
        
        // Adjust to 0-based index
        row--;
        col--;
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
}

// Main game function
void playGame() {
    vector<vector<char>> board;
    char currentPlayer = 'X';
    bool gameOver = false;
    
    initializeBoard(board);
    
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1: X\nPlayer 2: O\n";
    
    while (!gameOver) {
        displayBoard(board);
        getPlayerMove(board, currentPlayer);
        
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            gameOver = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw!\n";
            gameOver = true;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

// Function to ask if players want to play again
bool askToPlayAgain() {
    char response;
    cout << "Would you like to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}

int main() {
    bool playAgain = true;
    
    while (playAgain) {
        playGame();
        playAgain = askToPlayAgain();
    }
    
    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}
