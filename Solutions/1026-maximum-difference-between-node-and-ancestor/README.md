# [1026. Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, find the maximum value `v` for which there exist **different** nodes `a` and `b` where `v = |a.val - b.val|` and `a` is an ancestor of `b`.

A node `a` is an ancestor of `b` if either: any child of `a` is equal to `b` or any child of `a` is an ancestor of `b`.

**Example 1:**

```
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```

**Example 2:**

```
Input: root = [1,null,2,null,0,3]
Output: 3
```

**Constraints:**

* The number of nodes in the tree is in the range `[2, 5000]`.
* `0 <= Node.val <= 105`

---

## Solution & Editorial
# Intuition
To find the maximum absolute difference between any ancestor node $a$ and any descendant node $b$, we need to track the minimum and maximum values encountered along every root-to-leaf path. As we traverse down the binary tree, any node we visit can potentially form the maximum difference with the minimum or maximum value seen so far on its path from the root.

# Approach
1. Initialize an integer `ans` to store the maximum difference found so far.
2. Define a helper function `dfs(TreeNode* root, int mini, int maxi, int& ans)` that recursively traverses the tree.
3. At each node, update `ans` with the maximum of the absolute differences: `abs(root->val - mini)` and `abs(root->val - maxi)`.
4. Update `mini` to be the minimum of `mini` and `root->val`, and `maxi` to be the maximum of `maxi` and `root->val`.
5. Recursively invoke `dfs` on `root->left` and `root->right` passing along the updated `mini`, `maxi`, and `ans` reference.
6. Return `ans` from the main `maxAncestorDiff` function after initiating the DFS with the root's value as both initial `mini` and `maxi`.

### Visual Walkthrough (Example 1: root = [8,3,10,1,6,null,14,...])
- Start at root `8`: `mini = 8`, `maxi = 8`, `ans = 0`.
- Move to left child `3`: `ans = max(0, max(|3-8|, |3-8|)) = 5`. Update `mini = 3`, `maxi = 8`.
- Move to left child `1`: `ans = max(5, max(|1-3|, |1-8|)) = 7`. Update `mini = 1`, `maxi = 8`.
- The traversal continues down all branches, updating the global `ans` whenever a larger difference is discovered.

# Complexity
- Time complexity: $$O(N)$$ — We visit each of the $N$ nodes in the binary tree exactly once during the depth-first search.
- Space complexity: $$O(H)$$ — The auxiliary space is determined by the recursion call stack, which takes $$O(H)$$ where $H$ is the height of the binary tree (at most $$O(N)$$ for a skewed tree and $$O(\log N)$$ for a balanced tree).

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
    void dfs(TreeNode* root,int mini,int maxi,int& ans){
        if(root == NULL) return;

        ans = max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
        mini = min(mini,root->val);
        maxi = max(maxi,root->val);

        dfs(root->left,mini,maxi,ans);
        dfs(root->right,mini,maxi,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root,root->val,root->val,ans);
        return ans;

    }
};
```
