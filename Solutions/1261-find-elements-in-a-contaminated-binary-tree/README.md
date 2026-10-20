# [1261. Find Elements in a Contaminated Binary Tree](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `tree`, `depth-first-search`, `breadth-first-search`, `design`, `binary-tree`

---

## Problem Description
Given a binary tree with the following rules:

1. `root.val == 0`
2. For any `treeNode`:
   1. If `treeNode.val` has a value `x` and `treeNode.left != null`, then `treeNode.left.val == 2 * x + 1`
   2. If `treeNode.val` has a value `x` and `treeNode.right != null`, then `treeNode.right.val == 2 * x + 2`

Now the binary tree is contaminated, which means all `treeNode.val` have been changed to `-1`.

Implement the `FindElements` class:

* `FindElements(TreeNode* root)` Initializes the object with a contaminated binary tree and recovers it.
* `bool find(int target)` Returns `true` if the `target` value exists in the recovered binary tree.

**Example 1:**

```
Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True
```

**Example 2:**

```
Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
```

**Example 3:**

```
Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
```

**Constraints:**

* `TreeNode.val == -1`
* The height of the binary tree is less than or equal to `20`
* The total number of nodes is between `[1, 104]`
* Total calls of `find()` is between `[1, 104]`
* `0 <= target <= 106`

---

## Solution & Editorial
# Intuition
The problem asks us to recover a contaminated binary tree where each node's value is initially `-1`. The rules state that the root has value `0`, and for any node with value `x`, its left child has value `2 * x + 1` and its right child has value `2 * x + 2`. By performing a Depth-First Search (DFS) during initialization, we can reconstruct the original tree values and simultaneously store all valid recovered values in an `unordered_set` for $$O(1)$$ average time lookups.

# Approach
1. Maintain an `unordered_set<int> values` member variable to store all valid node values encountered during recovery.
2. Define a private helper method `dfs(TreeNode* node, int current_val)`:
   - Base case: If `node == nullptr`, return immediately.
   - Assign `node->val = current_val`.
   - Insert `current_val` into the `values` set.
   - Recursively call `dfs` on `node->left` with `2 * current_val + 1` and on `node->right` with `2 * current_val + 2`.
3. In the constructor `FindElements(TreeNode* root)`, initialize the recovery by calling `dfs(root, 0)`.
4. For the `find(int target)` method, query the hash set using `values.count(target) > 0` to return whether the target exists.

### Visual Walkthrough (Example 1)
Given tree: `root = [-1, null, -1]`
- `FindElements([-1, null, -1])` invoked:
  - `dfs(root, 0)`: `root->val = 0`, `values` = `{0}`
  - Left child is `nullptr`, returns.
  - Right child exists: `dfs(right_node, 2 * 0 + 2)` i.e., `dfs(right_node, 2)`:
    - `right_node->val = 2`, `values` = `{0, 2}`
- `find(1)`: Checks if `1` is in `values`. Returns `false`.
- `find(2)`: Checks if `2` is in `values`. Returns `true`.

# Complexity
- Time complexity: 
  - Constructor `FindElements`: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree, as each node is visited exactly once and hash set insertion takes $$O(1)$$ average time.
  - Method `find`: $$O(1)$$ average time complexity per query via `unordered_set::count`.
- Space complexity: $$O(N)$$ for storing the $$N$$ recovered node values inside the `unordered_set`, alongside $$O(H)$$ auxiliary stack space for recursion where $$H$$ is the height of the tree.

# Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
private:
    unordered_set<int> values;
    void dfs(TreeNode* node, int current_val) {
        if (node == nullptr) return;
        node->val = current_val;
        values.insert(current_val);
        dfs(node->left, 2 * current_val + 1);
        dfs(node->right, 2 * current_val + 2);
    }

public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return values.count(target) > 0;
    }
};
```
