# [24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `recursion`

---

## Problem Description
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

**Example 1:**

**Input:** head = [1,2,3,4]

**Output:** [2,1,4,3]

**Explanation:**

**Example 2:**

**Input:** head = []

**Output:** []

**Example 3:**

**Input:** head = [1]

**Output:** [1]

**Example 4:**

**Input:** head = [1,2,3]

**Output:** [2,1,3]

**Constraints:**

* The number of nodes in the list is in the range `[0, 100]`.
* `0 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
The problem requires swapping every adjacent pair of nodes in a singly linked list without modifying their values. By using a dummy node and three pointer references (`prev`, `curr`, and `second`), we can iteratively re-link the nodes in constant extra space.

# Approach
1. Handle the base cases: if the linked list is empty (`head == nullptr`) or contains only a single node (`head->next == nullptr`), return `head` directly.
2. Initialize a `dummy` node pointing to `head` to simplify pointer re-assignments at the head of the list. Set `prev` to `dummy` and `curr` to `head`.
3. Iterate while `curr` and `curr->next` are both non-null (meaning at least a pair of nodes exists to swap).
4. For each iteration, let `second = curr->next` and `nextPair = curr->next->next`.
5. Re-link the pointers: point `second->next` to `curr`, `curr->next` to `nextPair`, and `prev->next` to `second`.
6. Advance `prev` to `curr` and `curr` to `nextPair` for the next iteration.
7. Return `dummy.next` as the new head of the swapped list.

### Visual Trace (Example 1: head = [1, 2, 3, 4])
- Initial: `dummy -> 1 -> 2 -> 3 -> 4`, `prev = dummy`, `curr = 1`
- Iteration 1:
  - `second = 2`, `nextPair = 3`
  - Re-link: `2 -> 1`, `1 -> 3`, `dummy -> 2`
  - List becomes: `dummy -> 2 -> 1 -> 3 -> 4`
  - Advance: `prev = 1`, `curr = 3`
- Iteration 2:
  - `second = 4`, `nextPair = nullptr`
  - Re-link: `4 -> 3`, `3 -> nullptr`, `1 -> 4`
  - List becomes: `dummy -> 2 -> 1 -> 4 -> 3`
  - Advance: `prev = 3`, `curr = nullptr`
- Termination: `curr == nullptr`, loop ends. Returns `2 -> 1 -> 4 -> 3`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the linked list. Each node is visited exactly once during the traversal.
- Space complexity: $$O(1)$$ because only a fixed set of pointers (`dummy`, `prev`, `curr`, `second`, `nextPair`) are used regardless of the input size.

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while (curr != nullptr && curr->next != nullptr) {
            ListNode* second = curr->next;
            ListNode* nextPair = curr->next->next;
            second->next = curr;       
            curr->next = nextPair;     
            prev->next = second;       

            prev = curr;               
            curr = nextPair;           
        }
        
        return dummy.next;
    }
};
```
