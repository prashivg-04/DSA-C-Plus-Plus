//Friends Pairing Problem

#include<iostream>
using namespace std;

int friendsPairing(int n) {
    if(n == 1 || n == 2) {
        return n;
    }

    //Alone
    int ans1 = friendsPairing(n-1);

    //Pair with someone: A has n-1 options to make pair with
    int ans2 = (n-1) * friendsPairing(n-2);

    return ans1 + ans2;
}

int main() {
    cout << friendsPairing(3) << endl;
}
