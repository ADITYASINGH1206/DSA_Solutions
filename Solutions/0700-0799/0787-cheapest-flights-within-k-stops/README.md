# [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
**Difficulty:** `Medium` | **Tags:** `dynamic-programming`, `depth-first-search`, `breadth-first-search`, `graph`, `heap-priority-queue`, `shortest-path`

---

## Problem Description
There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [fromi, toi, pricei]` indicates that there is a flight from city `fromi` to city `toi` with cost `pricei`.

You are also given three integers `src`, `dst`, and `k`, return ***the cheapest price** from* `src` *to* `dst` *with at most* `k` *stops.* If there is no such route, return`-1`.

**Example 1:**

```
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
```

**Example 2:**

```
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
```

**Example 3:**

```
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
```

**Constraints:**

* `2 <= n <= 100`
* `0 <= flights.length <= (n * (n - 1) / 2)`
* `flights[i].length == 3`
* `0 <= fromi, toi < n`
* `fromi != toi`
* `1 <= pricei <= 104`
* There will not be any multiple flights between two cities.
* `0 <= src, dst, k < n`
* `src != dst`

---

## Solution & Editorial
# Intuition
This problem asks for the cheapest path between a source and destination city with a strict constraint on the number of intermediate stops. Since every edge has a non-negative cost and edge weights are traversed level by level according to the number of stops, a Breadth-First Search (BFS) combined with cost pruning is exceptionally well-suited. By storing the current number of stops along with the node and accumulated cost, we can efficiently explore valid paths up to $k$ stops.

# Approach
1. Build an adjacency list `adj` from the given `flights` where each entry stores pairs of `(neighbor, price)`.
2. Initialize a BFS queue `q` holding tuples of `(stops, (node, cost))`. Initialize a distance vector `dist` of size `n` with a large sentinel value (`1e9`), setting `dist[src] = 0`.
3. Push the starting state into the queue: `{0, {src, 0}}` representing 0 stops, starting at `src` with 0 cost.
4. Process the queue level-by-level:
   - Pop the front element containing `stops`, `node`, and `cost`.
   - If `stops > k`, skip further exploration along this path.
   - Otherwise, iterate over all outgoing neighbors `adjNode` with edge weight `edW`.
   - If the new accumulated cost `cost + edW` is strictly less than `dist[adjNode]`, update `dist[adjNode]` and push the new state `{stops + 1, {adjNode, cost + edW}}` into the queue.
5. After the queue is exhausted, check if `dist[dst]` is still `1e9`. If so, return `-1`; otherwise, return `dist[dst]`.

### Visual Walkthrough (Example 1)
`n = 4`, `src = 0`, `dst = 3`, `k = 1`, `flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]`

| Queue State (stops, node, cost) | Action / Transition | Distance Vector (`dist`) |
| :--- | :--- | :--- |
| Initial | Push `{0, {0, 0}}` | `[0, 1e9, 1e9, 1e9]` |
| Pop `{0, {0, 0}}` | Visit neighbor `1` with cost `100` (`stops = 0 <= 1`) | `[0, 100, 1e9, 1e9]`, Push `{1, {1, 100}}` |
| Pop `{1, {1, 100}}` | Visit neighbor `2` (cost `100`) & neighbor `3` (cost `600`) | `[0, 100, 200, 700]`, Push `{2, {2, 200}}`, `{2, {3, 700}}` |
| Pop `{2, {2, 200}}` | `stops = 2 > k (1)`, continue/skip | `[0, 100, 200, 700]` |
| Pop `{2, {3, 700}}` | `stops = 2 > k (1)`, continue/skip | `[0, 100, 200, 700]` |

Queue becomes empty. Final `dist[3] = 700`.

# Complexity
- Time complexity: $$O(V + E \cdot K)$$, where $$V$$ is the number of cities (`n`), $$E$$ is the number of flights, and $$K$$ is the maximum number of stops allowed. In the worst case, each node can be pushed into the queue multiple times corresponding to different stop counts up to $$K$$.
- Space complexity: $$O(V + E)$$ to store the adjacency list graph representation, the distance array, and the BFS queue.

# Code
```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        q.push({0, {src, 0}});
        dist[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edW = it.second;

                if(cost + edW < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edW;
                    q.push({stops +1 ,{adjNode, cost+edW}});
                }
            }
        }

        if (dist[dst] == 1e9)return -1;
        return dist[dst];
    }
};
```
