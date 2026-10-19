# [437. Path Sum III](https://leetcode.com/problems/path-sum-iii/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree and an integer `targetSum`, return *the number of paths where the sum of the values along the path equals* `targetSum`.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

**Example 1:**

```
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
```

**Example 2:**

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 1000]`.
* `-109 <= Node.val <= 109`
* `-1000 <= targetSum <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires finding the number of downward paths in a binary tree that sum up to a given `targetSum`. By maintaining a running prefix sum along the path from the root, we can reduce the subpath sum query problem to the Two Sum problem. Specifically, if the prefix sum at the current node is `sum`, and there exists an ancestor prefix sum equal to `sum - target`, then the subpath between that ancestor and the current node sums to `targetSum`.

# Approach
1. Use a depth-first search (DFS) traversal function `backtrack` that takes the current `root`, the `target`, the accumulated `sum`, a hash map `mp` storing prefix sum frequencies, and a reference to the answer counter `ans`.
2. Initialize `mp[0] = 1` in `pathSum` to handle cases where a prefix sum itself equals `targetSum`.
3. At each node, add `root->val` to `sum`. Check if `sum - target` exists in `mp`. If it does, add its frequency to `ans`.
4. Increment the frequency of the current `sum` in `mp` before recursively exploring the left and right subtrees.
5. Backtrack by decrementing the frequency of the current `sum` in `mp` before returning from the function to restore state for sibling branches.

### Visual Walkthrough (Example 1 Tree Branch: 10 -> 5 -> 3)
| Node | Current `sum` | `sum - target` (8) | Freq in `mp` before | Updated `ans` | `mp` state update |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Root (10) | 10 | 2 | 0 | 0 | `mp[10] = 1` |
| Left (5) | 15 | 7 | 0 | 0 | `mp[15] = 1` |
| Left->Left (3) | 18 | 10 | 1 (from root 10) | 1 | `mp[18] = 1` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Each node is visited exactly once, and hash map insertions and lookups take $$O(1)$$ average time.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree. The space is consumed by the recursion call stack and the prefix sum hash map, which stores at most $$H + 1$$ prefix sums along the active path.

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
    void backtrack(TreeNode* root, int target, long long sum, unordered_map<long long, int>& mp, int& ans) {
        if (root == NULL) return;
        
        sum += root->val;
        
        if (mp.count(sum - target)) {
            ans += mp[sum - target];
        }
        mp[sum]++;
        
        backtrack(root->left, target, sum, mp, ans);
        backtrack(root->right, target, sum, mp, ans);
        
        mp[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1; 
        int ans = 0;
        backtrack(root, targetSum, 0, mp, ans);
        return ans;
    }
};
```
