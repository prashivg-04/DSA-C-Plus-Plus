//Check for Power of 2

#include<iostream>
using namespace std;

bool checkPower(int n) {
    if(!(n & n-1)) {
        cout << "Number is power of 2" << endl;
        return true;
    } else {
        cout << "Number is not power of 2" << endl;
        return false;
    }
}

int main() {
    int num = 7;
    checkPower(num);
}