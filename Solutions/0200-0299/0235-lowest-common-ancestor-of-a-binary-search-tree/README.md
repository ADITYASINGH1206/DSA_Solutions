# [235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-search-tree`, `binary-tree`, `binary-lifting`, `lowest-common-ancestor`

---

## Problem Description
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

**Example 1:**

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```

**Example 2:**

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
Input: root = [2,1], p = 2, q = 1
Output: 2
```

**Constraints:**

* The number of nodes in the tree is in the range `[2, 105]`.
* `-109 <= Node.val <= 109`
* All `Node.val` are **unique**.
* `p != q`
* `p` and `q` will exist in the BST.

---

## Solution & Editorial
# Intuition
By leveraging the structural properties of a Binary Search Tree (BST), where all left subtree nodes are smaller than the root and all right subtree nodes are larger, we can determine the divergence point of nodes `p` and `q` simply by comparing their values against the current node's value.

# Approach
1. Check if the current `root` is `NULL`; if so, return `NULL`.
2. If both `p->val` and `q->val` are greater than `root->val`, the lowest common ancestor must lie in the right subtree. Recursively call `lowestCommonAncestor` on `root->right`.
3. If both `p->val` and `q->val` are smaller than `root->val`, the LCA must lie in the left subtree. Recursively call `lowestCommonAncestor` on `root->left`.
4. Otherwise, the current `root` value lies between `p->val` and `q->val` (inclusive, or equals one of them), meaning the current `root` is the split point (LCA). Return `root`.

### Visual Walkthrough (Example 1)
Tree: root = [6, 2, 8], p = 2, q = 8

| Step | Current Root | p->val | q->val | Comparison | Action |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 6 | 2 | 8 | Neither both < 6 nor both > 6 | Returns 6 (Split point) |

# Complexity
- Time complexity: $$O(H)$$ where $$H$$ is the height of the BST. In the worst case (skewed tree), this takes $$O(N)$$ time, and in a balanced BST, it takes $$O(\log N)$$ time.
- Space complexity: $$O(H)$$ for the recursive call stack space, mirroring the height of the tree.

# Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }

        return root;
    }
};
```
