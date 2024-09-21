//Job sequencing Problem 
//Maximize the total profit if only one job can be secheduled at a time
//Assume time to complete one job is 1
//Pair (Deadline, Profit)

#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> jobs, int n) {
    //sort on the basis of profit

    sort(jobs.begin(), jobs.end(), compare);

    int totProfit = jobs[0].second;
    int safeDeadline = 2;

    for(int i = 1; i < n; i++) {
        if(jobs[i].first >= safeDeadline) {
            totProfit += jobs[i].second;
            safeDeadline++;
        }
    }

    cout << "Maximum total profit that can be obtained: " << totProfit << endl;
    return totProfit;
}

int main() {
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    maxProfit(jobs, n);
}