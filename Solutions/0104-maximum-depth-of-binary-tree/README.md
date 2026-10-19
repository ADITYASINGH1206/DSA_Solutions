# [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *its maximum depth*.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Example 1:**

```
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

**Example 2:**

```
Input: root = [1,null,2]
Output: 2
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 104]`.
* `-100 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
The maximum depth of a binary tree is defined as the maximum number of nodes along any path from the root node down to the farthest leaf node. This property naturally lends itself to a recursive divide-and-conquer approach, where the maximum depth at any given node is 1 plus the maximum of the depths of its left and right subtrees.

# Approach
1. Base Case: Check if the current node `root` is `NULL`. If it is, the depth of the empty tree is `0`, so return `0`.
2. Recursive Step: Recursively compute the maximum depth of the left subtree by calling `maxDepth(root->left)` and store it in `lh`.
3. Recursive Step: Recursively compute the maximum depth of the right subtree by calling `maxDepth(root->right)` and store it in `rh`.
4. Combine: Return `1 + max(lh, rh)` to account for the current node plus the deeper of its two child branches.

### Visual Walkthrough for Example 1: root = [3, 9, 20, null, null, 15, 7]

| Call Stack / Node | `root->left` Depth (`lh`) | `root->right` Depth (`rh`) | Return Value (`1 + max(lh, rh)`) |
| :--- | :--- | :--- | :--- |
| `maxDepth(3)` | `maxDepth(9)` $ightarrow$ `1` | `maxDepth(20)` $ightarrow$ `2` | `1 + max(1, 2) = 3` |
| `maxDepth(9)` | `maxDepth(NULL)` $ightarrow$ `0` | `maxDepth(NULL)` $ightarrow$ `0` | `1 + max(0, 0) = 1` |
| `maxDepth(20)`| `maxDepth(15)` $ightarrow$ `1` | `maxDepth(7)` $ightarrow$ `1` | `1 + max(1, 1) = 2` |
| `maxDepth(15)`| `0` | `0` | `1 + max(0, 0) = 1` |
| `maxDepth(7)` | `0` | `0` | `1 + max(0, 0) = 1` |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once during the traversal.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the binary tree. This accounts for the maximum memory utilized by the recursive call stack, which in the worst-case (skewed tree) is $$O(N)$$ and in the best-case (balanced tree) is $$O(\log N)$$.

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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh,rh);
    }


};
```
