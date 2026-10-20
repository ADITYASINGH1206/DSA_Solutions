# [3559. Number of Ways to Assign Edge Weights II](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `dynamic-programming`, `bit-manipulation`, `tree`, `depth-first-search`

---

## Problem Description
There is an undirected tree with `n` nodes labeled from 1 to `n`, rooted at node 1. The tree is represented by a 2D integer array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates that there is an edge between nodes `ui` and `vi`.

Initially, all edges have a weight of 0. You must assign each edge a weight of either **1** or **2**.

The **cost** of a path between any two nodes `u` and `v` is the total weight of all edges in the path connecting them.

You are given a 2D integer array `queries`. For each `queries[i] = [ui, vi]`, determine the number of ways to assign weights to edges **in the path** such that the cost of the path between `ui` and `vi` is **odd**.

Return an array `answer`, where `answer[i]` is the number of valid assignments for `queries[i]`.

Since the answer may be large, apply **modulo** `109 + 7` to each `answer[i]`.

**Note:** For each query, disregard all edges **not** in the path between node `ui` and `vi`.

**Example 1:**

**Input:** edges = [[1,2]], queries = [[1,1],[1,2]]

**Output:** [0,1]

**Explanation:**

* Query `[1,1]`: The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
* Query `[1,2]`: The path from Node 1 to Node 2 consists of one edge (`1 → 2`). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.

**Example 2:**

**Input:** edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]

**Output:** [2,1,4]

**Explanation:**

* Query `[1,4]`: The path from Node 1 to Node 4 consists of two edges (`1 → 3` and `3 → 4`). Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
* Query `[3,4]`: The path from Node 3 to Node 4 consists of one edge (`3 → 4`). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
* Query `[2,5]`: The path from Node 2 to Node 5 consists of three edges (`2 → 1, 1 → 3`, and `3 → 5`). Assigning (1,2,2), (2,1,2), (2,2,1), or (1,1,1) makes the cost odd. Thus, the number of valid assignments is 4.

**Constraints:**

* `2 <= n <= 105`
* `edges.length == n - 1`
* `edges[i] == [ui, vi]`
* `1 <= queries.length <= 105`
* `queries[i] == [ui, vi]`
* `1 <= ui, vi <= n`
* `edges` represents a valid tree.

---

## Solution & Editorial
# Intuition
To make the total cost of a path with $d$ edges odd, we must choose an odd number of edges with weight 1. If we have $d$ edges, each can be weight 1 or 2. This is equivalent to choosing a subset of edges to have weight 1 such that the count of these edges is odd. By binomial expansion, the number of ways to choose an odd number of items from $d$ items is $2^{d-1}$ for $d > 0$, and $0$ for $d=0$.

# Approach
1. **Tree Preprocessing**: Build an adjacency list from the `edges`. Use DFS to compute the `depth` of each node and build a binary lifting table `up[node][j]` to facilitate $O(\log N)$ Lowest Common Ancestor (LCA) queries.
2. **Distance Calculation**: For any query $(u, v)$, the number of edges $d$ in the path is given by $depth[u] + depth[v] - 2 \times depth[LCA(u, v)]$.
3. **Combinatorial Logic**: If $d=0$ (i.e., $u=v$), the cost is 0 (even), so return 0. If $d > 0$, the number of ways to get an odd sum is $2^{d-1} \pmod{10^9+7}$.

### Visual Trace (Example 2: Query [1, 4])
- Path: 1 -> 3 -> 4. Number of edges $d = 2$.
- Formula: $2^{2-1} = 2^1 = 2$.
- Valid assignments: (1, 2) and (2, 1). Both sum to 3 (odd).

# Complexity
- Time complexity: $$O((N + Q) \log N)$$. Building the LCA table takes $$O(N \log N)$$, and each of the $$Q$$ queries takes $$O(\log N)$$ to find the LCA and calculate the distance.
- Space complexity: $$O(N \log N)$$ to store the binary lifting table `up` of size $N \times 20$.

# Code
```cpp
class Solution {
public:
    vector<int>per,depth;
    vector<vector<int>>up;
    int LOG=20;
    const int MOD=1e9+7;
    int power(long long a,long long b){
        long long ans=1;
        a%=MOD;
        while(b>0){
            if(b&1)ans=(ans*a)%MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return (int)ans;
    }

    int countWays(int d){
        if(d==0)return 0;
        return power(2,d-1);
    }

    void dfs(int node,int p,vector<vector<int>>&adj){
        per[node]=p;
        up[node][0]=p;
        for(int j=1;j<LOG;j++){
            if(up[node][j-1]!=-1)up[node][j]=up[up[node][j-1]][j-1];
        }
        for(auto&it:adj[node]){
            if(it!=p){
                depth[it]=depth[node]+1;
                dfs(it,node,adj);
            }
        }
    }

    int lca(int u,int v){
        if(depth[u]<depth[v])swap(u,v);
        int diff=depth[u]-depth[v];
        for(int j=0;j<LOG;j++){
            if(diff&(1<<j))
                u=up[u][j];
        }
        if(u==v)
            return u;
        for(int j=LOG-1;j>=0;j--){
            if(up[u][j]!=up[v][j]){
                u=up[u][j];
                v=up[v][j];
            }
        }
        return up[u][0];
    }

    int dist(int u,int v){
        int L=lca(u,v);
        int d=depth[u]+depth[v]-2*depth[L];
        return countWays(d);
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+2;
        vector<vector<int>>adj(n);
        for(auto&edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        per.resize(n,-1);
        depth.resize(n,0);
        up.resize(n,vector<int>(LOG,-1));
        dfs(1,-1,adj);
        vector<int>ans;
        for(auto&q:queries){
            int u=q[0],v=q[1];
            ans.push_back(dist(u,v));
        }
        return ans;
    }
};
```
