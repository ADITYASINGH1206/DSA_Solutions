# [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `two-pointers`, `tree`, `depth-first-search`, `breadth-first-search`, `binary-search-tree`, `binary-tree`

---

## Problem Description
Given the `root` of a binary search tree and an integer `k`, return `true` *if there exist two elements in the BST such that their sum is equal to* `k`, *or* `false` *otherwise*.

**Example 1:**

```
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
```

**Example 2:**

```
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 104]`.
* `-104 <= Node.val <= 104`
* `root` is guaranteed to be a **valid** binary search tree.
* `-105 <= k <= 105`

---

## Solution & Editorial
# Intuition
The problem asks us to find if there exist two nodes in a Binary Search Tree whose values sum up to a target `k`. Since a Binary Search Tree has the property that an in-order traversal yields a strictly sorted array of values, we can flatten the BST into a sorted vector and then use the classic two-pointer technique to find the required pair in linear time.

# Approach
1. Define a helper function `traverse(TreeNode* root, vector<int>& inorder)` to perform a standard recursive in-order traversal (Left, Root, Right) of the BST, appending each visited node's value to the `inorder` vector.
2. In the main function `findTarget`, call `traverse` to populate the `inorder` array.
3. Initialize two pointers: `l` at the beginning of the vector (`0`) and `h` at the end (`inorder.size() - 1`).
4. While `l < h`, compute the sum of `inorder[l]` and `inorder[h]`:
   - If the sum equals `k`, return `true`.
   - If the sum is greater than `k`, decrement `h` to decrease the sum.
   - If the sum is less than `k`, increment `l` to increase the sum.
5. If the loop terminates without finding a valid pair, return `false`.

### Visual Trace Walkthrough (Example 1)
Tree: `[5, 3, 6, 2, 4, null, 7]`, `k = 9`
- `inorder` vector produced: `[2, 3, 4, 5, 6, 7]`
- `l = 0` (val: 2), `h = 5` (val: 7)
  - `2 + 7 = 9` == `k` -> returns `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the BST. The in-order traversal visits each node once taking $$O(N)$$ time, and the two-pointer scan traverses the resulting array of size $$N$$ at most once taking $$O(N)$$ time.
- Space complexity: $$O(N)$$, required to store the node values in the `inorder` vector and for the recursion call stack during depth-first traversal, which in the worst-case (skewed tree) takes $$O(N)$$ space.

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        traverse(root,inorder);
        int l = 0;
        int h = inorder.size()-1;
        while(l<h){
            if(inorder[l]+inorder[h] == k) return true;
            else if(inorder[l] + inorder[h] > k) h--;
            else l++;
        }
        return false;
    }

    void traverse(TreeNode* root,vector<int>& inorder){
        if(root == NULL) return;

        traverse(root->left,inorder);
        inorder.push_back(root->val);
        traverse(root->right,inorder);
    }
};
```
