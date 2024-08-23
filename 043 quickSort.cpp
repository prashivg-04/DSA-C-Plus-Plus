//Quick Sort

#include<iostream>
using namespace std;

int findPiv(int arr[], int si, int ei) {
    int i = si - 1;
    int j = si;

    int pivot = arr[ei];

    while(j < ei) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }

    i++;
    swap(arr[i], arr[ei]);
    return i;
}

void quickSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }

    int pivotIdx = findPiv(arr, si, ei);

    quickSort(arr, si, pivotIdx-1);
    quickSort(arr, pivotIdx+1, ei);
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {6, 3, 7, 5, 2, 4};
    int n = 6;

    quickSort(arr, 0, n-1);
    printArray(arr, n);
}