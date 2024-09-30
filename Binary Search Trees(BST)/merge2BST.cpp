//Merge 2 BST

#include<iostream>
#include<vector>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

void getInorderSeq(Node* root, vector<int> &nodes) {
    if(root == NULL) {
        return;
    }

    getInorderSeq(root->left, nodes);
    nodes.push_back(root->data);
    getInorderSeq(root->right, nodes);
}

Node* BSTfromSortedVec(vector<int> nodes, int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = st + (end - st)/2;
    Node* curr = new Node(nodes[mid]);

    curr->left = BSTfromSortedVec(nodes, st, mid-1);
    curr->right = BSTfromSortedVec(nodes, mid+1, end);

    return curr;
}

Node* mergeBST(Node* root1, Node* root2) {
    vector<int> nodes1;
    vector<int> nodes2;

    getInorderSeq(root1, nodes1);
    getInorderSeq(root2, nodes2);

    vector<int> finNodes;

    int i = 0, j = 0;
    while(i < nodes1.size() && j < nodes2.size()) {
        if(nodes1[i] < nodes2[j]) {
            finNodes.push_back(nodes1[i++]);
        } else {
            finNodes.push_back(nodes2[j++]);
        }
    }

    while(i < nodes1.size()) {
        finNodes.push_back(nodes1[i++]);
    }

    while(j < nodes2.size()) {
        finNodes.push_back(nodes2[j++]);
    }

    return BSTfromSortedVec(finNodes, 0, finNodes.size() - 1);
}

int main() {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = mergeBST(root1, root2);
    preorder(root);
    cout << endl;
}