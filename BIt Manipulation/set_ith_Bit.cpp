//Set ith Bit

#include<iostream>
using namespace std;

int setIthBit(int n, int i) {
    int bitMask = 1 << i;
    return n | bitMask;
}

int main() {
    int num = 6;
    int i = 0;
    cout << setIthBit(num, i) << endl;
}