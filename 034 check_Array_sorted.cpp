//Check if array is sorted

#include<iostream>
using namespace std;

bool isSorted(int arr[], int n, int i) {
    if(i == n-1) {
        cout << "Array is Sorted" << endl;
        return true;
    }
    if(arr[i] > arr[i+1]) {
        cout << "Array is not sorted" << endl;
        return false;
    }
    
    return isSorted(arr, n, i+1);
    
}

int main() {
    int arr[] = {1,2,3,4,5};
    isSorted(arr, 5, 0);
}
