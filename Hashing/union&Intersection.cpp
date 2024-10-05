//Union & Intersection

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printUnion(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;

    for(int i = 0; i < arr1.size(); i++) {
        s.insert(arr1[i]);
    }
    for(int el : arr2) {
        s.insert(el);
    }

    for(int el : s) {
        cout << el << " ";
    }
    cout << endl;
}

void printIntersection(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;
    
    for(int el : arr1) {
        s.insert(el);
    }

    for(int el : arr2) {
        if(s.find(el) != s.end()) { //Found : iterator didn't reach the end 
            cout << el << " ";
            s.erase(el); //erase so element donot repeat
        }
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {7, 3, 9};
    vector<int> arr2 = {6, 3, 9, 2, 9, 4};

    printUnion(arr1, arr2);
    printIntersection(arr1, arr2);
    return 0;
}