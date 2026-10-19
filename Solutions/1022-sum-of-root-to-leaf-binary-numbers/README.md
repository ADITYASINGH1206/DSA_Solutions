# [1022. Sum of Root To Leaf Binary Numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
You are given the `root` of a binary tree where each node has a value `0` or `1`. Each root-to-leaf path represents a binary number starting with the most significant bit.

* For example, if the path is `0 -> 1 -> 1 -> 0 -> 1`, then this could represent `01101` in binary, which is `13`.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return *the sum of these numbers*.

The test cases are generated so that the answer fits in a **32-bits** integer.

**Example 1:**

```
Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
```

**Example 2:**

```
Input: root = [0]
Output: 0
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 1000]`.
* `Node.val` is `0` or `1`.

---

## Solution & Editorial
# Intuition
The problem asks us to compute the sum of binary numbers represented by all root-to-leaf paths in a binary tree. Since bits are generated from the root down to the leaves, we can accumulate the value of the binary number dynamically during a pre-order traversal by shifting the current accumulated value left by 1 and bitwise OR-ing the current node's value.

# Approach
1. Define a helper recursive function `dfs(TreeNode* root, int t)` where `root` is the current node and `t` is the accumulated binary number value from the root down to the parent of `root`.
2. Base case: If `root` is `nullptr`, return `0`.
3. Update the accumulated value: `t = (t << 1) | root->val` shifts the existing binary value to the left to make room for the new least significant bit represented by `root->val`.
4. Leaf check: If `root` has no left and right children (`!root->left && !root->right`), it is a leaf node; return the current accumulated value `t`.
5. Recursive step: Otherwise, return the sum of recursive calls on both the left and right subtrees passing the updated `t`.

### Visual Walkthrough (Example 1: root = [1, 0, 1, 0, 1, 0, 1])

| Step | Call | `root->val` | `t` (Before) | `t` (After Update) | Is Leaf? | Action / Return Value |
| :--- | :--- | :---: | :---: | :---: | :---: | :--- |
| 1 | `dfs(root, 0)` | 1 | 0 | 1 | No | Calls left & right with `t = 1` |
| 2 | `dfs(left, 1)` | 0 | 1 | 2 (`010`) | No | Calls left & right with `t = 2` |
| 3 | `dfs(left.left, 2)` | 0 | 2 | 4 (`100`) | Yes | Returns `4` |
| 4 | `dfs(left.right, 2)` | 1 | 2 | 5 (`101`) | Yes | Returns `5` |
| 5 | `dfs(right, 1)` | 1 | 1 | 3 (`011`) | No | Calls left & right with `t = 3` |
| 6 | `dfs(right.left, 3)` | 0 | 3 | 6 (`110`) | Yes | Returns `6` |
| 7 | `dfs(right.right, 3)` | 1 | 3 | 7 (`111`) | Yes | Returns `7` |

Total Sum = $4 + 5 + 6 + 7 = 22$.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once during the depth-first traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree, corresponding to the maximum recursion stack depth. In the worst case (skewed tree), this is $$O(N)$$; in the best case (balanced tree), it is $$O(\log N)$$.

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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int t) {
        if (!root) return 0;
        t = (t << 1) | root->val;
        if (!root->left && !root->right) return t;
        return dfs(root->left, t) + dfs(root->right, t);
    }
};
```
