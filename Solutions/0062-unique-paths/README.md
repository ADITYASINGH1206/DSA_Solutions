# [62. Unique Paths](https://leetcode.com/problems/unique-paths/)
**Difficulty:** `Medium` | **Tags:** `math`, `dynamic-programming`, `combinatorics`

---

## Problem Description
There is a robot on an `m x n` grid. The robot is initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

Given the two integers `m` and `n`, return *the number of possible unique paths that the robot can take to reach the bottom-right corner*.

The test cases are generated so that the answer will be less than or equal to `2 * 109`.

**Example 1:**

```
Input: m = 3, n = 7
Output: 28
```

**Example 2:**

```
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

**Constraints:**

* `1 <= m, n <= 100`

---

## Solution & Editorial
# Intuition
The problem asks for the number of unique paths from the top-left corner to the bottom-right corner of an $m \times n$ grid, given that the robot can only move either down or right. Since choices at each cell lead to overlapping subproblems and optimal substructure, we can solve this efficiently using memoized Depth-First Search (DFS).

# Approach
1. Initialize a 2D memoization table `grid` of size $m \times n$ with `-1` to indicate uncalculated states.
2. Define a recursive helper function `dfs(m, n, row, col, grid)` that returns the number of unique paths from cell `(row, col)` to `(m - 1, n - 1)`.
3. Base Cases:
   - If `row == m - 1` and `col == n - 1`, we have reached the destination. Return `1`.
   - If `row >= m` or `col >= n`, the position is out of bounds. Return `0`.
   - If `grid[row][col] != -1`, the subproblem has already been solved. Return the stored value `grid[row][col]`.
4. Recursive Transitions:
   - Compute paths by moving down: `int down = dfs(m, n, row + 1, col, grid)`
   - Compute paths by moving right: `int right = dfs(m, n, row, col + 1, grid)`
5. Memoize and return the result: `grid[row][col] = down + right`.

### Visual Walkthrough (Example 2: m = 3, n = 2)
| State (row, col) | Action | Recursive Calls | Returned Value | Memoized Grid State |
| :--- | :--- | :--- | :--- | :--- |
| `(0, 0)` | Explore Down, Right | `dfs(1,0)`, `dfs(0,1)` | `2 + 1 = 3` | `grid[0][0] = 3` |
| `(1, 0)` | Explore Down, Right | `dfs(2,0)`, `dfs(1,1)` | `1 + 1 = 2` | `grid[1][0] = 2` |
| `(2, 0)` | Reached boundary (Down) / Valid (Right) | `dfs(3,0)` [0], `dfs(2,1)` [1] | `0 + 1 = 1` | `grid[2][0] = 1` |
| `(2, 1)` | Destination reached | Base case `row==m-1, col==n-1` | `1` | `grid[2][1] = 1` |
| `(0, 1)` | Destination reached | Base case `row==m-1, col==n-1` | `1` | `grid[0][1] = 1` |
| `(1, 1)` | Destination reached | Base case `row==m-1, col==n-1` | `1` | `grid[1][1] = 1` |

# Complexity
- Time complexity: $$O(m \times n)$$ — There are $m \times n$ distinct states in the grid. Each state is computed exactly once thanks to memoization.
- Space complexity: $$O(m \times n)$$ — The space is consumed by the recursion call stack (up to $O(m + n)$ depth) and the 2D `grid` memoization table of size $m \times n$.

# Code
```cpp
class Solution {
public:
    int dfs(int&m,int& n,int row,int col,vector<vector<int>>& grid){
        if(row == m-1 && col == n-1) return 1;

        if(row >= m || col >= n) return 0;
        if(grid[row][col] != -1) return grid[row][col];

        int down = dfs(m,n,row+1,col,grid);
        int right = dfs(m,n,row,col+1,grid);

        return grid[row][col] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,-1));
        return dfs(m,n,0,0,grid);

    }
};
```
