# [3970. Shortest Path With At Most K Consecutive Identical Characters](https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/)
**Difficulty:** `Medium` | **Tags:** `string`, `graph`, `heap-priority-queue`, `shortest-path`

---

## Problem Description
You are given an integer `n` representing the number of nodes in a **directed weighted** graph, numbered from 0 to `n - 1`. This is represented by a 2D integer array `edges`, where `edges[i] = [ui, vi, wi]` represents a directed edge from node `ui` to node `vi` with weight `wi`.

You are also given a string `labels` of length `n`, where `labels[i]` is the character assigned to node `i`, and an integer `k`.

Return the **minimum** **total** edge weight of a path from node 0 to node `n - 1` such that the concatenation of the labels of the nodes along the path contains **at most** `k` **consecutive** **identical** characters. If no valid path exists, return -1.

**Example 1:**

**Input:** n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1

**Output:** 3

**Explanation:**

The optimal valid path from node 0 to node 2 is as follows:

* Use `edges[2] = [0, 2, 3]` to reach node 2 with a weight `wi = 3`.

The corresponding concatenation of labels is `"ab"`, which satisfies at most `k = 1` consecutive identical characters. Thus, the answer is 3.

**Example 2:**

**Input:** n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 2

**Output:** 2

**Explanation:**

The optimal valid path from node 0 to node 2 is as follows:

* Use `edges[0] = [0, 1, 1]` to reach node 1 with weight `wi = 1`.
* Use `edges[1] = [1, 2, 1]` to reach node 2 with weight `wi = 1`.

The corresponding concatenation of labels is `"aab"`, which satisfies at most `k = 2` consecutive identical characters. Thus, the answer is 2.

**Example 3:**

**Input:** n = 3, edges = [[0,1,1],[1,2,1]], labels = "aaa", k = 2

**Output:** -1

**Explanation:**

There is no valid path from node 0 to node 2 that satisfies at most `k = 2` consecutive identical characters. Thus, the answer is -1.

**Constraints:**

* `1 <= n == labels.length <= 5 * 104`
* `0 <= edges.length <= 5 * 104`
* `edges[i] == [ui, vi, wi]`
* `0 <= ui, vi <= n - 1`
* `ui != vi`
* `1 <= wi <= 104`
* `labels` consists of lowercase English letters
* `1 <= k <= 50`

---

## Solution & Editorial
# Intuition
The problem asks for the shortest path in a weighted graph with a constraint on the number of consecutive identical characters. Since the constraint depends on the current node's label relative to the previous node's label, we can model this as a shortest path problem on an expanded state space: `(node, consecutive_count)`. Dijkstra's algorithm is suitable here because all edge weights are positive.

# Approach
1. **State Definition**: Define a state as `(u, count)`, where `u` is the current node index and `count` is the number of consecutive identical characters ending at `u`.
2. **Graph Representation**: Build an adjacency list `adj` where each entry stores the neighbor and the edge weight.
3. **Dijkstra's Algorithm**: Use a priority queue to store `(distance, u, count)`. Initialize `dist[0][1] = 0` (starting at node 0 with a count of 1).
4. **Transitions**: For each neighbor `v` of `u`:
   - If `labels[v] == labels[u]`, the new count is `count + 1`.
   - If `labels[v] != labels[u]`, the new count resets to `1`.
   - Only proceed if the new count is `<= k`.
5. **Result**: The answer is the minimum value in `dist[n-1][1...k]`.

### Visual Trace (Example 1: n=3, labels="aab", k=1)
| Step | PQ (d, u, count) | dist[u][count] | Action |
| :--- | :--- | :--- | :--- |
| 0 | {(0, 0, 1)} | dist[0][1]=0 | Pop (0,0,1) |
| 1 | {(1, 1, 2), (3, 2, 1)} | dist[1][2]=1, dist[2][1]=3 | Process edges from 0 |
| 2 | {(3, 2, 1)} | - | Pop (1,1,2) (newcur 2 > k) |
| 3 | {} | - | Pop (3,2,1) (Target reached) |

# Complexity
- Time complexity: $$O(E \cdot k \cdot \log(N \cdot k))$$, where $$E$$ is the number of edges, $$N$$ is the number of nodes, and $$k$$ is the constraint. Each edge is processed for each possible consecutive count.
- Space complexity: $$O(N \cdot k)$$ to store the `dist` table and the priority queue states.

# Code
```cpp
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto e = pq.top(); pq.pop();
            long long d = e[0];
            int u = e[1];
            int cur = e[2];

            if (d != dist[u][cur]) continue;

            for (auto &vec : adj[u]) {
                int v = vec.first, w = vec.second;
                int newcur = (labels[v] == labels[u]) ? cur + 1 : 1;
                if (newcur > k) continue;

                if (dist[v][newcur] > d + w) {
                    dist[v][newcur] = d + w;
                    pq.push({dist[v][newcur], v, newcur});
                }
            }
        }

        long long ans = LLONG_MAX;
        for (int i = 1; i <= k; i++) ans = min(ans, dist[n - 1][i]);
        return ans == LLONG_MAX ? -1 : ans;
    }
};
```
