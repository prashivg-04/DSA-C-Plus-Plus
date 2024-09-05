//Print X to the power N

#include<iostream>
using namespace std;

int power(int x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n % 2 == 0) {
        return power(x, n/2) * power(x, n/2);
    } else {
        return x * power(x, n/2) * power(x, n/2);
    }
}

int main() {
    int x = 3;
    int n = 3;
    cout << power(x, n) << endl;
}
