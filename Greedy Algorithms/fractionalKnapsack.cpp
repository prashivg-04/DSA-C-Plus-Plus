//Fractional Knapsack
//Put items in the knapsack to get the maximum total value in the knapsack

#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first;
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int W) {
    int n = val.size();
    //Sort on the basis of ratio (whose rate is max per unit)

    vector<pair<double, int>> ratio(n, make_pair(0.0, 0)); //(ration(val/wt), idx)

    for(int i = 0; i < n; i++) {
        double rate = val[i]/(double)wt[i];
        ratio[i] = make_pair(rate, i);
    }
    
    sort(ratio.begin(), ratio.end(), compare);


    double count = 0;
    for(int i = 0; i < val.size() && W > 0; i++) {
        int idx = ratio[i].second;
        if(W >= wt[idx]) {
            count += val[idx];
            W -= wt[idx];
        } else {
            count += ratio[i].first * W;
            W = 0;
        }
    }

    cout << "Maximum total value: " << count << endl;
    return count;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    fractionalKnapsack(val, wt, W);
}