//Insertion Sort
//pick an element from unsorted part & place it correctly in sorted part
//O(n^2)

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i<n; i++) {
        int curr = arr[i];
        int j = i-1;
        while(curr < arr[j] && j>=0) {         //for descendind curr > arr[j]
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
    printArray(arr, n);
}

int main() {
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr)/sizeof(int);
    insertionSort(arr, n);
}