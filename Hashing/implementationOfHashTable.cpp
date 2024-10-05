//Implementation of HashTable

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public: 
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int hashfunction(string key) {
        int idx = 0;
        for(int i = 0; i < key.size(); i++) {
            idx = idx + (key[i] * key[i])%totSize;
        }

        return idx%totSize;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = totSize*2;
        currSize = 0;
        table = new Node*[totSize];

        for(int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }

        for(int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while(temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int totSize = 5) {
        this->totSize = totSize;
        currSize = 0;

        table = new Node*[totSize];

        for(int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = hashfunction(key);
        Node* currNode = new Node(key, val);

        currNode->next = table[idx];
        table[idx] = currNode;

        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda > 1) {
            rehash();
        }
    }

    void remove(string key) {
        int idx = hashfunction(key);
        Node* curr = table[idx];
        Node* prev = curr;

        while(curr != NULL) {
            if(curr->key == key) {  
                // Node* temp = curr;
                if(prev == curr) {
                    table[idx] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                // delete temp;
                // currSize--;
                break;
            }

            prev = curr;
            curr = curr->next;
        }

    }

    bool exists(string key) {
        int idx = hashfunction(key);
        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key) {
        int idx = hashfunction(key);
        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp->key == key) {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    void printTable() {
        for(int i = 0; i < totSize; i++) {
            cout << "idx " << i << " -> ";
            Node* temp = table[i];
            while(temp != NULL) {
                cout << "(" << temp->key << ", " << temp->val << ") -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

};

int main() {
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("UK", 100);
    ht.insert("USA", 60);
    ht.insert("China", 130);
    ht.insert("Nepal", 20);
    // ht.insert("Russia", 150);
    // ht.insert("Germany", 100);
    // ht.insert("UAE", 60);
    // ht.insert("Canada", 130);
    // ht.insert("Brazil", 20);

    ht.printTable();
    
}