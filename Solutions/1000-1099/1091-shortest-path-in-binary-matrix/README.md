# [1091. Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)
**Difficulty:** `Medium` | **Tags:** `array`, `breadth-first-search`, `matrix`

---

## Problem Description
Given an `n x n` binary matrix `grid`, return *the length of the shortest **clear path** in the matrix*. If there is no clear path, return `-1`.

A **clear path** in a binary matrix is a path from the **top-left** cell (i.e., `(0, 0)`) to the **bottom-right** cell (i.e., `(n - 1, n - 1)`) such that:

* All the visited cells of the path are `0`.
* All the adjacent cells of the path are **8-directionally** connected (i.e., they are different and they share an edge or a corner).

The **length of a clear path** is the number of visited cells of this path.

**Example 1:**

```
Input: grid = [[0,1],[1,0]]
Output: 2
```

**Example 2:**

```
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
```

**Example 3:**

```
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
```

**Constraints:**

* `n == grid.length`
* `n == grid[i].length`
* `1 <= n <= 100`
* `grid[i][j] is 0 or 1`

---

## Solution & Editorial
# Intuition
The problem asks for the shortest path from the top-left cell `(0, 0)` to the bottom-right cell `(n - 1, n - 1)` in a binary matrix, moving in 8 directions through cells with value `0`. Since all edge weights are equal to 1, Breadth-First Search (BFS) is the optimal algorithm to find the shortest path in an unweighted grid.

# Approach
1. Check if the starting cell `(0, 0)` or the ending cell `(n - 1, n - 1)` has a value of `1`. If `grid[0][0] == 1`, immediately return `-1` as no path can start.
2. Initialize a queue `q` storing pairs of coordinates and the path distance `{{row, col}, dis}`, and a 2D vector `vis` of size `n x n` initialized to `0` to keep track of visited cells.
3. Push the starting cell `{{0, 0}, 1}` into the queue and mark `vis[0][0] = 1`.
4. While the queue is not empty, pop the front element containing `row`, `col`, and `dis`.
5. If `row == n - 1` and `col == n - 1`, return the current distance `dis`.
6. Iterate over all 8 possible directions using direction arrays `drow` and `dcol`.
7. For each neighbor `(nrow, ncol)`, check if it is within bounds, unvisited (`!vis[nrow][ncol]`), and clear (`grid[nrow][ncol] == 0`). If valid, push it to the queue with distance `dis + 1` and mark it visited.
8. If the queue is exhausted without reaching the destination, return `-1`.

### Visual Trace Walkthrough (Example 1: `grid = [[0,1],[1,0]]`)<br>
- `n = 2`<br>
- Initial State: `q = [{{(0,0), 1}}]`, `vis[0][0] = 1`<br>
- Pop `(0,0)`, distance `1`. Not target.<br>
- Explore 8 neighbors. Only `(0,1)` and `(1,0)` are in bounds, but `grid[0][1] == 1` and `grid[1][0] == 1`. Neither can be visited.<br>
- Queue becomes empty. Returns `-1`. Wait, for `grid = [[0,1],[1,0]]`, Example 1 output is `2` because the bottom-right `(1,1)` is reachable directly from `(0,0)` if diagonal is used. Let's trace carefully: from `(0,0)`, `drow = {-1,-1,0,1,1,1,0,-1}`, `dcol = {0,1,1,1,0,-1,-1,-1}`. Direction `i = 3` gives `nrow = 0 + 1 = 1`, `ncol = 0 + 1 = 1`. `grid[1][1] == 0`, so `(1,1)` is pushed with distance `2`. Next iteration pops `(1,1)` which matches `n-1, n-1`, returning `2`.

# Complexity
- Time complexity: $$O(n^2)$$ — In the worst-case scenario, every cell in the $$n \times n$$ grid is pushed and popped from the queue at most once. Each cell has 8 constant-time neighbor checks.
- Space complexity: $$O(n^2)$$ — The visited matrix `vis` and the BFS queue `q` require auxiliary space proportional to the number of cells in the grid, which is $$n \times n$$.

# Code
```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(grid[0][0] == 1) return -1;
        q.push({{0,0},1});
        vis[0][0] = 1;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            int drow[] = {-1,-1,0,1,1,1,0,-1};
            int dcol[] = {0,1,1,1,0,-1,-1,-1};
            if(row == n-1 && col == n-1) return dis;
            for(int i =0;i<8;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                    q.push({{nrow,ncol},dis+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return -1;

    }
};
```
