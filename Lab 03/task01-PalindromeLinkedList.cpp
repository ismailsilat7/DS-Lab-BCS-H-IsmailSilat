struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        // handle edge case
        if(!head || !head->next) {
            return true;
        }

        // find middle 
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // check if palindrome
        ListNode* it1 = head;
        ListNode* it2 = prev;
        while(it1 && it2) {
            if(it1->val != it2->val) {
                return false;
            }
            it1 = it1->next;
            it2 = it2->next;
        }
        return true;
    }
};