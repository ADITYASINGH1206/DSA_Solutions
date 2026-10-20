# [3820. Pythagorean Distance Nodes in a Tree](https://leetcode.com/problems/pythagorean-distance-nodes-in-a-tree/)
**Difficulty:** `Medium` | **Tags:** `tree`, `breadth-first-search`

---

## Problem Description
You are given an integer `n` and an undirected tree with `n` nodes numbered from 0 to `n - 1`. The tree is represented by a 2D array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates an undirected edge between `ui` and `vi`.

You are also given three **distinct** target nodes `x`, `y`, and `z`.

For any node `u` in the tree:

* Let `dx` be the distance from `u` to node `x`
* Let `dy` be the distance from `u` to node `y`
* Let `dz` be the distance from `u` to node `z`

The node `u` is called **special** if the three distances form a **Pythagorean Triplet**.

Return an integer denoting the number of special nodes in the tree.

A **Pythagorean triplet** consists of three integers `a`, `b`, and `c` which, when sorted in **ascending** order, satisfy `a2 + b2 = c2`.

The **distance** between two nodes in a tree is the number of edges on the unique path between them.

**Example 1:**

**Input:** n = 4, edges = [[0,1],[0,2],[0,3]], x = 1, y = 2, z = 3

**Output:** 3

**Explanation:**

For each node, we compute its distances to nodes `x = 1`, `y = 2`, and `z = 3`.

* Node 0 has distances 1, 1, and 1. After sorting, the distances are 1, 1, and 1, which do not satisfy the Pythagorean condition.
* Node 1 has distances 0, 2, and 2. After sorting, the distances are 0, 2, and 2. Since `02 + 22 = 22`, node 1 is special.
* Node 2 has distances 2, 0, and 2. After sorting, the distances are 0, 2, and 2. Since `02 + 22 = 22`, node 2 is special.
* Node 3 has distances 2, 2, and 0. After sorting, the distances are 0, 2, and 2. This also satisfies the Pythagorean condition.

Therefore, nodes 1, 2, and 3 are special, and the answer is 3.

**Example 2:**

**Input:** n = 4, edges = [[0,1],[1,2],[2,3]], x = 0, y = 3, z = 2

**Output:** 0

**Explanation:**

For each node, we compute its distances to nodes `x = 0`, `y = 3`, and `z = 2`.

* Node 0 has distances 0, 3, and 2. After sorting, the distances are 0, 2, and 3, which do not satisfy the Pythagorean condition.
* Node 1 has distances 1, 2, and 1. After sorting, the distances are 1, 1, and 2, which do not satisfy the Pythagorean condition.
* Node 2 has distances 2, 1, and 0. After sorting, the distances are 0, 1, and 2, which do not satisfy the Pythagorean condition.
* Node 3 has distances 3, 0, and 1. After sorting, the distances are 0, 1, and 3, which do not satisfy the Pythagorean condition.

No node satisfies the Pythagorean condition. Therefore, the answer is 0.

**Example 3:**

**Input:** n = 4, edges = [[0,1],[1,2],[1,3]], x = 1, y = 3, z = 0

**Output:** 1

**Explanation:**

For each node, we compute its distances to nodes `x = 1`, `y = 3`, and `z = 0`.

* Node 0 has distances 1, 2, and 0. After sorting, the distances are 0, 1, and 2, which do not satisfy the Pythagorean condition.
* Node 1 has distances 0, 1, and 1. After sorting, the distances are 0, 1, and 1. Since `02 + 12 = 12`, node 1 is special.
* Node 2 has distances 1, 2, and 2. After sorting, the distances are 1, 2, and 2, which do not satisfy the Pythagorean condition.
* Node 3 has distances 1, 0, and 2. After sorting, the distances are 0, 1, and 2, which do not satisfy the Pythagorean condition.

Therefore, the answer is 1.

**Constraints:**

* `4 <= n <= 105`
* `edges.length == n - 1`
* `edges[i] = [ui, vi]`
* `0 <= ui, vi, x, y, z <= n - 1`
* `x`, `y`, and `z` are pairwise **distinct**.
* The input is generated such that `edges` represent a valid tree.

---

## Solution & Editorial
# Intuition
To determine if a node is "special," we need the distance from that node to three specific target nodes ($x, y, z$). Since the graph is an unweighted tree, the shortest path distance between any two nodes can be computed efficiently using Breadth-First Search (BFS). By running three independent BFS traversals, we can precompute the distance vectors for all nodes in $O(N)$ time.

# Approach
1. **Graph Representation**: Convert the `edges` list into an adjacency list `adj` to allow $O(1)$ traversal of neighbors for any node.
2. **Distance Computation**: Implement a `bfs` function that takes a starting node and populates a distance array. Run this function three times, once for each target node ($x, y, z$), resulting in three distance vectors: `distX`, `distY`, and `distZ`.
3. **Validation**: Iterate through every node $i$ from $0$ to $n-1$. Extract the distances $(d_1, d_2, d_3)$ to the targets, sort them such that $d[0] \le d[1] \le d[2]$, and check the Pythagorean condition $d[0]^2 + d[1]^2 = d[2]^2$.

### Visual Trace (Example 1: n=4, x=1, y=2, z=3)
| Node | Dist to 1 | Dist to 2 | Dist to 3 | Sorted | $a^2+b^2=c^2$ | Special? |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 1 | 1 | 1 | 1, 1, 1 | $1+1 \neq 1$ | No |
| 1 | 0 | 2 | 2 | 0, 2, 2 | $0+4 = 4$ | Yes |
| 2 | 2 | 0 | 2 | 0, 2, 2 | $0+4 = 4$ | Yes |
| 3 | 2 | 2 | 0 | 0, 2, 2 | $0+4 = 4$ | Yes |

# Complexity
- **Time complexity**: $$O(N)$$. Building the adjacency list takes $O(N)$. Each of the three BFS traversals visits every node and edge exactly once, resulting in $O(N + E) = O(N)$ time. The final loop iterates $N$ times with constant-time sorting (3 elements), totaling $O(N)$.
- **Space complexity**: $$O(N)$$. We store the adjacency list ($O(N)$) and three distance vectors of size $N$ ($O(N)$), leading to linear space usage.

# Code
```cpp
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    void bfs(int start, int n, const vector<vector<int>>& adj, vector<int>& dist) {
        fill(dist.begin(), dist.end(), -1); 
        queue<int> q;
        
        q.push(start);
        dist[start] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (dist[v] == -1) { 
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    
        vector<int> distX(n), distY(n), distZ(n);
        
        // Run BFS from each target node
        bfs(x, n, adj, distX);
        bfs(y, n, adj, distY);
        bfs(z, n, adj, distZ);
        
        int specialCount = 0;
    
        for (int i = 0; i < n; i++) {
            long long d1 = distX[i];
            long long d2 = distY[i];
            long long d3 = distZ[i];
            
            vector<long long> d = {d1, d2, d3};
            sort(d.begin(), d.end()); 

            if (d[0] * d[0] + d[1] * d[1] == d[2] * d[2]) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
};
```
