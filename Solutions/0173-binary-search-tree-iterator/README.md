# [173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/)
**Difficulty:** `Medium` | **Tags:** `stack`, `tree`, `design`, `binary-search-tree`, `binary-tree`, `iterator`

---

## Problem Description
Implement the `BSTIterator` class that represents an iterator over the **[in-order traversal](https://en.wikipedia.org/wiki/Tree_traversal#In-order_(LNR))** of a binary search tree (BST):

* `BSTIterator(TreeNode root)` Initializes an object of the `BSTIterator` class. The `root` of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
* `boolean hasNext()` Returns `true` if there exists a number in the traversal to the right of the pointer, otherwise returns `false`.
* `int next()` Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to `next()` will return the smallest element in the BST.

You may assume that `next()` calls will always be valid. That is, there will be at least a next number in the in-order traversal when `next()` is called.

**Example 1:**

```
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 105]`.
* `0 <= Node.val <= 106`
* At most `105` calls will be made to `hasNext`, and `next`.

**Follow up:**

* Could you implement `next()` and `hasNext()` to run in average `O(1)` time and use `O(h)` memory, where `h` is the height of the tree?

---

## Solution & Editorial
# Intuition
To achieve an in-order traversal of a Binary Search Tree with controlled memory, we can simulate the recursion stack explicitly using a standard stack data structure. By continuously pushing left child nodes onto the stack, we ensure that the top of the stack always points to the next smallest element in the in-order sequence.

# Approach
1. **Initialization (`BSTIterator`)**: Define a helper function `pushAll(TreeNode* root)` that traverses down the left spine of the given subtree, pushing every node onto `stk` until a `nullptr` is reached. Calling `pushAll(root)` in the constructor sets up the iterator to immediately point to the minimum element at the top of the stack.
2. **Fetch Next Element (`next`)**: Pop the top node from `stk`, which represents the current smallest element. If this popped node has a right child, we expand its right subtree by calling `pushAll(temp->right)` to discover and cache subsequent in-order candidates. Finally, return `temp->val`.
3. **Check Existence (`hasNext`)**: Return true if `stk` is non-empty, indicating more nodes remain in the traversal.

### Visual Trace Walkthrough
Consider Example 1 with root `7`, left child `3`, and right child `15` (having children `9` and `20`).

| Operation | Stack State (Bottom to Top) | Returned Value | Description |
| :--- | :--- | :--- | :--- |
| `BSTIterator([7, 3, 15, ...])` | `[7, 3]` | — | Pushes left spine `7 -> 3` onto stack. |
| `next()` | `[7]` | `3` | Pops `3`, pushes right child (`nullptr`). |
| `next()` | `[15, 9]` | `7` | Pops `7`, pushes right subtree `15` and its left spine `9`. |
| `hasNext()` | `[15, 9]` | `true` | Stack is non-empty. |
| `next()` | `[15]` | `9` | Pops `9`, pushes right child (`nullptr`). |

# Complexity
- Time complexity: Average $$O(1)$$ per `next()` call. Each node is pushed and popped from the stack exactly once across the entire traversal of $$N$$ nodes, amortizing traversal overhead over $$N$$ operations. `hasNext()` operates in $$O(1)$$ time.
- Space complexity: $$O(h)$$ where $$h$$ is the height of the BST. The stack at most holds one path from root to a leaf node, bounded by the tree height (at most $$O(N)$$ in the worst-case skewed tree, and $$O(\log N)$$ for a balanced tree).

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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = stk.top();
        stk.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }

    void pushAll(TreeNode* root){
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
};

// class BSTIterator {
// public:
//     vector<int> nodes;
//     BSTIterator(TreeNode* root) {
//         traverse(root,nodes);
//         reverse(nodes.begin(),nodes.end());
//     }
    
//     int next() {
//         int n = nodes.size();
//         int val = nodes[n-1];
//         nodes.pop_back();
//         return val;
//     }
    
//     bool hasNext() {
//         int n = nodes.size();
//         return n;
//     }
//     void traverse(TreeNode* root,vector<int> & nodes){
//         if(root == NULL) return;

//         traverse(root->left,nodes);
//         nodes.push_back(root->val);
//         traverse(root->right,nodes);

//     }
// };
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
