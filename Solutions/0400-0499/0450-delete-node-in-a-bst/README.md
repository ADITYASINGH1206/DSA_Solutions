# [450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)
**Difficulty:** `Medium` | **Tags:** `tree`, `binary-search-tree`, `binary-tree`

---

## Problem Description
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return *the **root node reference** (possibly updated) of the BST*.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

**Example 1:**

```
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
```

**Example 2:**

```
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
```

**Example 3:**

```
Input: root = [], key = 0
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 104]`.
* `-105 <= Node.val <= 105`
* Each node has a **unique** value.
* `root` is a valid binary search tree.
* `-105 <= key <= 105`

**Follow up:** Could you solve it with time complexity `O(height of tree)`?

---

## Solution & Editorial
# Intuition
The problem requires deleting a node from a Binary Search Tree (BST) while preserving the BST property. Since a BST has the property that elements in the left subtree are smaller and elements in the right subtree are larger, we can locate the node to be deleted in $$O(H)$$ time by comparing the target key with the current node's value. Once the node is found, we handle the deletion based on the presence of its children: zero, one, or two children.

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);     
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) return NULL;          
                if (root->left && !root->right)
                    return root->left;
                if(!root->left && root->right){
                    return root->right;
                }  
                TreeNode* left = root->left;  
                TreeNode* right = root->right;                      
                while(left->right != NULL) left = left->right;     
                left->right = right;                            
                return root->left;
            }
        return root;
    }   
};
```
