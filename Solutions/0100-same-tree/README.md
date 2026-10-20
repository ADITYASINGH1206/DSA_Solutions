# [100. Same Tree](https://leetcode.com/problems/same-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

**Example 1:**

```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

**Example 2:**

```
Input: p = [1,2], q = [1,null,2]
Output: false
```

**Example 3:**

```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```

**Constraints:**

* The number of nodes in both trees is in the range `[0, 100]`.
* `-104 <= Node.val <= 104`

---

## Solution & Editorial
# Intuition
To determine if two binary trees are identical, we must verify that their root nodes match in value, and that their respective left and right subtrees are structurally and numerically identical. This naturally lends itself to a recursive depth-first search (DFS) traversal.

# Approach
1. Check base cases: if either pointer `p` or `q` is `NULL`, return `true` if both are `NULL` (`p == q`), otherwise return `false`.
2. If both nodes are non-null, compare their values (`p->val == q->val`).
3. Recursively check their left subtrees (`isSameTree(p->left, q->left)`) and right subtrees (`isSameTree(p->right, q->right)`).
4. Combine all conditions using logical AND operators to return the final boolean result.

### Visual Trace Walkthrough (Example 1)
Input: `p = [1,2,3]`, `q = [1,2,3]`

| Call Stack Frame | `p` Node Val | `q` Node Val | Value Match? | Left Subtree Result | Right Subtree Result | Frame Output |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| `isSameTree(1, 1)` | 1 | 1 | Yes | `isSameTree(2, 2)` -> `true` | `isSameTree(3, 3)` -> `true` | `true` |
| `isSameTree(2, 2)` | 2 | 2 | Yes | `isSameTree(NULL, NULL)` -> `true` | `isSameTree(NULL, NULL)` -> `true` | `true` |
| `isSameTree(3, 3)` | 3 | 3 | Yes | `isSameTree(NULL, NULL)` -> `true` | `isSameTree(NULL, NULL)` -> `true` | `true` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the minimum number of nodes between the two trees. Each node is visited at most once during the recursive traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the binary tree. This accounts for the maximum depth of the call stack during recursion, which is $$O(N)$$ in the worst-case skewed tree and $$O(\log N)$$ in a balanced tree.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== NULL || q == NULL){
            return (p==q);
        }
        return(p->val == q->val)
            && isSameTree(p->left,q->left)
            && isSameTree(p->right,q->right);
    }
};
```
