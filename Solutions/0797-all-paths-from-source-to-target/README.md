# [797. All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/)
**Difficulty:** `Medium` | **Tags:** `backtracking`, `depth-first-search`, `breadth-first-search`, `graph`, `directed-acyclic-graph`

---

## Problem Description
Given a directed acyclic graph (**DAG**) of `n` nodes labeled from `0` to `n - 1`, find all possible paths from node `0` to node `n - 1` and return them in **any order**.

The graph is given as follows: `graph[i]` is a list of all nodes you can visit from node `i` (i.e., there is a directed edge from node `i` to node `graph[i][j]`).

**Example 1:**

```
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```

**Example 2:**

```
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
```

**Constraints:**

* `n == graph.length`
* `2 <= n <= 15`
* `0 <= graph[i][j] < n`
* `graph[i][j] != i` (i.e., there will be no self-loops).
* All the elements of `graph[i]` are **unique**.
* The input graph is **guaranteed** to be a **DAG**.

---

## Solution & Editorial
# Intuition
Since the graph is a Directed Acyclic Graph (DAG) with no cycles and vertices explicitly numbered from `0` to `n - 1`, we can use Depth-First Search (DFS) with backtracking to traverse all possible routes from the source node `0` to the target node `n - 1`.

# Approach
1. Initialize a result container `ans` and a temporary `path` vector to keep track of the current traversal sequence.
2. Define a recursive helper function `dfs` taking the graph, the current `node`, `path`, and `ans` references.
3. Push the current `node` into `path`.
4. If the current `node` equals `n - 1`, we have reached our target, so append a copy of `path` to `ans`.
5. Otherwise, iterate through all neighboring nodes `it` in `graph[node]` and recursively call `dfs` for each neighbor.
6. Backtrack by popping the last element from `path` before returning to restore the state for other branches.

### Visual Dry Run (Example 1: graph = [[1,2],[3],[3],[]])
- Start: `dfs(0)` -> `path = [0]`
  - Visit neighbor `1`: `dfs(1)` -> `path = [0, 1]`
    - Visit neighbor `3`: `dfs(3)` -> `path = [0, 1, 3]` (Target reached, `ans` = `[[0, 1, 3]]`)
    - Backtrack `3` -> `path = [0, 1]`
  - Backtrack `1` -> `path = [0]`
  - Visit neighbor `2`: `dfs(2)` -> `path = [0, 2]`
    - Visit neighbor `3`: `dfs(3)` -> `path = [0, 2, 3]` (Target reached, `ans` = `[[0, 1, 3], [0, 2, 3]]`)
    - Backtrack `3` -> `path = [0, 2]`
  - Backtrack `2` -> `path = [0]`
- Final Result: `[[0, 1, 3], [0, 2, 3]]`

# Complexity
- Time complexity: $$O(2^n \cdot n)$$ — In the worst-case scenario (a complete DAG), there can be up to $$2^{n-1}$$ paths from source to target, and copying each path of length up to $$n$$ takes $$O(n)$$ time.
- Space complexity: $$O(n)$$ — The maximum depth of the recursion stack and the auxiliary `path` vector both scale linearly with the number of nodes $$n$$.

# Code
```cpp
class Solution {
public:
    void dfs(vector<vector<int>>& graph,int node,vector<int>& path,vector<vector<int>>& ans){
        int n = graph.size();
        path.push_back(node);
        if(node == n-1) ans.push_back(path);
        else{
            for(auto it: graph[node]){
                dfs(graph,it,path,ans);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph,0,path,ans);
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>> ans;
//         int n = graph.size();
//         queue<vector<int>> q;
//         q.push({0});
//         while(!q.empty()){
//             vector<int> curPath = q.front();
//             int node = curPath.back();
//             q.pop();
//             if(node == n-1){
//                 ans.push_back(curPath);
//             } 
//             for(auto it :graph[node]){
//                 vector<int> newPath = curPath;
//                 newPath.push_back(it);
//                 q.push(newPath);
//             }
//         }
//         return ans;

//     }
// };
```
