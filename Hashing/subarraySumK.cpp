//Subarray Sum equals K

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int subarrayCountWithK(vector<int> arr, int K) {   
    unordered_map<int, int> m;    //(sum, count) 
    m[0] = 1; 
    int ans = 0;
    int sum = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if(m.count(sum - K)) {
            ans += m[sum-K];
        }

        if(m.count(sum)) {
            m[sum]++;
        } else {
            m[sum] = 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int K = -10;

    cout << subarrayCountWithK(arr, K) << endl;

    return 0;
}