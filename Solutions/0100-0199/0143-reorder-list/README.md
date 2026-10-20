# [143. Reorder List](https://leetcode.com/problems/reorder-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `two-pointers`, `stack`, `recursion`

---

## Problem Description
You are given the head of a singly linked-list. The list can be represented as:

```
L0 → L1 → … → Ln - 1 → Ln
```

*Reorder the list to be on the following form:*

```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

**Example 1:**

```
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```

**Example 2:**

```
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```

**Constraints:**

* The number of nodes in the list is in the range `[1, 5 * 104]`.
* `1 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires rearranging a singly linked list such that nodes from the second half are interleaved in reverse order with the first half. Since we cannot modify node values directly, we must manipulate the pointer links. We can achieve this efficiently in three distinct phases: finding the middle of the list, reversing the second half, and merging the two halves alternately.

# Approach
1. **Find the Middle**: Use the slow and fast pointer technique (`slow` and `fast`). `fast` moves two steps at a time while `slow` moves one step. When `fast` reaches the end, `slow` points to the midpoint separating the first and second halves.
2. **Split and Reverse**: Split the list into two parts by setting `slow->next = nullptr`. Reverse the second half (`slow->next`) in-place using standard pointer reversal (`node`, `second`, and `temp`).
3. **Merge Alternately**: Maintain pointers `first` (starting at `head`) and `second` (starting at the reversed second half). In a loop, splice nodes alternately by updating their `next` pointers using temporary variables `temp1` and `temp2` to preserve remaining references.

### Visual Trace Walkthrough (Example 1: head = [1, 2, 3, 4])
- **Find Midpoint**: `slow` stops at node `2`, `fast` at node `4`.
- **Split & Reverse**: First half = `1 -> 2`, Second half reversed = `4 -> 3`.
- **Merge**: 
  - `first` = `1`, `second` = `4` $ightarrow$ `1 -> 4 -> 2 -> 3`.

# Complexity
- Time complexity: $$O(N)$$ — Finding the middle takes $$O(N/2)$$, reversing the second half takes $$O(N/2)$$, and merging takes $$O(N/2)$$, resulting in linear overall time complexity.
- Space complexity: $$O(1)$$ — Only a few pointer variables are used, operating completely in-place without auxiliary data structures or recursion stacks.

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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* node = nullptr;

        while(second){
            ListNode* temp= second->next;
            second->next = node;
            node = second;
            second = temp;
        }

        ListNode* first = head;
        second = node;

        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }

    }
};
```
