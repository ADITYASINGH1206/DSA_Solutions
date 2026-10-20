# [2492. Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `breadth-first-search`, `union-find`, `graph`

---

## Problem Description
You are given a positive integer `n` representing `n` cities numbered from `1` to `n`. You are also given a **2D** array `roads` where `roads[i] = [ai, bi, distancei]` indicates that there is a **bidirectional** road between cities `ai` and `bi` with a distance equal to `distancei`. The cities graph is not necessarily connected.

The **score** of a path between two cities is defined as the **minimum** distance of a road in this path.

Return the **minimum** possible score of a path between cities 1 and `n`.

**Note**:

* A path is a sequence of roads between two cities.
* It is allowed for a path to contain the same road **multiple** times, and you can visit cities 1 and `n` multiple times along the path.
* The test cases are generated such that there is **at least** one path between 1 and `n`.

**Example 1:**

```
Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.
```

**Example 2:**

```
Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
```

**Constraints:**

* `2 <= n <= 105`
* `1 <= roads.length <= 105`
* `roads[i].length == 3`
* `1 <= ai, bi <= n`
* `ai != bi`
* `1 <= distancei <= 104`
* There are no repeated edges.
* There is at least one path between `1` and `n`.

---

## Solution & Editorial
# Intuition
Since we can traverse any road multiple times and visit cities multiple times, any city reachable from city 1 belongs to the same connected component as city 1 and city n. The problem effectively asks for the minimum edge weight present in the entire connected component containing both 1 and n.

# Approach
1. Represent the graph using an adjacency list `adj` where each entry stores a pair `{neighbor, weight}`.
2. Use Breadth-First Search (BFS) starting from node 1 to traverse all reachable nodes.
3. Maintain a `vis` array to keep track of visited nodes to avoid redundant processing.
4. During the traversal, for every edge encountered (even if the neighbor is already visited), update the global minimum `ans` with the edge weight `wt`.
5. Since the problem guarantees a path exists between 1 and n, the BFS will visit all nodes in the component containing 1, ensuring we check every edge connected to that component.

### Visual Trace (Example 1: n=4, roads=[[1,2,9],[2,3,6],[2,4,5],[1,4,7]])
| Step | Queue | Visited | Current Node | Edge (u, v, w) | ans |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | [1] | {1} | - | - | INF |
| 1 | [2, 4] | {1, 2, 4} | 1 | (1,2,9), (1,4,7) | 7 |
| 2 | [4, 3] | {1, 2, 4, 3} | 2 | (2,1,9), (2,3,6), (2,4,5) | 5 |
| 3 | [3] | {1, 2, 4, 3} | 4 | (4,2,5), (4,1,7) | 5 |
| 4 | [] | {1, 2, 4, 3} | 3 | (3,2,6) | 5 |

# Complexity
- Time complexity: $$O(N + E)$$, where $$N$$ is the number of cities and $$E$$ is the number of roads. We visit each node and traverse each edge exactly once.
- Space complexity: $$O(N + E)$$ to store the adjacency list and the visited array.

# Code
```cpp
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n + 1, false);
        queue<int> q;

        q.push(1);
        vis[1] = true;

        int ans = INT_MAX;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto &[edge, wt] : adj[node]){

                ans = min(ans, wt);

                if(!vis[edge]){
                    vis[edge] = true;
                    q.push(edge);
                }
            }
        }

        return ans;
    }
};
```
