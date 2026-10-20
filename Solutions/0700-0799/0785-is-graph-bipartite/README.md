# [785. Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `breadth-first-search`, `union-find`, `graph`, `graph-coloring`, `bipartite-graph`

---

## Problem Description
There is an **undirected** graph with `n` nodes, where each node is numbered between `0` and `n - 1`. You are given a 2D array `graph`, where `graph[u]` is an array of nodes that node `u` is adjacent to. More formally, for each `v` in `graph[u]`, there is an undirected edge between node `u` and node `v`. The graph has the following properties:

* There are no self-edges (`graph[u]` does not contain `u`).
* There are no parallel edges (`graph[u]` does not contain duplicate values).
* If `v` is in `graph[u]`, then `u` is in `graph[v]` (the graph is undirected).
* The graph may not be connected, meaning there may be two nodes `u` and `v` such that there is no path between them.

A graph is **bipartite** if the nodes can be partitioned into two independent sets `A` and `B` such that **every** edge in the graph connects a node in set `A` and a node in set `B`.

Return `true` *if and only if it is **bipartite***.

**Example 1:**

```
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
```

**Example 2:**

```
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
```

**Constraints:**

* `graph.length == n`
* `1 <= n <= 100`
* `0 <= graph[u].length < n`
* `0 <= graph[u][i] <= n - 1`
* `graph[u]` does not contain `u`.
* All the values of `graph[u]` are **unique**.
* If `graph[u]` contains `v`, then `graph[v]` contains `u`.

---

## Solution & Editorial
# Intuition
A graph is bipartite if and only if it can be 2-colored such that no two adjacent nodes share the same color. We can traverse the graph using Depth-First Search (DFS) and assign alternating colors ($0$ and $1$) to adjacent nodes. If we encounter an already visited neighbor with the same color as the current node, a conflict arises and the graph is not bipartite.

# Approach
1. Initialize a `color` array of size `n` with `-1` to represent unvisited nodes.
2. Iterate through all nodes from `0` to `n - 1` to handle potentially disconnected components.
3. For each unvisited node (`color[i] == -1`), initiate a DFS traversal starting with color `0`.
4. In the `dfs` function, color the current `node` with `col` and recursively inspect all its neighbors `it` in `graph[node]`:
   - If neighbor `it` is unvisited (`color[it] == -1`), recursively call `dfs` with the inverted color `!col`. If the recursive call returns `false`, propagate `false` upward.
   - If neighbor `it` is already colored with the same color (`color[it] == col`), a bipartition violation occurs, so return `false`.
5. If all components are successfully colored without conflicts, return `true`.

### Visual Trace Walkthrough (Example 1: `graph = [[1,2,3],[0,2],[0,1,3],[0,2]]`)
- Start DFS at node `0` with color `0`. `color[0] = 0`.
- Visit neighbor `1` of node `0`, color with `1`. `color[1] = 1`.
- Visit neighbor `0` of node `1` (already colored `0`, valid). Visit neighbor `2` of node `1`, color with `0`. `color[2] = 0`.
- Visit neighbor `0` of node `2` (already colored `0`), neighbor `1` (already colored `1`), neighbor `3` of node `2`, color with `1`. `color[3] = 1`.
- Now check neighbors of node `3`: node `0` has color `0` (valid), node `2` has color `0` (valid).
- Wait, let's look at node `0`'s adjacency list `[1, 2, 3]`: node `3` is adjacent to node `0` and has color `1`, while node `0` has color `0`. Edge `(0, 3)` connects colors `0` and `1` (valid).
- Let's check node `2`'s adjacency list `[0, 1, 3]`: node `3` has color `1`, node `2` has color `0`. Edge `(2, 3)` connects colors `0` and `1` (valid).
- Wait, let's check edge `(1, 2)`: node `1` has color `1`, node `2` has color `0` (valid).
- Let's check edge `(2, 0)`: node `2` has color `0`, node `0` has color `0` -> Conflict! `color[0] == color[2]`. Returns `false`.

# Complexity
- Time complexity: $$O(V + E)$$ — Every vertex is visited once and every edge is traversed twice (once from each endpoint), where $$V$$ is the number of nodes (`n`) and $$E$$ is the number of edges.
- Space complexity: $$O(V)$$ — The recursion stack for DFS and the `color` vector both take $$O(V)$$ auxiliary space in the worst case.

# Code
```cpp
class Solution {
public:
    bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& graph){
        color[node] = col;

        for(auto it: graph[node]){
            if(color[it] == -1){
                if(dfs(it,!col,color,graph) == false) return false;
            }
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int> color(n,-1);
        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(dfs(i,0,color,graph) == false) return false;
            }
        }
        return true;

    }
};
```
