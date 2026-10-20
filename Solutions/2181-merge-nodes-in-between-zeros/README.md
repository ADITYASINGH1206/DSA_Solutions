# [2181. Merge Nodes in Between Zeros](https://leetcode.com/problems/merge-nodes-in-between-zeros/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `simulation`

---

## Problem Description
You are given the `head` of a linked list, which contains a series of integers **separated** by `0`'s. The **beginning** and **end** of the linked list will have `Node.val == 0`.

For **every** two consecutive `0`'s, **merge** all the nodes lying in between them into a single node whose value is the **sum** of all the merged nodes. The modified list should not contain any `0`'s.

Return *the* `head` *of the modified linked list*.

**Example 1:**

```
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
```

**Example 2:**

```
Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.
```

**Constraints:**

* The number of nodes in the list is in the range `[3, 2 * 105]`.
* `0 <= Node.val <= 1000`
* There are **no** two consecutive nodes with `Node.val == 0`.
* The **beginning** and **end** of the linked list have `Node.val == 0`.

---

## Solution & Editorial
# Intuition
The problem requires aggregating values between consecutive zeros in a linked list. Since the list is guaranteed to start and end with a zero, we can treat each segment between zeros as a block to be summed and transformed into a new node.

# Approach
1. Initialize a `sum` variable to 0 and a `temp` pointer starting at `head->next` to traverse the list.
2. Iterate through the list using `temp`. Accumulate node values into `sum` until a node with value 0 is encountered.
3. Upon hitting 0, push the accumulated `sum` into a `vector<int> sums` and reset `sum` to 0.
4. After collecting all segment sums, construct a new linked list by iterating through the `sums` vector and creating new `ListNode` objects.

### Visual Trace (Example 1: [0, 3, 1, 0, 4, 5, 2, 0])
| Step | Current Node Val | Sum | Action |
| :--- | :--- | :--- | :--- |
| 1 | 3 | 3 | - |
| 2 | 1 | 4 | - |
| 3 | 0 | 4 | Push 4, Reset Sum |
| 4 | 4 | 4 | - |
| 5 | 5 | 9 | - |
| 6 | 2 | 11 | - |
| 7 | 0 | 11 | Push 11, Reset Sum |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the linked list. We traverse the list once to calculate sums and iterate through the resulting sums to build the new list.
- Space complexity: $$O(N)$$, as we store the segment sums in a `vector` which, in the worst case, contains $$O(N)$$ elements.

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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* temp = head->next; 
        vector<int> sums;
        while(temp != nullptr){ 
            sum += temp->val;
            if(temp->val == 0){
                sums.push_back(sum);
                sum = 0;
            }
            temp = temp->next; 
        }
        
        ListNode* ans = new ListNode(0);
        ListNode* dans = ans;
        for(int i = 0; i < sums.size(); i++){
            ans->next = new ListNode(sums[i]);
            ans = ans->next;
        }

        return dans->next;
    }
};
```
