# [1448. Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given a binary tree `root`, a node *X* in the tree is named **good** if in the path from root to *X* there are no nodes with a value *greater than* X.

Return the number of **good** nodes in the binary tree.

**Example 1:**

```

Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

**Example 2:**

```

Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
```

**Example 3:**

```

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
```

**Constraints:**

* The number of nodes in the binary tree is in the range `[1, 10^5]`.
* Each node's value is between `[-10^4, 10^4]`.

---

## Solution & Editorial
# Intuition
A node is "good" if its value is greater than or equal to the maximum value encountered on the path from the root to that node. By maintaining the current path maximum during a Depth-First Search (DFS), we can determine if a node is good in constant time.

# Approach
1. Initialize a counter `ans` to 0.
2. Perform a recursive DFS starting from the root. Pass the current node, the reference to `ans`, and the `maxi` value encountered so far on the current path.
3. At each node, if `root->val >= maxi`, the node is "good". Increment `ans` and update `maxi` to `root->val` for the subsequent recursive calls.
4. Recurse into the left and right children with the updated `maxi`.

### Visual Trace (Example 1: [3,1,4,3,null,1,5])
| Node | Path Max | Is Good? | ans |
| :--- | :--- | :--- | :--- |
| 3 | 3 | Yes | 1 |
| 1 | 3 | No | 1 |
| 4 | 4 | Yes | 2 |
| 3 | 4 | No | 2 |
| 1 | 4 | No | 2 |
| 5 | 5 | Yes | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the tree, as we visit each node exactly once.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the tree, representing the maximum depth of the recursion stack.

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
    void dfs(TreeNode* root,int& ans,int maxi){
        if(root == NULL) return;

        if(root->val >= maxi){
            maxi = root->val;
            ans++;
        }
        dfs(root->left,ans,maxi);
        dfs(root->right,ans,maxi);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root,ans,root->val);
        return ans;

    }
};
```
