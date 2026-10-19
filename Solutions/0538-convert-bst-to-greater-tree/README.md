# [538. Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-search-tree`, `binary-tree`

---

## Problem Description
Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a *binary search tree* is a tree that satisfies these constraints:

* The left subtree of a node contains only nodes with keys **less than** the node's key.
* The right subtree of a node contains only nodes with keys **greater than** the node's key.
* Both the left and right subtrees must also be binary search trees.

**Example 1:**

```
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

**Example 2:**

```
Input: root = [0,null,1]
Output: [1,null,1]
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 104]`.
* `-104 <= Node.val <= 104`
* All the values in the tree are **unique**.
* `root` is guaranteed to be a valid binary search tree.

**Note:** This question is the same as 1038: <https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/>

---

## Solution & Editorial
# Intuition
The problem requires transforming a Binary Search Tree (BST) into a Greater Tree where each node's value is updated to the sum of all keys greater than or equal to its original value. In a BST, the keys are ordered such that a node's right subtree contains strictly greater values, and its left subtree contains smaller values. By traversing the tree in a reverse in-order sequence (Right -> Root -> Left), we visit the nodes in descending order of their values. Maintaining a running cumulative sum allows us to accumulate the total of all previously visited (larger) nodes and update the current node in a single pass.

# Approach
1. Initialize a running sum integer `cur` to `0` to keep track of the cumulative sum of nodes with greater values.
2. Define a helper function `postorder(TreeNode* root, int& cur)` that performs a reverse in-order traversal: 
   - Base case: If `root` is `NULL`, return immediately.
   - Recursively traverse the right subtree: `postorder(root->right, cur);`
   - Update the running sum by adding the current node's value: `cur += root->val;`
   - Assign the updated cumulative sum back to the current node: `root->val = cur;`
   - Recursively traverse the left subtree: `postorder(root->left, cur);`
3. Call the helper function starting at the `root` and return the modified `root`.

### Visual Trace Walkthrough
Consider a simple BST with values `[2, 1, 3]`: 
- Start `cur = 0`.
- Visit rightmost node `3`: `cur` becomes `0 + 3 = 3`, node `3` becomes `3`.
- Visit root node `2`: `cur` becomes `3 + 2 = 5`, node `2` becomes `5`.
- Visit leftmost node `1`: `cur` becomes `5 + 1 = 6`, node `1` becomes `6`.
- Final tree values: root `2` becomes `5`, left `1` becomes `6`, right `3` becomes `3`.

# Complexity
- Time complexity: $$O(N)$$ — Each node in the BST is visited exactly once during the traversal, where $$N$$ is the total number of nodes.
- Space complexity: $$O(H)$$ — The auxiliary stack space is proportional to the height of the tree $$H$$ ($$O(\log N)$$ for balanced trees, up to $$O(N)$$ in the worst-case skewed tree).

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
    TreeNode* convertBST(TreeNode* root) {
        int cur = 0;
        postorder(root,cur);
        return root;

    }
    void postorder(TreeNode* root,int& cur){
        if(root == NULL) return;

        postorder(root->right,cur);
        cur+= root->val;
        root->val = cur;
        postorder(root->left,cur);
        
    }
};
```
