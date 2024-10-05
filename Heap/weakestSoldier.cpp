//Weakest Soldier
//For MxN matrix, a row i is weaker than a row j if one of the following is true:
// - The number of soldiers in a row i is less than the number of soldiers in row j
// - Both rows have same number of soldiers and i < j
//Also given that soldiers are always in front then come civilians
//Find K weakest rows

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row {
public:
    int count;
    int idx;

    Row(int count, int idx) {
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const {  //min heap
        if(this->count == obj.count) {
            return this->idx > obj.idx;
        }
        return this->count > obj.count;
    }
};

void weakestSoldier(vector<vector<int>> matrix, int K) {
    vector<Row> rows;
    
    for(int i = 0; i < matrix.size(); i++) {
        int count = 0;
        for(int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++) {
            count += 1;
        }
        rows.push_back(Row(count, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i = 0; i < K; i++) {
        cout << "Row: " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                  {1, 1, 1, 1},
                                  {1, 0, 0, 0},
                                  {1, 0, 0, 0}};

    int K = 2;

    weakestSoldier(matrix, K);
}