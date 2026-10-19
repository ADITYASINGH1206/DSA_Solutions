# [226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, invert the tree, and return *its root*.

**Example 1:**

```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
```

**Example 2:**

```
Input: root = [2,1,3]
Output: [2,3,1]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
To invert a binary tree, we must recursively visit every node and swap its left and right child pointers. Once the pointers are swapped, we recursively apply the same inversion process to both the newly positioned left and right subtrees.

# Approach
1. Base Case: Check if the current node `root` is `nullptr`. If it is, return `nullptr` to terminate the recursion for leaf node children.
2. Swap: Use the standard library function `swap(root->left, root->right)` to interchange the left and right children of the current `root` node.
3. Recurse: Recursively call `invertTree(root->left)` and `invertTree(root->right)` to process all descendants.
4. Return: Return the modified `root` node back up the call stack.

### Visual Trace Walkthrough (Example 1: root = [4, 2, 7, 1, 3, 6, 9])
```
Initial Tree:
      4
    /   \
   2     7
  / \   / \
 1   3 6   9

Step 1: At root = 4, swap left (2) and right (7).
      4
    /   \
   7     2
  / \   / \
 ... ... ...

Step 2: Recurse left (root = 7), swap its children (6 and 9).
Step 3: Recurse right (root = 2), swap its children (1 and 3).
Final Tree:
      4
    /   \
   7     2
  / \   / \
 9   6 3   1
```

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the binary tree, representing the maximum call stack depth during recursion. In the worst case (skewed tree), this is $$O(N)$$, and in the best case (balanced tree), it is $$O(\log N)$$.

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```
