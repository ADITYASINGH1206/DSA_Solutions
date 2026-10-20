# [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
**Difficulty:** `Medium` | **Tags:** `tree`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).

**Example 1:**

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 2000]`.
* `-1000 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
To traverse a binary tree level by level, we need a way to process nodes grouped by their depth. A Breadth-First Search (BFS) using a queue naturally handles this FIFO processing order, allowing us to capture all nodes at depth $k$ before proceeding to depth $k+1$.

# Approach
1. Check if the `root` is `NULL`. If it is, immediately return the empty result vector `ans`.
2. Initialize a queue of `TreeNode*` named `q` and push the `root` into it.
3. While the queue `q` is not empty, record the current level size `s = q.size()`, which represents the exact number of nodes residing at the current depth.
4. Allocate a local vector `v` to store the values of nodes at this level.
5. Iterate `s` times: pop the front node from `q`, push its non-null left and right children into `q`, and append its `val` to vector `v`.
6. After completing the inner loop for the current level, push `v` into `ans` and repeat until the queue is empty.

### Visual Trace Walkthrough (Example 1: root = [3, 9, 20, null, null, 15, 7])

| Iteration (`ans` state before push) | Queue State (`q`) before level | Level Size `s` | Nodes Processed (`node->val`) | Local Vector `v` | Queue State `q` after level |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `[]` | `[3]` | `1` | `3` | `[3]` | `[9, 20]` |
| `[[3]]` | `[9, 20]` | `2` | `9`, `20` | `[9, 20]` | `[15, 7]` |
| `[[3], [9, 20]]` | `[15, 7]` | `2` | `15`, `7` | `[15, 7]` | `[]` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the total number of nodes in the binary tree. Every node is pushed into and popped from the queue exactly once, and its value is appended to the result vectors in constant amortized time.
- Space complexity: $$O(W)$$, where $$W$$ is the maximum width of the binary tree. In the worst-case scenario (a complete binary tree), the bottom level holds roughly $$N/2$$ nodes, dominating the memory consumed by the queue and local level vectors.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>v;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
```
