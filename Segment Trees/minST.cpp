//Min Segment Tree

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

        tree[node] = min(tree[2*node +1], tree[2*node +2]);
    }

    int rangeMin(int qi, int qj, int si, int sj, int node) {

        if(qj < si || qi > sj) { //no overlap
            return INT_MAX;
        }

        if(si >= qi && sj <= qj) {  //complete overlap
            return tree[node];
        } 

        int mid = si + (sj-si)/2;
        return min(rangeMin(qi, qj, si, mid, 2*node +1), rangeMin(qi, qj, mid+1, sj, 2*node +2));
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

        tree[node] = min(tree[2*node +1], tree[2*node +2]);
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
        return rangeMin(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int val) {
        updateUtil(idx, val, 0, n-1, 0);
    }
};

int main() {
    vector<int> arr = {6, 8, -1, 2, 17, 1, 3, 2, 4};

    SegementTrees st(arr);

    st.printTree();

    cout << st.rangeQuery(2, 5) << endl;

    st.updateQuery(2, 11);

    st.printTree();
    cout << st.rangeQuery(2, 5) << endl;


    return 0;
}

