# [988. Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/)
**Difficulty:** `Medium` | **Tags:** `string`, `backtracking`, `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
You are given the `root` of a binary tree where each node has a value in the range `[0, 25]` representing the letters `'a'` to `'z'`.

Return *the **lexicographically smallest** string that starts at a leaf of this tree and ends at the root*.

As a reminder, any shorter prefix of a string is **lexicographically smaller**.

* For example, `"ab"` is lexicographically smaller than `"aba"`.

A leaf of a node is a node that has no children.

**Example 1:**

```
Input: root = [0,1,2,3,4,3,4]
Output: "dba"
```

**Example 2:**

```
Input: root = [25,1,3,1,3,0,2]
Output: "adz"
```

**Example 3:**

```
Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 8500]`.
* `0 <= Node.val <= 25`

---

## Solution & Editorial
# Intuition
The problem asks us to find the lexicographically smallest string formed by traversing from any leaf node up to the root. Since we visit nodes starting from the root down to the leaves during a traversal, building the path string in reverse order (root-to-leaf) and then reversing it when we reach a leaf gives the exact leaf-to-root string. We can maintain a global minimum string and update it whenever we encounter a valid leaf node.

# Approach
1. Define a recursive DFS helper function `dfs(TreeNode* node, string path, string& ans)` that takes the current node, the accumulated path string from the root, and a reference to the global answer `ans`.
2. Base case: If `node` is `nullptr`, return immediately.
3. Append the character corresponding to `node->val` (`'a' + node->val`) to the current `path` string.
4. Check if the current node is a leaf (both `node->left` and `node->right` are `nullptr`). If it is, reverse `path` to get the leaf-to-root string, compare it against `ans`, and update `ans` if `ans` is empty or the new path is lexicographically smaller. Reverse `path` back to its original root-to-leaf state to maintain correctness for subsequent recursive calls.
5. Recursively invoke `dfs` on `node->left` and `node->right` with the updated `path`.
6. In the main function `smallestFromLeaf(TreeNode* root)`, initialize an empty `ans` string, call `dfs(root, "", ans)`, and return `ans`.

### Visual Trace Walkthrough (Example 1)
Tree: `[0, 1, 2, 3, 4, 3, 4]`
- Root `0` ('a') -> Left `1` ('b') -> Left `3` ('d'): Leaf reached. Path = "abd" -> Reversed = "dba". `ans` becomes "dba".
- Root `0` ('a') -> Left `1` ('b') -> Right `4` ('e'): Leaf reached. Path = "abe" -> Reversed = "eba". "eba" > "dba", so `ans` remains "dba".
- Root `0` ('a') -> Right `2` ('c') -> Left `3` ('d'): Leaf reached. Path = "acd" -> Reversed = "dca". "dca" > "dba", so `ans` remains "dba".
- Root `0` ('a') -> Right `2` ('c') -> Right `4` ('e'): Leaf reached. Path = "ace" -> Reversed = "eca". "eca" > "dba", so `ans` remains "dba".
- Final Result: `"dba"`.

# Complexity
- Time complexity: $$O(N \cdot L)$$ — In the worst case, we visit every node in the tree ($N$ nodes) and perform string reversal and comparison at leaf nodes, where $L$ is the length of the path (bounded by the height of the tree). For a balanced tree, this is $O(N \log N)$, and in the worst skewed tree, it can be $O(N^2)$.
- Space complexity: $$O(L)$$ — The recursion stack and the `path` string take space proportional to the height of the tree $L$, where $L \le N$. Auxiliary storage for the answer string takes $O(L)$ space.

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
    void dfs(TreeNode* node, string path, string& ans) {
        if (node == nullptr) return;
        path += char('a' + node->val);
        if (node->left == nullptr && node->right == nullptr) {
            reverse(path.begin(), path.end());
            if (ans.empty() || path < ans) {
                ans = path;
            }
            reverse(path.begin(), path.end()); 
        }
        dfs(node->left, path, ans);
        dfs(node->right, path, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root, "", ans);
        return ans;
    }
    

};
```
