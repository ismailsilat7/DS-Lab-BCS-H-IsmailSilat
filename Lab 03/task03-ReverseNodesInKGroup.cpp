#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // handle edge cases
        if(k == 1 || !head || !head->next) {
            return head;
        }

        // count nodes
        ListNode* it = head;
        int length = 0;
        while(it) {
            it = it->next;
            length++;
        }
        //use temp dummy node to simplify linking (avoids special case for head)
        ListNode tempHead(0);
        tempHead.next = head;
        ListNode* prevGroupEnd = &tempHead;
        it = head;
        for(int i = 0; i < length/k; i++) {
            // keep track of group start to make it tail of prevEnd
            ListNode* groupStart = it;
            ListNode* prev = nullptr;

            // Reverse group
            for(int j = 0; j < k; j++) {
                ListNode* next = it->next;
                it->next = prev;
                prev = it;
                it = next;
            }

            // connect end of prevGroup to newHead of current group (at prev)
            prevGroupEnd->next = prev;
            // connect end of current group to start of next group
            groupStart->next = it;

            // update groupEnd for next group reversal
            prevGroupEnd = groupStart;
        }
        return tempHead.next;
    }
};