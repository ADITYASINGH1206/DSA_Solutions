# [1161. Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the **smallest** level `x` such that the sum of all the values of nodes at level `x` is **maximal**.

**Example 1:**

```
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
```

**Example 2:**

```
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 104]`.
* `-105 <= Node.val <= 105`

---

## Solution & Editorial
# Intuition
The problem asks us to find the level of a binary tree that has the maximum sum of node values, and to return the smallest level index if there is a tie. A standard Breadth-First Search (BFS) level-order traversal naturally processes the tree level by level, making it straightforward to compute the sum for each depth and track the maximum sum and corresponding level dynamically.

# Approach
1. Initialize a queue `q` containing the `root` node, an integer `maxi` set to `INT_MIN` to track the maximum sum encountered, `ans` set to `1` to record the optimal level, and `depth` set to `0` to keep track of the current level.
2. While the queue `q` is not empty, increment `depth` by 1 and determine the number of nodes at the current level using `s = q.size()`.
3. Iterate `s` times to process all nodes at the current level. For each node popped from `q`, accumulate its value into a local `sum` variable and push its non-null left and right children into the queue for the subsequent level.
4. After processing all nodes of the current level, compare `sum` with `maxi`. If `sum > maxi`, update `maxi = sum` and record the current level via `ans = depth`.
5. Return `ans` once the queue is fully exhausted.

### Visual Trace Walkthrough (Example 1: root = [1, 7, 0, 7, -8, null, null])
- **Level 1 (`depth = 1`)**: Queue has `[1]`. Size `s = 1`. `sum = 1`. `maxi` updated to `1`, `ans = 1`. Children `7`, `0` added to queue.
- **Level 2 (`depth = 2`)**: Queue has `[7, 0]`. Size `s = 2`. `sum = 7 + 0 = 7`. `maxi` updated to `7`, `ans = 2`. Children `7`, `-8` added to queue.
- **Level 3 (`depth = 3`)**: Queue has `[7, -8]`. Size `s = 3` (wait, size is 2). `sum = 7 + (-8) = -1`. `sum > maxi` is false (`-1 <= 7`). No update. Queue becomes empty.
- **Result**: Returns `2`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the total number of nodes in the binary tree. Every node is pushed into and popped from the queue exactly once, and its value is added to the level sum.
- Space complexity: $$O(W)$$, where $$W$$ is the maximum width of the binary tree. In the worst case (a complete binary tree), the queue holds up to $$N/2$$ leaf nodes simultaneously.

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
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int maxi = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int s=q.size();
            int sum = 0;
            depth++;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                sum+=node->val;
            }
            if(sum>maxi){
                maxi = sum;
                ans = depth;
            }
        }
        return ans;
    }
};
```
