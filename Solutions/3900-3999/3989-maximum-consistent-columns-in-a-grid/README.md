# [3989. Maximum Consistent Columns in a Grid](https://leetcode.com/problems/maximum-consistent-columns-in-a-grid/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`, `matrix`

---

## Problem Description
You are given a 2D integer array `grid` of size `m x n`, and an integer `limit`.

You may remove zero or more columns from the grid, but at least one column must remain. The **relative** order of the remaining columns must be preserved.

A grid is called **consistent** if for every row `i`, and for every pair of adjacent remaining columns `a` and `b` with `a < b`, the following holds: `|grid[i][b] - grid[i][a]| <= limit`.

Return the **maximum** number of columns that can remain such that the resulting grid is **consistent**.

**Example 1:**

**Input:** grid = [[-2,0,3]], limit = 2

**Output:** 2

**Explanation:**

* Remove column 2 and keep columns 0 and 1, which gives `|grid[0][1] − grid[0][0]| = |0 − (−2)| = 2 <= limit`.
* Thus, the maximum number of columns that can remain is 2.

**Example 2:**

**Input:** grid = [[1,-1,1],[2,2,2]], limit = 1

**Output:** 2

**Explanation:**

* Remove column 1 and keep columns 0 and 2, which gives
  + `|grid[0][2] − grid[0][0]| = |1 − 1| = 0 <= limit` and
  + `|grid[1][2] − grid[1][0]| = |2 − 2| = 0 <= limit`.
* Thus, the maximum number of columns that can remain is 2.

**Example 3:**

**Input:** grid = [[-5,5]], limit = 9

**Output:** 1

**Explanation:**

* Remove either column 0 or column 1, since `|grid[0][1] − grid[0][0]| = |5 − (−5)| = 10 > limit`.
* Thus, the maximum number of columns that can remain is 1.

**Constraints:**

* `1 <= m == grid.length <= 250`
* `1 <= n == grid[i].length <= 250`
* `-105 <= grid[i][j] <= 105`
* `0 <= limit <= 105​​​​​​​​​​​​​​​​`

---

## Solution & Editorial
# Intuition
The problem asks for the longest subsequence of columns such that every adjacent pair of columns in the subsequence satisfies the `limit` constraint across all rows. This structure is identical to the classic Longest Increasing Subsequence (LIS) problem, where the "increasing" condition is replaced by a custom consistency check between columns.

# Approach
1. Define `dp[j]` as the maximum number of consistent columns ending at column index `j`.
2. Initialize `dp` with 1s, as any single column is consistent by itself.
3. Iterate through each column `j` from `1` to `n-1`.
4. For each `j`, iterate through all previous columns `k < j`.
5. Check if column `j` can follow column `k` by verifying `|grid[i][j] - grid[i][k]| <= limit` for all rows `i`.
6. If consistent, update `dp[j] = max(dp[j], dp[k] + 1)`.
7. The final answer is the maximum value found in the `dp` array.

### Visual Trace (Example 1: grid = [[-2, 0, 3]], limit = 2)
| j | k | Check | dp[j] update |
|---|---|-------|--------------|
| 1 | 0 | |0 - (-2)|=2 <= 2 (True) | dp[1] = max(1, 1+1) = 2 |
| 2 | 0 | |3 - (-2)|=5 > 2 (False) | dp[2] = 1 |
| 2 | 1 | |3 - 0|=3 > 2 (False) | dp[2] = 1 |

# Complexity
- Time complexity: $$O(N^2 \cdot M)$$, where $$N$$ is the number of columns and $$M$$ is the number of rows. We have nested loops for $$j$$ and $$k$$ ($$O(N^2)$$) and an inner loop over rows ($$O(M)$$).
- Space complexity: $$O(N)$$, as we only maintain a 1D DP array of size $$N$$.

# Code
```cpp
class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 1);
        int ans = 1;
        
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < j; ++k) {
                bool check = true;
                for (int i = 0; i < m; ++i) {
                    if (abs(grid[i][j] - grid[i][k]) > limit) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
            }
            ans = max(ans, dp[j]);
        }
        
        return ans;
    }
};
```
