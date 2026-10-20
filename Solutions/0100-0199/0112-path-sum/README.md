# [112. Path Sum](https://leetcode.com/problems/path-sum/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.

**Example 1:**

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
```

**Example 2:**

```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

**Example 3:**

```
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 5000]`.
* `-1000 <= Node.val <= 1000`
* `-1000 <= targetSum <= 1000`

---

## Solution & Editorial
# Intuition
To determine if a root-to-leaf path sums up to `targetSum`, we can traverse the binary tree recursively using Depth-First Search (DFS). As we traverse down from the root to the leaves, we accumulate the running sum of node values. When we reach a leaf node, we check if the accumulated sum matches the target.

# Approach
1. Define a helper function `dfs(TreeNode* root, int sum, int target)` that takes the current node, the running `sum`, and the `target` value.
2. Base Case: If `root == NULL`, return `false`.
3. Add the current node's value (`root->val`) to `sum`.
4. Check if the current node is a leaf node (`root->left == NULL && root->right == NULL`). If it is, return `true` if `sum == target`, else `false`.
5. Recursively invoke `dfs` on the left child and right child.
6. Return `true` if either the left or right recursive call returns `true`.
7. The main function `hasPathSum` initializes the traversal by calling `dfs(root, 0, targetSum)`.

### Visual Trace (Example 1: root = [5,4,8,...], targetSum = 22)
- `dfs(5, 0, 22)` -> `sum` becomes `5`. Not a leaf.
- `dfs(4, 5, 22)` -> `sum` becomes `5 + 4 = 9`. Not a leaf.
- `dfs(11, 9, 22)` -> `sum` becomes `9 + 11 = 20`. Leaf node. `20 != 22`, returns `false`.
- Moves to right child `2`: `dfs(2, 20, 22)` -> `sum` becomes `20 + 2 = 22`. Leaf node. `22 == 22`, returns `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. In the worst case, every node is visited once during the traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree. This accounts for the recursive call stack space, which is $$O(N)$$ in the worst-case skewed tree and $$O(\log N)$$ in a balanced tree.

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
    bool dfs(TreeNode* root,int sum,int target){
        if(root == NULL) return false;

        sum+= root->val;

        if(root->left == NULL && root->right == NULL){
            if(sum == target) return true;
            return false;
        }

        bool left = dfs(root->left,sum,target);
        bool right = dfs(root->right,sum,target);

        if(left || right) return true;

        return false;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return(dfs(root,0,targetSum));
    }
};
```
