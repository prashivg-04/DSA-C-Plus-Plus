//Majority Element
//Find the element that appear more than n/3 times

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void majorityElement(vector<int> nums) {
    unordered_map<int, int> m;  //(element, frequency)

    for(int i = 0; i < nums.size(); i++) {
        if(m.count(nums[i])) {
            m[nums[i]]++;
        } else {
            m[nums[i]] = 1;
        }
    } 

    for(pair<int, int> it : m) {
        if(it.second > nums.size()/3) {
            cout << it.first << " ";
        }
    }

    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    vector<int> nums2 = {1, 2};

    majorityElement(nums2);
    return 0;
}