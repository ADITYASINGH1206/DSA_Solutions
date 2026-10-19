# [865. Smallest Subtree with all the Deepest Nodes](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`, `binary-lifting`, `lowest-common-ancestor`, `dp-on-trees`

---

## Problem Description
Given the `root` of a binary tree, the depth of each node is **the shortest distance to the root**.

Return *the smallest subtree* such that it contains **all the deepest nodes** in the original tree.

A node is called **the deepest** if it has the largest depth possible among any node in the entire tree.

The **subtree** of a node is a tree consisting of that node, plus the set of all descendants of that node.

**Example 1:**

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
```

**Example 2:**

```
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
```

**Example 3:**

```
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
```

**Constraints:**

* The number of nodes in the tree will be in the range `[1, 500]`.
* `0 <= Node.val <= 500`
* The values of the nodes in the tree are **unique**.

**Note:** This question is the same as 1123: <https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/>

---

## Solution & Editorial
# Intuition
To find the smallest subtree containing all the deepest nodes, we need to locate the lowest common ancestor (LCA) of all nodes that attain the maximum depth of the binary tree. If the deepest nodes are split between the left and right subtrees of a node, then that current node is precisely the LCA we are looking for. Otherwise, the LCA must lie entirely within the subtree containing the deepest nodes.

# Approach
1. First, we compute the maximum depth of the tree using a helper function `maxi(root)`, which returns the height of the tree rooted at `root`.
2. Next, we use a recursive depth-first search (`dfs`) function to traverse the tree keeping track of the current path length (`len`).
3. If the remaining height needed to reach the maximum depth matches the current level (`maxi - 1 == len`), the current node is a deepest leaf or an ancestor of the deepest leaves. However, to find the exact LCA, we recursively search both left and right children.
4. If both left and right recursive calls return non-null pointers, it signifies that the deepest nodes are present in both subtrees, making the current node the required LCA. If only one side returns a non-null pointer, we propagate that pointer upward.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree. We traverse the tree twice: once to compute the maximum height and once to locate the lowest common ancestor.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the tree, consumed by the recursion stack during the depth-first traversals.

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
    int maxi(TreeNode* root){
        if(!root) return 0;
        int lh = maxi(root->left);
        int rh = maxi(root->right);

        return 1 + max(lh,rh);
    }
    TreeNode* dfs(TreeNode* root, int maxi, int len) {
        if (!root) return nullptr;  
        if (maxi - 1 == len) return root;
        TreeNode* left = dfs(root->left, maxi, len + 1);
        TreeNode* right = dfs(root->right, maxi, len + 1);
        
        if (left && right) return root;
        return left ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxx = maxi(root);
        return dfs(root,maxx,0);
    }
};
```
