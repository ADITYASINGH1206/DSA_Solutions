# [92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)
**Difficulty:** `Medium` | **Tags:** `linked-list`

---

## Problem Description
Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.

**Example 1:**

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
```

**Example 2:**

```
Input: head = [5], left = 1, right = 1
Output: [5]
```

**Constraints:**

* The number of nodes in the list is `n`.
* `1 <= n <= 500`
* `-500 <= Node.val <= 500`
* `1 <= left <= right <= n`

**Follow up:** Could you do it in one pass?

---

## Solution & Editorial
# Intuition
The problem asks us to reverse a specific sublist of a singly linked list from index `left` to `right` in a single pass. By introducing a dummy node to gracefully handle edge cases where the reversal starts at the head, we can traverse up to the node just before `left` and then repeatedly pull the subsequent node to the front of our sublist window.

# Approach
1. Handle edge cases immediately: if `head` is null or `left == right`, no reversal is needed, return `head`.
2. Create a `dummy` node pointing to `head` to simplify pointer updates when `left = 1`.
3. Traverse `prev` pointer `left - 1` times from `dummy` so that `prev` rests directly before the sublist.
4. Set `curr = prev->next`, which points to the first node of the sublist to be reversed.
5. Iterate `right - left` times. In each iteration, extract `next_node = curr->next`, detach it from its current position, and insert it right after `prev` (at the beginning of the reversed sublist).
6. Clean up the `dummy` node and return `dummy->next` as the new head.

### Visual Trace Walkthrough (Example 1: head = [1,2,3,4,5], left = 2, right = 4)
- Initial: `dummy -> 1 -> 2 -> 3 -> 4 -> 5`
- After advancing `prev` to `left - 1` (index 1): `prev` points to node `1`. `curr` points to node `2`.
- Iteration 1 (`i = 0`):
  - `next_node` points to node `3`.
  - `curr->next` becomes `4` (node `3` is unlinked).
  - `next_node->next` becomes `prev->next` (node `2`).
  - `prev->next` becomes `next_node` (node `3`).
  - List state: `dummy -> 1 -> 3 -> 2 -> 4 -> 5`
- Iteration 2 (`i = 1`):
  - `next_node` points to node `4`.
  - `curr->next` becomes `5`.
  - `next_node->next` becomes `3`.
  - `prev->next` becomes `4`.
  - List state: `dummy -> 1 -> 4 -> 3 -> 2 -> 5`
- Final Output: `[1, 4, 3, 2, 5]`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the linked list. We traverse at most $$N$$ nodes to reach the `left` position and perform at most $$R - L$$ pointer adjustments inside the sublist, visiting each node a constant number of times.
- Space complexity: $$O(1)$$, as only a few pointer variables (`dummy`, `prev`, `curr`, `next_node`) are allocated regardless of list length.

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        
        for (int i = 0; i < right - left; i++) {
            ListNode* next_node = curr->next;
            curr->next = next_node->next; 
            next_node->next = prev->next; 
            prev->next = next_node;    
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};
```
