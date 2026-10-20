# [3650. Minimum Cost Path with Edge Reversals](https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/)
**Difficulty:** `Medium` | **Tags:** `graph`, `heap-priority-queue`, `shortest-path`

---

## Problem Description
You are given a directed, weighted graph with `n` nodes labeled from 0 to `n - 1`, and an array `edges` where `edges[i] = [ui, vi, wi]` represents a directed edge from node `ui` to node `vi` with cost `wi`.

Each node `ui` has a switch that can be used **at most once**: when you arrive at `ui` and have not yet used its switch, you may activate it on one of its incoming edges `vi → ui` reverse that edge to `ui → vi` and **immediately** traverse it.

The reversal is only valid for that single move, and using a reversed edge costs `2 * wi`.

Return the **minimum** total cost to travel from node 0 to node `n - 1`. If it is not possible, return -1.

**Example 1:**

**Input:** n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

**Output:** 5

**Explanation:**

* Use the path `0 → 1` (cost 3).
* At node 1 reverse the original edge `3 → 1` into `1 → 3` and traverse it at cost `2 * 1 = 2`.
* Total cost is `3 + 2 = 5`.

**Example 2:**

**Input:** n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]

**Output:** 3

**Explanation:**

* No reversal is needed. Take the path `0 → 2` (cost 1), then `2 → 1` (cost 1), then `1 → 3` (cost 1).
* Total cost is `1 + 1 + 1 = 3`.

**Constraints:**

* `2 <= n <= 5 * 104`
* `1 <= edges.length <= 105`
* `edges[i] = [ui, vi, wi]`
* `0 <= ui, vi <= n - 1`
* `1 <= wi <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks for the minimum cost to travel from node 0 to node n-1, with the unique ability to reverse an incoming edge at any node exactly once. This can be modeled as a shortest path problem on an augmented graph. By adding a reverse edge for every original directed edge `u -> v` with weight `w` as a new edge `v -> u` with weight `2 * w`, we effectively represent the "reversal" operation as a standard traversal in a modified graph.

# Approach
1. **Graph Augmentation**: Create an adjacency list `g` where for every directed edge `u -> v` with weight `w`, we add two entries: 
   - A forward edge `u -> v` with weight `w`.
   - A reverse edge `v -> u` with weight `2 * w`.
2. **Dijkstra's Algorithm**: Use a priority queue to perform Dijkstra's starting from node 0. The state is simply the current node `u` and the accumulated cost `d`.
3. **State Transition**: For each neighbor `v` of `u`, if the path through `v` offers a lower cost than the current known `dist[v]`, update `dist[v]` and push the new cost to the priority queue.
4. **Termination**: The first time we extract node `n-1` from the priority queue, we have found the minimum cost.

### Visual Trace (Example 1: n=4, edges=[[0,1,3],[3,1,1],[2,3,4],[0,2,2]])
- **Graph**: 
  - 0->1 (3), 1->0 (6)
  - 3->1 (1), 1->3 (2)
  - 2->3 (4), 3->2 (8)
  - 0->2 (2), 2->0 (4)
- **Trace**:
  - Start: `dist[0]=0`, PQ: `{(0,0)}`
  - Pop `(0,0)`: Neighbors 1 (cost 3), 2 (cost 2). PQ: `{(2,2), (3,1)}`
  - Pop `(2,2)`: Neighbor 3 (cost 2+4=6). PQ: `{(3,1), (6,3)}`
  - Pop `(3,1)`: Neighbor 3 (cost 3+2=5). PQ: `{(5,3), (6,3)}`
  - Pop `(5,3)`: Target reached, return 5.

# Complexity
- Time complexity: $$O(E \log V)$$, where $$E$$ is the number of edges and $$V$$ is the number of nodes. Each edge is added to the priority queue at most once.
- Space complexity: $$O(V + E)$$ to store the adjacency list and the distance array.

# Code
```cpp
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        using pii = pair<int, int>;
        vector<vector<pii>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w * 2});
        }

        const int inf = INT_MAX / 2;
        vector<int> dist(n, inf);
        dist[0] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            if (u == n - 1) {
                return d;
            }

            for (auto& [v, w] : g[u]) {
                int nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        return -1;
    }
};
```
