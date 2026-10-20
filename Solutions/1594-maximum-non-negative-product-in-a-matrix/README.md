# [1594. Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `matrix`

---

## Problem Description
You are given a `m x n` matrix `grid`. Initially, you are located at the top-left corner `(0, 0)`, and in each step, you can only **move right or down** in the matrix.

Among all possible paths starting from the top-left corner `(0, 0)` and ending in the bottom-right corner `(m - 1, n - 1)`, find the path with the **maximum non-negative product**. The product of a path is the product of all integers in the grid cells visited along the path.

Return the *maximum non-negative product **modulo*** `109 + 7`. *If the maximum product is **negative**, return* `-1`.

Notice that the modulo is performed after getting the maximum product.

**Example 1:**

```
Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
Output: -1
Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
```

**Example 2:**

```
Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
```

**Example 3:**

```
Input: grid = [[1,3],[0,-4]]
Output: 0
Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 15`
* `-4 <= grid[i][j] <= 4`

---

## Solution & Editorial
# Intuition
Since the grid contains negative numbers, a path that currently has a very small (large negative) product could become the maximum product if it encounters another negative number. Therefore, at each cell, we must track both the minimum and maximum possible products to correctly compute the potential future maximum.

# Approach
1. We define a 3D DP table `dp[m][n][2]`, where `dp[i][j][0]` stores the minimum product to reach `(i, j)` and `dp[i][j][1]` stores the maximum product.
2. Initialize the DP table with the starting cell `grid[0][0]`.
3. Fill the first row and first column iteratively, as they only have one possible path.
4. For all other cells `(i, j)`, calculate the potential products from the top `(i-1, j)` and left `(i, j-1)` neighbors. 
   - If `grid[i][j]` is non-negative, the new min is `min(prev_min) * grid[i][j]` and the new max is `max(prev_max) * grid[i][j]`.
   - If `grid[i][j]` is negative, the new min is `max(prev_max) * grid[i][j]` and the new max is `min(prev_min) * grid[i][j]`.
5. Finally, check if the result at `dp[m-1][n-1][1]` is negative. If so, return -1; otherwise, return the value modulo 10^9 + 7.

### Visual Trace (Example 2: 1x3 grid segment)
| Cell | Value | Min Product | Max Product |
| :--- | :--- | :--- | :--- |
| (0,0) | 1 | 1 | 1 |
| (0,1) | -2 | -2 | -2 |
| (0,2) | 1 | -2 | -2 |

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ and $$N$$ are the dimensions of the grid. We visit each cell exactly once and perform constant time operations.
- Space complexity: $$O(M \times N)$$ to store the DP table. This can be optimized to $$O(N)$$ if necessary, but $$O(M \times N)$$ is well within limits for the given constraints.

# Code
```cpp
using ll = long long;
const int mod = 1e9 + 7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(2, grid[0][0])));
        for (int i = 1; i < m; ++i) {
            dp[i][0][0] = dp[i - 1][0][0] * grid[i][0];
            dp[i][0][1] = dp[i - 1][0][1] * grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j][0] = dp[0][j - 1][0] * grid[0][j];
            dp[0][j][1] = dp[0][j - 1][1] * grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int v = grid[i][j];
                if (v >= 0) {
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                } else {
                    dp[i][j][0] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                    dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                }
            }
        }
        ll ans = dp[m - 1][n - 1][1];
        return ans < 0 ? -1 : (int) (ans % mod);
    }
};
```
