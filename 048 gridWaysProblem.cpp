//Grid Ways

#include<iostream>
using namespace std;

int gridWays(int n, int m, int row, int col) {
    if(row == n-1 && col == m-1) {
        return 1;
    }

    if(row >= n || col >= m) {
        return 0;
    }

    //right
    int val1 = gridWays(n, m, row, col+1);

    //down
    int val2 = gridWays(n, m, row+1, col);

    return val1 + val2;
}

int main() {
    int n = 3;
    int m = 3;
    cout << gridWays(n, m, 0, 0) << endl;
}
