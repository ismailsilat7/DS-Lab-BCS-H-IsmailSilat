# LinkedList Solutions

An explaination to the solutions of lab tasks
---

## Problem: [1. Palindrome Check in Singly Linked List](./task01-PalindromeLinkedList.cpp)

**Difficulty:** [Easy]  
**Problem Link:** [LeetCode 234](https://leetcode.com/problems/palindrome-linked-list/description/)

---

### Problem Statement

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

• Input: A singly linked list of integers.
• Output: true if the list reads the same forward and backward, false otherwise.

---

### Approach

- Find the middle: move slow by 1 and fast by 2; when fast finishes, slow is at the middle.
- Reverse the second half starting at slow using prev/curr pointers to get the tail-to-head order.
- Then traverse from head and from the reversed half together
    - return false if any mismatch

---

### Code
```cpp
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
```

## Problem: [2. Merge Two Sorted Singly Linked Lists](./task02-MergeTwoSortedLists.cpp)

**Difficulty:** [Easy]  
**Problem Link:** [LeetCode 21](https://leetcode.com/problems/merge-two-sorted-lists/description/)

---

### Problem Statement

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

---

### Approach

- Pick the smaller node between list1 and list2 as the head of the merged list.
- Use a pointer it (short for iterator) to build the result by always linking the smaller node.
- Continue until one list ends, then attach the remaining nodes of the other list.

---

### Code
```cpp
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
```
