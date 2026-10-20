# [199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.

**Example 1:**

**Input:** root = [1,2,3,null,5,null,4]

**Output:** [1,3,4]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,null,null,null,5]

**Output:** [1,3,4,5]

**Explanation:**

**Example 3:**

**Input:** root = [1,null,3]

**Output:** [1,3]

**Example 4:**

**Input:** root = []

**Output:** []

**Constraints:**

* The number of nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
When viewing a binary tree from the right side, we observe the first node encountered at each depth level. By prioritizing recursive traversal of the right subtree before the left subtree, the very first time we reach any given depth, that node is guaranteed to be the rightmost node visible from the right side view.

# Approach
1. Initialize a result vector `ans` to store the right side view values.
2. Define a helper function `traversal` taking the current `node`, reference to `ans`, and the current `depth` (starting at 0).
3. Base case: If `node` is `nullptr`, return immediately.
4. If `depth == ans.size()`, it means we have not yet visited any node at this depth level. Since we traverse right-first, this must be the rightmost node at this depth, so we push `node->val` into `ans`.
5. Recursively call `traversal` on `node->right` with `depth + 1`.
6. Recursively call `traversal` on `node->left` with `depth + 1`.

### Visual Walkthrough (Example 1: root = [1, 2, 3, null, 5, null, 4])

| Call Order | Node | Depth | `ans.size()` before check | Action | `ans` after action |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `1` | 0 | 0 | `depth == size` (0 == 0) -> Push `1` | `[1]` |
| 2 | `3` (1->right) | 1 | 1 | `depth == size` (1 == 1) -> Push `3` | `[1, 3]` |
| 3 | `4` (3->right) | 2 | 2 | `depth == size` (2 == 2) -> Push `4` | `[1, 3, 4]` |
| 4 | `nullptr` (4->right) | 3 | 3 | Return | `[1, 3, 4]` |
| 5 | `nullptr` (4->left) | 3 | 3 | Return | `[1, 3, 4]` |
| 6 | `nullptr` (3->left) | 2 | 3 | Return | `[1, 3, 4]` |
| 7 | `5` (1->left->right? Wait, in Ex 1: 2->right is 5) | 2 | 3 | `depth == size` (2 == 3) -> False, skip | `[1, 3, 4]` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree. This accounts for the maximum depth of the recursive call stack, which is $$O(N)$$ in the worst-case skewed tree and $$O(\log N)$$ in a balanced tree. Auxiliary space for `ans` takes $$O(H)$$ entries.

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans,0);
        return ans;
    }
    void traversal(TreeNode* node, vector<int>& ans,int depth) {
        if (node == nullptr) {
            return;
        }
        if (depth == ans.size()) {
            ans.push_back(node->val);
        }
        traversal(node->right, ans, depth + 1);
        traversal(node->left, ans, depth + 1);
    }
};
```
