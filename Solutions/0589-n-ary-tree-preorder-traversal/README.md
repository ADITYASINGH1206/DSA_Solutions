# [589. N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)
**Difficulty:** `Easy` | **Tags:** `stack`, `tree`, `depth-first-search`

---

## Problem Description
Given the `root` of an n-ary tree, return *the preorder traversal of its nodes' values*.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

**Example 1:**

```
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
```

**Example 2:**

```
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 104]`.
* `0 <= Node.val <= 104`
* The height of the n-ary tree is less than or equal to `1000`.

**Follow up:** Recursive solution is trivial, could you do it iteratively?

---

## Solution & Editorial
# Intuition
The preorder traversal of an N-ary tree visits the current node first, followed by recursively visiting each of its child subtrees from left to right. A depth-first search (DFS) utilizing recursion naturally mirrors this hierarchical visiting order.

# Approach
1. Define a helper function `preorder(Node* root, vector<int>& ans)` that takes the current node and a reference to the result vector `ans`.
2. Handle the base case: if `root` is `nullptr`, immediately return.
3. Push the current node's value (`root->val`) into `ans` to satisfy the preorder requirement (Root -> Children).
4. Iterate through all children in `root->children` from left to right, recursively invoking the helper function on each child node.
5. In the main `preorder` function, instantiate an empty `vector<int> ans`, invoke the helper starting from `root`, and return `ans`.

### Visual Walkthrough (Example 1: root = [1, null, 3, 2, 4, null, 5, 6])
- Call `preorder(1, ans)`: `ans` becomes `[1]`, iterates children `[3, 2, 4]`.
  - Call `preorder(3, ans)`: `ans` becomes `[1, 3]`, iterates children `[5, 6]`.
    - Call `preorder(5, ans)`: `ans` becomes `[1, 3, 5]`, no children.
    - Call `preorder(6, ans)`: `ans` becomes `[1, 3, 5, 6]`, no children.
  - Call `preorder(2, ans)`: `ans` becomes `[1, 3, 5, 6, 2]`, no children.
  - Call `preorder(4, ans)`: `ans` becomes `[1, 3, 5, 6, 2, 4]`, no children.
- Final Output: `[1, 3, 5, 6, 2, 4]`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the total number of nodes in the N-ary tree. Every node is visited exactly once during the traversal.
- Space complexity: $$O(H)$$, where $$H$$ is the height of the tree. This accounts for the maximum call stack depth utilized by the recursion, which in the worst case (skewed tree) is $$O(N)$$ and in the best case (balanced tree) is $$O(\log N)$$.

# Code
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;

    }

    void preorder(Node* root,vector<int>& ans){
        if(root == NULL) return;

        ans.push_back(root->val);
        for(int i = 0;i<root->children.size();i++){
            preorder(root->children[i],ans);
        }

    }
};
```
