//First Occurence

#include<iostream>
#include<vector>
using namespace std;

int firstOccur(vector<int> vec, int i, int key) {
    if(i == vec.size()) {
        return -1;
    }
    if(vec[i] == key) {
        return i;
    } 
    return firstOccur(vec, i+1, key);
}

int main() {
    vector<int> arr = {1,2,3,3,3,4};
    cout << firstOccur(arr, 0, 3) << endl;
    return 0;
}