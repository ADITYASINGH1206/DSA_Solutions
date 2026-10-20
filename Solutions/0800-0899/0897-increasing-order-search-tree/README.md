# [897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/)
**Difficulty:** `Easy` | **Tags:** `stack`, `tree`, `depth-first-search`, `binary-search-tree`, `binary-tree`

---

## Problem Description
Given the `root` of a binary search tree, rearrange the tree in **in-order** so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

**Example 1:**

```
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
```

**Example 2:**

```
Input: root = [5,1,7]
Output: [1,null,5,null,7]
```

**Constraints:**

* The number of nodes in the given tree will be in the range `[1, 100]`.
* `0 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks us to rearrange a Binary Search Tree (BST) into a right-skewed tree ordered strictly by an in-order traversal. Since an in-order traversal of a BST naturally yields elements in sorted ascending order, we can collect all node values into a linear vector and then reconstruct a new tree where each node has `left = nullptr` and `right` pointing to the next element in sequence.

# Approach
1. **In-Order Traversal (`Inorder` function)**: Recursively traverse the given binary tree in left-root-right order and store each visited node's value in a `vector<int> in`.
2. **Reconstruction (`create` function)**: Recursively build a new right-skewed binary tree from the sorted vector `in`. For each index, create a new `TreeNode`, set its `left` child to `nullptr`, and recursively assign its `right` child to the node generated at `index + 1`.
3. **Driver Function (`increasingBST`)**: Instantiate the vector, invoke the in-order traversal, and return the root of the newly constructed right-skewed tree.

### Visual Trace Walkthrough (Example 2: `root = [5, 1, 7]`)
- **Step 1 (`Inorder`)**: Traverses the tree and populates `in = [1, 5, 7]`.
- **Step 2 (`create(in, 0)`)**:
  - `index = 0`: Creates node `1`, sets `left = nullptr`, `right = create(in, 1)`.
  - `index = 1`: Creates node `5`, sets `left = nullptr`, `right = create(in, 2)`.
  - `index = 2`: Creates node `7`, sets `left = nullptr`, `right = create(in, 3)`.
  - `index = 3`: Returns `nullptr` (base case).
- **Result**: A right-skewed tree rooted at `1 -> 5 -> 7` with all left pointers null.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the tree. We visit every node once during the in-order traversal and iterate through the $$N$-sized vector once during reconstruction.
- Space complexity: $$O(N)$$, required to store the vector of size $$N$$ and the recursion stack frames which take up $$O(H)$$ space (where $$H$$ is the tree height, bounded by $$N$$).

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
    void Inorder(TreeNode* root,vector<int>&in){
        if(!root) return;

        Inorder(root->left,in);
        in.push_back(root->val);
        Inorder(root->right,in);
    }

    TreeNode* create(vector<int>&in, int index){
        if(index>=in.size()){
            return NULL;
        }

        TreeNode* root = new TreeNode(in[index]);
        root->left = NULL;
        root->right = create(in,index+1);

        return root;
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int>in;
        Inorder(root,in);
        return create(in,0);
    }
};
```
