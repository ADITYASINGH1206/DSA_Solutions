# [2196. Create Binary Tree From Descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `tree`, `binary-tree`

---

## Problem Description
You are given a 2D integer array `descriptions` where `descriptions[i] = [parenti, childi, isLefti]` indicates that `parenti` is the **parent** of `childi` in a **binary** tree of **unique** values. Furthermore,

* If `isLefti == 1`, then `childi` is the left child of `parenti`.
* If `isLefti == 0`, then `childi` is the right child of `parenti`.

Construct the binary tree described by `descriptions` and return *its **root***.

The test cases will be generated such that the binary tree is **valid**.

**Example 1:**

```
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
```

**Example 2:**

```
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
```

**Constraints:**

* `1 <= descriptions.length <= 104`
* `descriptions[i].length == 3`
* `1 <= parenti, childi <= 105`
* `0 <= isLefti <= 1`
* The binary tree described by `descriptions` is valid.

---

## Solution & Editorial
# Intuition
To reconstruct the binary tree, we need to identify two things: the parent-child relationships and the root node. Since every node except the root has exactly one parent, the root is the only node that appears as a parent in the `descriptions` but never as a child.

# Approach
1. Use an `unordered_map<int, TreeNode*>` to store pointers to all created nodes, ensuring we reuse nodes if they appear in multiple descriptions.
2. Use an `unordered_set<int>` to keep track of all nodes that have been identified as children. Any node present in this set cannot be the root.
3. Iterate through `descriptions`: 
   - Create `TreeNode` objects for both `parent` and `child` if they don't exist in the map.
   - Link the `parent` to the `child` based on the `isLeft` flag.
   - Add the `child` value to the `children` set.
4. Iterate through the `nodes` map; the key that is not present in the `children` set is the root.

### Visual Trace (Example 1)
`descriptions = [[20,15,1], [20,17,0], [50,20,1]]`

| Iteration | Parent | Child | isLeft | Map State | Children Set |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 20 | 15 | 1 | {20:N20, 15:N15} | {15} |
| 2 | 20 | 17 | 0 | {20:N20, 15:N15, 17:N17} | {15, 17} |
| 3 | 50 | 20 | 1 | {50:N50, 20:N20, 15:N15, 17:N17} | {15, 17, 20} |

Final check: 50 is in Map but not in Children Set. Return N50.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of descriptions. We iterate through the list once to build the tree and once through the map to find the root.
- Space complexity: $$O(N)$$, as we store up to $$N+1$$ nodes in the map and up to $$N$$ children in the set.

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        for (const auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (!nodes.contains(parent)) {
                nodes[parent] = new TreeNode(parent);
            }
            if (!nodes.contains(child)) {
                nodes[child] = new TreeNode(child);
            }
            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            children.insert(child);
        }
        for (const auto& [k, v] : nodes) {
            if (!children.contains(k)) {
                return v;
            }
        }
        return nullptr;
    }
};
```
