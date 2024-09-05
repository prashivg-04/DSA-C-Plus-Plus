//Remove Duplicate String

#include<iostream>
#include<string>
using namespace std;

void removesDuplicate(string str, int i, string ans, bool map[]) {
    if(i == str.size()) {
        cout << ans << endl;
        return;
    }

    int idx = str[i] - 'a';
    if(map[idx] == false) {
        map[idx] = true;
        removesDuplicate(str, i+1, ans + str[i], map);
    } else {
        removesDuplicate(str, i+1, ans, map);
    }
    
}

int main() {
    string str = "apnnacollege";
    bool map[26] = {false};
    string ans = "";
    removesDuplicate(str, 0, ans, map);
}
