# [328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`

---

## Problem Description
Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return *the reordered list*.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in `O(1)` extra space complexity and `O(n)` time complexity.

**Example 1:**

```
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

**Example 2:**

```
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

**Constraints:**

* The number of nodes in the linked list is in the range `[0, 104]`.
* `-106 <= Node.val <= 106`

---

## Solution & Editorial
# Intuition
The problem requires separating a linked list into odd-indexed and even-indexed nodes while preserving their relative order and operating in $$O(1)$$ auxiliary space. We can achieve this by maintaining two pointer tracks simultaneously: pointer `a` tracking the last node of the odd list, and pointer `b` tracking the last node of the even list. By rewiring pointers in a single pass, we bypass even nodes for the odd chain and odd nodes for the even chain.

# Approach
1. Handle the base case where the `head` is `nullptr` by returning `nullptr` immediately.
2. Initialize pointer `a` to `head` (first node, odd) and pointer `b` to `head->next` (second node, even). Also preserve the head of the even chain using pointer `c = b`.
3. Iterate while `b` and `b->next` are non-null:
   - Link the next odd node: `a->next = b->next`, then advance `a = a->next`.
   - Link the next even node: `b->next = a->next`, then advance `b = b->next`.
4. After the loop completes, connect the tail of the odd list (`a`) to the head of the even list (`c`).
5. Return `head`.

### Visual Walkthrough (Example 1: `[1, 2, 3, 4, 5]`)
- Initial State: `head = 1`, `a = 1`, `b = 2`, `c = 2`
- **Iteration 1:**
  - `b` is `2`, `b->next` is `3` (not null).
  - `a->next = b->next` (node `1` points to `3`).
  - `a` advances to `3`.
  - `b->next = a->next` (node `2` points to `4`).
  - `b` advances to `4`.
  - List structure: Odds `1 -> 3`, Evens `2 -> 4 -> 5`.
- **Iteration 2:**
  - `b` is `4`, `b->next` is `5` (not null).
  - `a->next = b->next` (node `3` points to `5`).
  - `a` advances to `5`.
  - `b->next = a->next` (node `4` points to `nullptr`).
  - `b` advances to `nullptr`.
  - List structure: Odds `1 -> 3 -> 5`, Evens `2 -> 4 -> nullptr`.
- Loop terminates as `b` is `nullptr`. Finally, `a->next = c` attaches the even list after the odd list: `1 -> 3 -> 5 -> 2 -> 4`.

# Complexity
- Time complexity: $$O(N)$$ — We traverse each node of the linked list exactly once using pointers `a` and `b`.
- Space complexity: $$O(1)$$ — Only a few pointer variables (`a`, `b`, `c`) are used, requiring constant extra memory regardless of input size.

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* a = head;
        ListNode *b = head->next, *c = b;
        while (b && b->next) {
            a->next = b->next;
            a = a->next;
            b->next = a->next;
            b = b->next;
        }
        a->next = c;
        return head;
    }
};
```
