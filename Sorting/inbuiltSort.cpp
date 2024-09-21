//Inbuilt Sort
//O(n * log n)

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4,2,6,3,7,9,4,2,6};
    int n = sizeof(arr)/sizeof(int);
    //sort(starting index, end index) 
    sort(arr,arr+n);    
    //for descending(start,end,greater<int>());   
    printArray(arr,n);
}