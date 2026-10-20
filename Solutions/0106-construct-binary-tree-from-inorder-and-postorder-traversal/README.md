# [106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `divide-and-conquer`, `tree`, `binary-tree`

---

## Problem Description
Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return *the binary tree*.

**Example 1:**

```
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
```

**Example 2:**

```
Input: inorder = [-1], postorder = [-1]
Output: [-1]
```

**Constraints:**

* `1 <= inorder.length <= 3000`
* `postorder.length == inorder.length`
* `-3000 <= inorder[i], postorder[i] <= 3000`
* `inorder` and `postorder` consist of **unique** values.
* Each value of `postorder` also appears in `inorder`.
* `inorder` is **guaranteed** to be the inorder traversal of the tree.
* `postorder` is **guaranteed** to be the postorder traversal of the tree.

---

## Solution & Editorial
# Intuition
The postorder traversal always places the root node at the very end of its sequence, while the inorder traversal splits the tree into left subtree, root, and right subtree. By maintaining a hash map for fast index lookups of values in the inorder array and passing a decreasing index pointer for the postorder array, we can recursively reconstruct the binary tree in linear time.

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
    
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        return helper(postorder, 0, inorder.size() - 1,index);
    }

    TreeNode* helper(vector<int>& postorder, int start, int end,int& index) {
        if (start > end) return nullptr;

        int rootVal = postorder[index--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal];

        root->right = helper(postorder, mid + 1, end,index);
        root->left = helper(postorder, start, mid - 1,index);
        
        return root;
    }
};
```
