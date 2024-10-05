//Implementation of Heap

#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Heap {  //Max Heap
    vector<int> vec;

public:
    void push(int data) {
        //step 1: add element in vector at the end
        vec.push_back(data);

        //step 2: fix heap
        int x = vec.size() -1;
        int parIdx = (x-1)/2;

        while(parIdx >= 0 && vec[x] > vec[parIdx]) {   //vec[x] < vec[parIdx]   for min heap
            swap(vec[x], vec[parIdx]);
            x = parIdx;
            parIdx = (x-1)/2;
        }
    }
    
    void heapify(int i) {
        if(i >= vec.size()) {
            return;
        }
        int leftChild = (2*i) +1;
        int rightChild = (2*i) +2;

        int maxIdx = i;
        if(leftChild < vec.size() && vec[leftChild] > vec[maxIdx]) {  //vec[leftChild] < vec[maxIdx]  for min heap
            maxIdx = leftChild;
        }

        if(rightChild < vec.size() && vec[rightChild] > vec[maxIdx]) {  //vec[rightChild] < vec[maxIdx]  for min heap
            maxIdx = rightChild;
        }

        swap(vec[i], vec[maxIdx]);
        if(maxIdx != i) {
            heapify(maxIdx);
        }
        // return;
    }

    void pop() {
        //step 1: swap first element with last
        swap(vec[0], vec[vec.size() -1]);

        //step 2: remove last element
        vec.pop_back();

        //step 2: fix heap
        heapify(0);
    }

    int top() {
        return vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }
};

int main() {
    Heap hp;

    hp.push(3);
    hp.push(4);
    hp.push(5);
    hp.push(9);

    while(!hp.empty()) {
        cout << hp.top() << endl;
        hp.pop();
    }
}