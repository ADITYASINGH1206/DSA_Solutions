# [2095. Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `two-pointers`

---

## Problem Description
You are given the `head` of a linked list. **Delete** the **middle node**, and return *the* `head` *of the modified linked list*.

The **middle node** of a linked list of size `n` is the `⌊n / 2⌋th` node from the **start** using **0-based indexing**, where `⌊x⌋` denotes the largest integer less than or equal to `x`.

* For `n` = `1`, `2`, `3`, `4`, and `5`, the middle nodes are `0`, `1`, `1`, `2`, and `2`, respectively.

**Example 1:**

```
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node.
```

**Example 2:**

```
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
```

**Example 3:**

```
Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
```

**Constraints:**

* The number of nodes in the list is in the range `[1, 105]`.
* `1 <= Node.val <= 105`

---

## Solution & Editorial
# Intuition
To delete the middle node of a linked list, we need to identify the node immediately preceding the middle node. Using the classic "Tortoise and Hare" (slow and fast pointers) approach, we can traverse the list such that when the fast pointer reaches the end, the slow pointer is positioned exactly at the node before the middle element.

# Approach
1. **Edge Case Handling**: If the list is empty or contains only one node, deleting the middle node results in an empty list (`nullptr`).
2. **Pointer Initialization**: Initialize `slow` and `fast` pointers at the `head`. To ensure `slow` stops at the node *before* the middle, we advance `fast` by two steps initially.
3. **Traversal**: Move `slow` one step and `fast` two steps simultaneously until `fast` reaches the end of the list (either `nullptr` or the last node).
4. **Deletion**: Update the `next` pointer of the `slow` node to skip the middle node: `slow->next = slow->next->next`.

### Visual Trace (Example 1: [1, 3, 4, 7, 1, 2, 6])
| Iteration | Slow | Fast | Action |
| :--- | :--- | :--- | :--- |
| Start | 1 | 4 | Initial state |
| 1 | 3 | 1 | Move slow to 3, fast to 1 |
| 2 | 4 | 6 | Move slow to 4, fast to 6 |
| End | 4 | 6 | Loop terminates |
*Result: `slow->next` (7) is bypassed by linking 4 to 1.*

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the linked list. We traverse the list exactly once.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for pointer variables.

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;

    }   
};
```
