# [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `breadth-first-search`, `graph`, `heap-priority-queue`, `shortest-path`, `dijkstra`

---

## Problem Description
You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where `ui` is the source node, `vi` is the target node, and `wi` is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return *the **minimum** time it takes for all the* `n` *nodes to receive the signal*. If it is impossible for all the `n` nodes to receive the signal, return `-1`.

**Example 1:**

```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```

**Example 2:**

```
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
```

**Example 3:**

```
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
```

**Constraints:**

* `1 <= k <= n <= 100`
* `1 <= times.length <= 6000`
* `times[i].length == 3`
* `1 <= ui, vi <= n`
* `ui != vi`
* `0 <= wi <= 100`
* All the pairs `(ui, vi)` are **unique**. (i.e., no multiple edges.)

---

## Solution & Editorial
# Intuition
The problem asks for the minimum time required for a signal to reach all $n$ nodes starting from node $k$. Since edge weights are non-negative, and we can treat this as finding the single-source shortest paths on a directed graph, a queue-based Breadth-First Search (similar to SPFA or Dijkstra without a priority queue) can be used to efficiently propagate the minimum arrival times across the network.

# Approach
1. Build an adjacency list `adj` where each entry stores pairs of `(neighbor_node, weight)` from the given `times` array.
2. Initialize a distance array `dist` of size `n + 1` filled with a large value (`1e9`), setting `dist[k] = 0` since the source node takes $0$ time to reach itself.
3. Use a `queue<pair<int, int>>` to process nodes and their accumulated costs. Push `{k, 0}` into the queue.
4. While the queue is not empty, pop the front element `node` with its current `cost`. Iterate through all its neighbors `adjNode` with edge weight `edW`.
5. If a strictly shorter path is found (`dist[adjNode] > cost + edW`), update `dist[adjNode]` and push the updated pair `{adjNode, cost + edW}` into the queue.
6. After the queue is exhausted, iterate through `dist` from index $1$ to $n$. If any node has a distance of `1e9`, it means it is unreachable, so return `-1`. Otherwise, find the maximum distance among all nodes, which represents the total time required for all nodes to receive the signal.

### Visual Trace (Example 1)
- Input: `times = [[2,1,1],[2,3,1],[3,4,1]]`, `n = 4`, `k = 2`
- Initial: `dist = [INF, 1e9, 0, 1e9, 1e9]`, Queue = `[(2, 0)]`
- Pop `(2, 0)`:
  - Visit neighbor `1` with weight `1`: `dist[1] = 1`, Queue = `[(1, 1)]`
  - Visit neighbor `3` with weight `1`: `dist[3] = 1`, Queue = `[(1, 1), (3, 1)]`
- Pop `(1, 1)`: No unvisited better neighbors.
- Pop `(3, 1)`:
  - Visit neighbor `4` with weight `1`: `dist[4] = 2`, Queue = `[(4, 2)]`
- Pop `(4, 2)`: No neighbors.
- Final `dist` array: `[INF, 1, 0, 1, 2]`. Max element is `2`.

# Complexity
- Time complexity: $$O(V + E)$$ in average graph topologies, where $$V = n$$ is the number of nodes and $$E = 	ext{times.length}$$ is the number of edges. In the worst-case with queue-based expansions, it is bounded by the number of edge relaxations.
- Space complexity: $$O(V + E)$$ to store the adjacency list `adj`, the distance vector `dist`, and the BFS queue.

# Code
```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = 0;
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        queue<pair<int,int>> q;
        q.push({k,0});
        while(!q.empty()){
            int node = q.front().first;
            int cost = q.front().second;

            q.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(dist[adjNode] > cost + edW){
                    dist[adjNode] = cost + edW;
                    q.push({adjNode,cost+edW});
                }
            }
        }

        for(int i = 1;i<=n;i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;

    }
};
```
