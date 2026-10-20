# [2236. Root Equals Sum of Children](https://leetcode.com/problems/root-equals-sum-of-children/)
**Difficulty:** `Easy` | **Tags:** `tree`, `binary-tree`

---

## Problem Description
You are given the `root` of a **binary tree** that consists of exactly `3` nodes: the root, its left child, and its right child.

Return `true` *if the value of the root is equal to the **sum** of the values of its two children, or* `false` *otherwise*.

**Example 1:**

```
Input: root = [10,4,6]
Output: true
Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
10 is equal to 4 + 6, so we return true.
```

**Example 2:**

```
Input: root = [5,3,1]
Output: false
Explanation: The values of the root, its left child, and its right child are 5, 3, and 1, respectively.
5 is not equal to 3 + 1, so we return false.
```

**Constraints:**

* The tree consists only of the root, its left child, and its right child.
* `-100 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
The problem asks us to verify a simple arithmetic property in a binary tree with exactly three nodes. Since the structure is fixed (root, left child, right child), we can directly access the values using pointer dereferencing without needing any traversal algorithms.

# Approach
1. Access the `val` member of the `root` node.
2. Access the `val` members of the `left` and `right` children using `root->left->val` and `root->right->val`.
3. Compare the root's value to the sum of the children's values.

### Visual Trace (Example 1: [10, 4, 6])
| Variable | Value | Description |
| :--- | :--- | :--- |
| `root->val` | 10 | Root node value |
| `root->left->val` | 4 | Left child value |
| `root->right->val` | 6 | Right child value |
| `sum` | 10 | 4 + 6 |
| `result` | true | 10 == 10 |

# Complexity
- Time complexity: $$O(1)$$. We perform a constant number of pointer dereferences and one addition/comparison operation.
- Space complexity: $$O(1)$$. No auxiliary data structures or recursion stacks are used.

# Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkTree(TreeNode* root) {
        int left = root->left->val;
        int val = root->val;
        int right = root->right->val;

        return (val == (left+right));
    }

};
```
