//Climbing Stairs
//Count the Ways to reach the nth stair. A person can climb 1 or 2 stairs at a time

#include<iostream>
#include<vector>
using namespace std;

int countWaysRec(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    return countWaysRec(n-1) + countWaysRec(n-2);
}

int countWaysMemo(int n, vector<int> &dp) {
    if(n == 0 || n == 1) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = countWaysMemo(n-1, dp) + countWaysMemo(n-2, dp);
    return dp[n];
}

int countWaysTab(int n, vector<int> &dp) {
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n = 4;
    vector<int> dp(n+1, -1);
    cout << countWaysTab(n, dp) << endl;
}