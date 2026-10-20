# [2482. Difference Between Ones and Zeros in Row and Column](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/)
**Difficulty:** `Medium` | **Tags:** `array`, `matrix`, `simulation`

---

## Problem Description
You are given a **0-indexed** `m x n` binary matrix `grid`.

A **0-indexed** `m x n` difference matrix `diff` is created with the following procedure:

* Let the number of ones in the `ith` row be `onesRowi`.
* Let the number of ones in the `jth` column be `onesColj`.
* Let the number of zeros in the `ith` row be `zerosRowi`.
* Let the number of zeros in the `jth` column be `zerosColj`.
* `diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj`

Return *the difference matrix* `diff`.

**Example 1:**

```
Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
Output: [[0,0,4],[0,0,4],[-2,-2,2]]
Explanation:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0 
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4 
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0 
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4 
- diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
- diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
- diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2
```

**Example 2:**

```
Input: grid = [[1,1,1],[1,1,1]]
Output: [[5,5,5],[5,5,5]]
Explanation:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 105`
* `1 <= m * n <= 105`
* `grid[i][j]` is either `0` or `1`.

---

## Solution & Editorial
# Intuition
The problem asks us to compute `diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j]`. Since the matrix is binary, we know that `zerosRow[i] = n - onesRow[i]` and `zerosCol[j] = m - onesCol[j]`. Substituting these into the formula simplifies the expression to `diff[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - n - m`, allowing us to compute the result using only the counts of ones.

# Approach
1. Precompute the number of ones in each row and column. We use two vectors `rows` of size `m` and `cols` of size `n` to store these counts.
2. Iterate through the `grid` once to populate `rows` and `cols`.
3. Create a result matrix `diff` of size `m x n`.
4. Iterate through each cell `(i, j)` and apply the simplified formula: `diff[i][j] = rows[i] + cols[j] - (n - rows[i]) - (m - cols[j])`.

### Visual Trace (Example 1)
`grid = [[0,1,1],[1,0,1],[0,0,1]]`
- `rows` (ones count per row): `[2, 2, 1]`
- `cols` (ones count per col): `[1, 1, 3]`
- `m=3, n=3`

| Cell (i,j) | Calculation | Result |
| :--- | :--- | :--- |
| (0,0) | 2 + 1 - (3-2) - (3-1) = 3 - 1 - 2 | 0 |
| (0,2) | 2 + 3 - (3-2) - (3-3) = 5 - 1 - 0 | 4 |
| (2,0) | 1 + 1 - (3-1) - (3-1) = 2 - 2 - 2 | -2 |

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ is the number of rows and $$N$$ is the number of columns. We traverse the matrix twice: once to count the ones and once to compute the differences.
- Space complexity: $$O(M + N)$$ to store the row and column sums, plus $$O(M \times N)$$ for the output matrix.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                rows[i] += v;
                cols[j] += v;
            }
        }
        vector<vector<int>> diff(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff[i][j] = rows[i] + cols[j] - (n - rows[i]) - (m - cols[j]);
            }
        }
        return diff;
    }
};
```
