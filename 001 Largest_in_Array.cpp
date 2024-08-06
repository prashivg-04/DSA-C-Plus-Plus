//Find Largest in the Array.

#include<iostream>
using namespace std;

int largestInArray(int nums[], int n) {
    int largest = INT_MIN;
    for(int i = 0; i<n; i++) {
        if(nums[i] > largest) {
            largest = nums[i];
        }
    }
    return largest;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(int);
    int largest = largestInArray(arr, n);
    cout << "Largest in the Array: " << largest << endl;
    return 0;
}