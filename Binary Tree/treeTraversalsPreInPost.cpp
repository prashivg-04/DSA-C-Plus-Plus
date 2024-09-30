//Tree Traversals:

//Preorder Traversals: Root -> Left Subtree -> Right Subtree
//Inorder Traversals: Left Subtree -> Root -> Right Subtree
//Postorder Traversals: Left Subtree -> Right Subtree -> Root

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

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left); //call for left subtree

    preorder(root->right); //call for right subtree
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left); //call for left subtree

    cout << root->data << " ";

    inorder(root->right); //call for right subtree
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    cout << root->data << " ";
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
}