//N Queens
//Place N queens on an N*N chessboard such that no 2 queens can attack each other

#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> board) {
    int n = board.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " "; 
        }
        cout << endl;
    }
    cout << "_______________________ \n" << endl;

}

bool isSafe(vector<vector<char>> board, int row, int col) {
    int n = board.size();
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    for(int i = 0; i < col; i++) {
        if(board[row][i] == 'Q') {
            return false;
        }
    }

    for(int i = row, j = col; i>=0 && j>= 0; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    for(int i = row, j = col; i>=0 && j<n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void nQueens(vector<vector<char>> board, int row) {
    int n = board.size();
    if(row == n) {
        printBoard(board);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(isSafe(board, row, i)) {
            board[row][i] = 'Q';
            nQueens(board, row+1);
            board[row][i] = '.';
        }
    }
}

int main() {
    int n = 5;
    vector<vector<char>> board;
    for(int i = 0; i < n; i++) {
        vector<char> newRow;
        for(int j = 0; j < n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    nQueens(board, 0);
}
