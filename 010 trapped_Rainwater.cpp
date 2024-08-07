//Trapped Rainwater

//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Constraints:
// n == height.length
// 1 <= n <= 2 * 10^4
// 0 <= height[i] <= 10^5

#include<iostream>
using namespace std;

void trappedRainwater(int height[], int n) {
    int leftMax[100000];
    leftMax[0] = height[0];
    for(int i = 1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], height[i]);
    }  

    int rightMax[100000];
    rightMax[n-1] = height[n-1];
    for(int i = n-2; i>=0; i--) {
        rightMax[i] = max(rightMax[i+1], height[i]);
    } 

    int trappedWater = 0;
    for(int i = 0; i<n; i++) {
        int currWater = min(leftMax[i], rightMax[i]) - height[i];
        if(currWater > 0) {
            trappedWater += currWater;
        }
    }

    cout << "Trapped Rainwater is:" << trappedWater << endl;
}

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(height)/sizeof(int);
    trappedRainwater(height, n);
    return 0;
}
