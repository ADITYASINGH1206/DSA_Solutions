# [1028. Recover a Tree From Preorder Traversal](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)
**Difficulty:** `Hard` | **Tags:** `string`, `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
We run a preorder depth-first search (DFS) on the `root` of a binary tree.

At each node in this traversal, we output `D` dashes (where `D` is the depth of this node), then we output the value of this node.  If the depth of a node is `D`, the depth of its immediate child is `D + 1`.  The depth of the `root` node is `0`.

If a node has only one child, that child is guaranteed to be **the left child**.

Given the output `traversal` of this traversal, recover the tree and return *its* `root`.

**Example 1:**

```
Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
```

**Example 2:**

```
Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
```

**Example 3:**

```
Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]
```

**Constraints:**

* The number of nodes in the original tree is in the range `[1, 1000]`.
* `1 <= Node.val <= 109`

---

## Solution & Editorial
# Intuition
The preorder traversal representation encodes the binary tree structure using dashes (`-`) to denote the depth of each node. We can parse this string sequentially by maintaining the current string index and the depth (level) of the dashes that precede the next node value. By using a recursive helper function that receives the expected depth of the child, we can accurately reconstruct the tree structure.

# Approach
1. Store the traversal string in a class member `s` and initialize pointers `idx` (current index in the string) and `level` (the number of dashes counted ahead of the next node).
2. Create a dummy sentinel node and invoke `helper(node, 0)` to start parsing from depth 0. The actual root will be attached to `node->left`.
3. Inside `helper(TreeNode* parent, int lvl)`:
   - Check if `idx` is within bounds and whether the pre-counted `level` matches the expected depth `lvl`.
   - Parse the contiguous digits into an integer `num` to form a new `TreeNode`.
   - Attach the new node to `parent->left` if it is vacant; otherwise, attach it to `parent->right`.
   - Reset `level = 0`, then count the consecutive dashes following the node value to determine the depth of the subsequent node.
   - Recursively call `helper(node, lvl + 1)` to build the subtree for the newly created node.

### Visual Trace (Example 1: `traversal = "1-2--3--4-5--6--7"`)
| Call Stack (`lvl`) | `idx` before node | Parsed Value | Dashes counted | Next `level` | Action |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `lvl = 0` | 0 | `1` | `-` (1 dash) | `1` | Attached to dummy->left, calls `helper(node, 1)` |
| `lvl = 1` | 2 | `2` | `--` (2 dashes)| `2` | Attached to 1->left, calls `helper(node, 2)` |
| `lvl = 2` | 6 | `3` | `--` (2 dashes)| `2` | Attached to 2->left, calls `helper(node, 3)` (depth mismatch returns) |
| `lvl = 2` | 10 | `4` | `-` (1 dash) | `1` | Attached to 2->right, calls `helper(node, 3)` (depth mismatch returns) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the traversal string. Each character and digit is visited a constant number of times during parsing and dash counting.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree, representing the maximum depth of the recursive call stack.

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
    string s;
    int idx = 0, level = 0;

    TreeNode* recoverFromPreorder(string traversal) {
        s = traversal;
        TreeNode* node = new TreeNode(-1);
        helper(node, 0);
        return node->left;
    }

    void helper(TreeNode* parent, int lvl) {
        while (idx < s.length() && lvl == level) {
            int num = 0;
            while (idx < s.length() && isdigit(s[idx])) {
                num = num * 10 + (s[idx++] - '0');
            }
            TreeNode* node = new TreeNode(num);
            if (!parent->left)
                parent->left = node;
            else
                parent->right = node;
            level = 0;
            while (idx < s.length() && s[idx] == '-') {
                level++;
                idx++;
            }
            helper(node, lvl + 1);
        }
    }
};
```
