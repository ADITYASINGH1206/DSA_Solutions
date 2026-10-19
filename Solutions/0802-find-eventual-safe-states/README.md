# [802. Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `breadth-first-search`, `graph`, `topological-sort`, `kosarajus-algorithm`, `tarjans-scc-algorithm`

---

## Problem Description
There is a directed graph of `n` nodes with each node labeled from `0` to `n - 1`. The graph is represented by a **0-indexed** 2D integer array `graph` where `graph[i]` is an integer array of nodes adjacent to node `i`, meaning there is an edge from node `i` to each node in `graph[i]`.

A node is a **terminal node** if there are no outgoing edges. A node is a **safe node** if every possible path starting from that node leads to a **terminal node** (or another safe node).

Return *an array containing all the **safe nodes** of the graph*. The answer should be sorted in **ascending** order.

**Example 1:**

```
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
```

**Example 2:**

```
Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
```

**Constraints:**

* `n == graph.length`
* `1 <= n <= 104`
* `0 <= graph[i].length <= n`
* `0 <= graph[i][j] <= n - 1`
* `graph[i]` is sorted in a strictly increasing order.
* The graph may contain self-loops.
* The number of edges in the graph will be in the range `[1, 4 * 104]`.

---

## Solution & Editorial
# Intuition
A node is a safe node if it cannot reach any cycle. By reversing all directed edges in the graph, terminal nodes (nodes with zero outgoing edges in the original graph) become sources (nodes with zero incoming edges). We can then apply Kahn's Algorithm for Topological Sort on the reversed graph to process nodes layer by layer from terminals backward.

# Approach
1. Initialize `n` as the number of nodes in `graph`, an array of vectors `adjRev` to represent the reversed graph, an `indegree` array of size `n` initialized to zero, and a queue `q` for topological sorting.
2. Iterate through every node `i` and its neighbors `it` in `graph`. For each original edge `i -> it`, add a reversed edge `it -> i` to `adjRev[it]` and increment `indegree[i]` to count the original outgoing degree.
3. Push all nodes with `indegree[i] == 0` (which correspond to terminal nodes in the original graph) into the queue `q`.
4. While `q` is not empty, pop the front node, add it to the `ans` vector, and iterate through all its neighbors `it` in `adjRev`. Decrement `indegree[it]` for each neighbor, and if `indegree[it]` drops to zero, push `it` into `q`.
5. Finally, sort the `ans` vector in ascending order and return it.

### Visual Trace (Example 1)
`graph = [[1,2],[2,3],[5],[0],[5],[],[]]`
- **Reversed Edges & Indegrees**: Node 5 and 6 have original out-degree 0 (indegree 0 in reversed graph). Queue starts with `[5, 6]`.
- **Pop 5**: Decrements indegree of nodes connected to 5. Safe nodes discovered.
- **Pop 6**: Decrements indegree of nodes connected to 6.
- **Result**: Nodes that successfully reach zero indegree are processed and collected into `ans`. Sorting yields `[2, 4, 5, 6]`.

# Complexity
- Time complexity: $$O(V + E \log V)$$ — Reversing the graph and running Kahn's algorithm takes $$O(V + E)$$ time, where $$V$$ is the number of nodes and $$E$$ is the number of edges. Sorting the final answer array of size at most $$V$$ takes $$O(V \log V)$$.
- Space complexity: $$O(V + E)$$ — Storing the reversed adjacency list `adjRev`, the `indegree` array, and the queue requires linear space proportional to the number of nodes and edges.

# Code
```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> ans;
        vector<int> indegree(n,0);
        queue<int> q;

        for(int i =0;i<n;i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }


        for(int i =0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
```
