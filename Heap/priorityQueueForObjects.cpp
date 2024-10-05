//Priority Queue for Objects/Pairs

#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const {      // operator overloading
        return  this->name > obj.name;                // < in case of max heap and > in case of min heap 
    }
};

struct ComparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {      // operator overloading
        return p1.second < p2.second;       //< for max heap, > for min heap
    }
};

int main() {
    priority_queue<Student> pq; //default: max heap on first 
    //for simple priority_queue we can add <int, vector<int>, greater<int>> for min heap
    
    // priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;   //default: max heap on "first"

    pq.push(Student("ram", 92));
    pq.push(Student("prashiv", 82));
    pq.push(Student("abhishek", 95));

    while(!pq.empty()) {
        cout << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }
}