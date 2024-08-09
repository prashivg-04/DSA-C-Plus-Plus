//Search in Sorted Matrix

#include<iostream>
using namespace std;

bool search(int mat[][4], int n, int m, int key) {
    int row = 0;
    int col = m-1;

    //O(n+m)
    while(row<=n-1 && col>=0) {
        if(mat[row][col] == key) {
            cout << "Key found at cell (" << row << "," << col << ")" << endl;
            return true;
        } else if(mat[row][col] > key) {
            //move to left
            col--;
        } else {
            //move down
            row++;
        }
    }

    cout << "Key not found" << endl;
    return false;
}

int main() {
    int mat[4][4] = {{10,20,30,40},
                     {15,25,35,45},
                     {27,29,37,48},
                     {32,33,39,50}};
    search(mat, 4, 4, 33);
    return 0;                 
}