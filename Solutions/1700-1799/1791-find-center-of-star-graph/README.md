# [1791. Find Center of Star Graph](https://leetcode.com/problems/find-center-of-star-graph/)
**Difficulty:** `Easy` | **Tags:** `graph`

---

## Problem Description
There is an undirected **star** graph consisting of `n` nodes labeled from `1` to `n`. A star graph is a graph where there is one **center** node and **exactly** `n - 1` edges that connect the center node with every other node.

You are given a 2D integer array `edges` where each `edges[i] = [ui, vi]` indicates that there is an edge between the nodes `ui` and `vi`. Return the center of the given star graph.

**Example 1:**

```
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
```

**Example 2:**

```
Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
```

**Constraints:**

* `3 <= n <= 105`
* `edges.length == n - 1`
* `edges[i].length == 2`
* `1 <= ui, vi <= n`
* `ui != vi`
* The given `edges` represent a valid star graph.

---

## Solution & Editorial
# Intuition
In a star graph, the center node is the only node that is connected to every other node. This implies that the center node must be present in every edge provided in the input list. Therefore, we only need to examine the first two edges to identify the common vertex.

# Approach
1. Extract the two endpoints of the first edge: `u1` and `v1`.
2. Extract the two endpoints of the second edge: `u2` and `v2`.
3. Since the center node must be common to both edges, compare `u1` with `u2` and `v2`. If `u1` matches either, then `u1` is the center.
4. If `u1` is not the center, then `v1` must be the center by process of elimination.

### Visual Trace (Example 1: edges = [[1,2],[2,3],[4,2]])
| Step | Variable | Value | Logic |
| :--- | :--- | :--- | :--- |
| 1 | u1, v1 | 1, 2 | First edge endpoints |
| 2 | u2, v2 | 2, 3 | Second edge endpoints |
| 3 | Check | 1 == 2? | False |
| 4 | Check | 1 == 3? | False |
| 5 | Return | v1 | Returns 2 |

# Complexity
- Time complexity: $$O(1)$$. We only access the first two elements of the `edges` array, regardless of the total number of nodes $$n$$.
- Space complexity: $$O(1)$$. We only use a few integer variables for storage.

# Code
```cpp
//O(1)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int u1 = edges[0][0];
        int v1 = edges[0][1];

        int u2 = edges[1][0];
        int v2 = edges[1][1];

        if (u1 == u2 || u1 == v2) {
            return u1;
        } else {
            return v1;
        }
    }
};



// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         int n = edges.size();
//         vector<int> vis(n+2,0);
//         for(int i = 0;i<n;i++){
//             if(vis[edges[i][0]]) return edges[i][0];
//             if(vis[edges[i][1]]) return edges[i][1];
//             else{
//                 vis[edges[i][0]] = 1;
//                 vis[edges[i][1]] = 1;
//             }
//         }
//         return 0;
//     }
// };
```
