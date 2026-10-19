# [637. Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the average value of the nodes on each level in the form of an array*. Answers within `10-5` of the actual answer will be accepted.

**Example 1:**

```
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
```

**Example 2:**

```
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 104]`.
* `-231 <= Node.val <= 231 - 1`

---

## Solution & Editorial
# Intuition
To find the average of node values at each level of a binary tree, we need to process nodes level by level. A Breadth-First Search (BFS) using a queue naturally visits nodes level-order, allowing us to compute the sum and count of nodes on each level independently.

# Approach
1. Initialize a result vector `res` to store the average values and handle the edge case where `root` is null by returning an empty vector.
2. Create a standard queue `q` of `TreeNode*` pointers and push the `root` node onto it.
3. Enter a while loop that continues as long as `q` is not empty. At the beginning of each iteration, record the number of nodes at the current level using `int size = q.size()` and initialize `double sum = 0` to accumulate node values.
4. Iterate `size` times, popping each `node` from the front of the queue, adding its value to `sum`, and pushing its non-null left and right children into the queue.
5. Compute the average by dividing `sum` by `size`, push the result into `res`, and repeat until the queue is exhausted.

### Visual Trace (Example 1: root = [3, 9, 20, null, null, 15, 7])
- Initial Queue: `[3]`
- **Level 0**: `size = 1`, `sum = 3`. Pop `3`, push children `9` and `20`. Average = `3 / 1 = 3.0`. `res = [3.0]`
- **Level 1**: `size = 2`, `sum = 9 + 20 = 29`. Pop `9` and `20`, push children `15` and `7`. Average = `29 / 2 = 14.5`. `res = [3.0, 14.5]`
- **Level 2**: `size = 2`, `sum = 15 + 7 = 22`. Pop `15` and `7`, no children. Average = `22 / 2 = 11.0`. `res = [3.0, 14.5, 11.0]`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the total number of nodes in the binary tree. Every node is pushed into and popped from the queue exactly once.
- Space complexity: $$O(W)$$ where $$W$$ is the maximum width of the binary tree. In the worst-case scenario (a complete binary tree), the queue holds up to $$N/2$$ leaf nodes simultaneously.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            double sum = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(sum / size);
        }

        return res;
    }
};
```
