//Diameter of a Tree Optimized
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

pair<int, int> diamTree(Node* root) {   //O(n)
    if(root == NULL) {
        return make_pair(0, 0);
    }

    pair<int, int> leftInfo = diamTree(root->left);   //LD, LH
    pair<int, int> rightInfo = diamTree(root->right); //RD, RH

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));

    int finalHt = max(leftInfo.second, rightInfo.second) + 1;
    return make_pair(finalDiam, finalHt);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << diamTree(root).first << endl;
}