# [861. Score After Flipping Matrix](https://leetcode.com/problems/score-after-flipping-matrix/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `bit-manipulation`, `matrix`

---

## Problem Description
You are given an `m x n` binary matrix `grid`.

A **move** consists of choosing any row or column and toggling each value in that row or column (i.e., changing all `0`'s to `1`'s, and all `1`'s to `0`'s).

Every row of the matrix is interpreted as a binary number, and the **score** of the matrix is the sum of these numbers.

Return *the highest possible **score** after making any number of **moves** (including zero moves)*.

**Example 1:**

```
Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
```

**Example 2:**

```
Input: grid = [[0]]
Output: 1
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 20`
* `grid[i][j]` is either `0` or `1`.

---

## Solution & Editorial
# Intuition
The problem asks us to maximize the sum of binary numbers represented by each row of a matrix after toggling rows and columns. To maximize a binary number, the most significant bits (MSBs) must be as large as possible. Therefore, we should greedily ensure that every row starts with a `1` by toggling rows whose first element is `0`. Once all row headers are `1`, we process subsequent columns from left to right, toggling a column if the count of `0`s exceeds the count of `1`s to maximize the number of `1`s in each column position.

# Approach
1. Initialize row and column dimensions `m` and `n` along with `ans = 0`.
2. Iterate through each row `i`. If `grid[i][0] == 0`, toggle all elements in that row to guarantee the highest possible bit placement.
3. Iterate through each column `col` starting from column `0` to `n - 1`. Count how many `0`s exist in that column. If `zero > m / 2`, toggle the entire column to maximize the total number of `1`s.
4. After optimal toggling, compute the integer value of each row by treating it as a binary string and add it to `ans`.

### Visual Walkthrough (Example 1)
Initial Matrix:
`[[0, 0, 1, 1], [1, 0, 1, 0], [1, 1, 0, 0]]`

Step 1: Make first column all `1`s by toggling row 0:
`[[1, 1, 0, 0], [1, 0, 1, 0], [1, 1, 0, 0]]`

Step 2: Check columns for majority `0`s:
- Col 0: `0` zeros (Keep)
- Col 1: `1` zero out of 3 (Keep)
- Col 2: `2` zeros out of 3 (`2 > 3/2` is true -> Toggle Col 2)
- Col 3: `2` zeros out of 3 (`2 > 3/2` is true -> Toggle Col 3)

Final Matrix:
`[[1, 1, 1, 1], [1, 0, 0, 1], [1, 1, 1, 1]]`

Step 3: Evaluate rows:
- Row 0: `0b1111 = 15`
- Row 1: `0b1001 = 9`
- Row 2: `0b1111 = 15`
Total Score = `15 + 9 + 15 = 39`.

# Complexity
- Time complexity: $$O(m \cdot n)$$ — We traverse the matrix a constant number of times: once to fix rows, once to evaluate and toggle columns, and once to calculate the final score.
- Space complexity: $$O(1)$$ — All operations are performed in-place on the existing matrix using primitive variables.

# Code
```cpp
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        for(int col = 0; col < n; col++) {
            int zero = 0;
            for(int row = 0; row < m; row++) {
                if(grid[row][col] == 0) zero++;
            }
            if(zero > m / 2) {
                for(int row = 0; row < m; row++) {
                    grid[row][col] = 1 - grid[row][col];
                }
            }
        }
        for(int i = 0; i < m; i++) {
            int num = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 1) {
                    num += (1 << (n - 1 - j));
                }
            }
            ans += num;
        }
        return ans;
    }
};
```
