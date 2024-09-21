//Min absolute difference pairs
//Pair elements of A & B to minimize sum of absolute difference between pairs

#include<iostream>
#include<vector>
using namespace std;

int minAbsoluteDiff(vector<int> A, vector<int> B) {
    //Sort both vector in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;
    for(int i = 0; i < A.size(); i++) {
        absDiff += abs(A[i] - B[i]);
    }

    cout << "Minimum Sum of Absolute Difference: " << absDiff << endl;
    return 0;
}

int main() {
    vector<int> A = {4, 1, 8, 7};
    vector<int> B = {2, 3, 6, 5};

    minAbsoluteDiff(A, B);
}