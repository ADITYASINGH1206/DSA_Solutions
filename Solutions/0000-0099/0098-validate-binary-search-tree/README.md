# [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-search-tree`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST)*.

A **valid BST** is defined as follows:

* The left subtree of a node contains only nodes with keys **strictly less than** the node's key.
* The right subtree of a node contains only nodes with keys **strictly greater than** the node's key.
* Both the left and right subtrees must also be binary search trees.

**Example 1:**

```
Input: root = [2,1,3]
Output: true
```

**Example 2:**

```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 104]`.
* `-231 <= Node.val <= 231 - 1`

---

## Solution & Editorial
# Intuition
To determine if a binary tree is a valid Binary Search Tree (BST), we must ensure that every node's value falls within a valid, dynamically restricted range. Simply checking whether a child node is less than or greater than its immediate parent is insufficient, as descendants in the left or right subtrees must also respect ancestral bounds.

# Approach
1. Use a helper function `isValidBST(TreeNode* root, long mini, long maxi)` that passes down allowable lower (`mini`) and upper (`maxi`) limits.
2. For the root node, initialize the bounds to `LLONG_MIN` and `LLONG_MAX` to accommodate the full 32-bit integer range.
3. At each node, check if `root->val` strictly violates the inequality `mini < root->val < maxi`. If `root->val <= mini` or `root->val >= maxi`, return `false`.
4. Recursively validate the left child by updating the upper bound to the current node's value (`root->val`), and validate the right child by updating the lower bound to `root->val`.

### Visual Walkthrough for Example 1: `root = [2, 1, 3]`

| Call | `root->val` | `mini` | `maxi` | Action / Check | Return Value |
| :--- | :---: | :---: | :---: | :--- | :---: |
| `isValidBST(2)` | `2` | `LLONG_MIN` | `LLONG_MAX` | Within bounds | Proceeds to children |
| `isValidBST(1)` | `1` | `LLONG_MIN` | `2` | `1 < 2`, valid | `true` |
| `isValidBST(3)` | `3` | `2` | `LLONG_MAX` | `2 < 3`, valid | `true` |
| **Overall** | - | - | - | Both subtrees valid | **`true`** |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Each node is visited exactly once during the depth-first traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the tree. This accounts for the maximum call stack depth during recursion, which is $$O(N)$$ in the worst-case skewed tree and $$O(\log N)$$ for a balanced tree.

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
class Solution{
    public:
        bool isValidBST(TreeNode* root){
            return isValidBST(root,LLONG_MIN,LLONG_MAX);
        }
        bool isValidBST(TreeNode* root,long mini,long maxi){
            if(root == NULL)return true;
            if(root->val >= maxi || root->val <= mini) return false;
            return isValidBST(root->left,mini,root->val) && isValidBST(root->right,root->val,maxi);
        }
};
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         vector<int> result;
//         traverse(root,result);
//         int n = result.size();
//         if(n>1){
//             for(int i =1;i<n;i++){
//                 if(result[i]<=result[i-1]) return false;
//             }
//         }
//         return true;
//     }
    
//     void traverse(TreeNode* root,vector<int>& result){
//         if(root == NULL) return;

//         traverse(root->left,result);
//         result.push_back(root->val);
//         traverse(root->right,result);
//     }
// };
```
