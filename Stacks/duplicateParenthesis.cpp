//Duplicate Parenthesis
//True - if string is duplicate
//False - if not
//Given: A valid string

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s;

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if(ch != ')') {
            s.push(ch);
        } else {
            if(s.top() == '(') {
                return true;
            }

            while(s.top() != '(') {
                s.pop();
            }
            s.pop(); 
        }
    }

    return false;
}

int main() {
    string str = "((a+b))";
    cout << isDuplicate(str) << endl;
    return 0;
}