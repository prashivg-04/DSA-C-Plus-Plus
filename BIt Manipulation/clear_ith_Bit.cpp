//Clear ith Bit

#include<iostream>
using namespace std;

int clearIthBit(int n, int i) {
    int bitMask = ~(1 << i);
    return (n & bitMask);
}

int main() {
    int num = 6;
    int i = 1;
    cout << clearIthBit(num, i) << endl;
}