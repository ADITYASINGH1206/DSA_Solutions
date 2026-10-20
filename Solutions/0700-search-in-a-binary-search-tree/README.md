# [700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `binary-search-tree`, `binary-tree`

---

## Problem Description
You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

**Example 1:**

```
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
```

**Example 2:**

```
Input: root = [4,2,7,1,3], val = 5
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 5000]`.
* `1 <= Node.val <= 107`
* `root` is a binary search tree.
* `1 <= val <= 107`

---

## Solution & Editorial
# Intuition
The problem asks us to locate a specific value within a Binary Search Tree (BST) and return the subtree rooted at that node. By definition, a BST satisfies the property that for any node, all values in its left subtree are smaller and all values in its right subtree are larger. This structural invariant allows us to eliminate half of the search space at each step without checking every node.

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if(root->val == val) return root;
        else if(root->val > val) return searchBST(root->left,val);
        else return searchBST(root->right, val);  

        
    }
};
```
