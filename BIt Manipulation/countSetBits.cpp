//Count Set Bits

#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while(n > 0) {
        int lastDig = n & 1;
        count += lastDig;
        n = n >> 1;
    }
    return count;
}

int main() {
    int num = 8;
    cout << countSetBits(num) << endl;
}