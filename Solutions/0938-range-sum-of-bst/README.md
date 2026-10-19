# [938. Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `binary-search-tree`, `binary-tree`

---

## Problem Description
Given the `root` node of a binary search tree and two integers `low` and `high`, return *the sum of values of all nodes with a value in the **inclusive** range* `[low, high]`.

**Example 1:**

```
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
```

**Example 2:**

```
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 2 * 104]`.
* `1 <= Node.val <= 105`
* `1 <= low <= high <= 105`
* All `Node.val` are **unique**.

---

## Solution & Editorial
# Intuition
The problem requires us to find the sum of all node values within the inclusive range `[low, high]` in a Binary Search Tree (BST). Since it is a BST, we can traverse the tree and accumulate values of nodes that fall within the specified range.

# Approach
1. Initialize an accumulator variable `ans` to `0` inside the main function `rangeSumBST`.
2. Pass `root`, `low`, `high`, and a reference to `ans` into a helper function `traverse`.
3. In `traverse`, base case checks if `root == NULL`, returning immediately if true.
4. If the current `root->val` falls within the inclusive range `[low, high]`, add `root->val` to `ans`.
5. Recursively call `traverse` on both the left and right child pointers.

### Visual Walkthrough (Example 1)
Tree: `[10, 5, 15, 3, 7, null, 18]`, `low = 7`, `high = 15`

| Current Node | Val | Range Check ($7 \le \text{val} \le 15$) | Action | Accumulator (`ans`) |
| :--- | :--- | :--- | :--- | :--- |
| 10 | 10 | True | Add 10 | 10 |
| 5 | 5 | False | Skip | 10 |
| 3 | 3 | False | Skip | 10 |
| 7 | 7 | True | Add 7 | 17 |
| 15 | 15 | True | Add 15 | 32 |
| 18 | 18 | False | Skip | 32 |

# Complexity
- Time complexity: $$O(N)$$ — In the worst-case scenario, the algorithm visits every node in the BST once, where $$N$$ is the total number of nodes.
- Space complexity: $$O(H)$$ — The recursive call stack consumes space proportional to the height $$H$$ of the tree. In the worst case (skewed tree), this is $$O(N)$$, and in the best case (balanced tree), it is $$O(\log N)$$.

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        traverse(root,low,high,ans);
        return ans;
    }

    void traverse(TreeNode* root,int low,int high,int& ans){
        if(root == NULL) return;

        if(root->val >= low && root->val <= high){
            ans += root->val;
        }
        traverse(root->left,low,high,ans);
        traverse(root->right,low,high,ans);
    }
};
```
