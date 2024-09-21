//Reverse a Stack

#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}

void pushAtBottom(stack<int> &s, int val) {
    if(s.empty()) {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
    return;
}

void reverse(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}

int main() {
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);
    cout << "\n\n";
    reverse(s);
    printStack(s);
}