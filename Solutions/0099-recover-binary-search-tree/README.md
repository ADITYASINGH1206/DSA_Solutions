# [99. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `binary-search-tree`, `binary-tree`

---

## Problem Description
You are given the `root` of a binary search tree (BST), where the values of **exactly** two nodes of the tree were swapped by mistake. *Recover the tree without changing its structure*.

**Example 1:**

```
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
```

**Example 2:**

```
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
```

**Constraints:**

* The number of nodes in the tree is in the range `[2, 1000]`.
* `-231 <= Node.val <= 231 - 1`

**Follow up:** A solution using `O(n)` space is pretty straight-forward. Could you devise a constant `O(1)` space solution?

---

## Solution & Editorial
# Intuition
A Binary Search Tree (BST) has the property that an in-order traversal visits nodes in strictly ascending order. When exactly two nodes are swapped, this sorted order is violated at one or two locations. By performing a standard in-order traversal and comparing each node with its predecessor, we can precisely identify the two swapped nodes and restore them.

# Approach
1. Maintain three pointer variables: `first` and `second` to track the misplaced nodes, and `prev` to keep track of the previously visited node during traversal.
2. Recursively traverse the left subtree (`inorder(root->left)`).
3. During the visit, check if `prev` is not null and if the current node value (`root->val`) is strictly less than `prev->val`. This indicates an inversion in the BST order.
   - If `first` is still `nullptr`, this is the first violation; set `first = prev`.
   - Always update `second = root` to handle both adjacent and non-adjacent swaps.
4. Update `prev = root` and proceed to traverse the right subtree (`inorder(root->right)`).
5. After the recursion completes, swap the values stored in `first` and `second` to correct the tree.

### Visual Walkthrough (Example 1: root = [1, 3, null, null, 2])
- In-order traversal visits nodes in the sequence: `3`, `1`, `2` (due to the swap).
- Visiting `3`: `prev = nullptr`, `prev` becomes `3`.
- Visiting `1`: `root->val (1) < prev->val (3)`. Violation detected! `first` is null, so `first = prev` (node `3`). `second = root` (node `1`). `prev` becomes `1`.
- Visiting `2`: `root->val (2) > prev->val (1)`. No violation. `prev` becomes `2`.
- Final state: `first` points to node `3`, `second` points to node `1`. Swapping their values results in `[3, 1, null, null, 2]`, restoring the valid BST.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once during the in-order traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree. This accounts for the maximum depth of the recursive call stack (which is $$O(\log N)$$ for a balanced tree and $$O(N)$$ in the worst-case skewed tree).

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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }
    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if(prev != NULL && root->val < prev->val){
            if(first == nullptr) first = prev;
            second = root;
        }

        prev = root;
        inorder(root->right);
    }

};
```
