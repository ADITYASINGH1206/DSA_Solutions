# [654. Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `array`, `divide-and-conquer`, `stack`, `tree`, `monotonic-stack`, `binary-tree`, `cartesian-tree`

---

## Problem Description
You are given an integer array `nums` with no duplicates. A **maximum binary tree** can be built recursively from `nums` using the following algorithm:

1. Create a root node whose value is the maximum value in `nums`.
2. Recursively build the left subtree on the **subarray prefix** to the **left** of the maximum value.
3. Recursively build the right subtree on the **subarray suffix** to the **right** of the maximum value.

Return *the **maximum binary tree** built from* `nums`.

**Example 1:**

```
Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]
Explanation: The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.
```

**Example 2:**

```
Input: nums = [3,2,1]
Output: [3,null,2,null,1]
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `0 <= nums[i] <= 1000`
* All integers in `nums` are **unique**.

---

## Solution & Editorial
# Intuition
The problem asks us to construct a Maximum Binary Tree by repeatedly finding the maximum element in the current range, making it the root, and recursively building the left and right subtrees from the prefix and suffix subarrays. This maps directly to a divide-and-conquer strategy.

# Approach
1. Define a helper function `TreeBuild(vector<int>& nums, int start, int end)` that operates on the subarray bounds `[start, end]`.
2. Base Case: If `start > end`, the subarray is empty, so return `nullptr`.
3. Find the index `max_idx` of the maximum element in `nums` within the range `[start, end]` by performing a linear scan.
4. Create a new `TreeNode` with the value `nums[max_idx]`.
5. Recursively build the left subtree by calling `TreeBuild(nums, start, max_idx - 1)` and assign it to `node->left`.
6. Recursively build the right subtree by calling `TreeBuild(nums, max_idx + 1, end)` and assign it to `node->right`.
7. Return the constructed `node`.

### Visual Trace Walkthrough for Example 1
`nums = [3, 2, 1, 6, 0, 5]`

| Range `[start, end]` | Max Value & Index | Left Subtree Range | Right Subtree Range | Node Created |
| :--- | :--- | :--- | :--- | :--- |
| `[0, 5]` | `6` at index `3` | `[0, 2]` | `[4, 5]` | `6` |
| `[0, 2]` | `3` at index `0` | `[0, -1]` | `[1, 2]` | `3` |
| `[1, 2]` | `2` at index `1` | `[1, 0]` | `[2, 2]` | `2` |
| `[2, 2]` | `1` at index `2` | `[2, 1]` | `[3, 2]` | `1` |
| `[4, 5]` | `5` at index `5` | `[4, 4]` | `[6, 5]` | `5` |
| `[4, 4]` | `0` at index `4` | `[4, 3]` | `[5, 4]` | `0` |

# Complexity
- Time complexity: $$O(N^2)$$ in the worst-case scenario (e.g., when the input array is strictly sorted, leading to skewed trees where we scan almost the entire remaining array at each level of recursion). On average, balanced splits yield $$O(N \log N)$$.
- Space complexity: $$O(N)$$ for the recursion call stack in the worst-case skewed tree configuration, and $$O(N)$$ to store the resulting binary tree nodes.

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
    TreeNode* TreeBuild(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        int max_idx = start;
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }
        TreeNode* node = new TreeNode(nums[max_idx]);
        node->left = TreeBuild(nums, start, max_idx - 1);
        node->right = TreeBuild(nums, max_idx + 1, end);
        
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return TreeBuild(nums, 0, nums.size() - 1);
    }
};
```
