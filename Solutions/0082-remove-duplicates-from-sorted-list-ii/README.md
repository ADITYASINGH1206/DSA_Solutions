# [82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `two-pointers`

---

## Problem Description
You are given the `head` of a **sorted** linked list.

Delete all nodes that have **duplicate** numbers, leaving only **distinct** numbers from the original list.

Return the linked list **sorted** as well.

**Example 1:**

```
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
```

**Example 2:**

```
Input: head = [1,1,1,2,3]
Output: [2,3]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 300]`.
* `-100 <= Node.val <= 100`
* The list is guaranteed to be **sorted** in ascending order.

---

## Solution & Editorial
# Intuition
The problem requires us to remove all nodes that appear more than once from a sorted linked list, keeping only strictly unique elements. Since the head itself might be a duplicate and get removed, using a dummy node positioned before the head simplifies edge case handling and ensures we always have a stable anchor to build the resulting list.

# Approach
1. Initialize a `dummy` node with value `0` pointing to `head`, and a pointer `prev` initialized to `dummy`.
2. Iterate through the list using the `head` pointer. For each node, check if it has a duplicate by comparing `head->val` with `head->next->val`.
3. If a duplicate sequence is detected, advance `head` through all consecutive nodes sharing the same value until the last element of the duplicate block is reached. Then, bypass the entire duplicate block by setting `prev->next = head->next`.
4. If no duplicate is found at the current `head`, safely advance the `prev` pointer to `prev->next`.
5. In all cases, advance `head = head->next` to continue the traversal.
6. Clean up the `dummy` node and return `dummy->next` as the new head.

### Visual Dry Run (Example 1: head = [1, 2, 3, 3, 4, 4, 5])
- Initial: `dummy(0) -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5`, `prev = dummy`, `head = 1`
- `head->val (1) != head->next->val (2)`: `prev` advances to node `1`, `head` advances to `2`.
- `head->val (2) != head->next->val (3)`: `prev` advances to node `2`, `head` advances to `3`.
- `head->val (3) == head->next->val (3)`: Inner loop consumes both `3` nodes, `head` stops at second `3`. `prev->next` points to `4`. `head` advances to `4`.
- `head->val (4) == head->next->val (4)`: Inner loop consumes both `4` nodes, `head` stops at second `4`. `prev->next` points to `5`. `head` advances to `5`.
- `head` reaches `5` and `head->next` is `nullptr`. `prev` advances to `5`.
- Final list: `1 -> 2 -> 5`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the linked list. Each node is visited at most twice (once by `head` and potentially once during the inner duplicate-skipping loop).
- Space complexity: $$O(1)$$, as only a constant amount of extra pointer memory (`dummy`, `prev`, `newHead`) is allocated regardless of the list size.

# Code
```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        
        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
```
