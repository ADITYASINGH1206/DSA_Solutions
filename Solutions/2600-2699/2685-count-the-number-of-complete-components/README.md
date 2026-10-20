# [2685. Count the Number of Complete Components](https://leetcode.com/problems/count-the-number-of-complete-components/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `breadth-first-search`, `union-find`, `graph`

---

## Problem Description
You are given an integer `n`. There is an **undirected** graph with `n` vertices, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an **undirected** edge connecting vertices `ai` and `bi`.

Return *the number of **complete connected components** of the graph*.

A **connected component** is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be **complete** if there exists an edge between every pair of its vertices.

**Example 1:**

```
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.
```

**Example 2:**

```
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
```

**Constraints:**

* `1 <= n <= 50`
* `0 <= edges.length <= n * (n - 1) / 2`
* `edges[i].length == 2`
* `0 <= ai, bi <= n - 1`
* `ai != bi`
* There are no repeated edges.

---

## Solution & Editorial
# Intuition
A connected component is "complete" if every pair of distinct vertices within it is connected by an edge. In a component with $k$ vertices, the number of edges must be exactly $\frac{k(k-1)}{2}$. We can identify all connected components using Breadth-First Search (BFS) and verify this property for each.

# Approach
1. Build an adjacency list `adj` from the given `edges` to represent the undirected graph.
2. Use a boolean array `vis` to keep track of visited vertices. Iterate through all vertices from $0$ to $n-1$.
3. For each unvisited vertex, initiate a BFS to traverse the entire connected component:
   - Count the number of vertices (`nodes`) in the component.
   - Sum the degrees of all vertices in the component (`edgeCount`). Since each edge is counted twice (once for each endpoint), the actual number of edges is `edgeCount / 2`.
4. After the BFS completes, check if the calculated `edgeCount` equals $\frac{nodes \times (nodes - 1)}{2}$. If it does, increment the answer `ans`.

### Visual Trace (Example 1: n=6, edges=[[0,1],[0,2],[1,2],[3,4]])
| Step | Component Nodes | Total Nodes | Total Degree Sum | Edges (Sum/2) | Complete? |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | {0, 1, 2} | 3 | 6 | 3 | Yes (3 == 3*2/2) |
| 2 | {3, 4} | 2 | 2 | 1 | Yes (1 == 2*1/2) |
| 3 | {5} | 1 | 0 | 0 | Yes (0 == 1*0/2) |

# Complexity
- Time complexity: $$O(V + E)$$, where $$V$$ is the number of vertices and $$E$$ is the number of edges. We visit each vertex and each edge exactly once during the BFS traversal.
- Space complexity: $$O(V + E)$$ to store the adjacency list and the visited array.

# Code
```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = true;

            int nodes = 0;
            int edgeCount = 0; 
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                nodes++;
                edgeCount += adj[u].size();

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            edgeCount /= 2;

            if (edgeCount == nodes * (nodes - 1) / 2)
                ans++;
        }

        return ans;
    }
};
```
