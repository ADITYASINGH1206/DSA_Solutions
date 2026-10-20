# [101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, *check whether it is a mirror of itself* (i.e., symmetric around its center).

**Example 1:**

```
Input: root = [1,2,2,3,4,4,3]
Output: true
```

**Example 2:**

```
Input: root = [1,2,2,null,3,null,3]
Output: false
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 1000]`.
* `-100 <= Node.val <= 100`

**Follow up:** Could you solve it both recursively and iteratively?

---

## Solution & Editorial
# Intuition
To determine if a binary tree is symmetric around its center, we need to check if its left and right subtrees are mirror images of each other. A tree is a mirror of another if their roots have equal values, the left subtree of the first tree is a mirror of the right subtree of the second tree, and the right subtree of the first tree is a mirror of the left subtree of the second tree.

# Approach
1. Define a helper function `dfs(TreeNode* n1, TreeNode* n2)` that takes two tree nodes and checks whether they are symmetric reflections.
2. Handle base cases in `dfs`: if both `n1` and `n2` are `nullptr`, return `true` (reached the end symmetrically). If one is `nullptr` and the other is not, return `false`.
3. Compare the values `n1->val` and `n2->val`. If they match, recursively check `dfs(n1->left, n2->right)` and `dfs(n1->right, n2->left)`.
4. In the main `isSymmetric` function, initiate the check by passing `root->left` and `root->right` to `dfs`.

### Visual Trace (Example 1)
Tree: `[1, 2, 2, 3, 4, 4, 3]`
- `isSymmetric(root)` calls `dfs(2_left, 2_right)`
- `dfs(3, 3)` -> compares values (3 == 3), recurses on children (both null) -> returns `true`
- `dfs(4, 4)` -> compares values (4 == 4), recurses on children (both null) -> returns `true`
- `dfs(2, 2)` -> compares values (2 == 2), matches `dfs(3, 3)` and `dfs(4, 4)` -> returns `true`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the total number of nodes in the binary tree. Every node is visited exactly once during the recursive mirror traversal.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the tree, representing the maximum call stack depth during recursion. In the worst case (skewed tree), this is $$O(N)$$, and in the best case (balanced tree), it is $$O(\log N)$$.

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
    bool dfs(TreeNode* n1, TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr) {
            return true;
        }
        
        if (n1 == nullptr || n2 == nullptr) {
            return false;
        }
        
        return n1->val == n2->val && dfs(n1->left, n2->right) && dfs(n1->right, n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }


};
```
