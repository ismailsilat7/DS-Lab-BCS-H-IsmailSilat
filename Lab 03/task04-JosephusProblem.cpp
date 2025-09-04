#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int josephus(int n, int k) {

        // create circular linkedlist
        ListNode* head = new ListNode(1);
        ListNode* it = head;
        for(int i = 2; i <= n; i++) {
            it->next = new ListNode(i);
            it = it->next;
        }
        it->next = head;

        // loop & eliminate every kth element
        ListNode* prev = it;
        it = head;
        while(it != it->next) {
            for (int i = 0; i < k - 1; i++)
            {
                prev = it;
                it = it->next;
            }
            prev->next = it->next;
            ListNode* temp = it;
            it = it->next;
            delete temp;
        }

        int returnVal = it->val;
        delete it;
        return returnVal;
    }
};
