//Max Subarray Sum (Brute Force)

#include<iostream>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxSum = INT_MIN;
     for(int start = 0; start<n; start++) {
        for(int end = start; end<n; end++) {
            int currSum = 0;
            for(int i = start; i<=end; i++){
                currSum += arr[i];
            }
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

int main() {
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);
    int sum = maxSubarraySum(arr, n);
    cout << "Maximum Subarray sum is: " << sum << endl;
    return 0;
}