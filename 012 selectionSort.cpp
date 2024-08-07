//Selection Sort
//pick the smallest(from unsorted part of array) & put in the beginning
//O(n^2)

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n) {
    
    for(int i = 0; i<n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j<n; j++) {
            if(arr[j] < arr[minIdx]) {      //for descending arr[j] > arr[minIdx]
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }

    printArray(arr, n);
}

int main() {
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr, n);
}