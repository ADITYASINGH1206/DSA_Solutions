# [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `divide-and-conquer`, `tree`, `binary-tree`

---

## Problem Description
Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return *the binary tree*.

**Example 1:**

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```

**Example 2:**

```
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

**Constraints:**

* `1 <= preorder.length <= 3000`
* `inorder.length == preorder.length`
* `-3000 <= preorder[i], inorder[i] <= 3000`
* `preorder` and `inorder` consist of **unique** values.
* Each value of `inorder` also appears in `preorder`.
* `preorder` is **guaranteed** to be the preorder traversal of the tree.
* `inorder` is **guaranteed** to be the inorder traversal of the tree.

---

## Solution & Editorial
# Intuition
The preorder traversal guarantees that the first element is always the root of the current subtree. By using an unordered map to store the indices of the inorder traversal, we can locate the root position in $$O(1)$$ time and instantly partition the inorder array into left and right subtrees.

# Approach
1. Initialize a hash map `map` to store value-to-index mappings for the `inorder` array for constant-time lookups.
2. Maintain a global pointer `index` starting at `0` to traverse the `preorder` vector sequentially.
3. Implement a recursive `helper` function taking bounds `start` and `end` corresponding to the current segment of the `inorder` array.
4. Base case: If `start > end`, return `nullptr` as the subtree segment is empty.
5. Extract the next root value using `preorder[index++]` and instantiate the root `TreeNode`.
6. Find the root's position `mid` in `inorder` using the hash map.
7. Recursively construct the left subtree with bounds `[start, mid - 1]` and the right subtree with bounds `[mid + 1, end]`.

### Visual Trace (Example 1)
`preorder = [3, 9, 20, 15, 7]`, `inorder = [9, 3, 15, 20, 7]`

| Call | index | start | end | rootVal | mid | Subtree Partition | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 -> 1 | 0 | 4 | 3 | 1 | Left: [0,0], Right: [2,4] | Root 3 created |
| 2 | 1 -> 2 | 0 | 0 | 9 | 0 | Left: [0,-1], Right: [1,0] | Left child 9 created |
| 3 | 2 -> 3 | 2 | 4 | 20 | 3 | Left: [2,2], Right: [4,4] | Right child 20 created |
| 4 | 3 -> 4 | 2 | 2 | 15 | 2 | Left: [2,1], Right: [3,2] | Left child of 20 -> 15 created |
| 5 | 4 -> 5 | 4 | 4 | 7 | 4 | Left: [4,3], Right: [5,4] | Right child of 20 -> 7 created |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the tree. Populating the hash map takes $$O(N)$$ time, and every node is visited exactly once during the recursive construction, where lookups take $$O(1)$$ time.
- Space complexity: $$O(N)$$, required for storing the hash map and the recursive call stack which can go up to $$O(N)$$ depth in the worst case (skewed tree).

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
    int index = 0;
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        return helper(preorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[index++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal];

        root->left = helper(preorder, start, mid - 1);
        root->right = helper(preorder, mid + 1, end);
        return root;
    }
};
```
