//Transform to Sum Tree

#include<iostream>
#include<vector>
#include<queue>
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

void leveorder(Node* root) { 
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* currNode = Q.front();
        Q.pop();
        if(currNode == NULL) {
            cout << endl;
            if(Q.empty()) {
                break;
            }
            Q.push(NULL);
        } else {
            cout << currNode->data << " ";
            if(currNode->left != NULL) {
                Q.push(currNode->left);
            }
            if(currNode->right != NULL) {
                Q.push(currNode->right);
            }
        }
    }
}


int transform(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);

    int currOld = root->data;

    root->data = leftOld + rightOld;
    if(root->left != NULL) {
        root->data += root->left->data;
    }
    if(root->right != NULL) {
        root->data += root->right->data;
    }

    return currOld;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    transform(root);
    leveorder(root);
    
}