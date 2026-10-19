# [145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)
**Difficulty:** `Easy` | **Tags:** `stack`, `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the postorder traversal of its nodes' values*.

**Example 1:**

**Input:** root = [1,null,2,3]

**Output:** [3,2,1]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,5,null,8,null,null,6,7,9]

**Output:** [4,6,7,5,2,9,8,3,1]

**Explanation:**

**Example 3:**

**Input:** root = []

**Output:** []

**Example 4:**

**Input:** root = [1]

**Output:** [1]

**Constraints:**

* The number of the nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`

**Follow up:** Recursive solution is trivial, could you do it iteratively?

---

## Solution & Editorial
# Intuition
Postorder traversal visits nodes in the order of Left subtree, Right subtree, and finally the Root node. A straightforward recursive Depth-First Search naturally maps to this execution flow by leveraging the function call stack.

# Approach
1. Define a helper function `postorder(TreeNode* root, vector<int>& ans)` that takes the current node and a reference to the result vector `ans`.
2. Base case: If `root` is `NULL`, return immediately.
3. Recursively call `postorder` on the left child: `postorder(root->left, ans)`.
4. Recursively call `postorder` on the right child: `postorder(root->right, ans)`.
5. Append the current node's value `root->val` to the result vector `ans` using `ans.push_back(root->val)`.
6. In the main `postorderTraversal` function, instantiate an empty vector `ans`, initiate the recursive helper with `root`, and return `ans`.

### Visual Walkdown (Example 1: root = [1, null, 2, 3])
- Call `postorder(1)`
  - Call `postorder(null)` -> returns
  - Call `postorder(2)`
    - Call `postorder(3)`
      - Call `postorder(null)` -> returns
      - Call `postorder(null)` -> returns
      - Push `3` to `ans` -> `ans = [3]`
    - Call `postorder(null)` -> returns
    - Push `2` to `ans` -> `ans = [3, 2]`
  - Push `1` to `ans` -> `ans = [3, 2, 1]`
- Final Output: `[3, 2, 1]`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree, required by the recursion stack. In the worst case (skewed tree), this is $$O(N)$$, and in the best case (balanced tree), this is $$O(\log N)$$.

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
    void postorder(TreeNode* root,vector<int>& ans){
        if(root == NULL) return;

        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* temp = root;
        vector<int> ans;
        postorder(temp,ans);
        return ans;
    }
};
```
