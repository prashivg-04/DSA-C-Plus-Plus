//Longest Common Substring
//Substring is a contiguous sequence of characters within a string

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lcsTab(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0;

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int main() {
    string str1 = "abcde";
    string str2 = "abgce";

    cout << lcsTab(str1, str2) << endl;

    return 0;
}