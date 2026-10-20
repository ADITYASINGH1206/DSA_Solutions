# [872. Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a **leaf value sequence***.*

For example, in the given tree above, the leaf value sequence is `(6, 7, 4, 9, 8)`.

Two binary trees are considered *leaf-similar* if their leaf value sequence is the same.

Return `true` if and only if the two given trees with head nodes `root1` and `root2` are leaf-similar.

**Example 1:**

```
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
```

**Example 2:**

```
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
```

**Constraints:**

* The number of nodes in each tree will be in the range `[1, 200]`.
* Both of the given trees will have values in the range `[0, 200]`.

---

## Solution & Editorial
# Intuition
The problem requires us to determine if two binary trees share the exact same leaf value sequence from left to right. We can extract the leaf nodes of both trees independently using a standard Depth-First Search (DFS) traversal and compare the resulting vectors element by element.

# Approach
1. Define a recursive helper function `dfs(TreeNode* root, vector<int>& leaves)` that traverses the tree in pre-order (root, left, right).
2. Inside `dfs`, check if the current node `root` is `NULL`. If so, return immediately.
3. If `root` has no left or right children (`root->left == NULL && root->right == NULL`), append its value `root->val` to the `leaves` vector.
4. Recursively call `dfs` on `root->left` and then `root->right`.
5. In `leafSimilar`, initialize two vectors `leaves1` and `leaves2`, and populate them by calling `dfs` on `root1` and `root2` respectively.
6. Compare the sizes of `leaves1` and `leaves2`. If they differ in length, return `false` immediately.
7. Iterate through both vectors to verify if all corresponding leaf values match. If any mismatch occurs, return `false`; otherwise, return `true`.

### Visual Walkthrough (Example 2)
- `root1 = [1, 2, 3]` -> Leaves extracted: `leaves1 = [2, 3]`
- `root2 = [1, 3, 2]` -> Leaves extracted: `leaves2 = [3, 2]`
- Comparison: `leaves1[0] (2) != leaves2[0] (3)` -> Returns `false`.

# Complexity
- Time complexity: $$O(N + M)$$ where $$N$$ and $$M$$ are the number of nodes in `root1` and `root2` respectively. Each node is visited once during the DFS traversal, and comparing the two leaf sequences takes linear time relative to the number of leaves.
- Space complexity: $$O(H_1 + H_2)$$ where $$H_1$$ and $$H_2$$ are the maximum heights of the two binary trees, accounting for the recursion stack space, plus additional storage for the leaf vectors.

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
    void dfs(TreeNode* root,vector<int>& leaves){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL) leaves.push_back(root->val);
        dfs(root->left,leaves);
        dfs(root->right,leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1,leaves1);
        dfs(root2,leaves2);
        int n1 = leaves1.size();
        int n2 = leaves2.size();
        if(n1 != n2) return false;
        for(int i = 0;i<n1;i++){
            if(leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
};
```
