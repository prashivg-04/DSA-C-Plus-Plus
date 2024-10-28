//Target Sum Subset
//Find if there is a subset of numbers which give sum equal to target

#include<iostream>
#include<vector>
using namespace std;

int targetSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    for(int i = 1; i < n+1; i++) {
        for(int j = 0; j < target+1; j++) {
            if(nums[i-1] <= j) {
                dp[i][j]= max(dp[i-1][j-nums[i-1]] + nums[i-1], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target] == target;
}

int main() {
    vector<int> nums = {4, 2, 1, 7, 3};
    int target = 10;

    cout << targetSum(nums, target) << endl;
    return 0;
}