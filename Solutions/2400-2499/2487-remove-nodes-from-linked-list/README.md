# [2487. Remove Nodes From Linked List](https://leetcode.com/problems/remove-nodes-from-linked-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `stack`, `recursion`, `monotonic-stack`

---

## Problem Description
You are given the `head` of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return *the* `head` *of the modified linked list.*

**Example 1:**

```
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
```

**Example 2:**

```
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
```

**Constraints:**

* The number of the nodes in the given list is in the range `[1, 105]`.
* `1 <= Node.val <= 105`

---

## Solution & Editorial
# Intuition
The problem requires removing any node that has a larger value to its right. This is equivalent to finding the "next greater element" for every node and keeping only those that do not have a greater element to their right. A monotonic decreasing stack is the ideal data structure to maintain the sequence of nodes that satisfy this condition.

# Approach
1. Traverse the linked list from left to right.
2. Maintain a `vector<int> stk` acting as a monotonic stack. For every node value `temp->val` encountered:
   - While the stack is not empty and the top element is smaller than the current node value, pop the stack. This effectively discards nodes that have a larger value to their right.
   - Push the current node value onto the stack.
3. After the traversal, the stack contains the values of the nodes that should remain in the list in their original relative order.
4. Reconstruct the linked list using the values stored in the stack.

### Visual Trace (Example 1: [5, 2, 13, 3, 8])
| Step | Current Node | Stack State | Action |
| :--- | :--- | :--- | :--- |
| 1 | 5 | [5] | Push 5 |
| 2 | 2 | [5, 2] | Push 2 |
| 3 | 13 | [13] | Pop 2, Pop 5, Push 13 |
| 4 | 3 | [13, 3] | Push 3 |
| 5 | 8 | [13, 8] | Pop 3, Push 8 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes. Each node is pushed onto and popped from the stack at most once.
- Space complexity: $$O(N)$$ to store the values in the stack and the newly created linked list.

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
    ListNode* removeNodes(ListNode* head) {
        vector<int> stk;
        ListNode* temp = head;
        while(temp != NULL){
            if(stk.empty()){
                stk.push_back(temp->val);
            }
            else{
                while(!stk.empty() && stk.back() < temp->val){
                    stk.pop_back();
                }
                stk.push_back(temp->val);

            }
            temp = temp->next;
        }
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        
        for (int val : stk) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        return ans->next;
    }
};
```
