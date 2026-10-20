# [4052. Cyclically Shift Rows and Columns](https://leetcode.com/problems/cyclically-shift-rows-and-columns/)
**Difficulty:** `Easy` | **Tags:** `array`, `matrix`, `simulation`

---

## Problem Description
You are given an integer `n`, a 2D integer array `grid` of size `n x n`, and two integer arrays `rowShift` and `colShift`, each of length `n`, where:

* `rowShift[i]` represents the number of positions to **cyclically shift** the `ith` row of `grid` to the **left**.
* `colShift[j]` represents the number of positions to **cyclically shift** the `jth` column of `grid` **upward**.

First, cyclically shift each row according to `rowShift`, then cyclically shift each column of the resulting grid according to `colShift`.

Return the resulting grid after performing all the shifts.

A **cyclic left shift** of a row by `k` positions moves the element at column `j` to column `(j - k + n) % n`. All other rows remain unchanged.

A **cyclic upward shift** of a column by `k` positions moves the element at row `i` to row `(i - k + n) % n`. All other columns remain unchanged.

**Example 1:**

**Input:** n = 2, `grid` = [[1,2],[3,4]], rowShift = [1,0], colShift = [0,1]

**Output:** [[2,4],[3,1]]

**Explanation:**

The `grid` changes as follows:

**Example 2:**

**Input:** n = 3, `grid` = [[1,2,3],[4,5,6],[7,8,9]], rowShift = [1,2,0], colShift = [2,2,1]

**Output:** [[7,8,5],[2,3,9],[6,4,1]]

**Explanation:**

The `grid` changes as follows:

**Constraints:**

* `1 <= n == grid.length == grid[i].length <= 10`
* `1 <= grid[i][j] <= 100`
* `rowShift.length == colShift.length == n`
* `0 <= rowShift[i], colShift[i] < n`

---

## Solution & Editorial
# Intuition
The problem requires two independent transformation phases: row-wise cyclic shifts followed by column-wise cyclic shifts. Since the constraints are small ($n \le 10$), we can perform these transformations using auxiliary grids to store intermediate states without worrying about memory overhead.

# Approach
1. **Row Shift Phase**: Create a `tempGrid`. For each row `i`, the element at `tempGrid[i][j]` is determined by shifting the original row `grid[i]` to the left by `rowShift[i]`. This maps the original column `(j + rowShift[i]) % n` to the new position `j`.
2. **Column Shift Phase**: Create an `ans` grid. For each column `j`, the element at `ans[i][j]` is determined by shifting the column `tempGrid[...][j]` upward by `colShift[j]`. This maps the row `(i + colShift[j]) % n` from `tempGrid` to the new row `i`.

### Visual Trace (Example 1: n=2, grid=[[1,2],[3,4]], rowShift=[1,0], colShift=[0,1])
- **Row Shift**: 
  - Row 0: shift left by 1 -> [2, 1]
  - Row 1: shift left by 0 -> [3, 4]
  - `tempGrid` = [[2, 1], [3, 4]]
- **Column Shift**:
  - Col 0: shift up by 0 -> [2, 3]
  - Col 1: shift up by 1 -> [4, 1]
  - `ans` = [[2, 4], [3, 1]]

# Complexity
- Time complexity: $$O(n^2)$$ where $n$ is the dimension of the grid. We iterate over the $n \times n$ grid twice.
- Space complexity: $$O(n^2)$$ to store the intermediate `tempGrid` and the final `ans` grid.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> tempGrid(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                tempGrid[i][j] = grid[i][(j + rowShift[i]) % n];
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = tempGrid[(i + colShift[j]) % n][j];
            }
        }
        
        return ans;
    }
};
```
