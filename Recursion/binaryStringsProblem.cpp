//Binary Strings Problem

#include<iostream>
#include<string>
using namespace std; 

void binStrings(string str, int n, int prev) {
    if(n == 0) {
        cout << str << endl;
        return;
    }
    if(prev != 1) {
        binStrings(str+'0', n-1, 0);
        binStrings(str+'1', n-1, 1);
    } else {
        binStrings(str+'0', n-1, 0);
    }
}

int main() {
    int n = 4;
    string str = "";
    binStrings(str, n, 0);
}