# [979. Distribute Coins in Binary Tree](https://leetcode.com/problems/distribute-coins-in-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-tree`, `dp-on-trees`

---

## Problem Description
You are given the `root` of a binary tree with `n` nodes where each `node` in the tree has `node.val` coins. There are `n` coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return *the **minimum** number of moves required to make every node have **exactly** one coin*.

**Example 1:**

```
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
```

**Example 2:**

```
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
```

**Constraints:**

* The number of nodes in the tree is `n`.
* `1 <= n <= 100`
* `0 <= Node.val <= n`
* The sum of all `Node.val` is `n`.

---

## Solution & Editorial
# Intuition
To distribute coins evenly across a binary tree where every node must end up with exactly one coin, we can use a bottom-up post-order traversal. Each subtree requires a net balance of coins to satisfy its internal nodes. Any excess coins or coin deficits passing through an edge between a child and its parent will contribute directly to the total number of moves.

# Approach
1. Define a recursive helper function `dfs(TreeNode* root)` that computes the coin balance for the subtree rooted at `root` and returns it to the parent.
2. The base case checks if `root` is null; if so, return `0`.
3. Recursively compute the balance required from the left subtree (`left = dfs(root->left)`) and the right subtree (`right = dfs(root->right)`).
4. Accumulate the absolute values of the deficits or excesses (`abs(left)` and `abs(right)`) into the global answer `ans`, because every surplus or deficit coin must traverse the edge connecting the child to the parent.
5. Return the net balance for the current node, calculated as `root->val + left + right - 1` (since the current node keeps 1 coin and passes the rest upward or requests what it lacks).

### Visual Walkthrough (Example 1: root = [3, 0, 0])
- Root is 3, left child is 0, right child is 0.
- `dfs(left)`: node has value 0, returns `0 + 0 + 0 - 1 = -1` (needs 1 coin, adds `abs(-1) = 1` to `ans`).
- `dfs(right)`: node has value 0, returns `0 + 0 + 0 - 1 = -1` (needs 1 coin, adds `abs(-1) = 1` to `ans`).
- `dfs(root)`: node has value 3, receives `-1` from left and `-1` from right. Adds `abs(-1) + abs(-1) = 2` to `ans`. Total `ans` becomes 4? Wait, let's trace accurately:
  - `left` returns `-1`, `ans` increases by `1` (`ans = 1`).
  - `right` returns `-1`, `ans` increases by `1` (`ans = 2`).
  - `dfs(root)` computes `3 + (-1) + (-1) - 1 = 0` and adds `abs(-1) + abs(-1) = 2` to `ans`, making `ans = 4`? No, Example 1 output is 2. Let's re-verify: root=3, left=0, right=0. 
  - `dfs(left)`: `0 + 0 + 0 - 1 = -1`, `ans += abs(-1)` -> `ans = 1`.
  - `dfs(right)`: `0 + 0 + 0 - 1 = -1`, `ans += abs(-1)` -> `ans = 2`.
  - `dfs(root)`: `3 + (-1) + (-1) - 1 = 0`, `ans += abs(-1) + abs(-1)` -> wait, `left` and `right` were already added? No, `abs(left)` and `abs(right)` are added at `root`'s level for the edges connecting `root->left` and `root->right` to `root`.
  - Let's trace carefully: `left = -1`, `right = -1`. `ans += abs(-1) + abs(-1)` -> `ans += 1 + 1 = 2`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree. We visit each node exactly once during the post-order traversal.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the tree, representing the maximum call stack depth during recursion. In the worst case (skewed tree), this is $$O(N)$$, and in the best case (balanced tree), it is $$O(\log N)$$.

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
    int ans = 0;
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        ans += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};
```
