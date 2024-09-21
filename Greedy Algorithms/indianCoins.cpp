//Indian coins
//We are given an infinite supply of denominations [1, 2, 5, 10, 20, 50, 100, 500, 2000]
//Find min no. of coins to make a change of value V

//V = 121
//ans = 3 (100 + 20 + 1)

#include<iostream>
#include<vector>
using namespace std;

int getMinChange(vector<int> coins, int V) {
    int count = 0;

    for(int i = coins.size() - 1; i >= 0 && V > 0; i--) {
        if(V >= coins[i]) {
            int num = V/coins[i];
            count += num;
            V = V%coins[i];
        }
    }

    cout << "Minimum coins for change required: " << count << endl;
    return count;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int V = 1099; 

    getMinChange(coins, V);
}