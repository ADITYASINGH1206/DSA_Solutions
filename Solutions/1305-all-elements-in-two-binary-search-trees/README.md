# [1305. All Elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-search-tree`, `sorting`, `binary-tree`

---

## Problem Description
Given two binary search trees `root1` and `root2`, return *a list containing all the integers from both trees sorted in **ascending** order*.

**Example 1:**

```
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
```

**Example 2:**

```
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
```

**Constraints:**

* The number of nodes in each tree is in the range `[0, 5000]`.
* `-105 <= Node.val <= 105`

---

## Solution & Editorial
# Intuition
To combine all elements from two binary search trees into a single sorted list, we can traverse both trees independently and collect all their node values into a common vector. Once all elements are gathered, sorting the vector provides the final ascending sequence.

# Approach
1. Initialize a dynamic array `ans` to store the node values.
2. Define a recursive helper function `dfs(TreeNode* root, vector<int>& ans)` that traverses the tree in pre-order (or any traversal order). If the current `root` is `NULL`, return immediately. Otherwise, push `root->val` into `ans` and recursively visit `root->left` and `root->right`.
3. Call `dfs` on `root1` and `root2` to populate `ans` with all elements from both trees.
4. Sort the `ans` vector in ascending order using `std::sort`.
5. Return the sorted `ans` vector.

### Visual Walkthrough
For Example 1:
- `root1 = [2, 1, 4]` and `root2 = [1, 0, 3]`
- After `dfs(root1, ans)`: `ans = [2, 1, 4]`
- After `dfs(root2, ans)`: `ans = [2, 1, 4, 1, 0, 3]`
- After `std::sort(ans.begin(), ans.end())`: `ans = [0, 1, 1, 2, 3, 4]`

# Complexity
- Time complexity: $$O((N + M) \log(N + M))$$ — where $$N$$ and $$M$$ are the number of nodes in `root1` and `root2`, respectively. The DFS traversals take $$O(N + M)$$ time, and sorting the combined vector of size $$N + M$$ takes $$O((N + M) \log(N + M))$$ time.
- Space complexity: $$O(N + M)$$ — required to store the node values in the `ans` vector and the recursion stack, which in the worst case (skewed tree) takes $$O(N + M)$$ space.

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        dfs(root1,ans);
        dfs(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;

    }
    void dfs(TreeNode * root,vector<int>& ans){
        if(root == NULL) return;

        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
};
```
