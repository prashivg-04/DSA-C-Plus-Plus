//Activity Selection 
//Select maximum no. of activities that can be performed by a single person
//(A person can work on one activity at a time)

#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int maxActivities(vector<int> start, vector<int> end) {
    //sort on the basis of end time

    vector<pair<int, int>> activities(start.size(), make_pair(0, 0));

    for(int i = 0; i < start.size(); i++) {
        activities[i] = make_pair(start[i], end[i]);
    }

    sort(activities.begin(), activities.end(), compare);

    //select the first activity
    int currEnd = activities[0].second;
    int count = 1;

    for(int i = 1; i < end.size(); i++) {
        if(activities[i].first >= currEnd) {   //condition to check overlapping
            currEnd = activities[i].second;
            count++;
        }
    }

    cout << "Maximum number of activities that can be selected: " << count << endl;
    return count;
}

int main() {
    vector<int> start = {0, 1, 2}; //consider this as start time for activity
    vector<int> end = {9, 2, 4};  //consider this as end time for activity

    maxActivities(start, end);
}