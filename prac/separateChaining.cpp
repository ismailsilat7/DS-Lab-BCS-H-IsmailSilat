#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int data;
    Node* next;

    Node(int k, int d = 0) {
        key = k;
        data = d;
        next = nullptr;
    }
};

class HashTable {
public:
    Node** table;
    int c;

    HashTable(int c) : c(c) {
        table = new Node*[c];
        for(int i = 0; i < c; i++) {
            table[i] = nullptr;
        }
    }

    int hash(int k) {
        return k % c;
    }

    void insert(int key, int data = 0) {
        int index = hash(key);
        Node* p = new Node(key, data);

        p->next = table[index];
        table[index] = p;
    }

    void deleteNode(int key) {
        int index = hash(key);

        if(!table[index]) {
            cout << "No value with key " << key << " found in hash table" << endl;
            return;
        }

        Node* curr = table[index];
        Node* prev = nullptr;

        while(curr) {
            if(curr->key == key) {

                if(prev == nullptr)
                    table[index] = curr->next;
                else
                    prev->next = curr->next;

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        cout << "No value with key " << key << " found in hash table" << endl;
    }
};
