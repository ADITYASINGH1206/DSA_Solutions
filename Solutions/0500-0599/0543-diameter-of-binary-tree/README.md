# [543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `binary-tree`, `dp-on-trees`

---

## Problem Description
Given the `root` of a binary tree, return *the length of the **diameter** of the tree*.

The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The **length** of a path between two nodes is represented by the number of edges between them.

**Example 1:**

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

**Example 2:**

```
Input: root = [1,2]
Output: 1
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 104]`.
* `-100 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
The diameter of a binary tree is the longest path between any two nodes, measured in edges. For any given node, the longest path passing through it is the sum of the height of its left subtree and the height of its right subtree. By performing a post-order traversal, we can simultaneously compute the height of each subtree and update the maximum diameter encountered so far.

# Approach
1. Initialize an integer variable `ans` to 0, which will track the maximum diameter found across all nodes.
2. Define a helper function `checkHeight(TreeNode* root, int& ans)` that returns the height of the subtree rooted at `root` and updates `ans` using the sum of the left and right heights (`lh + rh`).
3. Base case: If `root` is `NULL`, return `0`.
4. Recursively compute the left height `lh` and right height `rh` by calling `checkHeight` on `root->left` and `root->right` respectively.
5. Update `ans = max(ans, lh + rh)` to capture the path passing through the current node.
6. Return the height of the current node as `1 + max(lh, rh)` to its parent.

### Visual Dry Run (Example 1)
Tree: `[1, 2, 3, 4, 5]`

| Node | Left Height (`lh`) | Right Height (`rh`) | Path Through Node (`lh + rh`) | Max Diameter (`ans`) | Returned Height (`1 + max`) |
| :--- | :---: | :---: | :---: | :---: | :---: |
| 4 | 0 | 0 | 0 | 0 | 1 |
| 5 | 0 | 0 | 0 | 0 | 1 |
| 2 | 1 | 1 | 2 | 2 | 2 |
| 3 | 0 | 0 | 0 | 2 | 1 |
| 1 | 2 | 1 | 3 | 3 | 3 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once during the post-order traversal.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the binary tree. This accounts for the recursive call stack space, which is $$O(N)$$ in the worst-case skewed tree and $$O(\log N)$$ for a balanced tree.

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        checkHeight(root,ans);
        return ans;

    }
    int checkHeight(TreeNode* root,int& ans){
        if(root == NULL) return 0;

        int lh = checkHeight(root->left,ans);
        int rh = checkHeight(root->right,ans);

        ans = max(ans,lh+rh);

        return 1+ max(lh,rh);
    }
};
```
