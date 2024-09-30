//Sorted Array to BST

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

Node* buildBSTfromSorted(int arr[], int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = st + (end - st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTfromSorted(arr, st, mid-1);
    curr->right = buildBSTfromSorted(arr, mid+1, end);

    return curr;
}

int main() {
    int arr[7] = {3, 4, 5, 6, 7, 8, 9};

    Node* root = buildBSTfromSorted(arr, 0, 6);

    preorder(root);
    cout << endl;
}

