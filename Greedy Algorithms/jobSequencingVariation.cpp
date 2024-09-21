//Job sequencing Problem 
//Maximize the total profit if only one job can be secheduled at a time
//Also print the job number selected
//Assume time to complete one job is 1
//Pair (Deadline, Profit)

#include<iostream>
#include<vector>
using namespace std;

class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int deadline, int profit, int idx) {
        this->deadline = deadline;
        this->profit = profit;
        this->idx = idx;
    }
};

int maxProfit(vector<pair<int, int>> pairs, int n) {
    //create class which also include index

    vector<Job> jobs;

    for(int i = 0; i < n; i++) {
        jobs.emplace_back(pairs[i].first, pairs[i].second, i);
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){   //lambda function
        return a.profit > b.profit;
    });

    cout << "Selecting Job " << jobs[0].idx << endl;
    int totProfit = jobs[0].profit;
    int safeDeadline = 2;

    for(int i = 1; i < n; i++) {
        if(jobs[i].deadline >= safeDeadline) {
            cout << "Selecting Job " << jobs[i].idx << endl;
            totProfit += jobs[i].profit;
            safeDeadline++;
        }
    }

    cout << "Maximum total profit that can be obtained: " << totProfit << endl;
    return totProfit;
}

int main() {
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);  //Job 0
    jobs[1] = make_pair(1, 10);  //Job 1
    jobs[2] = make_pair(1, 40);  //Job 2
    jobs[3] = make_pair(1, 30);  //Job 3

    //first -> deadline, second -> profit

    maxProfit(jobs, n);
}