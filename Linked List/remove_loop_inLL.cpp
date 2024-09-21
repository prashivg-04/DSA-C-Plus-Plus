//Remove a Cycle/Loop in a Linked List

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
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
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
};

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void removeCycle(Node* head) {
    Node* slow = head;
    Node* fast = slow;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cout << "Cycle Exits" << endl;
            isCycle = true;
            break;
        }
    }

    if(!isCycle) {
        cout << "Cycle doesn't exits\n";
        return;
    }

    slow = head;
    
    if(slow == fast) { //Special case when tail->head

        while(fast->next != head) {
            fast = fast->next;
        }
        fast->next = NULL;

    } else {

        Node* prev = NULL;

        while(slow != fast) {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }

        prev->next = NULL;
    }
}


int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.tail->next = ll.head;

    removeCycle(ll.head);
    printList(ll.head);

}