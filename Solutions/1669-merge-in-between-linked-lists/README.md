# [1669. Merge In Between Linked Lists](https://leetcode.com/problems/merge-in-between-linked-lists/)
**Difficulty:** `Medium` | **Tags:** `linked-list`

---

## Problem Description
You are given two linked lists: `list1` and `list2` of sizes `n` and `m` respectively.

Remove `list1`'s nodes from the `ath` node to the `bth` node, and put `list2` in their place.

The blue edges and nodes in the following figure indicate the result:

*Build the result list and return its head.*

**Example 1:**

```
Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
```

**Example 2:**

```
Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
```

**Constraints:**

* `3 <= list1.length <= 104`
* `1 <= a <= b < list1.length - 1`
* `1 <= list2.length <= 104`

---

## Solution & Editorial
# Intuition
To merge `list2` into `list1` between indices `a` and `b`, we need to identify the node immediately preceding index `a` and the node at index `b`. By re-linking the predecessor of `a` to the head of `list2` and the tail of `list2` to the successor of `b`, we effectively excise the segment `[a, b]` and splice in the new list.

# Approach
1. Traverse `list1` to find the node at index `a-1` (stored as `prevA`).
2. From `prevA`, traverse `b - a + 1` steps forward to find the node at index `b` (stored as `nodeB`).
3. Connect `prevA->next` to the head of `list2`.
4. Traverse `list2` to find its last node (`tail2`).
5. Connect `tail2->next` to `nodeB->next` to complete the splice.

### Visual Trace (Example 1)
`list1 = [10, 1, 13, 6, 9, 5]`, `a = 3`, `b = 4`
- `prevA` stops at index `a-1` (index 2, value `13`).
- `nodeB` stops at index `b` (index 4, value `9`).
- `prevA->next` becomes `list2` head (`1000000`).
- `tail2` (value `1000002`) connects to `nodeB->next` (value `5`).

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the length of `list1` and $$M$$ is the length of `list2`. We traverse a portion of `list1` to find the splice points and the entirety of `list2` to find its tail.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for pointers regardless of input size.

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        for (int i = 0; i < a - 1; ++i) {
            curr = curr->next;
        }
        ListNode* prevA = curr;
        for (int i = 0; i < b - a + 1; ++i) {
            curr = curr->next;
        }
        ListNode* nodeB = curr;
        
        prevA->next = list2;
        ListNode* tail2 = list2;
        while (tail2->next != nullptr) {
            tail2 = tail2->next;
        }
        tail2->next = nodeB->next;
        
        return list1;
    }
};
```
