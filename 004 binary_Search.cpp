//Binary Search

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;
    while(start<=end) {
        int mid = (start+end)/2;
        if(arr[mid] == key) {
            return mid;
        } 
        if(arr[mid] > key) {
            end = mid-1;
        } else if (arr[mid] < key) {
            start = mid+1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cout << "Enter Element to Search: " << endl;
    cin >> key;
    int idx = binarySearch(arr,n,key);
    if(idx == -1) {
        cout << "Element not found" << endl;
        return 0;
    }
    cout << "Element found at index: " << idx << endl;
    return 0;
}
