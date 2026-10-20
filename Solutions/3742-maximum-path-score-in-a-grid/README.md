# [3742. Maximum Path Score in a Grid](https://leetcode.com/problems/maximum-path-score-in-a-grid/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `matrix`

---

## Problem Description
You are given an `m x n` grid where each cell contains one of the values 0, 1, or 2. You are also given an integer `k`.

You start from the top-left corner `(0, 0)` and want to reach the bottom-right corner `(m - 1, n - 1)` by moving only **right** or **down**.

Each cell contributes a specific score and incurs an associated cost, according to their cell values:

* 0: adds 0 to your score and costs 0.
* 1: adds 1 to your score and costs 1.
* 2: adds 2 to your score and costs 1. ​​​​​​​

Return the **maximum** score achievable without exceeding a total cost of `k`, or -1 if no valid path exists.

**Note:** If you reach the last cell but the total cost exceeds `k`, the path is invalid.

**Example 1:**

**Input:** grid = [[0, 1],[2, 0]], k = 1

**Output:** 2

**Explanation:**​​​​​​​

The optimal path is:

| Cell | grid[i][j] | Score | Total  Score | Cost | Total  Cost |
| --- | --- | --- | --- | --- | --- |
| (0, 0) | 0 | 0 | 0 | 0 | 0 |
| (1, 0) | 2 | 2 | 2 | 1 | 1 |
| (1, 1) | 0 | 0 | 2 | 0 | 1 |

Thus, the maximum possible score is 2.

**Example 2:**

**Input:** grid = [[0, 1],[1, 2]], k = 1

**Output:** -1

**Explanation:**

There is no path that reaches cell `(1, 1)`​​​​​​​ without exceeding cost k. Thus, the answer is -1.

**Constraints:**

* `1 <= m, n <= 200`
* `0 <= k <= 103​​​​​​​`
* `​​​​​​​grid[0][0] == 0`
* `0 <= grid[i][j] <= 2`

---

## Solution & Editorial
# Intuition
The problem asks for the maximum score in a grid given a cost constraint $k$. Since we can only move right or down, the state of our path is defined by our current position $(i, j)$ and the remaining cost budget. This structure suggests a Dynamic Programming approach where we explore paths and memoize results to avoid redundant computations.

# Approach
1. Define a 3D DP table `f[i][j][k]` where `i` and `j` represent the current cell coordinates and `k` represents the remaining cost budget.
2. Use a recursive DFS function with memoization. For each cell `(i, j)`, calculate the score contribution based on the cell value: 0 adds 0 score/cost, 1 adds 1 score/cost, and 2 adds 2 score/cost.
3. If the current cell value is greater than 0, decrement the budget `k` before recursing to the top `(i-1, j)` or left `(i, j-1)` neighbors.
4. Base case: If we reach `(0, 0)`, return 0. If we go out of bounds or the budget becomes negative, return a sufficiently small negative value (`-inf`) to indicate an invalid path.
5. The final answer is the result of `dfs(m-1, n-1, k)`. If the result is negative, return -1.

### Visual Trace (Example 1: grid = [[0, 1], [2, 0]], k = 1)
| Step | Call | i, j | k | Result |
| :--- | :--- | :--- | :--- | :--- |
| 1 | dfs(1, 1, 1) | 1, 1 | 1 | 0 + max(dfs(0, 1, 1), dfs(1, 0, 1)) |
| 2 | dfs(0, 1, 1) | 0, 1 | 1 | 1 + max(dfs(-1, 1, 0), dfs(0, 0, 0)) = 1 + 0 = 1 |
| 3 | dfs(1, 0, 1) | 1, 0 | 1 | 2 + max(dfs(0, 0, 0), dfs(1, -1, 0)) = 2 + 0 = 2 |
| 4 | Final | - | - | max(1, 2) = 2 |

# Complexity
- Time complexity: $$O(M \times N \times K)$$ — Each state `(i, j, k)` is computed exactly once due to memoization.
- Space complexity: $$O(M \times N \times K)$$ — The 3D DP table stores results for every possible state.

# Code
```cpp
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int inf = 1 << 30;
        vector f(m, vector(n, vector<int>(k + 1, -1)));

        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i < 0 || j < 0 || k < 0) {
                return -inf;
            }
            if (i == 0 && j == 0) {
                return 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }

            int res = grid[i][j];
            int nk = k;
            if (grid[i][j] > 0) {
                --nk;
            }

            int a = dfs(i - 1, j, nk);
            int b = dfs(i, j - 1, nk);
            res += max(a, b);

            return f[i][j][k] = res;
        };

        int ans = dfs(m - 1, n - 1, k);
        return ans < 0 ? -1 : ans;
    }
};
```
