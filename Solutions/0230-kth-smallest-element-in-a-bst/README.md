# [230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-search-tree`, `binary-tree`

---

## Problem Description
Given the `root` of a binary search tree, and an integer `k`, return *the* `kth` *smallest value (**1-indexed**) of all the values of the nodes in the tree*.

**Example 1:**

```
Input: root = [3,1,4,null,2], k = 1
Output: 1
```

**Example 2:**

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
```

**Constraints:**

* The number of nodes in the tree is `n`.
* `1 <= k <= n <= 104`
* `0 <= Node.val <= 104`

**Follow up:** If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

---

## Solution & Editorial
# Intuition
The fundamental property of a Binary Search Tree (BST) is that an in-order traversal (Left, Root, Right) visits the nodes in ascending order of their values. By collecting all node values during an in-order traversal into a vector, the $k$-th smallest element will simply reside at the $(k-1)$-th index.

# Approach
1. Define a helper function `traverse(TreeNode* root, vector<int>& result)` that performs a standard recursive in-order traversal.
2. In `traverse`, if the current `root` is `NULL`, return immediately.
3. Recursively call `traverse` on the left child `root->left`.
4. Append the current node's value `root->val` to the `result` vector using `result.push_back(root->val)`.
5. Recursively call `traverse` on the right child `root->right`.
6. In the main function `kthSmallest`, initialize an empty `vector<int> result`, invoke `traverse(root, result)`, and finally return `result[k - 1]`.

### Visual Trace Walkthrough
Example 1: `root = [3, 1, 4, null, 2]`, `k = 1`
- Start `traverse` at root `3`.
- Go left to `1`. Go left from `1` (null). Push `1`. Go right from `1` to `2`. Push `2`. Vector: `[1, 2]`
- Backtrack to `3`. Push `3`. Vector: `[1, 2, 3]`
- Go right to `4`. Push `4`. Vector: `[1, 2, 3, 4]`
- Result vector: `[1, 2, 3, 4]`
- Return `result[k - 1] = result[0] = 1`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the BST. Every node is visited exactly once during the recursive in-order traversal.
- Space complexity: $$O(N)$$, to store all $$N$$ node values in the `result` vector and account for the recursive call stack of maximum depth $$O(N)$$ in the worst-case skewed tree.

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        traverse(root,result);
        return result[k-1];
    }

    void traverse(TreeNode* root,vector<int>& result){
        if(root == NULL) return;

        traverse(root->left,result);
        result.push_back(root->val);
        traverse(root->right,result);

    }
};
```
