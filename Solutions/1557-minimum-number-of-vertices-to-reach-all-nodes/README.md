# [1557. Minimum Number of Vertices to Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/)
**Difficulty:** `Medium` | **Tags:** `graph`, `directed-acyclic-graph`

---

## Problem Description
Given a**directed acyclic graph**, with `n` vertices numbered from `0` to `n-1`, and an array `edges` where `edges[i] = [fromi, toi]` represents a directed edge from node `fromi` to node `toi`.

Find *the smallest set of vertices from which all nodes in the graph are reachable*. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.

**Example 1:**

```
Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
```

**Example 2:**

```
Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
Output: [0,2,3]
Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.
```

**Constraints:**

* `2 <= n <= 10^5`
* `1 <= edges.length <= min(10^5, n * (n - 1) / 2)`
* `edges[i].length == 2`
* `0 <= fromi, toi < n`
* All pairs `(fromi, toi)` are distinct.

---

## Solution & Editorial
# Intuition
In a Directed Acyclic Graph (DAG), any node that has an incoming edge (in-degree > 0) can be reached from some other node. Therefore, the only nodes that *must* be included in our starting set are those with an in-degree of 0, as they cannot be reached by any other node in the graph.

# Approach
1. Initialize a boolean array (or integer vector) `vis` of size `n` to keep track of nodes that have at least one incoming edge.
2. Iterate through the `edges` list. For every edge `[from, to]`, mark `vis[to]` as 1, indicating that node `to` has an incoming edge.
3. After processing all edges, iterate through the range `[0, n-1]`. Any node `i` where `vis[i]` remains 0 has no incoming edges and must be part of the result set.
4. Collect all such nodes into the `ans` vector and return it.

### Visual Trace (Example 1: n=6, edges=[[0,1],[0,2],[2,5],[3,4],[4,2]])
| Node | 0 | 1 | 2 | 3 | 4 | 5 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Initial `vis` | 0 | 0 | 0 | 0 | 0 | 0 |
| After [0,1] | 0 | 1 | 0 | 0 | 0 | 0 |
| After [0,2] | 0 | 1 | 1 | 0 | 0 | 0 |
| After [2,5] | 0 | 1 | 1 | 0 | 0 | 1 |
| After [3,4] | 0 | 1 | 1 | 0 | 1 | 1 |
| After [4,2] | 0 | 1 | 1 | 0 | 1 | 1 |

Result: Indices where `vis[i] == 0` are {0, 3}.

# Complexity
- Time complexity: $$O(N + E)$$, where $$N$$ is the number of vertices and $$E$$ is the number of edges. We iterate through all edges once to mark incoming nodes and then iterate through all vertices once to collect the result.
- Space complexity: $$O(N)$$, required for the `vis` vector to store the in-degree status of each vertex.

# Code
```cpp
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> vis(n,0);
        for(int i =0;i<edges.size();i++){
            vis[edges[i][1]] = 1;
        }
        for(int i =0;i<n;i++){
            if(vis[i] == 0) ans.push_back(i);
        }
        return ans;
        
    }   
};
```
