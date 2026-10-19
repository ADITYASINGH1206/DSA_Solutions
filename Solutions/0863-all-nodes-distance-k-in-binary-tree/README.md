# [863. All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, the value of a target node `target`, and an integer `k`, return *an array of the values of all nodes that have a distance* `k` *from the target node.*

You can return the answer in **any order**.

**Example 1:**

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
```

**Example 2:**

```
Input: root = [1], target = 1, k = 3
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 500]`.
* `0 <= Node.val <= 500`
* All the values `Node.val` are **unique**.
* `target` is the value of one of the nodes in the tree.
* `0 <= k <= 1000`

---

## Solution & Editorial
# Intuition
A binary tree only provides downward traversal from parent to child. To find nodes at distance $k$ in all directions (including upward toward the parent), we can map each node to its parent using a breadth-first search and then perform a second breadth-first search starting from the target node, treating the tree as an undirected graph.

# Approach
1. **Parent Mapping (`markParents`)**: Use a queue-based BFS traversal starting from the `root` to populate an `unordered_map<TreeNode*, TreeNode*>& parentsMp` mapping every child node to its corresponding parent.
2. **Graph BFS Traversal (`distanceK`)**: Initialize a queue and an `unordered_map<TreeNode*, bool> visited` hash map. Push the `target` node into the queue and mark it as visited.
3. **Level-by-Level Expansion**: Perform a standard level-order traversal. For each node popped from the queue, explore three possible directions: left child, right child, and parent. If any neighbor exists and has not been visited, mark it as visited and push it to the queue.
4. **Distance Check**: Track the current level (`cur_level`). Once `cur_level` reaches $k$, break out of the expansion loop. The remaining nodes in the queue are precisely those at distance $k$.
5. **Collection**: Extract the values of all nodes remaining in the queue into a vector and return the result.

### Visual Walkthrough (Example 1: Target = 5, k = 2)
- **Step 1**: `parentsMp` records parents: `5->3`, `1->3`, `6->5`, `2->5`, `0->1`, `8->1`, `7->2`, `4->2`.
- **Step 2**: Start BFS at queue `[5]`, `visited = {5}`, `cur_level = 0`.
- **Step 3**: Pop `5`, push unvisited neighbors `6`, `2`, and parent `3`. Queue: `[6, 2, 3]`, `visited = {5, 6, 2, 3}`, `cur_level = 1`.
- **Step 4**: Pop `6`, `2`, `3`. Push unvisited neighbors: from `2` push `7`, `4`. Queue becomes `[7, 4, 1]` (since `1` is parent of `3`), `cur_level = 2`.
- **Step 5**: `cur_level` reaches $k = 2$, loop terminates. Queue contains nodes `[7, 4, 1]`, which are collected and returned.

# Complexity
- Time complexity: $$O(N)$$ — Traversing the tree to map parents takes $$O(N)$$ time, and the BFS from the target node visits every node and edge at most once, taking $$O(N)$$ time. Thus, total time complexity is $$O(N)$$.
- Space complexity: $$O(N)$$ — The `parentsMp`, `visited` map, and the queue each store up to $$O(N)$$ entries corresponding to the number of nodes in the binary tree.

# Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parentsMp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left != NULL){
                parentsMp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right != NULL){
                parentsMp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentsMp;
        markParents(root,parentsMp);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int cur_level = 0;
        while(!q.empty()){
            int n = q.size();
            if(cur_level++ == k) break;
            for(int i =0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parentsMp[temp] && !visited[parentsMp[temp]]){
                    q.push(parentsMp[temp]);
                    visited[parentsMp[temp]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            ans.push_back(cur->val);
        }
        return ans;
        
    }
};
```
