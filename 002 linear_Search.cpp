//Linear Search

#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;
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
    int idx = linearSearch(arr,n,key);
    if(idx == -1) {
        cout << "Element not found" << endl;
        return 0;
    }
    cout << "Element found at index: " << idx << endl;
    return 0;
}
