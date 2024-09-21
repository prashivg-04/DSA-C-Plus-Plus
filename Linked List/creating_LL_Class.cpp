//Linked List

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL; 
    }

    ~Node() {
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        if(head != NULL) {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert(int val, int pos) {
        Node* newNode = new Node(val);

        Node* temp = head;

        for(int i = 0; i < pos-1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if(head == NULL) {
            cout << "Linked List is empty\n";
        }
        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        if(head == NULL) {
            cout << "Linked List is empty\n";
        }

        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int searchItr(int key) {
        Node* temp = head;
        int idx = 0;
        while(temp != NULL) {
            if(temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }

        return -1;
    }

    int helper(Node* head, int key) {   //This is not the orignal head pointer but a copy
        if(head == NULL) {
            return -1;
        }

        if(head->data == key) {
            return 0;
        }

        int idx = helper(head->next, key);
        if(idx == -1) {
            return -1;
        }

        return idx+1;
    }

    int searchRec(int key) {
        return helper(head, key);
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL) {
            Node* nxt = curr->next;
            curr->next = prev;

            //updations for next iterations
            prev = curr;
            curr = nxt;
        }

        head = prev;
    }

    int getSize() {
        Node* temp = head;

        int sz = 0;
        while(temp != NULL) {
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n) {
        int size = getSize();

        Node* temp = head;
        for(int i = 1; i<size-n; i++) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;

        temp->next = temp->next->next;

        toDelete->next = NULL;
        delete toDelete;
    }
};

int main() {
    List ll; 
    
}