# [61. Rotate List](https://leetcode.com/problems/rotate-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `two-pointers`

---

## Problem Description
Given the `head` of a linked list, rotate the list to the right by `k` places.

**Example 1:**

```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

**Example 2:**

```
Input: head = [0,1,2], k = 4
Output: [2,0,1]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 500]`.
* `-100 <= Node.val <= 100`
* `0 <= k <= 2 * 109`

---

## Solution & Editorial
# Intuition
To rotate a singly linked list to the right by $k$ places, we can connect the tail node back to the head to form a circular linked list. Since rotating by the length of the list brings us back to the original configuration, we only need to perform the rotation by $k \pmod{\text{len}}$ effective steps. Finding the new tail node at position $\text{len} - k$ allows us to break the circle and form the newly rotated list.

# Approach
1. Handle edge cases: if `head` is `NULL` or `k == 0`, immediately return `head`.
2. Traverse the list from `head` to find the total length (`len`) and locate the `tail` node. Keep the time complexity optimal by counting nodes in a single traversal.
3. Compute the effective rotation steps as `k = k % len`. If `k == 0`, no rotation is needed, so return `head`.
4. Connect `tail->next = head` to convert the linear linked list into a circular linked list.
5. Use the helper function `nthNode` to find the new last node at position $\text{len} - k$ from the start of the list.
6. Update `head = newLastNode->next`, sever the circular link by setting `newLastNode->next = NULL`, and return the updated `head`.

### Visual Trace Walkthrough (Example 1)
Input: `head = [1, 2, 3, 4, 5], k = 2`
- Step 1: Compute `len = 5`, `tail` points to node with value `5`.
- Step 2: Compute effective rotations `k = 2 % 5 = 2`.
- Step 3: Connect `tail->next` to `head` (forming a circle: `1 -> 2 -> 3 -> 4 -> 5 -> 1`).
- Step 4: Find new last node at position $\text{len} - k = 5 - 2 = 3$ (node with value `3`).
- Step 5: Update `head` to `newLastNode->next` (node with value `4`), and set `newLastNode->next = NULL`.
- Output: `[4, 5, 1, 2, 3]`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the linked list. We traverse the list once to find its length and tail, and once more up to $$N - (k \pmod N)$$ steps to find the new tail node.
- Space complexity: $$O(1)$$ auxiliary space since we only use a few pointer variables.

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
    ListNode* nthNode(ListNode* temp,int n){
        int c = 1;
        while(temp != NULL){
            if(c == n) return temp;
            c++;
            temp = temp->next;

        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }

        if(k % len == 0) return head;

        k = k%len;

        tail->next = head;
        ListNode* newLastNode = nthNode(head,len-k);
        
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};
```
