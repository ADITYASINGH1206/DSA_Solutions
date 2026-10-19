# [993. Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree with unique values and the values of two different nodes of the tree `x` and `y`, return `true` *if the nodes corresponding to the values* `x` *and* `y` *in the tree are **cousins**, or* `false` *otherwise.*

Two nodes of a binary tree are **cousins** if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth `0`, and children of each depth `k` node are at the depth `k + 1`.

**Example 1:**

```
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
```

**Example 2:**

```
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
```

**Example 3:**

```
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
```

**Constraints:**

* The number of nodes in the tree is in the range `[2, 100]`.
* `1 <= Node.val <= 100`
* Each node has a **unique** value.
* `x != y`
* `x` and `y` are exist in the tree.

---

## Solution & Editorial
# Intuition
Two nodes are considered cousins if they reside at the exact same depth within the binary tree but stem from different parent nodes. By utilizing a Depth-First Search (DFS) traversal, we can record both the parent node's value and the absolute depth for each target value ($x$ and $y$). Once both values are queried, we verify if their depths match while their parent values differ.

# Approach
1. Define a helper function `dfs` that traverses the binary tree while tracking the current node's `parent`, target value `x`, an output array `ans` of size 2 storing `[parent_value, depth]`, and the current `depth`.
2. In `dfs`, if `root` is `NULL`, return immediately. Increment `depth` upon entering a node. If `root->val == x`, record `parent->val` into `ans[0]` and `depth` into `ans[1]`, then return.
3. Recursively call `dfs` on `root->left` and `root->right` with the updated `parent` set to `root`.
4. In `isCousins`, instantiate two separate result containers `t1` and `t2` for target values `x` and `y` respectively.
5. Execute `dfs` for both targets starting from the `root`.
6. Compare the results: return `true` if `t1[0] != t2[0]` (different parents) and `t1[1] == t2[1]` (same depth), otherwise return `false`.

### Visual Walkthrough (Example 2)
Tree: `root = [1, 2, 3, null, 4, null, 5]`, `x = 5`, `y = 4`

- Traversing for `x = 5` (`t1`):
  - Reaches node `5` at depth `3` with parent node `3` -> `t1 = {3, 3}`.
- Traversing for `y = 4` (`t2`):
  - Reaches node `4` at depth `3` with parent node `2` -> `t2 = {2, 3}`.
- Comparison: `t1[0] (3) != t2[0] (2)` and `t1[1] (3) == t2[1] (3)` -> Returns `true`.

# Complexity
- Time complexity: $$O(N)$$ — In the worst-case scenario, the DFS visits every node in the binary tree containing $N$ nodes twice (once for `x`, once for `y`).
- Space complexity: $$O(H)$$ — Where $H$ is the height of the binary tree, representing the maximum call stack depth during recursion.

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
    void dfs(TreeNode* root,TreeNode* parent,int& x,vector<int>& ans,int depth){
        if(root == NULL) return;
        depth++;
        if(root->val == x){
            ans[0] = parent->val;
            ans[1] = depth;
            return;
        }
        parent = root;
        dfs(root->left,parent,x,ans,depth);
        dfs(root->right,parent,x,ans,depth);


    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> t1(2,0);
        vector<int> t2(2,0);
        TreeNode* temp1 = root;
        TreeNode* temp2 = root;
        dfs(temp1,temp1,x,t1,0);
        dfs(temp2,temp2,y,t2,0);
        if(t1[0] != t2[0] && t1[1] == t2[1]) return true;

        return false;
    }
};
```
