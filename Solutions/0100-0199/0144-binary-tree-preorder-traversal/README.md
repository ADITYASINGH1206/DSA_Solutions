# [144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
**Difficulty:** `Easy` | **Tags:** `stack`, `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the preorder traversal of its nodes' values*.

**Example 1:**

**Input:** root = [1,null,2,3]

**Output:** [1,2,3]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,5,null,8,null,null,6,7,9]

**Output:** [1,2,4,5,6,7,3,8,9]

**Explanation:**

**Example 3:**

**Input:** root = []

**Output:** []

**Example 4:**

**Input:** root = [1]

**Output:** [1]

**Constraints:**

* The number of nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`

**Follow up:** Recursive solution is trivial, could you do it iteratively?

---

## Solution & Editorial
# Intuition
Preorder traversal follows the Root -> Left -> Right pattern. By utilizing a recursive depth-first search approach, we can naturally visit the root node, record its value, and recursively traverse its left and right subtrees in order.

# Approach
1. Define a helper function `preorder(TreeNode* root, vector<int>& ans)` that takes the current node and a reference to the answer vector.
2. In the helper function, base case check: if `root == NULL`, return immediately.
3. Push the current node's value (`root->val`) into `ans` (Root step).
4. Recursively call `preorder` on `root->left` (Left step).
5. Recursively call `preorder` on `root->right` (Right step).
6. In `preorderTraversal`, initialize an empty vector `ans`, call the helper function starting from `root`, and return `ans`.

### Visual Trace (Example 1: root = [1, null, 2, 3])
- Call `preorder(1, ans)`: `ans` becomes `[1]`, visits left child (`NULL`), visits right child (`2`).
- Call `preorder(2, ans)`: `ans` becomes `[1, 2]`, visits left child (`3`), visits right child (`NULL`).
- Call `preorder(3, ans)`: `ans` becomes `[1, 2, 3]`, visits left child (`NULL`), visits right child (`NULL`).
- Final Result: `[1, 2, 3]`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Each node is visited exactly once.
- Space complexity: $$O(N)$$ in the worst-case scenario (degenerate tree) due to the recursive call stack, and $$O(\log N)$$ for a balanced binary tree.

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
    void preorder(TreeNode* root,vector<int>& ans){
        if(root == NULL) return;

        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* temp = root;
        vector<int> ans;
        preorder(temp,ans);
        return ans;
    }   
};
```
