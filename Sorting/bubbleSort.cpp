//Bubble Sort
//large elements come to end by swapping with adjacents
//O(n^2)

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {

    for(int i = 0; i<n-1; i++) {
        for(int j = 0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {        //for descending  arr[j] < arr[j+1]
                swap(arr[j], arr[j+1]);
            }
        }
    }

    printArray(arr, n);
}

int main() {
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr, n);
}