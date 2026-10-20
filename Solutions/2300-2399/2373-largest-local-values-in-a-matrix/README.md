# [2373. Largest Local Values in a Matrix](https://leetcode.com/problems/largest-local-values-in-a-matrix/)
**Difficulty:** `Easy` | **Tags:** `array`, `matrix`

---

## Problem Description
You are given an `n x n` integer matrix `grid`.

Generate an integer matrix `maxLocal` of size `(n - 2) x (n - 2)` such that:

* `maxLocal[i][j]` is equal to the **largest** value of the `3 x 3` matrix in `grid` centered around row `i + 1` and column `j + 1`.

In other words, we want to find the largest value in every contiguous `3 x 3` matrix in `grid`.

Return *the generated matrix*.

**Example 1:**

```
Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
Output: [[9,9],[8,6]]
Explanation: The diagram above shows the original matrix and the generated matrix.
Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
```

**Example 2:**

```
Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
Output: [[2,2,2],[2,2,2],[2,2,2]]
Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.
```

**Constraints:**

* `n == grid.length == grid[i].length`
* `3 <= n <= 100`
* `1 <= grid[i][j] <= 100`

---

## Solution & Editorial
# Intuition
The problem asks us to compute the local maximum for every possible 3x3 subgrid within an n x n matrix. Since the constraints are small (n <= 100), a direct simulation of the sliding window process is efficient and optimal.

# Approach
1. Initialize a result matrix `ans` of size (n-2) x (n-2).
2. Iterate through every possible top-left corner (i, j) of a 3x3 subgrid, where 0 <= i < n-2 and 0 <= j < n-2.
3. For each (i, j), perform a nested loop over the 3x3 area starting at (i, j) to find the maximum value.
4. Update `ans[i][j]` with the maximum value found in the current 3x3 window.

### Visual Trace (Example 1)
Grid: 
[[9,9,8,1],
 [5,6,2,6],
 [8,2,6,4],
 [6,2,2,2]]

- i=0, j=0: Window is grid[0..2][0..2]. Max of {9,9,8, 5,6,2, 8,2,6} is 9.
- i=0, j=1: Window is grid[0..2][1..3]. Max of {9,8,1, 6,2,6, 2,6,4} is 9.
- i=1, j=0: Window is grid[1..3][0..2]. Max of {5,6,2, 8,2,6, 6,2,2} is 8.
- i=1, j=1: Window is grid[1..3][1..3]. Max of {6,2,6, 2,6,4, 2,2,2} is 6.

Result: [[9,9],[8,6]]

# Complexity
- Time complexity: $$O(N^2)$$, where N is the dimension of the grid. We iterate through (N-2)^2 cells, and for each cell, we perform a constant number of operations (9 comparisons).
- Space complexity: $$O(1)$$ auxiliary space, excluding the output matrix `ans` which is required by the problem.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                for (int x = i; x <= i + 2; x++) {
                    for (int y = j; y <= j + 2; y++) {
                        ans[i][j] = max(ans[i][j], grid[x][y]);
                    }
                }
            }
        }
        return ans;
    }
};
```
