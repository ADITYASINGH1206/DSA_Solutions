# [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `linked-list`, `two-pointers`, `floyds-cycle-finding-algorithm`

---

## Problem Description
Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.

Return `true` *if there is a cycle in the linked list*. Otherwise, return `false`.

**Example 1:**

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

**Example 2:**

```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
```

**Example 3:**

```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

**Constraints:**

* The number of the nodes in the list is in the range `[0, 104]`.
* `-105 <= Node.val <= 105`
* `pos` is `-1` or a **valid index** in the linked-list.

**Follow up:** Can you solve it using `O(1)` (i.e. constant) memory?

---

## Solution & Editorial
# Intuition
To detect a cycle in a linked list without using extra memory (such as a hash set), we can deploy Floyd's Tortoise and Hare algorithm. The core idea is to use two pointers traversing the list at different speeds: a slow pointer that advances by one step and a fast pointer that advances by two steps. If a cycle exists, the fast pointer will eventually lap the slow pointer inside the loop.

# Approach
1. Initialize two pointers, `slow` and `fast`, both starting at the `head` of the linked list.
2. Iterate with a `while` loop as long as `fast` and `fast->next` are not `NULL`, ensuring we never dereference a null pointer.
3. Inside the loop, advance `slow` by one node (`slow = slow->next`) and `fast` by two nodes (`fast = fast->next->next`).
4. Check if `slow` equals `fast`. If they meet, a cycle is confirmed, so return `true`.
5. If the loop terminates because `fast` or `fast->next` reaches `NULL`, the list is acyclic, so return `false`.

### Visual Trace Walkthrough (Example 1: head = [3, 2, 0, -4], pos = 1)

| Iteration | `fast` Node | `slow` Node | `fast->next` | Action / Result |
| :--- | :--- | :--- | :--- | :--- |
| Start | 3 (Val) | 3 (Val) | 2 | Pointers initialized at head |
| 1 | 0 (Val) | 2 (Val) | -4 | `slow` moves to 2, `fast` moves to 0 |
| 2 | 2 (Val) | 0 (Val) | 0 | `slow` moves to 0, `fast` moves to 2 (looped back via node 1) |
| 3 | 2 (Val) | 2 (Val) | -4 | `slow` moves to 2, `fast` moves to 2 (`slow == fast`, return `true`) |

# Complexity
- Time complexity: $$O(N)$$ — In the worst-case scenario where there is no cycle, the fast pointer traverses the list of $N$ nodes in $$O(N)$$ steps. If a cycle exists of length $K$, the fast pointer catches up to the slow pointer in at most $K$ additional steps inside the cycle, bounded by $$O(N)$$.
- Space complexity: $$O(1)$$ — Only two pointer variables (`slow` and `fast`) are used, requiring constant auxiliary space regardless of the list size.

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast= fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
```
