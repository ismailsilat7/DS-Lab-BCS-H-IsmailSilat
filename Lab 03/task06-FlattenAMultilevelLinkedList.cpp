#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flattenHelper(Node* start, Node* end) { 
        Node* child = start->child;
        if(!child) {
            return start;
        }
        Node* prev = nullptr;
        Node* it = child;
        while(it) {
            if(it->child) {
                it = flattenHelper(it, it->next);
            }
            prev = it;
            it = it->next;
        }
        prev->next = end;
        if (end) {
            end->prev = prev;
        }
        start->next = child;
        child->prev = start;
        start->child = nullptr;
        return prev;
    }

    Node* flatten(Node* head) {
        Node* it = head;
        while(it) {
            if(it->child) {
                it = flattenHelper(it, it->next);
            }
            it = it->next;
        }
        return head;
    }
};