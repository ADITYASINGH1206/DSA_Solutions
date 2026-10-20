# [1721. Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `two-pointers`

---

## Problem Description
You are given the `head` of a linked list, and an integer `k`.

Return *the head of the linked list after **swapping** the values of the* `kth` *node from the beginning and the* `kth` *node from the end (the list is **1-indexed**).*

**Example 1:**

```
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```

**Example 2:**

```
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
```

**Constraints:**

* The number of nodes in the list is `n`.
* `1 <= k <= n <= 105`
* `0 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
To swap the $k^{th}$ node from the beginning and the $k^{th}$ node from the end, we need to identify both nodes efficiently. Since the list is singly linked, we can find the $k^{th}$ node from the start in one pass. To find the $k^{th}$ node from the end without a second pass or extra storage, we use a two-pointer technique where one pointer is offset by $k$ positions.

# Approach
1. Initialize two pointers, `fast` and `slow`, both pointing to `head`.
2. Move `fast` forward $k-1$ times. The node at `fast` is now our $k^{th}$ node from the beginning. Store this in `start`.
3. Continue moving both `fast` and `slow` forward simultaneously until `fast` reaches the last node (`fast->next == nullptr`).
4. At this point, `slow` will be exactly at the $k^{th}$ node from the end.
5. Swap the values of `start` and `slow`.

### Visual Trace (Example 1: [1, 2, 3, 4, 5], k = 2)
| Step | fast | slow | start | Description |
| :--- | :--- | :--- | :--- | :--- |
| Init | 1 | 1 | null | Start pointers |
| Move fast | 2 | 1 | 2 | fast moves to index k (2) |
| Loop | 5 | 4 | 2 | fast reaches end, slow is at k-th from end |
| Swap | 5 | 4 | 2 | Swap values 2 and 4 |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the number of nodes. We traverse the list once to find the $k^{th}$ node and once more to find the $k^{th}$ from the end.
- Space complexity: $$O(1)$$, as we only use a few pointers regardless of the input size.

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* start = nullptr;
        
        for (int i = 1; i < k; ++i) {
            fast = fast->next;
        }
        
        start = fast;
        
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        swap(start->val, slow->val);
        
        return head;
    }
};
```
