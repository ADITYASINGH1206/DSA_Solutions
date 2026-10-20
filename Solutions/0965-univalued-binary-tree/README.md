# [965. Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
A binary tree is **uni-valued** if every node in the tree has the same value.

Given the `root` of a binary tree, return `true` *if the given tree is **uni-valued**, or* `false` *otherwise.*

**Example 1:**

```
Input: root = [1,1,1,1,1,null,1]
Output: true
```

**Example 2:**

```
Input: root = [2,2,2,5,2]
Output: false
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 100]`.
* `0 <= Node.val < 100`

---

## Solution & Editorial
# Intuition
The problem asks us to determine if all nodes in a binary tree share the exact same value. We can verify this property by recursively traversing the tree using Depth-First Search (DFS) while passing along the value of the root node as a reference to compare against every visited node.

# Approach
1. Initiate the DFS check from the `root` node, capturing its value (`root->val`) as the expected constant value for the entire tree.
2. In the `dfs` helper function, check if the current node `root` is `NULL`. If so, return `true` as the base case.
3. Update `cur = root->val` and compare it with `prev`. If `prev != cur`, return `false` immediately since a node violates the univalued condition.
4. Recursively traverse the left subtree (`dfs(root->left, prev, cur)`) and right subtree (`dfs(root->right, prev, cur)`).
5. Combine the results using logical AND (`left & right`) to ensure all nodes across the tree match the initial value.

### Visual Walkthrough (Example 2: root = [2,2,2,5,2])
- `dfs(root=2, prev=2, cur=2)`: Matches `prev == cur`. Recurse left and right.
- Left child `dfs(root=2, prev=2, cur=2)`: Matches. Recurse into its children.
- Right child of left child `dfs(root=5, prev=2, cur=5)`: `prev (2) != cur (5)`, returns `false`.
- Ultimately returns `false` for the entire tree.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the tree, representing the maximum call stack depth during recursion. In the worst case (skewed tree), this is $$O(N)$$, and in the best case (balanced tree), it is $$O(\log N)$$.

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
    bool isUnivalTree(TreeNode* root) {
        bool ans = dfs(root,root->val,root->val);
        return ans;
    }
    bool dfs(TreeNode* root,int prev,int cur){
        if(root == NULL)return true;
        cur = root->val;
        if(prev != cur) return false;
        bool left = dfs(root->left,prev,cur);
        bool right = dfs(root->right,prev,cur);

        prev = cur;

        return (left&right);

    }
};
```
