//Heap Sort

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(int i, vector<int> &arr, int n) {
    int leftChild = (2*i) +1;
    int rightChild = (2*i) +2;

    int maxIdx = i;
    if(leftChild < n && arr[leftChild] > arr[maxIdx]) {
        maxIdx = leftChild;
    }

    if(rightChild < n && arr[rightChild] > arr[maxIdx]) {
        maxIdx = rightChild;
    }

    if(maxIdx != i) {
        swap(arr[i], arr[maxIdx]);
        heapify(maxIdx, arr, n);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();

    for(int i = n/2 -1; i >= 0; i--) {  //creating max heap
        heapify(i, arr, n);
    }

    for(int i = n-1; i >= 1; i--) {  //push the top element at the end
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};  //for descending order create min heap change the heapify function

    heapSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
