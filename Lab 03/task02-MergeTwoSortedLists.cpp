
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // handle edge case
        if(!list1 || !list2) {
            return (list2)? list2 : list1;
        }

        // assign head
        ListNode* result;
        if(list1->val > list2->val) {
            result = list2;
            list2 = list2->next;
        } else {
            result = list1;
            list1 = list1->next;
        }

        // link other nodes
        ListNode* it = result;
        while(list1 && list2) {
            if(list1->val > list2->val) {
                it->next = list2;
                list2 = list2->next;
            } else {
                it->next = list1;
                list1 = list1->next;
            }
            it = it->next;
        }

        // concat remaining nodes
        if(list1) {
            it->next = list1;
        }
        if(list2) {
            it->next = list2;
        }

        return result;
    }
};