# [3558. Number of Ways to Assign Edge Weights I](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/)
**Difficulty:** `Medium` | **Tags:** `math`, `tree`, `depth-first-search`

---

## Problem Description
There is an undirected tree with `n` nodes labeled from 1 to `n`, rooted at node 1. The tree is represented by a 2D integer array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates that there is an edge between nodes `ui` and `vi`.

Initially, all edges have a weight of 0. You must assign each edge a weight of either **1** or **2**.

The **cost** of a path between any two nodes `u` and `v` is the total weight of all edges in the path connecting them.

Select any one node `x` at the **maximum** depth. Return the number of ways to assign edge weights in the path from node 1 to `x` such that its total cost is **odd**.

Since the answer may be large, return it **modulo** `109 + 7`.

**Note:** Ignore all edges **not** in the path from node 1 to `x`.

**Example 1:**

**Input:** edges = [[1,2]]

**Output:** 1

**Explanation:**

* The path from Node 1 to Node 2 consists of one edge (`1 → 2`).
* Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.

**Example 2:**

**Input:** edges = [[1,2],[1,3],[3,4],[3,5]]

**Output:** 2

**Explanation:**

* The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.
* For example, the path from Node 1 to Node 4 consists of two edges (`1 → 3` and `3 → 4`).
* Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.

**Constraints:**

* `2 <= n <= 105`
* `edges.length == n - 1`
* `edges[i] == [ui, vi]`
* `1 <= ui, vi <= n`
* `edges` represents a valid tree.

---

## Solution & Editorial
# Intuition
To make the total cost of a path of length $L$ (where $L$ is the number of edges) odd, we must choose an odd number of edges to have weight 1. Since each edge can be either 1 or 2, we are essentially choosing a subset of edges to be 1, and the rest to be 2. The number of ways to choose an odd number of edges from $L$ edges is exactly $2^{L-1}$.

# Approach
1. Build an adjacency list from the `edges` input to represent the tree structure.
2. Perform a Depth First Search (DFS) starting from node 1 to determine the maximum depth of the tree. The depth is defined as the number of edges from the root to a node.
3. Let $L$ be the maximum depth found. The number of ways to assign weights such that the sum is odd is $2^{L-1}$.
4. Use modular exponentiation to compute $2^{L-1} \pmod{10^9 + 7}$ efficiently.

### Visual Trace (Example 2: edges = [[1,2],[1,3],[3,4],[3,5]])
- Path 1->3->4 has length 2. Path 1->3->5 has length 2.
- Max depth $L = 2$.
- Result: $2^{2-1} = 2^1 = 2$.

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the number of nodes. We traverse the tree once using DFS to find the maximum depth and perform modular exponentiation in logarithmic time.
- Space complexity: $$O(N)$$ to store the adjacency list and the recursion stack during DFS.

# Code
```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxHeight = 0;


    long long powerMod(long long base, long long exp) {
        long long result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }

    void dfs(int node, int parent, int depth, const vector<vector<int>>& adj) {
        maxHeight = max(maxHeight, depth);
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, adj);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        maxHeight = 0;
        dfs(1, -1, 0, adj); 

        if (maxHeight == 0) return 1;

        return powerMod(2, maxHeight - 1); 
    }
};
```
