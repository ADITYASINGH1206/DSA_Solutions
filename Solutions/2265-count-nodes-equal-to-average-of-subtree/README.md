# [2265. Count Nodes Equal to Average of Subtree](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the number of nodes where the value of the node is equal to the **average** of the values in its **subtree***.

**Note:**

* The **average** of `n` elements is the **sum** of the `n` elements divided by `n` and **rounded down** to the nearest integer.
* A **subtree** of `root` is a tree consisting of `root` and all of its descendants.

**Example 1:**

```
Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
```

**Example 2:**

```
Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 1000]`.
* `0 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
To determine if a node's value equals the average of its subtree, we need two pieces of information from every subtree: the sum of all node values and the total count of nodes. Since these values depend on the results of child subtrees, a post-order traversal (bottom-up) is the most efficient approach.

# Approach
1. Define a helper function `postOrder` that returns a `pair<int, int>`, where `.first` is the sum of values in the subtree and `.second` is the count of nodes.
2. For each node, recursively call `postOrder` on the left and right children.
3. Calculate the `currentSum` as `leftSum + rightSum + root->val` and `currentCount` as `leftCount + rightCount + 1`.
4. Check if `currentSum / currentCount == root->val`. If true, increment the global counter `ans`.
5. Return the calculated `{currentSum, currentCount}` to the parent caller.

### Visual Trace (Example 1: [4,8,5,0,1,null,6])
| Node | Left (Sum, Count) | Right (Sum, Count) | Current (Sum, Count) | Match? |
| :--- | :--- | :--- | :--- | :--- |
| 0 | (0,0) | (0,0) | (0,1) | Yes (0/1=0) |
| 1 | (0,0) | (0,0) | (1,1) | Yes (1/1=1) |
| 8 | (0,1) | (1,1) | (9,3) | No (9/3=3!=8) |
| 6 | (0,0) | (0,0) | (6,1) | Yes (6/1=6) |
| 5 | (0,0) | (6,1) | (11,2) | Yes (11/2=5) |
| 4 | (9,3) | (11,2) | (24,6) | Yes (24/6=4) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the tree. We visit each node exactly once during the post-order traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the tree, representing the maximum depth of the recursion stack.

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

    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return ans;
    }

    pair<int, int> postOrder(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0}; 
        }

        pair<int, int> leftSubtree = postOrder(root->left);
        pair<int, int> rightSubtree = postOrder(root->right);

        int currentSum = leftSubtree.first + rightSubtree.first + root->val;
        int currentCount = leftSubtree.second + rightSubtree.second + 1;

        if (currentSum / currentCount == root->val) {
            ans++;
        }
        return {currentSum, currentCount};
    }
};
```
