# [547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `breadth-first-search`, `union-find`, `graph`

---

## Problem Description
There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A **province** is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return *the total number of **provinces***.

**Example 1:**

```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
```

**Example 2:**

```
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
```

**Constraints:**

* `1 <= n <= 200`
* `n == isConnected.length`
* `n == isConnected[i].length`
* `isConnected[i][j]` is `1` or `0`.
* `isConnected[i][i] == 1`
* `isConnected[i][j] == isConnected[j][i]`

---

## Solution & Editorial
# Intuition
This problem asks us to find the number of connected components in an undirected graph representing cities and their direct connections. We can model the cities as nodes and the direct connections as edges. By transforming the given adjacency matrix into an adjacency list, we can perform Depth First Search (DFS) to traverse each connected component entirely.

# Approach
1. Initialize `n` as the number of cities from `isConnected.size()`, a `vis` vector of size `n` initialized to 0 to keep track of visited cities, and an array of vectors `adj` of size `n` to store the adjacency list.
2. Iterate through the `isConnected` matrix to populate the adjacency list: for each pair `(i, j)` where `i != j` and `isConnected[i][j] == 1`, add an undirected edge between `i` and `j`.
3. Initialize `ans` counter to 0 for counting the provinces. Iterate through each city `i` from `0` to `n - 1`.
4. If city `i` has not been visited (`!vis[i]`), increment `ans` and initiate a DFS traversal starting from `i` to mark all reachable connected cities as visited.
5. In the `dfs` function, mark the current node as visited (`vis[node] = 1`) and recursively visit all its unvisited neighbors.

### Visual Trace Walkthrough (Example 1)
`isConnected = [[1,1,0],[1,1,0],[0,0,1]]`, `n = 3`
- Adjacency list construction:
  - `adj[0] = [1], adj[1] = [0], adj[2] = []`
- Loop `i = 0`:
  - `vis[0]` is 0. `ans` becomes 1. Call `dfs(0)`.
  - `vis[0] = 1`. Neighbor `1` is unvisited. Call `dfs(1)`.
  - `vis[1] = 1`. Neighbor `0` is visited. Return.
- Loop `i = 1`:
  - `vis[1]` is 1. Skip.
- Loop `i = 2`:
  - `vis[2]` is 0. `ans` becomes 2. Call `dfs(2)`.
  - `vis[2] = 1`. No unvisited neighbors. Return.
- Final Answer: `2`.

# Complexity
- Time complexity: $$O(n^2 + V + E)$$ where $$n$$ is the number of cities. Constructing the adjacency list takes $$O(n^2)$$ time as we scan the entire `n x n` matrix. The DFS traversal visits each vertex once ($$O(V)$$ where $$V = n$$) and each edge twice ($$O(E)$$ where $$E \	o n^2$$). Thus, total time is bounded by $$O(n^2)$$.
- Space complexity: $$O(n^2)$$ auxiliary space. The adjacency list stores up to $$O(n^2)$$ edges in the worst case (fully connected graph), the `vis` vector takes $$O(n)$$ space, and the recursive call stack for DFS can go up to $$O(n)$$ depth in the worst-case linear graph.

# Code
```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }

        return ans;

    }

    void dfs(int node,vector<int> adj[],vector<int>& vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
};
```
