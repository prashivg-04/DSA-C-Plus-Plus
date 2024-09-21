//Counting Sort 
//use a frequency count of elements from min to max
//useful if range is small and numbers are postive
//O(n + range)

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingSort(int arr[], int n) {
    int freq[100] = {0};

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for(int i = 0; i<n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    for(int i = 0; i<n; i++) {
        freq[arr[i]]++;
    }

    for(int i = minVal, j = 0; i<=maxVal; i++) {     //descending: for(int i = maxVal, j = 0; i>=minVal; i--)
        while(freq[i] > 0) {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }

    printArray(arr, n);

}

int main() {
    int arr[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(arr)/sizeof(int);
    countingSort(arr, n);
}