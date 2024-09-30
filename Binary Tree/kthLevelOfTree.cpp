//Kth Level of a Tree

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

void kthLevel(Node* root, int currLvl, int kthLvl) {
    if(root == NULL) {
        return;
    }

    if(currLvl == kthLvl) {
        cout << root->data << " ";
    }

    kthLevel(root->left, currLvl+1, kthLvl);
    kthLevel(root->right, currLvl+1, kthLvl);

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);
    
    kthLevel(root, 1, 3);
    cout << endl;
}