//Diameter of a Tree
//No. of Nodes in the longest path between 2 leaves

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

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftHt = height(root->left);

    int rightHt = height(root->right);

    return max(leftHt, rightHt) + 1;
}

int diamTree(Node* root) { //O(n^2)
    if(root == NULL) {
        return 0;
    }
    int currDiam = height(root->left) + height(root->right) + 1;

    int leftDiam = diamTree(root->left);
    int rightDiam = diamTree(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << diamTree(root) << endl;
}