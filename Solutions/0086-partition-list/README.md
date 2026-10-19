# [86. Partition List](https://leetcode.com/problems/partition-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `two-pointers`

---

## Problem Description
Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.

**Example 1:**

```
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```

**Example 2:**

```
Input: head = [2,1], x = 2
Output: [1,2]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 200]`.
* `-100 <= Node.val <= 100`
* `-200 <= x <= 200`

---

## Solution & Editorial
# Intuition
The problem asks us to partition a linked list such that all elements strictly less than $x$ appear before elements greater than or equal to $x$, while maintaining their original relative order. Since we need to extract and regroup elements, a simple and robust way is to collect all node values into a linear buffer (vector), partition them into two separate lists using dummy nodes, and then recombine them.

# Approach
1. Initialize a vector `nums` and traverse the input linked list using a pointer `temp`, pushing each node's value into `nums` to preserve the original sequence.
2. Create two dummy head nodes `left` and `right` with respective tracking pointers `leftTemp` and `rightTemp` to build the two partitions.
3. Iterate through each element `num` in `nums`. If `num < x`, append a newly allocated node containing `num` to the `leftTemp` list. Otherwise, append it to the `rightTemp` list.
4. Connect the tail of the `left` partition (`leftTemp->next`) to the actual start of the `right` partition (`right->next`).
5. Return `left->next` as the head of the newly partitioned list.

### Visual Trace Walkthrough
For `head = [1, 4, 3, 2, 5, 2]`, `x = 3`:
- **Vector Collection**: `nums = [1, 4, 3, 2, 5, 2]`
- **Partitioning**: 
  - `num = 1`: `< 3` $ightarrow$ `left` gets `[1]`
  - `num = 4`: $\ge 3$ $ightarrow$ `right` gets `[4]`
  - `num = 3`: $\ge 3$ $ightarrow$ `right` gets `[4, 3]`
  - `num = 2`: `< 3` $ightarrow$ `left` gets `[1, 2]`
  - `num = 5`: $\ge 3$ $ightarrow$ `right` gets `[4, 3, 5]`
  - `num = 2`: `< 3` $ightarrow$ `left` gets `[1, 2, 2]`
- **Recombination**: Connect `left` tail (`2`) to `right` head (`4`), resulting in `[1, 2, 2, 4, 3, 5]`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the linked list. We traverse the list once to collect values, and iterate over the vector of size $$N$$ to build the new nodes.
- Space complexity: $$O(N)$$ to store the node values in the vector and allocate new nodes for the partitioned lists.

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
    ListNode* partition(ListNode* head, int x) {
        vector<int> nums;
        ListNode* temp = head;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        ListNode* leftTemp = left;
        ListNode* rightTemp = right;
        for(int num:nums){
            if(num < x){
                ListNode* node = new ListNode(num);
                leftTemp->next =node;
                leftTemp = leftTemp->next;
            }else{
                ListNode* node = new ListNode(num);
                rightTemp->next = node;
                rightTemp = rightTemp->next;
            }
        }

        leftTemp->next =right->next;
        return left->next;
    }
};
```
