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

## Problem: [3. Reverse in Groups of K](./task03-ReverseNodesInKGroup.cpp)

**Difficulty:** [Hard]  
**Problem Link:** [LeetCode 25](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)

---

### Problem Statement

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

---

### Approach

- Start with finding the length of the LL
- Use a dummy node to avoid special case for insertion at head
- Keep track of prevGroupEnd (node after which the new group will start - dummy node being the initial one)
- Loop length/k times (number of complete groups)
    - keep track of groupStart (becomes tail of the group after reversal)
    - Reverse k nodes
    - Connect the prevGroupEnd with the new head of reversed Group
    - Connect groupStart (now tail) with nextGroup
    - set prevGroupEnd (to groupStart) so that it can be used for next loop
- return dummy node's next

---

### Code
```cpp
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
```

## Problem: [4. Josephus Problem using Circular Linked List](./task03-ReverseNodesInKGroup.cpp)

**Difficulty:** [Medium]  
**Problem Link:** [LeetCode 1823](https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/)

---

### Problem Statement

Use a circular linked list to solve the Josephus problem:
• N people stand in a circle, eliminating every k-th person until only one survives.
• Input: N = 7, k = 3
• Output: Position of survivor.
• Hint: Use circular traversal and deletion.

---

### Approach

- Build a circular linked list of n nodes (each representing a person).
- Start traversal from the head with a prev pointer to track the node before the current one.
    - Move (k-1) steps each time to find the k-th person.
    - Remove the k-th person by linking prev->next to it->next.
    - Continue until only one node remains.
- Return the value of the survivor.

---

### Code
```cpp
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

```