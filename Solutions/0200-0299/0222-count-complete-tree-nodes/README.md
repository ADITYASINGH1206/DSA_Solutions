# [222. Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/)
**Difficulty:** `Medium` | **Tags:** `binary-search`, `bit-manipulation`, `tree`, `binary-tree`

---

## Problem Description
Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to **[Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)**, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and `2h` nodes inclusive at the last level `h`.

Design an algorithm that runs in less than `O(n)` time complexity.

**Example 1:**

```
Input: root = [1,2,3,4,5,6]
Output: 6
```

**Example 2:**

```
Input: root = []
Output: 0
```

**Example 3:**

```
Input: root = [1]
Output: 1
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 5 * 104]`.
* `0 <= Node.val <= 5 * 104`
* The tree is guaranteed to be **complete**.

---

## Solution & Editorial
# Intuition
To find the total number of nodes in a binary tree, we can traverse every node in the tree and increment a counter. Since every node must be visited to correctly compute the count without assumptions about completeness, a depth-first traversal correctly visits all nodes.

# Approach
1. Define a helper function `height` that takes the current node `temp` and a reference to the accumulator `ans`.
2. If the current node `temp` is `nullptr`, return immediately.
3. Otherwise, increment `ans` by 1, and recursively call `height` on both `temp->left` and `temp->right`.
4. In `countNodes`, initialize `ans = 0`, invoke the traversal helper, and return the accumulated result `ans`.

### Visual Trace Walkthrough (Example 1: root = [1, 2, 3, 4, 5, 6])
- Initial state: `ans = 0`
- Visit `1`: `ans = 1`, traverse left to `2`
- Visit `2`: `ans = 2`, traverse left to `4`
- Visit `4`: `ans = 3`, left and right are `nullptr` (returns)
- Back to `2`: traverse right to `5`
- Visit `5`: `ans = 4`, left and right are `nullptr` (returns)
- Back to `1`: traverse right to `3`
- Visit `3`: `ans = 5`, traverse left to `6`
- Visit `6`: `ans = 6`, left and right are `nullptr` (returns)
- Final result: `ans = 6`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the tree, representing the maximum call stack depth during recursion. In the worst case (skewed tree), this is $$O(N)$$, and in the best case (balanced tree), this is $$O(\log N)$$.

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
    int countNodes(TreeNode* root) {
        int ans = 0;
        height(root,ans);
        return ans;
    }
    void height(TreeNode* temp,int& ans){
        if(temp == NULL){
            return ;
        }

        ans++;
        height(temp->left,ans);
        height(temp->right,ans);
        
    }
};
```
