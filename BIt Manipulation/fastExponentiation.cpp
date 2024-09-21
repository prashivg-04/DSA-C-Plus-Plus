//Fast Exponentiation

#include<iostream>
using namespace std;

void power(int x, int n) {
    int ans = 1;

    while(n > 0) {
        int lastDig = n & 1;

        if(lastDig) {
            ans = ans * x;
        }
        x = x * x;

        n = n >> 1;
    }

    cout << ans << endl;
}

int main() {
    int num = 3;
    int pow = 5;
    power(num, pow);

}