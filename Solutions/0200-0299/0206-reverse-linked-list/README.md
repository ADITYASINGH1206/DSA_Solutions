# [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
**Difficulty:** `Easy` | **Tags:** `linked-list`, `recursion`

---

## Problem Description
Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.

**Example 1:**

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

**Example 2:**

```
Input: head = [1,2]
Output: [2,1]
```

**Example 3:**

```
Input: head = []
Output: []
```

**Constraints:**

* The number of nodes in the list is the range `[0, 5000]`.
* `-5000 <= Node.val <= 5000`

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

---

## Solution & Editorial
# Intuition
To reverse a singly linked list in place, we need to redirect the `next` pointer of each node to point to its preceding node instead of its succeeding node. Maintaining three pointers (`prev`, `temp`, and `front`) allows us to iterate through the list safely without losing track of the remaining nodes or breaking connectivity.

# Approach
1. Check if the initial `head` is `NULL`. If it is, return `head` immediately since an empty list is already reversed.
2. Initialize `prev` to `NULL` to serve as the new tail's successor. Initialize `temp` to `head` to track the current working node.
3. Enter a `while (temp)` loop that runs as long as there are nodes to process:
   - Store the next node in `front = temp->next` to prevent losing the rest of the list.
   - Reverse the current node's pointer by setting `temp->next = prev`.
   - Advance the `prev` pointer forward to `temp`.
   - Advance the `temp` pointer forward to `front`.
4. Once the loop terminates (`temp` becomes `NULL`), `prev` points to the new head of the reversed list. Return `prev`.

### Visual Trace Walkthrough (Example 1: head = [1, 2, 3, 4, 5])
| Iteration | prev | temp | front | Action / Pointer Updates |
| :--- | :--- | :--- | :--- | :--- |
| Initial | `nullptr` | `1` | `2` | Start traversal |
| Step 1 | `1` | `2` | `3` | `1->next = nullptr`, `prev = 1`, `temp = 2` |
| Step 2 | `2` | `3` | `4` | `2->next = 1`, `prev = 2`, `temp = 3` |
| Step 3 | `3` | `4` | `5` | `3->next = 2`, `prev = 3`, `temp = 4` |
| Step 4 | `4` | `5` | `nullptr` | `4->next = 3`, `prev = 4`, `temp = 5` |
| Step 5 | `5` | `nullptr` | `nullptr` | `5->next = 4`, `prev = 5`, `temp = nullptr` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the linked list. We traverse each node exactly once.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra pointer storage (`prev`, `temp`, `front`) regardless of input size.

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* temp = head;
        ListNode* front = temp->next;
        ListNode* prev = NULL;
        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
};
```
