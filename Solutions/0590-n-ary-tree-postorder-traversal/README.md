# [590. N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)
**Difficulty:** `Easy` | **Tags:** `stack`, `tree`, `depth-first-search`

---

## Problem Description
Given the `root` of an n-ary tree, return *the postorder traversal of its nodes' values*.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

**Example 1:**

```
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
```

**Example 2:**

```
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 104]`.
* `0 <= Node.val <= 104`
* The height of the n-ary tree is less than or equal to `1000`.

**Follow up:** Recursive solution is trivial, could you do it iteratively?

---

## Solution & Editorial
# Intuition
Postorder traversal of an N-ary tree visits all children of a node recursively before visiting the node itself. Since each node must be processed after its subtrees, a standard depth-first traversal naturally fits this visiting order.

# Approach
1. Initialize an empty integer vector `ans` to store the final traversal order.
2. Define a helper function `traverse(Node* root, vector<int>& ans)` that checks if the current `root` is `NULL`. If it is, return immediately.
3. Iterate through each `child` in `root->children` and recursively call `traverse(child, ans)`.
4. After visiting all children, append the current node's value (`root->val`) to `ans` using `ans.push_back(root->val)`.
5. Return the populated `ans` vector from the main `postorder` method.

### Visual Trace (Example 1: root = [1, null, 3, 2, 4, null, 5, 6])
- Call `traverse(1)`:
  - Iterate children `[3, 2, 4]`:
    - Call `traverse(3)` -> visits children `[5, 6]`:
      - Call `traverse(5)` -> pushes `5`, returns.
      - Call `traverse(6)` -> pushes `6`, returns.
      - Pushes `3`, returns.
    - Call `traverse(2)` -> pushes `2`, returns.
    - Call `traverse(4)` -> pushes `4`, returns.
  - Pushes `1`, returns.
- Final `ans` = `[5, 6, 3, 2, 4, 1]`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the total number of nodes in the N-ary tree. Every node is visited exactly once.
- Space complexity: $$O(H)$$ where $$H$$ is the height of the tree, representing the maximum recursion stack depth during depth-first search.

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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        traverse(root,ans);
        return ans;
    }
    void traverse(Node* root,vector<int>& ans){
        if(root == NULL) return;

        for(Node* child : root->children){
            traverse(child, ans);
        }
         
        ans.push_back(root->val);
    }
};
```
