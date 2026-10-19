# [876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)
**Difficulty:** `Easy` | **Tags:** `linked-list`, `two-pointers`

---

## Problem Description
Given the `head` of a singly linked list, return *the middle node of the linked list*.

If there are two middle nodes, return **the second middle** node.

**Example 1:**

```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```

**Example 2:**

```
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

**Constraints:**

* The number of nodes in the list is in the range `[1, 100]`.
* `1 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
The most efficient way to find the middle of a singly linked list without knowing its length is to use the two-pointer technique with a slow and a fast pointer. By advancing the `fast` pointer twice as fast as the `slow` pointer, when `fast` reaches the end of the list, `slow` will be precisely at the middle node.

# Approach
1. Initialize two pointers, `slow` and `fast`, both pointing to the `head` of the linked list.
2. Iterate through the list using a `while` loop that continues as long as `fast` is not `NULL` and `fast->next` is not `nullptr`.
3. In each iteration, advance `slow` by one step (`slow = slow->next`) and `fast` by two steps (`fast = fast->next->next`).
4. When the loop terminates, `slow` points to the middle node (the second middle node in case of an even number of nodes).
5. Return `slow`.

### Visual Dry Run (Example 1: head = [1,2,3,4,5])
| Iteration | `fast` before loop | `slow` before loop | Action | `fast` after | `slow` after |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | 1 | `slow = slow->next`, `fast = fast->next->next` | 3 | 2 |
| 2 | 3 | 2 | `slow = slow->next`, `fast = fast->next->next` | 5 | 3 |
| End | 5 | 3 | `fast->next` is `nullptr`, loop terminates | 5 | 3 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the linked list. The `fast` pointer traverses the list at twice the speed, visiting roughly $$N/2$$ nodes.
- Space complexity: $$O(1)$$ auxiliary space as only two pointer variables (`slow` and `fast`) are used.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```
