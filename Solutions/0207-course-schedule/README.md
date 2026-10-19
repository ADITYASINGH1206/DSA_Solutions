# [207. Course Schedule](https://leetcode.com/problems/course-schedule/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `breadth-first-search`, `graph`, `topological-sort`, `directed-acyclic-graph`

---

## Problem Description
There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

* For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```

**Constraints:**

* `1 <= numCourses <= 2000`
* `0 <= prerequisites.length <= 5000`
* `prerequisites[i].length == 2`
* `0 <= ai, bi < numCourses`
* All the pairs prerequisites[i] are **unique**.

---

## Solution & Editorial
# Intuition
The problem asks whether we can finish all courses given their prerequisites, which is equivalent to detecting if a directed graph contains a cycle. If the graph is a Directed Acyclic Graph (DAG), a valid topological ordering exists, meaning we can complete all courses. We can solve this efficiently using Kahn's algorithm via Breadth-First Search (BFS) and in-degree tracking.

# Approach
1. Build the adjacency list `adj` from the `prerequisites` array, where a directed edge from `pre[1]` to `pre[0]` indicates that course `pre[1]` must be taken before course `pre[0]`.
2. Compute the `indegree` array for each node by counting incoming edges. 
3. Initialize a queue `q` and push all courses with an `indegree` of `0` since they have no prerequisites and can be taken immediately.
4. Process nodes from the queue one by one, adding them to the topological order vector `topo`. For each neighbor `it` of the current `node`, decrement its `indegree`. If a neighbor's `indegree` drops to `0`, push it onto the queue.
5. Finally, compare the size of `topo` with `numCourses`. If they are equal, no cycles exist, and we return `true`; otherwise, return `false`.

### Visual Walkthrough (Example 1)
- Input: `numCourses = 2`, `prerequisites = [[1,0]]`
- Adjacency List: `0 -> [1]`, `1 -> []`
- In-degrees: `indegree[0] = 0`, `indegree[1] = 1`
- Initial Queue `q`: `[0]` (since `indegree[0] == 0`)
- Iteration 1:
  - Pop `node = 0`, `topo = [0]`
  - For neighbor `1`: decrement `indegree[1]` to `0`, push `1` to `q`.
- Iteration 2:
  - Pop `node = 1`, `topo = [0, 1]`
- Queue is empty. `topo.size() == 2 == numCourses`, return `true`.

# Complexity
- Time complexity: $$O(V + E)$$ where $$V$$ is `numCourses` and $$E$$ is the number of `prerequisites`. Building the graph, computing in-degrees, and traversing each node and edge takes linear time.
- Space complexity: $$O(V + E)$$ to store the adjacency list `adj`, the `indegree` vector, the queue `q`, and the `topo` vector.

# Code
```cpp
// class Solution {
// public:
//     bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
//         vis[node] = 1;
//         pathVis[node] = 1; 

//         for (auto it : adj[node]) {
//             if (!vis[it]) {
//                 if (dfs(it, adj, vis, pathVis)) return true;
//             }
//             else if (pathVis[it] == 1) {
//                 return true;
//             }
//         }

//         pathVis[node] = 0;
//         return false;
//     }

//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);
//         for (auto& pre : prerequisites) {
//             adj[pre[1]].push_back(pre[0]);
//         }

//         vector<int> vis(numCourses, 0);
//         vector<int> pathVis(numCourses, 0);

//         for (int i = 0; i < numCourses; i++) {
//             if (!vis[i]) {
//                 if (dfs(i, adj, vis, pathVis) == true) {
//                     return false;
//                 }
//             }
//         }

//         return true; 
//     }
// };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> indegree(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }

        }
        if(topo.size() == numCourses) return true;
        return false;
    }
};
```
