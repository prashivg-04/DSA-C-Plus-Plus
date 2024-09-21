//Reverse a string using stack

#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseString(string str) {
    string ans = "";
    stack<char> s;
    for(int i = 0; i<str.size(); i++) {
        char ch = str[i];
        s.push(ch);
    }

    while(!s.empty()) {
        ans = ans + s.top();
        s.pop();
    }
    return ans;
}

int main() {
    string str = "prashiv";
    cout << reverseString(str) << endl;
}