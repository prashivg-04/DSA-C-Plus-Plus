//Largest Subarray with Sum 0

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int largestSubWithSum0(vector<int> arr) {
    unordered_map<int, int> m;  //(sum, idx)
    int sum = 0;
    int ans = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if(m.count(sum)) {
            int currLen = i - m[sum];
            ans = max(ans, currLen);
        } else {
            m[sum] = i;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};

    cout << largestSubWithSum0(arr) << endl;

    return 0;
}