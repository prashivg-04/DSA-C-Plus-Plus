//Clear last i bits

#include<iostream>
using namespace std;

int clearIbits(int n, int i) {
    int bitMask = ~0 << i;
    return n & bitMask;
}

int main() {
    int num = 15;
    int i = 2;
    cout << clearIbits(num, i) << endl;
}