# [2331. Evaluate Boolean Binary Tree](https://leetcode.com/problems/evaluate-boolean-binary-tree/)
**Difficulty:** `Easy` | **Tags:** `tree`, `depth-first-search`, `binary-tree`

---

## Problem Description
You are given the `root` of a **full binary tree** with the following properties:

* **Leaf nodes** have either the value `0` or `1`, where `0` represents `False` and `1` represents `True`.
* **Non-leaf nodes** have either the value `2` or `3`, where `2` represents the boolean `OR` and `3` represents the boolean `AND`.

The **evaluation** of a node is as follows:

* If the node is a leaf node, the evaluation is the **value** of the node, i.e. `True` or `False`.
* Otherwise, **evaluate** the node's two children and **apply** the boolean operation of its value with the children's evaluations.

Return *the boolean result of **evaluating** the* `root` *node.*

A **full binary tree** is a binary tree where each node has either `0` or `2` children.

A **leaf node** is a node that has zero children.

**Example 1:**

```
Input: root = [2,1,3,null,null,0,1]
Output: true
Explanation: The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.
```

**Example 2:**

```
Input: root = [0]
Output: false
Explanation: The root node is a leaf node and it evaluates to false, so we return false.
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 1000]`.
* `0 <= Node.val <= 3`
* Every node has either `0` or `2` children.
* Leaf nodes have a value of `0` or `1`.
* Non-leaf nodes have a value of `2` or `3`.

---

## Solution & Editorial
# Intuition
The problem describes a recursive structure where the evaluation of a node depends entirely on its children. Since this is a full binary tree, we can naturally use Depth-First Search (DFS) to evaluate the tree bottom-up, starting from the leaves and propagating the boolean results to the root.

# Approach
1. **Base Case**: If the current node is a leaf (checked by `!root->left`), return `true` if the value is `1` and `false` if the value is `0`.
2. **Recursive Step**: If the node is not a leaf, recursively evaluate the `left` and `right` children.
3. **Boolean Logic**: 
   - If `root->val == 2`, apply the OR operator: `dfs(root->left) || dfs(root->right)`.
   - If `root->val == 3`, apply the AND operator: `dfs(root->left) && dfs(root->right)`.

### Visual Trace (Example 1: [2, 1, 3, null, null, 0, 1])
```
      2 (OR)
     /  \
    1    3 (AND)
        /  \
       0    1
```
- `dfs(node 1)` -> returns `true`
- `dfs(node 0)` -> returns `false`
- `dfs(node 1)` -> returns `true`
- `dfs(node 3)` -> `false && true` -> returns `false`
- `dfs(node 2)` -> `true || false` -> returns `true`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the tree. We visit each node exactly once during the post-order traversal.
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
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }

    bool dfs(TreeNode* root){
        if(!root->left){
            return (root->val == 0 ? false : true);
        }else{
            if(root->val == 2){
                return dfs(root->left) || dfs(root->right);
            }else{
                return dfs(root->left) && dfs(root->right);
            }
        }

        return false;

    }


};
```
