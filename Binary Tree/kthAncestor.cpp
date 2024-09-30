//Kth Ancestor of node

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

static int i = -1;
Node* buildTree(vector<int> nodes) {
    i++;

    if(nodes[i] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[i]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int KthAncestor(Node* root, int node, int k) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == node) {
        return 0;
    }

    int leftDist = KthAncestor(root->left, node, k);
    int rightDist = KthAncestor(root->right, node, k);

    if(leftDist == -1 && rightDist == -1) {
        return -1;
    }

    int validValue = (leftDist == -1) ? rightDist : leftDist;
    if(validValue+1 == k) {
        cout << root->data << endl;
    }
    return validValue+1;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    KthAncestor(root, 5, 2);
    
}