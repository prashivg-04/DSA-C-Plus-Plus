//Sum of N natural number

#include<iostream>
using namespace std;

int sum(int n) {
    if(n == 1) {
        return n;
    }
    return n + sum(n-1);
}

int main() {
    int n = 6;
   cout << sum(n) << endl;
}