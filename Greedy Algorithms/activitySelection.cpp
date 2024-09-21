//Activity Selection 
//Select maximum no. of activities that can be performed by a single person
//Input is sorted on basis of end[]
//(A person can work on one activity at a time)

#include<iostream>
#include<vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end) {
    //sort on the basis of end time
    //already sorted on the basis of end time

    //select the first activity
    int currEnd = end[0];
    int count = 1;

    for(int i = 1; i < end.size(); i++) {
        if(start[i] >= currEnd) {   //condition to check overlapping
            currEnd = end[i];
            count++;
        }
    }

    cout << "Maximum number of activities that can be selected: " << count << endl;
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5}; //consider this as start time for activity
    vector<int> end = {2, 4, 6, 7, 9, 9};   //consider this as end time for activity

    maxActivities(start, end);
}