# [662. Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the **maximum width** of the given tree*.

The **maximum width** of a tree is the maximum **width** among all levels.

The **width** of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is **guaranteed** that the answer will in the range of a **32-bit** signed integer.

**Example 1:**

```
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
```

**Example 2:**

```
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
```

**Example 3:**

```
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 3000]`.
* `-100 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
The maximum width of a binary tree at any level is determined by the distance between its leftmost and rightmost non-null nodes, including any implicit null nodes in between. By assigning standard heap-like indices to nodes ($2 \times i + 1$ for left and $2 \times i + 2$ for right), we can track exact positions. To prevent integer overflow from deeply skewed trees, we normalize indices at each level by subtracting the index of the first node from all nodes in that level.

# Approach
1. Handle the edge case where the root is `nullptr`, returning `0` immediately.
2. Initialize a queue `q` holding pairs of `(TreeNode*, unsigned int)` to store the node and its calculated index, starting with `{root, 0}`.
3. Perform a level-order traversal (BFS). For each level, capture the starting index `min_idx = q.front().second`.
4. Iterate through all nodes `n` in the current level. For each node, compute its relative normalized index `cur_id = q.front().second - min_idx`.
5. Record the first (`i == 0`) and last (`i == n - 1`) normalized indices of the level to calculate the width as `last - first + 1`.
6. Push child nodes into the queue with their updated heap indices (`cur_id * 2 + 1` for left and `cur_id * 2 + 2` for right).
7. Update the maximum width `ans` using `max(ans, static_cast<int>(last - first + 1))`.

### Visual Dry Run (Example 1: root = [1,3,2,5,3,null,9])
- **Level 0**: Queue has `{1, index 0}`. `min_idx = 0`.
  - Node `1`: `cur_id = 0 - 0 = 0`. `first = 0, last = 0`. Width = $0 - 0 + 1 = 1$.
- **Level 1**: Queue has `{3, index 1}` and `{2, index 2}`. `min_idx = 1`.
  - Node `3`: `cur_id = 1 - 1 = 0`. `first = 0`.
  - Node `2`: `cur_id = 2 - 1 = 1`. `last = 1`.
  - Width = $1 - 0 + 1 = 2$.
- **Level 2**: Queue has `{5, index 3}`, `{3, index 4}`, `{9, index 8}`. `min_idx = 3`.
  - Node `5`: `cur_id = 3 - 3 = 0`. `first = 0`.
  - Node `3`: `cur_id = 4 - 3 = 1`.
  - Node `9`: `cur_id = 8 - 3 = 5`. `last = 5`.
  - Width = $5 - 0 + 1 = 6$? Wait, Example 1 tree structure: left child of 3 is 5 (index 3), right child of 3 is 3 (index 4). Left child of 2 is null, right child of 2 is 9 (index 8). `min_idx = 3`. Nodes at level 2 are indices 3, 4, and 8. Normalized: $3-3=0, 4-3=1, 8-3=5$. Width = $5 - 0 + 1 = 6$ (Wait, Example 1 tree has max width 4: nodes 5, 3, null, 9. Indices 3, 4, 5(null), 6(null), 7(null), 8. Wait, index for 9 is 8. Normalized: $8-3=5$. Length is $5 - 0 + 1 = 6$? Ah, standard complete binary tree indexing places 9 at index 6 or 8 depending on parent. For node 2 at index 2, left is $2(2)+1=5$, right is $2(2)+2=6$. Node 9 is right child of 2, so its index is 6! Normalized: $6-3=3$. Width = $3 - 0 + 1 = 4$).

# Complexity
- Time complexity: $$O(N)$$ — Every node in the binary tree is visited exactly once during the breadth-first search traversal.
- Space complexity: $$O(W)$$ — The queue holds at most the width of one complete binary tree level ($W$), which in the worst-case balanced binary tree is $$O(N)$$.

# Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        int ans = 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int n = q.size();
            unsigned int min_idx = q.front().second; 
            unsigned int first, last;
            
            for (int i = 0; i < n; i++) {
                unsigned int cur_id = q.front().second - min_idx;
                TreeNode* temp = q.front().first;
                q.pop();
                
                if (i == 0) first = cur_id;
                if (i == n - 1) last = cur_id;
                
                if (temp->left != NULL) {
                    q.push({temp->left, cur_id * 2 + 1});
                }
                if (temp->right != NULL) {
                    q.push({temp->right, cur_id * 2 + 2});
                }
            }
            
            ans = max(ans, static_cast<int>(last - first + 1));
        }
        return ans;
    }
};
```
