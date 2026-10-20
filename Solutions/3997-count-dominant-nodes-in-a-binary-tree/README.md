# [3997. Count Dominant Nodes in a Binary Tree](https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
You are given the `root` of a complete binary tree.

A node `x` is called **dominant** if its value is equal to the maximum value among all nodes in the subtree rooted at `x`.

Return the number of dominant nodes in the tree.

**Example 1:**

**Input:** root = [5,3,8,2,4,7,1]

**Output:** 5

**Explanation:**

* The leaf nodes with values 2, 4, 7, and 1 are dominant.
* The node with value 8 is dominant because its value is the maximum value in its subtree `[8, 7, 1]`.
* Thus, the answer is 5.

**Example 2:**

**Input:** root = [1,2,3,1,2]

**Output:** 4

**Explanation:**

* The leaf nodes with values 1, 2, and 3 are dominant.
* The node with value 2 whose subtree is `[2, 1, 2]` is dominant because its value is the maximum value in its subtree.
* Thus, the answer is 4.

**Constraints:**

* The number of nodes in the tree is in the range `[1, 105]`.
* `1 <= Node.val <= 109`
* The tree is guaranteed to be a complete binary tree.

---

## Solution & Editorial
# Intuition
To determine if a node is dominant, we need to compare its value against the maximum value present in its entire subtree. Since the maximum value of a subtree rooted at `x` is simply `max(x->val, max_left, max_right)`, we can compute this information efficiently using a post-order traversal.

# Approach
1. Use a recursive helper function `dfs(root)` that returns the maximum value found in the subtree rooted at `root`.
2. For each node, recursively call `dfs` on the left and right children to retrieve the maximum values of those subtrees.
3. Compare the current node's value (`root->val`) with the maximums returned by its children. If `root->val >= max(left_max, right_max)`, the node is dominant; increment a global counter `cnt`.
4. Return the overall maximum of the current subtree (`max({root->val, left_max, right_max})`) to the parent caller.

### Visual Trace (Example 1: [5,3,8,2,4,7,1])
| Node | Left Max | Right Max | Max in Subtree | Dominant? |
| :--- | :--- | :--- | :--- | :--- |
| 2 | 0 | 0 | 2 | Yes |
| 4 | 0 | 0 | 4 | Yes |
| 3 | 2 | 4 | 4 | No |
| 7 | 0 | 0 | 7 | Yes |
| 1 | 0 | 0 | 1 | Yes |
| 8 | 7 | 1 | 8 | Yes |
| 5 | 3 | 8 | 8 | No |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the tree. We visit each node exactly once during the post-order traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the tree, representing the maximum depth of the recursion stack. In the worst case (a skewed tree), this is $$O(N)$$, though for a complete binary tree, it is $$O(\log N)$$.

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
    int cnt=0;
    int dfs(TreeNode* root){
        if(root == NULL)return 0;

        int left=dfs(root->left);
        int right=dfs(root->right);

        if(root->val>=max(left,right))cnt++; 
        return max({root->val,left,right}); 
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};
```
