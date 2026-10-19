# [1008. Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `tree`, `binary-search-tree`, `monotonic-stack`, `binary-tree`

---

## Problem Description
Given an array of integers preorder, which represents the **preorder traversal** of a BST (i.e., **binary search tree**), construct the tree and return *its root*.

It is **guaranteed** that there is always possible to find a binary search tree with the given requirements for the given test cases.

A **binary search tree** is a binary tree where for every node, any descendant of `Node.left` has a value **strictly less than** `Node.val`, and any descendant of `Node.right` has a value **strictly greater than** `Node.val`.

A **preorder traversal** of a binary tree displays the value of the node first, then traverses `Node.left`, then traverses `Node.right`.

**Example 1:**

```
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
```

**Example 2:**

```
Input: preorder = [1,3]
Output: [1,null,3]
```

**Constraints:**

* `1 <= preorder.length <= 100`
* `1 <= preorder[i] <= 1000`
* All the values of `preorder` are **unique**.

---

## Solution & Editorial
# Intuition
The problem asks us to construct a Binary Search Tree (BST) given its preorder traversal array. In a preorder traversal, the root node is visited first, followed by its left subtree and then its right subtree. By leveraging the BST property where all values in the left subtree are smaller than the current node and all values in the right subtree are smaller than a given upper bound, we can recursively build the tree in $$O(N)$$ time without repeatedly searching for insertion positions.

# Approach
1. Maintain an index pointer `i` by reference to keep track of the current element being processed in the `preorder` vector.
2. Define a helper function `build(vector<int>& preorder, int& i, int bound)` that takes the upper bound constraint for the current subtree.
3. If `i` reaches the end of the vector or the current element `preorder[i]` exceeds the `bound`, return `nullptr`.
4. Otherwise, create a new `TreeNode` with `preorder[i++]` as its value.
5. Recursively construct the left child by setting the bound to the current node's value (`root->val`).
6. Recursively construct the right child by passing the same upper `bound` inherited from the parent context.

### Visual Walkthrough (Example 1: `preorder = [8,5,1,7,10,12]`)
- `build(preorder, i=0, bound=INT_MAX)` -> Creates root `8`. Calls left with bound `8`.
- `build(preorder, i=1, bound=8)` -> Creates node `5`. Calls left with bound `5`.
- `build(preorder, i=2, bound=5)` -> Creates node `1`. Calls left with bound `1` (returns `nullptr`), calls right with bound `5` (returns `nullptr`).
- `build(preorder, i=3, bound=5)` -> Sees `7 > 5`, returns `nullptr`. Right of `5` builds node `7` with bound `8`.
- Process continues similarly for right subtree starting at `10`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of elements in `preorder`. Each element is visited exactly once when constructing its corresponding node.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the tree. This accounts for the recursive call stack, which in the worst case (skewed tree) is $$O(N)$$ and in the best case (balanced tree) is $$O(\log N)$$.

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
    
    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode* root = new TreeNode(preorder[0]);
//         int n = preorder.size();
//         TreeNode* temp = root;
//         TreeNode* prev= root;
//         for(int i = 1;i<n;i++){
//             temp = root;
//             int val = preorder[i];
//             while(temp){
//                 if(temp->val > val){
//                     prev = temp;
//                     temp = temp->left;
//                 }
//                 else{
//                     prev= temp;
//                     temp = temp->right;
//                 }
//             }

//             if(prev->val > val){
//                 TreeNode* l1 = new TreeNode(val);
//                 prev->left = l1;
//                 continue;
//             }
//             else{
//                 TreeNode* r1 = new TreeNode(val);
//                 prev->right = r1;
//                 continue;
//             }

//         }
//         return root;
//     }
// };
```
