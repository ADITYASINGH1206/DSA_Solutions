# [606. Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `string`, `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` node of a binary tree, your task is to create a string representation of the tree following a specific set of formatting rules. The representation should be based on a preorder traversal of the binary tree and must adhere to the following guidelines:

* **Node Representation**: Each node in the tree should be represented by its integer value.
* **Parentheses for Children**: If a node has at least one child (either left or right), its children should be represented inside parentheses. Specifically:

  + If a node has a left child, the value of the left child should be enclosed in parentheses immediately following the node's value.
  + If a node has a right child, the value of the right child should also be enclosed in parentheses. The parentheses for the right child should follow those of the left child.
* **Omitting Empty Parentheses**: Any empty parentheses pairs (i.e., `()`) should be omitted from the final string representation of the tree, with one specific exception: when a node has a right child but no left child. In such cases, you must include an empty pair of parentheses to indicate the absence of the left child. This ensures that the one-to-one mapping between the string representation and the original binary tree structure is maintained.

  In summary, empty parentheses pairs should be omitted when a node has only a left child or no children. However, when a node has a right child but no left child, an empty pair of parentheses must precede the representation of the right child to reflect the tree's structure accurately.

**Example 1:**

```
Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the empty parenthesis pairs. And it will be "1(2(4))(3)".
```

**Example 2:**

```
Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except the () after 2 is necessary to indicate the absence of a left child for 2 and the presence of a right child.
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 104]`.
* `-1000 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires us to convert a binary tree into a string using a preorder traversal while strictly following specific parentheses rules. The key observation is that empty parentheses can generally be omitted, except when a node has a right child but no left child. In that specific scenario, an empty pair `()` must be placed before the right child's representation to preserve structural isomorphism.

# Approach
1. Use a recursive depth-first search (`preorder`) passing the result string by reference (`ans`).
2. Base Case: If the current node is `NULL`, return immediately.
3. Append the current node's integer value (`root->val`) to `ans` using `std::to_string`.
4. Check if the left or right child exists (`root->left || root->right`). If true, append `(`, recursively process the left child, and append `)`.
5. Check if the right child exists (`root->right`). If true, append `(`, recursively process the right child, and append `)`.
6. Note that if `root->left` is `NULL` but `root->right` is non-NULL, step 4 will produce `()` because the recursive call on the left child hits the `NULL` base case and returns without appending, resulting in `()`. This perfectly satisfies the edge case requirement.

### Visual Walkthrough for Example 1: `root = [1, 2, 3, 4]`

| Step | Action | Current Node | `ans` string state |
| :--- | :--- | :--- | :--- |
| 1 | Visit root | `1` | `"1"` |
| 2 | Has children, enter left | `2` | `"1("` |
| 3 | Visit left.val | `2` | `"1(2"` |
| 4 | Has children, enter left | `4` | `"1(2("` |
| 5 | Visit left.val | `4` | `"1(2(4"` |
| 6 | No children, return | `4` | `"1(2(4)"` |
| 7 | No right child, return | `2` | `"1(2(4))"` |
| 8 | Enter right of `1` | `3` | `"1(2(4))("` |
| 9 | Visit right.val | `3` | `"1(2(4))(3"` |
| 10 | No children, return | `3` | `"1(2(4))(3)"` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the binary tree. Every node is visited exactly once during the preorder traversal, and string appends take amortized constant time per character relative to the tree size.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree. This accounts for the recursive call stack during DFS, which in the worst case is $$O(N)$$ for a skewed tree and $$O(\log N)$$ for a balanced tree.

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
    void preorder(TreeNode* root,string& ans){
        if(root == NULL) return;
    
        ans += to_string(root->val);
        if(root->left || root->right){
            ans += '(';
            preorder(root->left,ans);
            ans += ')';
        }

        if(root->right){
            ans+= '(';
            preorder(root->right,ans);
            ans += ')';
        }

    }
    string tree2str(TreeNode* root) {
        string ans = "";
        preorder(root,ans);
        int n = ans.size();
        return ans;
    }
};
```
