//Diagonal Sum

#include<iostream>
using namespace std;

int diagonalSum(int mat[][3], int n) {
    int sum = 0;

    //O(N^2) - Time Complexity
    // for(int i = 0; i<n; i++) {
    //     for(int j = 0; j<n; j++) {
    //         if(i == j) {
    //             sum += mat[i][i];
    //         } else if(i + j == n-1) {
    //             sum += mat[i][j];
    //         }
    //     }
    // }


    //O(N) - Time Complexity
    for(int i = 0; i<n; i++) {
        sum += mat[i][i];
        if(i != n-i-1) {
            sum += mat[i][n-i-1];
        }
    }

    return sum;
}

int main() {
    int mat[3][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}};
    int sum = diagonalSum(mat, 3);
    cout << "Diagonal Sum: " << sum << endl;
    return 0;
}
