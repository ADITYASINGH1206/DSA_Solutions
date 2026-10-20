# [73. Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `matrix`

---

## Problem Description
Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it [in place](https://en.wikipedia.org/wiki/In-place_algorithm).

**Example 1:**

```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```

**Example 2:**

```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[0].length`
* `1 <= m, n <= 200`
* `-231 <= matrix[i][j] <= 231 - 1`

**Follow up:**

* A straightforward solution using `O(mn)` space is probably a bad idea.
* A simple improvement uses `O(m + n)` space, but still not the best solution.
* Could you devise a constant space solution?

---

## Solution & Editorial
# Intuition
To set entire rows and columns to zero when a zero is encountered without accidentally overwriting data prematurely or using $$O(mn)$$ space, we can record the indices of rows and columns that need to be zeroed out using two separate boolean marker arrays.

# Approach
1. Get the matrix dimensions `m` (rows) and `n` (columns).
2. Initialize two boolean vectors `row` of size `m` and `col` of size `n` to `false`.
3. Traverse every element in `matrix`. If `matrix[i][j] == 0`, mark `row[i] = true` and `col[j] = true`.
4. Traverse the matrix a second time. For each element `matrix[i][j]`, if `row[i]` is true or `col[j]` is true, set `matrix[i][j] = 0`.

### Visual Walkthrough (Example 1)
Matrix:
$$\begin{bmatrix} 1 & 1 & 1 \\ 1 & 0 & 1 \\ 1 & 1 & 1 \end{bmatrix}$$

- **Pass 1 (Detection)**:
  - Encounter `matrix[1][1] == 0` $\implies$ `row[1] = true`, `col[1] = true`.
  - `row` vector: `[false, true, false]`
  - `col` vector: `[false, true, false]`

- **Pass 2 (Application)**:
  - Any cell with `row[i] == true` or `col[j] == true` becomes `0`.
  - Result:
    $$\begin{bmatrix} 1 & 0 & 1 \\ 0 & 0 & 0 \\ 1 & 0 & 1 \end{bmatrix}$$

# Complexity
- Time complexity: $$O(m \times n)$$
  We iterate through the entire matrix twice: once for finding zeros and once for updating the elements.
- Space complexity: $$O(m + n)$$
  We utilize two auxiliary boolean arrays `row` of size `m` and `col` of size `n`.

# Code
```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m);
        vector<bool> col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
```
