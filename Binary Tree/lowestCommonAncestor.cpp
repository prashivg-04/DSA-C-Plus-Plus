//Lowest Common Ancestor (Approach 1)

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

bool findPath(vector<int> &path, Node* root, int n) {
    if(root == NULL) {
        return false;
    }

    path.push_back(root->data);
    if(root->data == n) {
        return true;
    }

    bool isLeft = findPath(path, root->left, n);
    bool isRight = findPath(path, root->right, n);

    if(isLeft || isRight) {
        return true;
    }

    path.pop_back();
    return false;
}

int lca(Node* root, int n1, int n2) {  // TC = O(n), SC = O(n)
    vector<int> path1;
    vector<int>path2;

    findPath(path1, root, n1);
    findPath(path2, root, n2);

    int lca = -1;
    for(int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
        if(path1[i] != path2[j]) {
            return lca;
        }
        lca = path1[i];
    }

    return lca;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << lca(root, 2, 5) << endl;
    
}