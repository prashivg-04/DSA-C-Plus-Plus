//Pair Sum
//2 Pointer Approach

#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> vec1, int key) {
    int start = 0, end = vec1.size() - 1;
    while(start < end) {
        int currSum = vec1[start] + vec1[end];
        if(currSum == key) {
            vector<int> vec2;
            vec2.push_back(start);
            vec2.push_back(end);
            return vec2;
        } else if(currSum > key) {
            end--;
        } else {
            start++;
        }
    }

    return vec1;
}

int main() {
    vector<int> vec = {2,7,11,15};
    int target = 9;
    vector<int> ans = pairSum(vec, target);
    cout << "(" << ans[0] << "," << ans[1] << ")" << endl;
    return 0;

}
