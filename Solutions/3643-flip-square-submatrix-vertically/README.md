# [3643. Flip Square Submatrix Vertically](https://leetcode.com/problems/flip-square-submatrix-vertically/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`, `matrix`

---

## Problem Description
You are given an `m x n` integer matrix `grid`, and three integers `x`, `y`, and `k`.

The integers `x` and `y` represent the row and column indices of the **top-left** corner of a **square** submatrix and the integer `k` represents the size (side length) of the square submatrix.

Your task is to flip the submatrix by reversing the order of its rows vertically.

Return the updated matrix.

**Example 1:**

**Input:** grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], x = 1, y = 0, k = 3

**Output:** [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]

**Explanation:**

The diagram above shows the grid before and after the transformation.

**Example 2:**

​​​​​​​

**Input:** grid = [[3,4,2,3],[2,3,4,2]], x = 0, y = 2, k = 2

**Output:** [[3,4,4,2],[2,3,2,3]]

**Explanation:**

The diagram above shows the grid before and after the transformation.

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `1 <= grid[i][j] <= 100`
* `0 <= x < m`
* `0 <= y < n`
* `1 <= k <= min(m - x, n - y)`

---

## Solution & Editorial
# Intuition
To flip a square submatrix vertically, we need to swap rows within the submatrix symmetrically. Specifically, the row at index `i` (relative to the submatrix top) must be swapped with the row at index `k - 1 - i`.

# Approach
1. Iterate through the first half of the rows in the submatrix, starting from row `x` up to `x + k/2 - 1`.
2. For each row `i`, calculate the corresponding symmetric row index `i2 = x + k - 1 - (i - x)`.
3. Iterate through each column `j` in the range `[y, y + k - 1]` and perform a `swap` between `grid[i][j]` and `grid[i2][j]`.

### Visual Trace (Example 1: x=1, y=0, k=3)
Submatrix rows are indices 1, 2, 3. We swap row 1 with row 3.
- `i = 1`: `i2 = 1 + 3 - 1 - (1 - 1) = 3`. Swap `grid[1][0..2]` with `grid[3][0..2]`.
- `i = 2`: `i2 = 1 + 3 - 1 - (2 - 1) = 2`. No change (middle row).

# Complexity
- Time complexity: $$O(k^2)$$, where $$k$$ is the side length of the submatrix. We iterate through half the rows ($$k/2$$) and for each row, we iterate through all $$k$$ columns.
- Space complexity: $$O(1)$$, as we perform the swaps in-place without using any auxiliary data structures.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = x; i < x + k / 2; i++) {
            int i2 = x + k - 1 - (i - x);
            for (int j = y; j < y + k; j++) {
                swap(grid[i][j], grid[i2][j]);
            }
        }
        return grid;
    }
};
```
