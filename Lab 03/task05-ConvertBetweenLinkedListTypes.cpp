#include <bits/stdc++.h>
using namespace std;

// Leetcode-like starter template

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct DoublyListNode {
    int val;
    DoublyListNode* prev;
    DoublyListNode* next;
    DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class Solution {
public:
    // 1. Convert singly linked list to doubly linked list
    DoublyListNode* convertToDoubly(ListNode* head) {
        // handle edge case
        if (!head) {
            return nullptr;
        }
        // create head for doubly LL with same val  as head for singly
        DoublyListNode* dHead = new DoublyListNode(head->val);

        // create iterators for doubly & singly
        DoublyListNode* dIt = dHead;
        ListNode* it = head->next;

        while(it) {
            dIt->next = new DoublyListNode(it->val);
            dIt->next->prev = dIt;
            dIt = dIt->next;
            it = it->next;
        }
        return dHead;
    }

    // 2. Convert singly linked list to circular linked list
    ListNode* convertToCircular(ListNode* head) {
        // handle edge case
        if (!head) {
            return nullptr;
        }
        // just loop till the end & link last node with head
        ListNode* it = head;
        while(it->next) {
            it = it->next;
        }
        it->next = head;
        return head;
    }
};

ListNode* buildSinglyList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* it = head;
    for (int i = 1; i < vals.size(); i++) {
        it->next = new ListNode(vals[i]);
        it = it->next;
    }
    return head;
}

void printDoublyList(DoublyListNode* head) {
    cout << "Doubly (forward): ";
    DoublyListNode* it = head;
    DoublyListNode* last = nullptr;
    while (it) {
        cout << it->val << " ";
        last = it;
        it = it->next;
    }
    cout << endl << "Doubly (backward): ";
    while (last) {
        cout << last->val << " ";
        last = last->prev;
    }
    cout << endl;
}

void printCircularList(ListNode* head, int n) {
    cout << "Circular (first " << n << " nodes): ";
    ListNode* it = head;
    for (int i = 0; i < n; i++) {
        cout << it->val << " ";
        it = it->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* sHead = buildSinglyList(vals);

    Solution sol;

    DoublyListNode* dHead = sol.convertToDoubly(sHead);
    printDoublyList(dHead);

    ListNode* cHead = sol.convertToCircular(sHead);
    printCircularList(cHead, 12);

    return 0;
}
