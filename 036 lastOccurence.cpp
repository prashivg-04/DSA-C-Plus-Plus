//Last Occurence

#include<iostream>
#include<vector>
using namespace std;

int lastOccur(vector<int> vec, int i, int key) {
    if(i == -1) {
        return -1;
    }
    if(vec[i] == key) {
        return i;
    }
    return lastOccur(vec, i-1, key);
}

int main() {
    vector<int> arr = {1,2,3,3,3,4};
    cout << lastOccur(arr, arr.size(), 3) << endl;
}
