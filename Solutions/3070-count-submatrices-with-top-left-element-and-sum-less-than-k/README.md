# [3070. Count Submatrices with Top-Left Element and Sum Less Than k](https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/)
**Difficulty:** `Medium` | **Tags:** `array`, `matrix`, `prefix-sum`

---

## Problem Description
You are given a **0-indexed** integer matrix `grid` and an integer `k`.

Return *the **number** of submatrices that contain the top-left element of the* `grid`, *and have a sum less than or equal to* `k`.

**Example 1:**

```
Input: grid = [[7,6,3],[6,6,1]], k = 18
Output: 4
Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
```

**Example 2:**

```
Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
Output: 6
Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= n, m <= 1000`
* `0 <= grid[i][j] <= 1000`
* `1 <= k <= 109`

---

## Solution & Editorial
# Intuition
Since we need to count submatrices that include the top-left element `(0,0)`, any such submatrix is uniquely defined by its bottom-right corner `(i, j)`. The sum of the submatrix spanning from `(0,0)` to `(i, j)` can be computed efficiently using a 2D prefix sum array.

# Approach
1. Initialize a 2D prefix sum array `s` of size `(m+1) x (n+1)` to store the sum of the submatrix from `(0,0)` to `(i-1, j-1)`.
2. Iterate through each cell `(i, j)` of the grid. The prefix sum at `s[i][j]` is calculated as: `s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + grid[i-1][j-1]`.
3. For every cell, check if `s[i][j] <= k`. If true, increment the counter `ans`.

### Visual Trace (Example 1: grid = [[7,6,3],[6,6,1]], k = 18)
| i,j | Calculation | s[i][j] | <= 18? | ans |
|---|---|---|---|---|
| 1,1 | 0+0-0+7 | 7 | Yes | 1 |
| 1,2 | 7+0-0+6 | 13 | Yes | 2 |
| 1,3 | 13+0-0+3 | 16 | Yes | 3 |
| 2,1 | 0+7-0+6 | 13 | Yes | 4 |
| 2,2 | 13+13-7+6 | 25 | No | 4 |
| 2,3 | 25+16-13+1 | 29 | No | 4 |

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ and $$N$$ are the dimensions of the grid. We perform a single pass over the matrix to compute prefix sums and evaluate the condition.
- Space complexity: $$O(M \times N)$$ to store the prefix sum matrix. This can be optimized to $$O(N)$$ if necessary, but $$O(MN)$$ is well within limits for $$1000 \times 1000$$.

# Code
```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
                if (s[i][j] <= k) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```
