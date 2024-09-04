//Print numbers in decreasing order

#include<iostream>
using namespace std;

void printDec(int n) {
    if(n == 1) {
        cout << n << " " << endl;
        return;
    }
    cout << n << " ";
    printDec(n-1);
    return;
}

int main() {
    int n = 10;
    printDec(n);
    return 0;
}
