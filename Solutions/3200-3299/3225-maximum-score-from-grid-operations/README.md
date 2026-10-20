# [3225. Maximum Score From Grid Operations](https://leetcode.com/problems/maximum-score-from-grid-operations/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`, `matrix`, `prefix-sum`

---

## Problem Description
You are given a 2D matrix `grid` of size `n x n`. Initially, all cells of the grid are colored white. In one operation, you can select any cell of indices `(i, j)`, and color black all the cells of the `jth` column starting from the top row down to the `ith` row.

The grid score is the sum of all `grid[i][j]` such that cell `(i, j)` is white and it has a horizontally adjacent black cell.

Return the **maximum** score that can be achieved after some number of operations.

**Example 1:**

**Input:** grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]

**Output:** 11

**Explanation:**

In the first operation, we color all cells in column 1 down to row 3, and in the second operation, we color all cells in column 4 down to the last row. The score of the resulting grid is `grid[3][0] + grid[1][2] + grid[3][3]` which is equal to 11.

**Example 2:**

**Input:** grid = [[10,9,0,0,15],[7,1,0,8,0],[5,20,0,11,0],[0,0,0,1,2],[8,12,1,10,3]]

**Output:** 94

**Explanation:**

We perform operations on 1, 2, and 3 down to rows 1, 4, and 0, respectively. The score of the resulting grid is `grid[0][0] + grid[1][0] + grid[2][1] + grid[4][1] + grid[1][3] + grid[2][3] + grid[3][3] + grid[4][3] + grid[0][4]` which is equal to 94.

**Constraints:**

* `1 <= n == grid.length <= 100`
* `n == grid[i].length`
* `0 <= grid[i][j] <= 109`

---

## Solution & Editorial
# Intuition
The problem asks us to maximize the score by selecting column-wise black cell segments. A key observation is that the state of column `j` only depends on the boundary of the black segment in column `j-1`. Specifically, if we define the black segment in column `j` as ending at row `v` (where `v` is the number of black cells from the top), the score contribution depends on the difference between the current column's black segment boundary and the previous column's boundary.

# Approach
1. Precompute column prefix sums `col_sum[c][r]` to allow $O(1)$ calculation of the sum of any vertical segment in a column.
2. Define `dp[v][w]` as the maximum score after processing some columns, where the current column's black segment ends at row `v` and the previous column's black segment ended at row `w`.
3. Iterate through each column `i` from `0` to `n-1`. For each transition from `w` (previous column boundary) to `v` (current column boundary):
   - If `v > w`, we gain points from the white cells in column `i` that are now adjacent to black cells in column `i-1`.
   - If `w > v`, we gain points from the white cells in column `i-1` that are now adjacent to black cells in column `i`.
4. Use prefix and suffix maximums to optimize the inner transition loops from $O(N^4)$ to $O(N^3)$.

### Visual Trace (Simplified)
For a column transition from `w` to `v`:
- If `v > w`: Column `i` has black cells up to `v`, column `i-1` has black cells up to `w`. The cells `(w, i-1)` to `(v-1, i-1)` are white and adjacent to black cells in column `i`.
- If `w > v`: Column `i` has black cells up to `v`, column `i-1` has black cells up to `w`. The cells `(v, i)` to `(w-1, i)` are white and adjacent to black cells in column `i-1`.

# Complexity
- Time complexity: $$O(N^3)$$ where $$N$$ is the grid dimension. We iterate through $$N$$ columns, and for each, we perform nested loops over $$N$$ boundaries, optimized by prefix/suffix arrays.
- Space complexity: $$O(N^2)$$ to store the `dp` table and the precomputed column sums.

# Code
```cpp
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<long long>> col_sum(n, vector<long long>(n + 1, 0));
        for (int c = 0; c < n; ++c) {
            for (int r = 0; r < n; ++r) {
                col_sum[c][r + 1] = col_sum[c][r] + grid[r][c];
            }
        }
        
        const long long INF = 1e18; 
        
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -INF));
        
        for (int v = 0; v <= n; ++v) {
            dp[0][v] = 0;
        }
        
        for (int i = 0; i < n; ++i) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, -INF));
            const vector<long long>& base_sum = col_sum[i];
            
            for (int v = 0; v <= n; ++v) {
                long long val_v = base_sum[v];
                vector<long long> pref(n + 1, -INF);
                long long curr_max = -INF;
                for (int w = 0; w <= n; ++w) {
                    if (dp[w][v] > curr_max) {
                        curr_max = dp[w][v];
                    }
                    pref[w] = curr_max;
                }
                vector<long long> suff(n + 1, -INF);
                curr_max = -INF;
                for (int w = n - 1; w >= 0; --w) {
                    int u = w + 1;
                    long long cst = (u > v) ? (base_sum[u] - val_v) : 0;
                    
                    if (dp[u][v] != -INF) {
                        long long val = dp[u][v] + cst;
                        if (val > curr_max) {
                            curr_max = val;
                        }
                    }
                    suff[w] = curr_max;
                }
                for (int w = 0; w <= n; ++w) {
                    long long ans = suff[w];
                    long long p = pref[w];
                    
                    if (p != -INF) {
                        long long cst = (w > v) ? (base_sum[w] - val_v) : 0;
                        long long cand = p + cst;
                        if (cand > ans) {
                            ans = cand;
                        }
                    }
                    next_dp[v][w] = ans;
                }
            }
            dp = move(next_dp);
        }
        
        long long max_score = 0;
        for (int v = 0; v <= n; ++v) {
            max_score = max(max_score, dp[v][0]);
        }
        
        return max_score;
    }
};
```
