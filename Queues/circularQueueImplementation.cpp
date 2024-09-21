//Circular Queue Implementation using Array

#include<iostream>
using namespace std;

class Queue {
    int* arr;

    int currSize;
    int capacity;

    int f;
    int r;

public: 

    Queue(int size) {
        arr = new int[size];
        capacity = size;
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int val) {
        if(currSize == capacity) {
            cout << "Queue is FULL" << endl;
            return;
        }
        r = (r + 1) % capacity;
        arr[r] = val;
        currSize++;
    }

    void pop() {
        if(empty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        f = (f + 1) % capacity;
        currSize--;
    }

    int front() {
        if(empty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }
};

int main() {
    Queue q(3);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.push(5);
    cout << q.front() << endl;
    
}