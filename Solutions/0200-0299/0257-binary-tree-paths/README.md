# [257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)
**Difficulty:** `Easy` | **Tags:** `string`, `backtracking`, `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
You are given the `root` of a binary tree.

Return all **root-to-leaf** pathsin **any order**.

A **leaf** is a node with no children.

**Example 1:**

```
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
```

**Example 2:**

```
Input: root = [1]
Output: ["1"]
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 100]`.
* `-100 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
The problem requires us to find all root-to-leaf paths in a binary tree. A depth-first search (DFS) traversal naturally tracks paths from the root to the leaves by maintaining the current path elements in a temporary collection and backtracking upon returning from recursive calls.

# Approach
1. Initialize an empty result vector `ans` to store the path strings and a temporary vector `path` to track the node values along the current traversal path.
2. Define a recursive helper function `dfs(TreeNode* root, vector<string>& ans, vector<int>& path)`:
   - Base case: If `root` is `NULL`, return immediately.
   - Append `root->val` to `path`.
   - Check if `root` is a leaf node (i.e., both `root->left` and `root->right` are `NULL`). If so, construct the path string `s` by joining the elements in `path` with "->", and push `s` into `ans`.
   - Otherwise, recursively call `dfs` on `root->left` and `root->right`.
   - Backtrack by popping the last element from `path` using `path.pop_back()` before returning from the function.
3. Return `ans` from the main `binaryTreePaths` function.

### Visual Walkthrough (Example 1: root = [1, 2, 3, null, 5])
- Call `dfs(1)`: `path` becomes `[1]`
  - Call `dfs(2)`: `path` becomes `[1, 2]`
    - Call `dfs(null)` for left child: returns immediately.
    - Call `dfs(5)`: `path` becomes `[1, 2, 5]` (Leaf node)
      - Construct string: `"1->2->5"` added to `ans`.
    - Pop back 5: `path` becomes `[1, 2]`
  - Pop back 2: `path` becomes `[1]`
  - Call `dfs(3)`: `path` becomes `[1, 3]` (Leaf node)
    - Construct string: `"1->3"` added to `ans`.
  - Pop back 3: `path` becomes `[1]`
- Final Result: `["1->2->5", "1->3"]`

# Complexity
- Time complexity: $$O(N \cdot H)$$ where $$N$$ is the number of nodes in the binary tree and $$H$$ is the height of the tree. Visiting each node takes $$O(N)$$ time, and constructing the string representation at leaf nodes takes time proportional to the path length ($$O(H)$$). In the worst case, this is bounded by $$O(N \log N)$$ for balanced trees and $$O(N^2)$$ for skewed trees.
- Space complexity: $$O(H)$$ auxiliary space for the recursion stack and the temporary `path` vector, where $$H$$ is the height of the tree.

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
    void dfs(TreeNode* root, vector<string>& ans, vector<int>& path) {
        if (root == NULL) return;
        path.push_back(root->val);

        if (!root->left && !root->right) {
            string s = to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                s += "->" + to_string(path[i]);
            }
            ans.push_back(s);
        } 
        else {
            dfs(root->left, ans, path);
            dfs(root->right, ans, path);
        }
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        dfs(root, ans, path);
        return ans;
    }
};
```
