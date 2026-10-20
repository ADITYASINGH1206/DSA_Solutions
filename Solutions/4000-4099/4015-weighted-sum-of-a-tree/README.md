# [4015. Weighted Sum of a Tree](https://leetcode.com/problems/weighted-sum-of-a-tree/)
**Difficulty:** `Medium` | **Tags:** `array`, `tree`, `depth-first-search`

---

## Problem Description
You are given an integer array `parent` of length `n` representing a rooted tree with nodes labeled from 0 to `n - 1`.

The tree is **rooted** at node 0, so `parent[0] = -1`. For each node `i` where `1 <= i <= n - 1`, `parent[i]` denotes the parent of node `i`.

You are also given an integer array `nums` of length `n`, where `nums[i]` denotes the value of node `i`.

The weight of a node `i` at depth `d` is `nums[i] * (h - d + 1)`, where `h` is the height of the tree.

Return the **sum** of the weights of all nodes in the tree.

The **depth** of a node is the number of nodes on the path from the root to that node, inclusive, with the root having depth 1.

The **height** of the tree is the maximum depth among all nodes in the tree.

**Example 1:**

​​​​​​​

**Input:** parent = [-1,0,0,0,2,2], nums = [5,2,3,1,4,6]

**Output:** 37

**Explanation:**

The height of the tree is 3.

| Node | `nums[i]` | Depth (`d`) | Weight |
| --- | --- | --- | --- |
| 0 | 5 | 1 | `5 * (3 - 1 + 1) = 15` |
| 1 | 2 | 2 | `2 * (3 - 2 + 1) = 4` |
| 2 | 3 | 2 | `3 * (3 - 2 + 1) = 6` |
| 3 | 1 | 2 | `1 * (3 - 2 + 1) = 2` |
| 4 | 4 | 3 | `4 * (3 - 3 + 1) = 4` |
| 5 | 6 | 3 | `6 * (3 - 3 + 1) = 6` |

The sum of all node weights is `15 + 4 + 6 + 2 + 4 + 6 = 37`.

**Example 2:**

​​​​​​​​​​​​​​

**Input:** parent = [-1,0,1,2], nums = [1,2,3,4]

**Output:** 20

**Explanation:**

The height of the tree is 4.

| Node | `nums[i]` | Depth (`d`) | Weight |
| --- | --- | --- | --- |
| 0 | 1 | 1 | `1 * (4 - 1 + 1) = 4` |
| 1 | 2 | 2 | `2 * (4 - 2 + 1) = 6` |
| 2 | 3 | 3 | `3 * (4 - 3 + 1) = 6` |
| 3 | 4 | 4 | `4 * (4 - 4 + 1) = 4` |

The sum of all node weights is `4 + 6 + 6 + 4 = 20`.

**Constraints:**

* `1 <= n <= 105`
* `n == parent.length == nums.length`
* `parent[0] == -1`
* `0 <= parent[i] <= n - 1` for all `i` in `[1, n - 1]`
* `1 <= nums[i] <= 106`
* The input is generated such that the array `parent` represents a valid tree rooted at node 0.

---

## Solution & Editorial
# Intuition
To calculate the weighted sum, we first need to determine the depth of every node and the overall height of the tree. Since the tree structure is provided via a parent array, we can represent it as an adjacency list and perform a Breadth-First Search (BFS) to compute depths efficiently.

# Approach
1. **Build Adjacency List**: Iterate through the `parent` array to construct an adjacency list `adj` where `adj[u]` contains all children of node `u`.
2. **BFS for Depth**: Initialize a `depth` array and a queue `q`. Starting from the root (node 0), perform a level-order traversal. For each node `curr`, set `depth[child] = depth[curr] + 1` and track the `maxDepth` encountered.
3. **Calculate Weighted Sum**: Once all depths are known, iterate through all nodes `i` from `0` to `n-1`. Apply the formula `nums[i] * (maxDepth - depth[i] + 1)` and accumulate the result in a `long long` variable `ans` to prevent overflow.

### Visual Trace (Example 1: parent = [-1,0,0,0,2,2])
| Step | Queue | Node | Depth | MaxDepth |
| :--- | :--- | :--- | :--- | :--- |
| Init | [0] | - | 1 | 0 |
| Pop 0 | [1, 2, 3] | 0 | 1 | 1 |
| Pop 1 | [2, 3] | 1 | 2 | 2 |
| Pop 2 | [3, 4, 5] | 2 | 2 | 2 |
| Pop 3 | [4, 5] | 3 | 2 | 2 |
| Pop 4 | [5] | 4 | 3 | 3 |
| Pop 5 | [] | 5 | 3 | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes. We traverse each node and edge exactly once during the BFS and once more during the final summation.
- Space complexity: $$O(N)$$, required for the adjacency list, the `depth` vector, and the queue used in BFS.

# Code
```cpp
class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = i;
            } else {
                adj[parent[i]].push_back(i);
            }
        }

        vector<int> depth(n, 0);
        int maxDepth = 0;
        queue<int> q;
        if (root != -1) {
            q.push(root);
            depth[root] = 1;
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            maxDepth = max(maxDepth, depth[curr]);
            for (int child : adj[curr]) {
                depth[child] = depth[curr] + 1;
                q.push(child);
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (maxDepth - depth[i] + 1);
        }

        return ans;
    }
};
```
