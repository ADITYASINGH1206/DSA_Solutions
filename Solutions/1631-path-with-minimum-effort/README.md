# [1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-search`, `depth-first-search`, `breadth-first-search`, `union-find`, `heap-priority-queue`, `matrix`, `dijkstra`

---

## Problem Description
You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., **0-indexed**). You can move **up**, **down**, **left**, or **right**, and you wish to find a route that requires the minimum **effort**.

A route's **effort** is the **maximum absolute difference**in heights between two consecutive cells of the route.

Return *the minimum **effort** required to travel from the top-left cell to the bottom-right cell.*

**Example 1:**

```
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
```

**Example 2:**

```
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
```

**Example 3:**

```
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
```

**Constraints:**

* `rows == heights.length`
* `columns == heights[i].length`
* `1 <= rows, columns <= 100`
* `1 <= heights[i][j] <= 106`

---

## Solution & Editorial
# Intuition
The problem asks for a path that minimizes the maximum absolute difference between consecutive cells. This is a classic shortest path problem on a weighted graph where the "weight" of an edge between two adjacent cells is the absolute difference in their heights. Since we want to minimize the maximum edge weight along a path, Dijkstra's algorithm is the optimal choice.

# Approach
1. Treat each cell `(r, c)` as a node in a graph. The weight of an edge between adjacent cells `(r1, c1)` and `(r2, c2)` is `abs(heights[r1][c1] - heights[r2][c2])`.
2. Use a min-priority queue to store `{effort, {row, col}}`, where `effort` is the maximum absolute difference encountered on the path from `(0, 0)` to `(row, col)`.
3. Maintain an `effort` matrix initialized to `INT_MAX` to store the minimum effort found so far to reach each cell. Initialize `effort[0][0] = 0`.
4. In each iteration, extract the cell with the smallest `dist` (effort). If it is the destination `(n-1, m-1)`, return `dist`.
5. Explore all 4 neighbors. For each neighbor, calculate the new effort as `max(current_effort, abs(diff))`. If this new effort is smaller than the recorded `effort[nrow][ncol]`, update it and push to the priority queue.

### Visual Trace (Example 1: 3x3 Grid)
| Step | PQ (effort, r, c) | Effort Matrix (Update) |
| :--- | :--- | :--- |
| Init | {(0, 0, 0)} | [[0, inf, inf], [inf, inf, inf], [inf, inf, inf]] |
| Pop (0,0,0) | {(1, 0, 1), (3, 1, 0)} | [[0, 1, inf], [3, inf, inf], [inf, inf, inf]] |
| Pop (1,0,1) | {(1, 0, 2), (3, 1, 0)} | [[0, 1, 1], [3, inf, inf], [inf, inf, inf]] |

# Complexity
- Time complexity: $$O(N \cdot M \log(N \cdot M))$$, where $$N$$ is rows and $$M$$ is columns. Each cell is pushed into the priority queue at most once, and each heap operation takes logarithmic time relative to the number of cells.
- Space complexity: $$O(N \cdot M)$$ to store the `effort` matrix and the priority queue.

# Code
```cpp
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
                       
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        pq.push({0, {0, 0}});
        effort[0][0] = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (row == n - 1 && col == m - 1) {
                return dist;
            }
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int temp = abs(heights[row][col] - heights[nrow][ncol]);
                    int temp2 = max(dist, temp);
                    if (temp2 < effort[nrow][ncol]) {
                        effort[nrow][ncol] = temp2;
                        pq.push({temp2, {nrow, ncol}});
                    }
                }
            }
        }
        
        return 0; 
    }
};
```
