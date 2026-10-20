# [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `two-pointers`

---

## Problem Description
Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

**Example 1:**

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Example 2:**

```
Input: head = [1], n = 1
Output: []
```

**Example 3:**

```
Input: head = [1,2], n = 1
Output: [1]
```

**Constraints:**

* The number of nodes in the list is `sz`.
* `1 <= sz <= 30`
* `0 <= Node.val <= 100`
* `1 <= n <= sz`

**Follow up:** Could you do this in one pass?

---

## Solution & Editorial
# Intuition
The problem requires removing the $n$-th node from the end of a singly linked list. A straightforward strategy is to first determine the total length of the list, compute the exact 0-indexed position from the head, and then traverse to the predecessor of the target node to perform the deletion.

# Approach
1. Initialize a pointer `temp` at `head` and traverse the entire list to compute the total node count `length`.
2. Calculate the 0-indexed target position from the start using `targetIndex = length - n`.
3. Handle the edge case where `targetIndex == 0` (meaning the head itself must be removed): advance `head`, free the old head, and return the new head.
4. For any other case, traverse `temp` from the start `targetIndex - 1` times to reach the node immediately preceding the target.
5. Adjust `temp->next` to bypass the target node, safely delete the target node, and return `head`.

### Visual Trace Walkthrough (Example 1: head = [1,2,3,4,5], n = 2)
- **Pass 1 (Length Calculation):** `temp` traverses all 5 nodes $ightarrow$ `length = 5`.
- **Target Index Calculation:** `targetIndex = 5 - 2 = 3` (we want to remove the node with value 4).
- **Traversal to Predecessor:** `temp` starts at `head` (value 1) and advances `3 - 1 = 2` times to reach the node with value 3 (`temp->val = 3`).
- **Deletion:** `toDelete` points to `temp->next` (value 4). Update `temp->next = temp->next->next` (connecting 3 to 5). Delete node 4.
- **Result:** List becomes `[1,2,3,5]`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the linked list. We perform at most two linear passes: one to find the length and one to reach the target predecessor.
- Space complexity: $$O(1)$$ auxiliary space, as only constant pointers and integer variables are used.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        int targetIndex = length - n;

        if (targetIndex == 0) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }
        temp = head;
        while (targetIndex > 1) {
            temp = temp->next;
            targetIndex--;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete; 
        
        return head;
    }
};
```
