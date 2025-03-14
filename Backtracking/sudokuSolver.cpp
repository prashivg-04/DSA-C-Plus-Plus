//Sudoku Solver

#include<iostream>
using namespace std;

void printSudoku(int arr[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

bool isSafe(int sudoku[9][9], int row, int col, int n) {
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][col] == n) {
            return false;
        }
    }

    for(int i = 0; i < 9; i++) {
        if(sudoku[row][i] == n) {
            return false;
        }
    }

    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    for(int i = startRow; i <= startRow+2; i++) {
        for(int j = startCol; j <= startCol+2; j++) {
            if(sudoku[i][j] == n) {
            return false;
            }
        }
    }

    return true; 
}

bool sudokuSolver(int sudoku[9][9], int row, int col) {

    if(row == 9) {
        printSudoku(sudoku);
        return true;
    }

    int nxtRow = row;
    int nxtCol = col+1;
    if(col + 1 == 9) {
        nxtRow = row + 1;
        nxtCol = 0;
    }

    if(sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nxtRow, nxtCol);
    }

    for(int i = 1; i <= 9; i++) {
        if(isSafe(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if(sudokuSolver(sudoku, nxtRow, nxtCol)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int arr[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                     {4, 9, 0, 1, 5, 7, 0, 0, 2},
                     {0, 0, 3, 0, 0, 4, 1, 9, 0},
                     {1, 8, 5, 0, 6, 0, 0, 2, 0},
                     {0, 0, 0, 0, 2, 0, 0, 6, 0},
                     {9, 6, 0, 4, 0, 5, 3, 0, 0},
                     {0, 3, 0, 0, 7, 2, 0, 0, 4},
                     {0, 4, 9, 0, 3, 0, 0, 5, 7},
                     {8, 2, 7, 0, 0, 9, 0, 1, 3}};
    sudokuSolver(arr, 0, 0);
}
