//Fibonacci series using Dynamic Programming

#include<iostream>
#include<vector>
using namespace std;

int fibMemo(int n, vector<int> &dp) {//O(n)         //Memoization  Top to Down
    if(n == 0 || n == 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
    return dp[n];  
}

int fibTab(int n, vector<int> &dp) { //O(n)       //Tabulation  Bottom to Up
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n = 6;
    vector<int> dp(n+1, -1);
    cout << fibTab(n, dp) << endl;
}