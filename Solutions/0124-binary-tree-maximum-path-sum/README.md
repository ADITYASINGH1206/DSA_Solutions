# [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
**Difficulty:** `Hard` | **Tags:** `dynamic-programming`, `tree`, `depth-first-search`, `binary-tree`, `dp-on-trees`

---

## Problem Description
A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return *the maximum **path sum** of any **non-empty** path*.

**Example 1:**

```
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
```

**Example 2:**

```
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 3 * 104]`.
* `-1000 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks for the maximum path sum in a binary tree, where a path can start and end at any node. For any given node, a valid path passing through it as the highest point (turning point) consists of the node's value plus the maximum single-branch path sum from its left child and its right child. We can use a bottom-up depth-first search (DFS) to compute the maximum gain from each subtree while dynamically updating the global maximum path sum.

# Approach
1. Initialize a global variable `ans` to `INT_MIN` to keep track of the maximum path sum found so far.
2. Define a recursive helper function `maxPath(node, ans)` that returns the maximum path sum obtainable by extending a single branch downwards from the current `node`.
3. Base Case: If `node` is `NULL`, return `0` since a null child contributes nothing to the path sum.
4. Recursive Steps: Recursively compute the maximum contribution of the left child (`lh`) and right child (`rh`). To handle negative path sums, use `max(0, ...)` so that any negative subpath is discarded.
5. Update Global Maximum: At the current `node`, compute the path sum passing through it as a peak: `node->val + lh + rh`. Update `ans = max(ans, node->val + lh + rh)`.
6. Return Branch Sum: Return the maximum single-branch sum that can be extended upwards to the parent, which is `node->val + max(lh, rh)`.

### Visual Walkthrough for Example 1: `root = [1, 2, 3]`

| Node | Left Child (`lh`) | Right Child (`rh`) | Peak Path Sum (`node->val + lh + rh`) | Global Max (`ans`) | Returned Branch Sum (`node->val + max(lh, rh)`) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `2` (Left) | `0` (null) | `0` (null) | `2 + 0 + 0 = 2` | `2` | `2 + 0 = 2` |
| `3` (Right) | `0` (null) | `0` (null) | `3 + 0 + 0 = 3` | `3` | `3 + 0 = 3` |
| `1` (Root) | `max(0, 2) = 2` | `max(0, 3) = 3` | `1 + 2 + 3 = 6` | `6` | `1 + max(2, 3) = 4` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once during the post-order DFS traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree. This accounts for the maximum depth of the recursive call stack, which is $$O(N)$$ in the worst-case skewed tree and $$O(\log N)$$ in a balanced tree.

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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPath(root,ans);
        return ans;
    }
    int maxPath(TreeNode* node,int& ans){
        if(node == NULL){
            return 0;
        }

        int lh = max(0,maxPath(node->left,ans));
        int rh = max(0,maxPath(node->right,ans));

        ans = max(ans,node->val + lh+rh);

        return node->val + max(lh,rh);
    }
    
};
```
