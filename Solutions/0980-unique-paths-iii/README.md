# [980. Unique Paths III](https://leetcode.com/problems/unique-paths-iii/)
**Difficulty:** `Hard` | **Tags:** `array`, `backtracking`, `bit-manipulation`, `matrix`, `hamiltonian-path`

---

## Problem Description
You are given an `m x n` integer array `grid` where `grid[i][j]` could be:

* `1` representing the starting square. There is exactly one starting square.
* `2` representing the ending square. There is exactly one ending square.
* `0` representing empty squares we can walk over.
* `-1` representing obstacles that we cannot walk over.

Return *the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once*.

**Example 1:**

```
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
```

**Example 2:**

```
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
```

**Example 3:**

```
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 20`
* `1 <= m * n <= 20`
* `-1 <= grid[i][j] <= 2`
* There is exactly one starting cell and one ending cell.

---

## Solution & Editorial
# Intuition
To find a path that visits every non-obstacle square exactly once and ends at the target square, we can use Depth-First Search (DFS) with backtracking. We first scan the grid to count total valid squares to visit (empty squares plus the starting square) and locate the starting coordinates. Then, we recursively explore all 4-directional moves, temporarily marking visited cells as obstacles and restoring them upon backtracking.

# Approach
1. Initialize `empty` to 1 to account for the start cell, and iterate through the grid to find the start cell coordinates (`startR`, `startC`) and count all open cells (`grid[i][j] == 0`).
2. Call the recursive `backtrack` function starting from (`startR`, `startC`) with a `count` of 0.
3. Inside `backtrack`: 
   - Check boundary conditions and obstacle encounters (`grid[r][c] == -1`), returning early if invalid.
   - If the current cell is the end cell (`grid[r][c] == 2`), check if `count == empty`. If true, increment the valid path counter `ans` and return.
   - Temporarily mark the current cell as visited by setting `grid[r][c] = -1`.
   - Recursively explore all four neighbors: `r + 1`, `r - 1`, `c + 1`, `c - 1`, incrementing `count + 1`.
   - Backtrack by restoring `grid[r][c]` to its original value (`temp`).

### Visual Trace Walkthrough (Example 1)
Grid: `[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]`
- Total valid cells (`empty`) = 11 (1 start + 10 zeros).
- DFS explores paths starting from `(0, 0)`.
- When a path reaches `(2, 2)` (value 2), if the visited count equals 11, `ans` is incremented.

# Complexity
- Time complexity: $$O(4^{M \times N})$$ — In the worst-case, from each cell we can branch into 4 directions. Since $M \times N \le 20$, the backtracking search efficiently prunes paths that hit obstacles or run out of bounds.
- Space complexity: $$O(M \times N)$$ — The recursion stack can go as deep as the total number of cells in the grid, alongside constant auxiliary space variables.

# Code
```cpp
class Solution {
public:
    void backtrack(vector<vector<int>>& grid, int r, int c, int& row, int& clm,
                   int& ans,int& empty, int count) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
            grid[r][c] == -1) {
            return;
        }

        if (grid[r][c] == 2) {
            if (count == empty)
                ans++;
            return;
        }

        int temp = grid[r][c];
        grid[r][c] = -1;

        backtrack(grid, r + 1, c, row, clm,ans,empty, count + 1);
        backtrack(grid, r - 1, c, row, clm,ans,empty, count + 1);
        backtrack(grid, r, c + 1, row, clm,ans,empty, count + 1);
        backtrack(grid, r, c - 1, row, clm,ans,empty, count + 1);
        grid[r][c] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startR, startC;
        int ans = 0;
        int empty = 1;
        int row = grid.size();
        int clm = grid[0].size();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startR = i;
                    startC = j;
                } else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }

        backtrack(grid, startR, startC, row, clm,ans,empty,0);
        return ans;
    }
};
```
