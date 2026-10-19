# [203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
**Difficulty:** `Easy` | **Tags:** `linked-list`, `recursion`

---

## Problem Description
Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return *the new head*.

**Example 1:**

```
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
```

**Example 2:**

```
Input: head = [], val = 1
Output: []
```

**Example 3:**

```
Input: head = [7,7,7,7], val = 7
Output: []
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 104]`.
* `1 <= Node.val <= 50`
* `0 <= val <= 50`

---

## Solution & Editorial
# Intuition
The problem requires us to eliminate all nodes in a singly linked list whose values equal a given target `val`. Instead of mutating pointers in place and managing edge cases for head deletions, we can construct a completely new result list by traversing the original list and appending matching elements to a fresh dummy head structure.

# Approach
1. Initialize a pointer `temp` starting at the `head` to iterate through the input linked list.
2. Create a dummy node `ans` with a value of `0` to serve as the anchor for our new constructed list, and maintain a tail pointer `temp1` pointing to `ans`.
3. Traverse the list using the `while(temp)` loop. For each node, check if `temp->val != val`.
4. If the condition is met, instantiate a new node with `temp->val`, attach it to `temp1->next`, and advance `temp1` to this newly attached node.
5. Unconditionally advance `temp` to `temp->next` to continue the traversal.
6. Return `ans->next`, which points to the head of the newly filtered linked list.

### Visual Trace Walkthrough
For `head = [1, 2, 6, 3, 4, 5, 6]`, `val = 6`:
- Initial: `ans = [0]`, `temp1 = [0]`, `temp = [1]`
- `temp->val = 1 != 6`: Append `1`. `ans->next = [1]`, `temp1` at `[1]`, `temp` moves to `[2]`
- `temp->val = 2 != 6`: Append `2`. `ans->next = [1, 2]`, `temp1` at `[2]`, `temp` moves to `[6]`
- `temp->val = 6 == 6`: Skip. `temp` moves to `[3]`
- `temp->val = 3 != 6`: Append `3`. `ans->next = [1, 2, 3]`, `temp1` at `[3]`, `temp` moves to `[4]`
- `temp->val = 4 != 6`: Append `4`. `ans->next = [1, 2, 3, 4]`, `temp1` at `[4]`, `temp` moves to `[5]`
- `temp->val = 5 != 6`: Append `5`. `ans->next = [1, 2, 3, 4, 5]`, `temp1` at `[5]`, `temp` moves to `[6]`
- `temp->val = 6 == 6`: Skip. `temp` becomes `nullptr`.
- Loop terminates. Returns `ans->next` which points to `[1, 2, 3, 4, 5]`.

# Complexity
- Time complexity: $$O(N)$$ — We perform a single linear traversal of the input linked list containing $N$ nodes, executing constant-time checks and allocations per node.
- Space complexity: $$O(N)$$ — Auxiliary space is used to construct a new linked list containing at most $N$ nodes in the worst case where no elements match `val`.

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* ans = new ListNode(0);
        ListNode* temp1 = ans;
        while(temp){
            if(temp->val != val){
                ListNode* node = new ListNode(temp->val);
                temp1->next = node;
                temp1 = temp1->next;
            }
            temp = temp->next;
        }

        return ans->next;
    }
};
```
