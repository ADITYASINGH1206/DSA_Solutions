# [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-tree`, `binary-lifting`, `lowest-common-ancestor`

---

## Problem Description
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

**Example 1:**

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

**Example 2:**

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
Input: root = [1,2], p = 1, q = 2
Output: 1
```

**Constraints:**

* The number of nodes in the tree is in the range `[2, 105]`.
* `-109 <= Node.val <= 109`
* All `Node.val` are **unique**.
* `p != q`
* `p` and `q` will exist in the tree.

---

## Solution & Editorial
# Intuition
The problem asks for the lowest common ancestor (LCA) of two nodes, `p` and `q`, in a binary tree. By leveraging post-order DFS traversal, we can inspect subtrees bottom-up. If a node matches `p` or `q`, or is `NULL`, we return it immediately. As recursive calls bubble up, if both left and right subtrees return non-NULL pointers, the current node is the exact split point where `p` and `q` reside in separate branches, making it their lowest common ancestor.

# Approach
1. Base Case: Check if the current `root` is `NULL`, `p`, or `q`. If so, return `root`. This handles both hitting a null leaf and finding one of the target nodes.
2. Recursive Step: Recursively search for `p` and `q` in the left subtree (`lowestCommonAncestor(root->left, p, q)`) and the right subtree (`lowestCommonAncestor(root->right, p, q)`).
3. Combine Results:
   - If `left` is `NULL`, it means neither `p` nor `q` were found in the left subtree (or they are in the right subtree), so return `right`.
   - If `right` is `NULL`, return `left`.
   - If both `left` and `right` are non-`NULL`, it implies `p` and `q` are located in distinct subtrees of the current `root`, making `root` the LCA. Thus, return `root`.

### Visual Trace (Example 1)
Tree: Root `3`, with `p = 5` and `q = 1`.
- DFS goes down to node `5`: matches `p`, returns `5`.
- DFS goes down to node `1`: matches `q`, returns `1`.
- At root `3`: `left` returns `5`, `right` returns `1`. Since both are non-`NULL`, root `3` is returned as the LCA.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree. In the worst case, every node is visited once during the depth-first search.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the binary tree, consumed by the recursion stack. In the worst case of a skewed tree, this is $$O(N)$$, and for a balanced tree, it is $$O(\log N)$$.

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
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == NULL){
            return right;
        }else if(right == NULL){
            return left;
        }else{
            return root;
        }
    }
};
```
