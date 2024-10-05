//Count Distinct

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int countDistinct(vector<int> arr) {
    unordered_set<int> s;

    for(int i = 0; i < arr.size(); i++) {
        s.insert(arr[i]);
    }

    // for(int el : s) {   //to print distinct
    //     cout << el << " ";
    // }
    // cout << endl;

    return s.size();
}

int main() {
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};

    cout << countDistinct(arr) << endl;
    return 0;
}