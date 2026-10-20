# [2130. Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `two-pointers`, `stack`

---

## Problem Description
In a linked list of size `n`, where `n` is **even**, the `ith` node (**0-indexed**) of the linked list is known as the **twin** of the `(n-1-i)th` node, if `0 <= i <= (n / 2) - 1`.

* For example, if `n = 4`, then node `0` is the twin of node `3`, and node `1` is the twin of node `2`. These are the only nodes with twins for `n = 4`.

The **twin sum** is defined as the sum of a node and its twin.

Given the `head` of a linked list with even length, return *the **maximum twin sum** of the linked list*.

**Example 1:**

```
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6.
```

**Example 2:**

```
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7.
```

**Example 3:**

```
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
```

**Constraints:**

* The number of nodes in the list is an **even** integer in the range `[2, 105]`.
* `1 <= Node.val <= 105`

---

## Solution & Editorial
# Intuition
To find the maximum twin sum, we need to access nodes at symmetric positions (i and n-1-i). Since a singly linked list only allows forward traversal, the most straightforward approach is to map the node values into a linear data structure that supports random access, such as a `std::vector`.

# Approach
1. Traverse the linked list starting from `head` and store every `val` in a `std::vector<int> arr`.
2. Once all values are stored, the size of the list `n` is `arr.size()`.
3. Iterate from `i = 0` to `n/2 - 1`. For each index, calculate the twin sum as `arr[i] + arr[n - 1 - i]`.
4. Maintain a variable `ans` to track the maximum sum encountered during the iteration.

### Visual Trace (Example 1: [5, 4, 2, 1])
| Step | i | arr[i] | arr[n-1-i] | Sum | Max (ans) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 5 | 1 | 6 | 6 |
| 2 | 1 | 4 | 2 | 6 | 6 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes. We perform one pass to populate the vector and one pass over half the vector to compute sums.
- Space complexity: $$O(N)$$, required to store the node values in the `std::vector`.

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
    int pairSum(ListNode* head) {
        ListNode *temp = head;
        vector<int> arr;
        int ans = INT_MIN;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        for(int i = 0;i<n/2;i++){
            ans = max(ans,arr[i] + arr[n-i-1]);

        }
        return ans;
    }
};
```
