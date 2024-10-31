#include <stdio.h>

char board[3][3]; // 3x3 game board
char currentPlayer; // Current player ('X' or 'O')

// Function to initialize the game board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the game board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if the current player has won
int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // There is still an empty space
            }
        }
    }
    return 1; // Board is full
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Main function to run the game
int main() {
    int row, col;
    int gameOver = 0;

    initializeBoard();
    currentPlayer = 'X'; // Player X starts

    while (!gameOver) {
        printBoard();
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check for valid input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Place the move on the board
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            gameOver = 1;
        } else if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        } else {
            switchPlayer(); // Switch to the other player
        }
    }
    return 0;
}
