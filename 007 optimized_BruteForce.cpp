//Max Subarray Sum (Brute Force) Optimized

#include<iostream>
using namespace std;

int maxSubarraySum2(int arr[], int n) {
    int maxSum = INT_MIN;
     for(int start = 0; start<n; start++) {
        int currSum = 0;
        for(int end = start; end<n; end++) {
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

int main() {
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);
    int sum = maxSubarraySum2(arr, n);
    cout << "Maximum Subarray sum is: " << sum << endl;
    return 0;
}
