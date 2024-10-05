//Nearby Cars

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Car {
public:
    int distSq;
    int idx;

    Car(int distSq, int idx) {
        this->distSq = distSq;
        this->idx = idx;
    }

    bool operator < (const Car &obj) const {
        return this->distSq > obj.distSq; //min heap
    }
};

void nearbyCars(vector<pair<int, int>> pos, int K) {
    vector<Car> cars;
    for(int i = 0; i < pos.size(); i++) { //O(n)
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(distSq, i));
    }

    priority_queue<Car> pq(cars.begin(), cars.end()); //O(n)  //pushing objects in pq

    for(int i = 0; i < K; i++) {  //O(K*logn + n)
        cout << "Car: " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<pair<int, int>> pos;
    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));

    int K = 2;

    nearbyCars(pos, K);

}