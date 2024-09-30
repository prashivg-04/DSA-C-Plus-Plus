//Top View of a Tree

#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(Node* root) {
    queue<pair<Node*, int>> Q;   //Node* ,HD(Horizontal Distance)
    map<int, int> m;
    Q.push(make_pair(root, 0));

    while(!Q.empty()) {
        pair<Node*, int> currPair = Q.front();
        Q.pop();
        Node* currNode = currPair.first;
        int currHD = currPair.second;

        if(!m.count(currHD)) {
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL) {
            Q.push(make_pair(currNode->left, currHD-1));
        }
        if(currNode->right != NULL) {
            Q.push(make_pair(currNode->right, currHD+1));
        }
    }

    for(auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    topView(root);  
}