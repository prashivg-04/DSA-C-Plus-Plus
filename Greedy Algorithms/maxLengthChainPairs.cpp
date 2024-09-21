//Max Lenght Chain of Pairs
//A pair (c, d) can come after a pair (a, b) iff b < c
//Find the longest chain which can be formed from a given set of pairs

#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int maxChainLength(vector<pair<int, int>> pairs, int n) {
    //sort on the basis of second element of each pair
    sort(pairs.begin(), pairs.end(), compare);

    //Selecting first pair
    int currSmall = pairs[0].second;
    int count = 1;

    for(int i = 1; i < n; i++) {
        if(pairs[i].first >= currSmall) {
            count++;
            currSmall = pairs[i].second;
        }
    }

    cout << "Max Longest chain: " << count << endl;
    return count;
}

int main() {
    int n = 5;
    vector<pair<int, int>> pairs(n , make_pair(0, 0));
    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50 ,90);

    maxChainLength(pairs, n);

}