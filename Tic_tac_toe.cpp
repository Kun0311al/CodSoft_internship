#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};
char currentPlayer = 'X';

void drawBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-------------" << endl;
    }
}

void playerInput() {
    int input;
    cout << "It's " << currentPlayer << "'s turn. Enter a number between 1 and 9: ";
    cin >> input;

    int row = (input - 1) / 3;
    int col = (input - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move. Try again." << endl;
        playerInput();
    }
    else {
        board[row][col] = currentPlayer;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            drawBoard();
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            drawBoard();
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        drawBoard();
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        drawBoard();
        return true;
    }
    return false;
}

bool checkTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    drawBoard();
    return true;
}

void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    }
    else {
        currentPlayer = 'X';
    }
}

int main() {
    bool gameOn = true;

    while (gameOn) {
        drawBoard();
        playerInput();
        if (checkWin()) {
            cout<<"Congratulation "<<currentPlayer<<endl;
            cout << currentPlayer << " wins!" << endl;
            gameOn = false;
        }
        else if (checkTie()) {
            cout << "It's a tie!" << endl;
            gameOn = false;
        }
        else {
            switchPlayer();
        }
    }

    return 0;
}