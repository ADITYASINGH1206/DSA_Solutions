# [404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the sum of all left leaves.*

A **leaf** is a node with no children. A **left leaf** is a leaf that is the left child of another node.

**Example 1:**

```
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
```

**Example 2:**

```
Input: root = [1]
Output: 0
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 1000]`.
* `-1000 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
To find the sum of all left leaves, we need to inspect every node in the binary tree and determine whether its left child exists and is a leaf node (i.e., has no children of its own). A recursive depth-first search allows us to visit each node while maintaining an accumulated sum.

# Approach
1. Initialize an integer variable `ans` to 0.
2. Define a helper function `dfs(TreeNode* root, int& ans)` that takes the current node and a reference to the running total `ans`.
3. Base case: If `root` is `NULL`, return immediately.
4. Check if the current node has a left child (`root->left != NULL`) and that this left child is a leaf node (`!root->left->left && !root->left->right`). If both conditions are satisfied, add `root->left->val` to `ans`.
5. Recursively call `dfs` on `root->left` and `root->right` to traverse the entire binary tree.
6. Return `ans` from the main `sumOfLeftLeaves` function.

### Visual Trace Walkthrough (Example 1: root = [3, 9, 20, null, null, 15, 7])

| Current Node (`root`) | `root->left` Check | Is Left Leaf? | Action / Update `ans` | Recursive Calls |
| :--- | :--- | :--- | :--- | :--- |
| `3` | `9` (leaf) | Yes | `ans += 9` (ans = 9) | `dfs(9)`, `dfs(20)` |
| `9` | `NULL` | No | None | `dfs(NULL)`, `dfs(NULL)` |
| `20` | `15` (leaf) | Yes | `ans += 15` (ans = 24) | `dfs(15)`, `dfs(7)` |
| `15` | `NULL` | No | None | `dfs(NULL)`, `dfs(NULL)` |
| `7` | `NULL` | No | None | `dfs(NULL)`, `dfs(NULL)` |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree, as each node is visited exactly once.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the binary tree, corresponding to the maximum depth of the recursive call stack.

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
    void dfs(TreeNode* root,int& ans){
        if(root == NULL) return;

        if(root->left != NULL && !root->left->left && !root->left->right) ans+= root->left->val;
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};
```
