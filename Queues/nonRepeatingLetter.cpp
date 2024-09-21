//Non Repeating Letter

#include<iostream>
#include<string>
#include<queue>
using namespace std;

void nonrepeat(string str) {
    int freq[26] = {0};
    queue<char> q;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        q.push(ch);
        freq[ch - 'a']++;
        
        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if(q.empty()) {
            cout << " -1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string str = "aabccxb";
    nonrepeat(str);
}