//Tiling Problem
//Count total ways to tile a floor (2*n) with tiles (2*1)

#include<iostream>
using namespace std;

int tilingProblem(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    int horizontalChoice = tilingProblem(n-2);

    int verticalChoice = tilingProblem(n-1);

    return horizontalChoice + verticalChoice;
}

int main() {
    int n = 5; 
    cout << tilingProblem(5) << endl;
}
