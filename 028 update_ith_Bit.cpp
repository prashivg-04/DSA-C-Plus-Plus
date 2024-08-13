//Update ith Bit

#include<iostream>
using namespace std;

int updateIthBit(int n, int i, int val) {
    n = n & (~(1<<i)); //clear ith bit

    int bitMask = val << i;
    return n | bitMask;
}

int main() {
    int num = 7;
    int i = 3;
    int val = 1;
    cout << updateIthBit(num, i, val) << endl;
}