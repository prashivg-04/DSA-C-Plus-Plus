//Creating Segement Trees 

#include<iostream>
#include<vector>
using namespace std;

class SegementTrees {
    vector<int> tree;
    int n;

    void buildtree(vector<int> &arr, int start, int end, int node) {
        if(start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end-start)/2;

        buildtree(arr, start, mid, 2*node +1);
        buildtree(arr, mid+1, end, 2*node +2);

        tree[node] = tree[2*node +1] + tree[2*node +2];
    }

    int rangeSum(int qi, int qj, int si, int sj, int node) {

        if(qj < si || qi > sj) { //no overlap
            return 0;
        }

        if(si >= qi && sj <= qj) {  //complete overlap
            return tree[node];
        } 

        int mid = si + (sj-si)/2;
        return rangeSum(qi, qj, si, mid, 2*node +1) + rangeSum(qi, qj, mid+1, sj, 2*node +2);
    }

    void updateUtil(int idx, int newVal, int start, int end, int node) {
        if(start == end) {
            tree[node] = newVal;
            return;
        }

        int mid = start + (end-start)/2;

        if(idx >= start && idx <= mid) {
            updateUtil(idx, newVal, start, mid, 2*node +1);
        } else {
            updateUtil(idx, newVal, mid+1, end, 2*node +2);
        }

        tree[node] = tree[2*node +1] + tree[2*node +2];
    }

public:
    SegementTrees(vector<int> arr) {
        n = arr.size();
        tree.resize(4*n);
        buildtree(arr, 0, n-1, 0);
    }

    void printTree() {
        for(int el : tree) {
            cout << el << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        return rangeSum(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int val) {
        updateUtil(idx, val, 0, n-1, 0);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    SegementTrees st(arr);

    cout << st.rangeQuery(0, 3) << endl;

    st.updateQuery(1, 3);

    cout << st.rangeQuery(0, 3) << endl;


    return 0;
}

