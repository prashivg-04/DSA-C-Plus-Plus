//Sliding Window Maximum
//Maximum of all subarrays of size K

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void slidingWindowMax(vector<int> arr, int K) {
    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < K; i++) { //first window
        pq.push(make_pair(arr[i], i));
    }
    cout << pq.top().first << " ";

    for(int i = K; i < arr.size(); i++) {
        pq.push(make_pair(arr[i], i));

        while(!pq.empty() && pq.top().second <= i-K) {  //check for any top element outside current window
            pq.pop();
        }

        cout << pq.top().first << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};

    int K = 3;

    slidingWindowMax(arr, K);
}