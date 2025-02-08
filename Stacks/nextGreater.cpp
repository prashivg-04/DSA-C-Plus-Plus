//Next Greater Element
//First greater element that is to the right

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void nextGreater(vector<int> arr, vector<int>& ans) {
    stack<int> s;
    int n = arr.size();
    ans[n-1] = -1;
    s.push(arr[n-1]);

    for(int i = n-2; i >= 0; i--) {
        while(!s.empty() && arr[i] >= s.top()) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    for(int el : ans) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans(arr.size());
    nextGreater(arr ,ans);
    return 0;
}