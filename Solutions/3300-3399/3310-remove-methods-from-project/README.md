# [3310. Remove Methods From Project](https://leetcode.com/problems/remove-methods-from-project/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `breadth-first-search`, `graph`

---

## Problem Description
You are maintaining a project that has `n` methods numbered from `0` to `n - 1`.

You are given two integers `n` and `k`, and a 2D integer array `invocations`, where `invocations[i] = [ai, bi]` indicates that method `ai` invokes method `bi`.

There is a known bug in method `k`. Method `k`, along with any method invoked by it, either **directly** or **indirectly**, are considered **suspicious** and we aim to remove them.

A group of methods can only be removed if no method **outside** the group invokes any methods **within** it.

Return an array containing all the remaining methods after removing all the **suspicious** methods. You may return the answer in *any order*. If it is not possible to remove **all** the suspicious methods, **none** should be removed.

**Example 1:**

**Input:** n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]

**Output:** [0,1,2,3]

**Explanation:**

Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.

**Example 2:**

**Input:** n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]

**Output:** [3,4]

**Explanation:**

Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

**Example 3:**

**Input:** n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]

**Output:** []

**Explanation:**

All methods are suspicious. We can remove them.

**Constraints:**

* `1 <= n <= 105`
* `0 <= k <= n - 1`
* `0 <= invocations.length <= 2 * 105`
* `invocations[i] == [ai, bi]`
* `0 <= ai, bi <= n - 1`
* `ai != bi`
* `invocations[i] != invocations[j]`

---

## Solution & Editorial
# Intuition
The problem asks us to identify a set of "suspicious" methods starting from method `k` and determine if they can be safely removed. A set of methods is removable if and only if no method outside the set invokes any method inside the set. This is a graph reachability problem where we first identify the suspicious component and then verify if any external node has an edge pointing into this component.

# Approach
1. **Identify Suspicious Nodes**: Use a Breadth-First Search (BFS) starting from `k` to find all nodes reachable from `k`. We mark these nodes as "suspicious" (e.g., `mark[i] = 1`).
2. **Verify Removability**: Iterate through all edges `[u, v]` in the graph. If `u` is not suspicious (`mark[u] != 1`) but `v` is suspicious (`mark[v] == 1`), it means an external node invokes a suspicious method. In this case, removal is impossible.
3. **Construct Result**: If the condition in step 2 is never met, return all nodes `i` where `mark[i] != 1`. Otherwise, return all nodes from `0` to `n-1`.

### Visual Trace (Example 1: n=4, k=1, edges=[[1,2],[0,1],[3,2]])
- **Step 1 (BFS from 1)**: Reachable nodes are {1, 2}. `mark` array becomes `[0, 1, 1, 0]`.
- **Step 2 (Check Edges)**:
  - Edge [1, 2]: 1 is suspicious, 2 is suspicious. (OK)
  - Edge [0, 1]: 0 is NOT suspicious, 1 is suspicious. **Violation found!**
- **Step 3**: Since a violation exists, return all nodes: `[0, 1, 2, 3]`.

# Complexity
- Time complexity: $$O(N + E)$$, where $$N$$ is the number of methods and $$E$$ is the number of invocations. We traverse the graph once to mark nodes and once to check all edges.
- Space complexity: $$O(N + E)$$ to store the adjacency list and the `mark` array.

# Code
```cpp
class Solution {
public:
    bool outsideConnection = false;
    vector<int> mark;

    void bfs(int color, unordered_map<int, vector<int>>& graph, int src){
        queue<int> q;
        q.push(src);
        mark[src] = color;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(!graph.count(node)) continue;

            for(int nxt : graph[node]){
                if(mark[nxt] == 1 && color == 2){
                    outsideConnection = true;
                    return;
                }

                if(mark[nxt] != color){
                    mark[nxt] = color;
                    q.push(nxt);
                }
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        mark.assign(n, 0);

        for(auto &e : edges)
            graph[e[0]].push_back(e[1]);

        bfs(1, graph, k);

        for(int i = 0; i < n; i++){
            if(i == k || mark[i] == 1) continue;
            bfs(2, graph, i);
        }

        vector<int> res;

        for(int i = 0; i < n; i++){
            if(!outsideConnection && mark[i] == 1) continue;
            res.push_back(i);
        }

        return res;
    }
};
```
