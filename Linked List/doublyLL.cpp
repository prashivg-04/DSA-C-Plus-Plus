//Doubly Linked List

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail; 

    DoublyList() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front() {
        if(head == NULL) {
            cout << "Doubly Linked List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        head->prev = NULL;

        delete temp;
    }

    void pop_back() {
        if(head == NULL) {
            cout << "Doubly Linked List is empty" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;

        tail->next = NULL;
        temp->prev = NULL;

        delete temp;
    }

    void printList(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
        return;
    }
};

int main() {
    DoublyList dbll;
    
}