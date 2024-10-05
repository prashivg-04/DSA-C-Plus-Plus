//Itinerary from Tickets
//Plane tickets Pair<from, to>

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printItinerary(unordered_map<string, string> tickets) {
    unordered_set<string> to;

    for(pair<string, string> tckt : tickets) {  //inserting to loactions
        to.insert(tckt.second);
    } 

    string start = "";

    for(pair<string, string> ticket : tickets) {  //matcing with from locations
        if(to.find(ticket.first) == to.end()) {  
            start = ticket.first;                  //not in the to loactions but only in from loaction
        }
    }

    cout << start << " -> ";
    while(tickets.count(start)) {
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }
    cout << "End Destination" << endl;
}

int main() {
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);

    return 0; 
}