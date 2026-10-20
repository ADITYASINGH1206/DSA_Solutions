# [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
**Difficulty:** `Easy` | **Tags:** `stack`, `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the inorder traversal of its nodes' values*.

**Example 1:**

**Input:** root = [1,null,2,3]

**Output:** [1,3,2]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,5,null,8,null,null,6,7,9]

**Output:** [4,2,6,5,7,1,3,9,8]

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
An inorder traversal visits the nodes of a binary tree in the specific order: Left subtree, Root node, Right subtree. By leveraging the call stack recursively, we can naturally follow this left-root-right pattern with minimal and elegant code.

# Approach
1. Initialize an empty vector `ans` to store the traversal sequence.
2. Define a helper function `inorder(TreeNode* root, vector<int>& ans)` that takes the current node and the reference to the result vector.
3. Base case: If the current `root` is `NULL`, return immediately.
4. Recursively traverse the left child: `inorder(root->left, ans)`.
5. Process the current node by pushing `root->val` into `ans`.
6. Recursively traverse the right child: `inorder(root->right, ans)`.

### Visual Trace (Example 1: root = [1, null, 2, 3])
- Call `inorder(1)` -> descends to `inorder(1->left)` which is `NULL`.
- Call `inorder(2)` -> descends to `inorder(2->left)` (`3`).
- Call `inorder(3)` -> `3->left` is `NULL` (returns), pushes `3` (`ans = [3]`), `3->right` is `NULL` (returns).
- Back in `inorder(2)` -> pushes `2` (`ans = [3, 2]`), descends to `2->right` (`NULL`).
- Back in `inorder(1)` -> pushes `1` (`ans = [1, 3, 2]`), descends to `1->right` (`2`), processes subtree.
- Final result vector: `[1, 3, 2]`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree. Each node is visited exactly once.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the binary tree, consumed by the recursion stack. In the worst case (skewed tree), this is $$O(N)$$, and in the best case (balanced tree), this is $$O(\log N)$$.

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }

    void inorder(TreeNode* root,vector<int>& ans){
        if(root == NULL) return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
};
```
