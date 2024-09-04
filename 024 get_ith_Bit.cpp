//Get ith Bit

#include<iostream>
using namespace std;

int getIthBit(int n, int i) {
    int bitMask = 1 << i;

    if(!(n & bitMask)) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n = 6;
    int i = 0;
    cout << getIthBit(n, i) << endl;
}
