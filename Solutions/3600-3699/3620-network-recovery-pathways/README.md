# [3620. Network Recovery Pathways](https://leetcode.com/problems/network-recovery-pathways/)
**Difficulty:** `Hard` | **Tags:** `array`, `binary-search`, `dynamic-programming`, `graph`, `topological-sort`, `heap-priority-queue`, `shortest-path`

---

## Problem Description
You are given a directed acyclic graph of `n` nodes numbered from 0 to `n − 1`. This is represented by a 2D array `edges` of length `m`, where `edges[i] = [ui, vi, costi]` indicates a one‑way communication from node `ui` to node `vi` with a recovery cost of `costi`.

Some nodes may be offline. You are given a boolean array `online` where `online[i] = true` means node `i` is online. Nodes 0 and `n − 1` are always online.

A path from 0 to `n − 1` is **valid** if:

* All intermediate nodes on the path are online.
* The total recovery cost of all edges on the path does not exceed `k`.

For each valid path, define its **score** as the minimum edge‑cost along that path.

Return the **maximum** path score (i.e., the largest **minimum**-edge cost) among all valid paths. If no valid path exists, return -1.

**Example 1:**

**Input:** edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]], online = [true,true,true,true], k = 10

**Output:** 3

**Explanation:**

* The graph has two possible routes from node 0 to node 3:

  1. Path `0 → 1 → 3`

     + Total cost = `5 + 10 = 15`, which exceeds k (`15 > 10`), so this path is invalid.
  2. Path `0 → 2 → 3`

     + Total cost = `3 + 4 = 7 <= k`, so this path is valid.
     + The minimum edge‐cost along this path is `min(3, 4) = 3`.
* There are no other valid paths. Hence, the maximum among all valid path‐scores is 3.

**Example 2:**

**Input:** edges = [[0,1,7],[1,4,5],[0,2,6],[2,3,6],[3,4,2],[2,4,6]], online = [true,true,true,false,true], k = 12

**Output:** 6

**Explanation:**

* Node 3 is offline, so any path passing through 3 is invalid.
* Consider the remaining routes from 0 to 4:

  1. Path `0 → 1 → 4`

     + Total cost = `7 + 5 = 12 <= k`, so this path is valid.
     + The minimum edge‐cost along this path is `min(7, 5) = 5`.
  2. Path `0 → 2 → 3 → 4`

     + Node 3 is offline, so this path is invalid regardless of cost.
  3. Path `0 → 2 → 4`

     + Total cost = `6 + 6 = 12 <= k`, so this path is valid.
     + The minimum edge‐cost along this path is `min(6, 6) = 6`.
* Among the two valid paths, their scores are 5 and 6. Therefore, the answer is 6.

**Constraints:**

* `n == online.length`
* `2 <= n <= 5 * 104`
* `0 <= m == edges.length <=` `min(105, n * (n - 1) / 2)`
* `edges[i] = [ui, vi, costi]`
* `0 <= ui, vi < n`
* `ui != vi`
* `0 <= costi <= 109`
* `0 <= k <= 5 * 1013`
* `online[i]` is either `true` or `false`, and both `online[0]` and `online[n − 1]` are `true`.
* The given graph is a directed acyclic graph.

---

## Solution & Editorial
# Intuition
To maximize the minimum edge-cost on a path, we observe that the property is monotonic: if a path exists with a minimum edge-cost of at least `X`, then a path also exists for any value less than `X`. This monotonicity allows us to use binary search on the answer. For a fixed threshold `mid`, we need to verify if there exists a path from `0` to `n-1` using only edges with `cost >= mid` such that the total path cost is at most `k` and all intermediate nodes are `online`.

# Approach
1. **Topological Sort**: Since the graph is a Directed Acyclic Graph (DAG), we compute a topological ordering once. This allows us to perform dynamic programming (shortest path) in linear time for any given `mid`.
2. **Binary Search**: The search space for the minimum edge-cost is `[0, max_edge_cost]`. 
3. **Validation (`check` function)**: 
   - Initialize `dist[0] = 0` and `dist[i] = INF` for others.
   - Iterate through nodes in topological order. For each node `u`, if `dist[u]` is reachable, relax its neighbors `v` only if `edge_cost >= mid` and `v` is `online` (or `v` is the destination).
   - If `dist[n-1] <= k`, the threshold `mid` is feasible.

### Visual Trace (Example 1)
`edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]], k = 10`
- Topological Order: `[0, 1, 2, 3]`
- Try `mid = 3`:
  - `dist[0]=0`
  - `u=0`: `dist[1]=min(inf, 0+5)=5`, `dist[2]=min(inf, 0+3)=3`
  - `u=1`: `dist[3]=min(inf, 5+10)=15`
  - `u=2`: `dist[3]=min(15, 3+4)=7`
  - `dist[3]=7 <= 10` (True)

# Complexity
- Time complexity: $$O(M \log(\max(\text{cost})) + N + M)$$. The topological sort takes $$O(N+M)$$. The binary search performs $$O(\log(\max(\text{cost})))$$ iterations, each running a DP traversal in $$O(N+M)$$.
- Space complexity: $$O(N+M)$$ to store the adjacency list, topological order, and distance array.

# Code
```cpp
class Solution {
public:

    bool check(long long mid, vector<vector<pair<int, int>>> &adj, vector<int> &topo, vector<bool> &online, long long k, int n) {

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == INF) continue;
            if (u != 0 && u != n - 1 && !online[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (w < mid) continue;
                if (v != n - 1 && !online[v]) continue;

                dist[v] = min(dist[v], dist[u] + w);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);

        int mx = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            indegree[v]++;
            mx = max(mx, w);
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        long long low = 0, high = mx;
        int ans = -1;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (check(mid, adj, topo, online, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
```
