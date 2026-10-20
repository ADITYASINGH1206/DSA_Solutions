# [1123. Lowest Common Ancestor of Deepest Leaves](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`, `binary-lifting`, `lowest-common-ancestor`, `dp-on-trees`

---

## Problem Description
Given the `root` of a binary tree, return *the lowest common ancestor of its deepest leaves*.

Recall that:

* The node of a binary tree is a leaf if and only if it has no children
* The depth of the root of the tree is `0`. if the depth of a node is `d`, the depth of each of its children is `d + 1`.
* The lowest common ancestor of a set `S` of nodes, is the node `A` with the largest depth such that every node in `S` is in the subtree with root `A`.

**Example 1:**

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
```

**Example 2:**

```
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.
```

**Example 3:**

```
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
```

**Constraints:**

* The number of nodes in the tree will be in the range `[1, 1000]`.
* `0 <= Node.val <= 1000`
* The values of the nodes in the tree are **unique**.

**Note:** This question is the same as 865: <https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/>

---

## Solution & Editorial
# Intuition
To find the lowest common ancestor (LCA) of the deepest leaves, we first need to determine the maximum depth of the binary tree. Once we know the maximum depth (`maxi`), any node at depth `maxi - 1` whose left and right subtrees both reach the maximum depth must be the LCA of the deepest leaves. We can combine a helper function to compute tree depth with a post-order traversal to pinpoint this node.

# Approach
1. Compute the maximum depth of the binary tree using a helper function `maxDepth`.
2. Use a recursive DFS helper `dfs(root, maxi, len)` to traverse the tree where `len` tracks the current depth of `root`.
3. Base case: If `root` is `nullptr`, return `nullptr`.
4. If the current depth `len` is equal to `maxi - 1`, the current node is the parent of a deepest leaf (or is itself a deepest leaf when `maxi == 1`). However, to handle general depths cleanly, we check if both subtrees reach the target maximum depth.
5. Recursively find the result in the left subtree (`left`) and right subtree (`right`).
6. If both `left` and `right` are non-null, the current `root` is the LCA of the deepest leaves.
7. Otherwise, return the non-null child among `left` and `right` (or `nullptr` if neither reaches the max depth).

### Visual Trace Walkthrough (Example 1: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4])
- `maxDepth(root)` computes `maxi = 3` (depths: root at 0, leaves 7 and 4 at 3).
- `dfs(root = 3, maxi = 3, len = 0)`:
  - Left child 5: `dfs(5, 3, 1)` -> returns node `2` (since its subtrees contain leaves 7 and 4 at depth 3).
  - Right child 1: `dfs(1, 3, 1)` -> returns `nullptr` (subtrees do not reach depth 3).
- Since `left` returns node `2` and `right` returns `nullptr`, `dfs` returns node `2` as the final LCA.

# Complexity
- Time complexity: $$O(N)$$ — We visit each node twice: once in `maxDepth` to find the maximum depth and once in `dfs` to locate the LCA, where $$N$$ is the number of nodes in the tree.
- Space complexity: $$O(H)$$ — The auxiliary space is determined by the recursion call stack, where $$H$$ is the height of the binary tree ($$O(N)$$ in the worst-case skewed tree, $$O(\log N)$$ for a balanced tree).

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxi = maxDepth(root); 
        return dfs(root, maxi, 0);
    }

    TreeNode* dfs(TreeNode* root, int maxi, int len) {
        if (!root) return nullptr;  
        if (maxi - 1 == len) return root;
        TreeNode* left = dfs(root->left, maxi, len + 1);
        TreeNode* right = dfs(root->right, maxi, len + 1);
        
        if (left && right) return root;
        return left ? left : right;
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```
