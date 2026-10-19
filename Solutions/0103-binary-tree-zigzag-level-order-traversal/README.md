# [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
**Difficulty:** `Medium` | **Tags:** `tree`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).

**Example 1:**

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 2000]`.
* `-100 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
The problem requires us to perform a level-order traversal of a binary tree where the traversal direction alternates between left-to-right and right-to-left at each consecutive level. A standard Breadth-First Search (BFS) using a queue naturally visits nodes level by level. By tracking the traversal direction using a toggle flag (`cur`), we can collect nodes normally for left-to-right levels and reverse the level vector for right-to-left levels.

# Approach
1. Handle the base case: if `root` is `NULL`, return an empty 2D vector `ans`.
2. Initialize a queue `q` and push `root` into it. Define a toggle flag `cur = 1` to indicate left-to-right traversal order for the first level.
3. While `q` is not empty, determine the current level size `s` using `q.size()`.
4. Iterate `s` times to process all nodes at the current level:
   - Pop the front node `temp` from `q`.
   - Push `temp->left` and `temp->right` into `q` if they are not `NULL`.
   - Store `temp->val` in a temporary vector `v`.
5. Check the direction flag `cur`:
   - If `cur == 1`, append `v` directly to `ans` and set `cur = -1`.
   - If `cur == -1`, reverse `v` using `reverse(v.begin(), v.end())`, append it to `ans`, and set `cur = 1`.
6. Return `ans` once the queue is fully exhausted.

### Visual Walkthrough (Example 1: root = [3, 9, 20, null, null, 15, 7])
- **Initial State**: `q = [3]`, `cur = 1`, `ans = []`
- **Level 0**: `s = 1`
  - Pop `3`. Push `9`, `20`. Vector `v = [3]`.
  - `cur == 1`, so push `[3]` to `ans`. `ans = [[3]]`, `cur = -1`.
- **Level 1**: `s = 2`
  - Pop `9`. No children. Vector `v = [9]`.
  - Pop `20`. Push `15`, `7`. Vector `v = [9, 20]`.
  - `cur == -1`, reverse `v` to `[20, 9]`, push to `ans`. `ans = [[3], [20, 9]]`, `cur = 1`.
- **Level 2**: `s = 2`
  - Pop `15`. No children. Vector `v = [15]`.
  - Pop `7`. No children. Vector `v = [15, 7]`.
  - `cur == 1`, push `[15, 7]` to `ans`. `ans = [[3], [20, 9], [15, 7]]`, `cur = -1`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree. Every node is pushed and popped from the queue exactly once. Level reversal takes proportional time to the number of nodes at that level, summing up to $$O(N)$$ overall.
- Space complexity: $$O(W)$$ where $$W$$ is the maximum width of the binary tree. In the worst-case scenario (a complete binary tree), the queue holds up to $$O(N)$$ leaf nodes.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int cur = 1;
        while(!q.empty()){
            int s = q.size();
            vector<int> v;
            for(int i = 0;i<s;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                v.push_back(temp->val);
            }
            if(cur == 1){
                ans.push_back(v);
                cur = -1;
            }else{
                reverse(v.begin(),v.end());
                ans.push_back(v);
                cur = 1;
            }
        }
        return ans;
    }
};
```
