# [542. 01 Matrix](https://leetcode.com/problems/01-matrix/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `breadth-first-search`, `matrix`

---

## Problem Description
Given an `m x n` binary matrix `mat`, return *the distance of the nearest* `0` *for each cell*.

The distance between two cells sharing a common edge is `1`.

**Example 1:**

```
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
```

**Example 2:**

```
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
```

**Constraints:**

* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 104`
* `1 <= m * n <= 104`
* `mat[i][j]` is either `0` or `1`.
* There is at least one `0` in `mat`.

**Note:** This question is the same as 1765: [https://leetcode.com/problems/map-of-highest-peak/](https://leetcode.com/problems/map-of-highest-peak/description/)

---

## Solution & Editorial
# Intuition
This problem asks for the shortest distance from each cell to the nearest `0`. Since we want to find shortest paths from multiple source cells (all cells containing `0`) simultaneously to all other cells, Multi-Source Breadth-First Search (BFS) is the ideal technique. By initializing all `0` cells as starting points in our queue with a distance of `0` and marking unvisited cells with `-1`, we can propagate outward level by level, guaranteeing that the first time we visit any cell, we have found its minimum distance.

# Approach
1. Get the dimensions `n` (rows) and `m` (cols) of the matrix `mat`. Initialize an answer matrix `ans` of size `n x m` with `-1`, and a queue `q` to store coordinate pairs `{row, col}`.
2. Iterate through every cell in `mat`. If `mat[i][j] == 0`, set `ans[i][j] = 0` and push `{i, j}` into `q` as our multi-source starting points.
3. Define directional arrays `dr = {-1, 1, 0, 0}` and `dc = {0, 0, -1, 1}` to explore the four cardinal neighbors (up, down, left, right).
4. While the queue `q` is not empty, pop the front coordinate `(r, c)`. For each of the four directions, calculate neighbor coordinates `(nr, nc)`.
5. If `(nr, nc)` is within bounds and its distance in `ans` is `-1` (unvisited), update `ans[nr][nc] = ans[r][c] + 1` and push `(nr, nc)` into the queue.
6. Return the completed `ans` matrix after the queue is fully processed.

### Visual Walkthrough (Example 2)
Input: `mat = [[0,0,0],[0,1,0],[1,1,1]]`

- **Initial Queue & `ans` Matrix**: 
  Queue contains all `0` cells: `(0,0)`, `(0,1)`, `(0,2)`, `(1,0)`, `(1,2)`.
  `ans` matrix:
  ```
  [[ 0,  0,  0],
   [ 0, -1,  0],
   [-1, -1, -1]]
  ```
- **BFS Propagation**: 
  - Pop `(1,0)` (dist 0), visits `(2,0)` setting `ans[2][0] = 1`. Queue pushes `(2,0)`.
  - Pop `(1,2)` (dist 0), visits `(2,2)` setting `ans[2][2] = 1`. Queue pushes `(2,2)`.
  - Pop `(2,0)` (dist 1), visits `(2,1)` setting `ans[2][1] = 2`. Queue pushes `(2,1)`.
  - Pop `(2,2)` (dist 1), visits `(2,1)` (already visited).

Final `ans` matrix:
```
[[0, 0, 0],
 [0, 1, 0],
 [1, 2, 1]]
```

# Complexity
- Time complexity: $$O(m \times n)$$
  Every cell is pushed into and popped from the queue at most once. Traversing the 4 neighbors takes constant time per cell, resulting in linear time complexity relative to the total number of cells.
- Space complexity: $$O(m \times n)$$
  The distance matrix `ans` and the BFS queue `q` both store at most $$m \times n$$ elements in the worst case (e.g., when all cells are `0`).

# Code
```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1) {
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return ans;
    }
};
```
