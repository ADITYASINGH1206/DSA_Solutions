# [1038. Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)
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

* The number of nodes in the tree is in the range `[1, 100]`.
* `0 <= Node.val <= 100`
* All the values in the tree are **unique**.

**Note:** This question is the same as 538: <https://leetcode.com/problems/convert-bst-to-greater-tree/>

---

## Solution & Editorial
# Intuition
To convert a Binary Search Tree (BST) into a Greater Sum Tree, each node's value must be updated to the sum of all keys greater than or equal to its own key. In a BST, keys larger than a given node are located in its right subtree, and further nodes larger than it lie up its ancestor chain (which corresponds to visiting nodes in descending order). By performing a reverse in-order traversal (Right -> Root -> Left), we visit nodes from largest to smallest, maintaining a running prefix sum of all processed nodes.

# Approach
1. Initialize a cumulative sum variable `cur` to `0` inside `bstToGst`.
2. Pass `cur` by reference into a recursive helper function `postorder` (which implements a reverse in-order traversal).
3. In the helper function, recursively traverse the `root->right` subtree first.
4. Add the current node's `root->val` to `cur`, then update `root->val = cur`.
5. Recursively traverse the `root->left` subtree.
6. Return the modified `root` pointer.

### Visual Trace (Example 1 Root Node 4)
Reverse in-order visits nodes in order: `8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0`

| Visited Node | `cur` Before Update | `root->val` Updated to (`cur`) |
|:---:|:---:|:---:|
| 8 | 0 | 8 |
| 7 | 8 | 15 |
| 6 | 15 | 21 |
| 5 | 21 | 26 |
| 4 | 26 | 30 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the BST. Each node is visited exactly once during the recursive traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the tree, corresponding to the maximum depth of the recursive call stack. In the worst case (skewed tree), this is $$O(N)$$; in the best case (balanced tree), it is $$O(\log N)$$.

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
    TreeNode* bstToGst(TreeNode* root) {
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
