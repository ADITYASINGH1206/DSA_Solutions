# [3418. Maximum Amount of Money Robot Can Earn](https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `matrix`

---

## Problem Description
You are given an `m x n` grid. A robot starts at the top-left corner of the grid `(0, 0)` and wants to reach the bottom-right corner `(m - 1, n - 1)`. The robot can move either right or down at any point in time.

The grid contains a value `coins[i][j]` in each cell:

* If `coins[i][j] >= 0`, the robot gains that many coins.
* If `coins[i][j] < 0`, the robot encounters a robber, and the robber steals the **absolute** value of `coins[i][j]` coins.

The robot has a special ability to **neutralize robbers** in at most **2 cells** on its path, preventing them from stealing coins in those cells.

**Note:** The robot's total coins can be negative.

Return the **maximum** profit the robot can gain on the route.

**Example 1:**

**Input:** coins = [[0,1,-1],[1,-2,3],[2,-3,4]]

**Output:** 8

**Explanation:**

An optimal path for maximum coins is:

1. Start at `(0, 0)` with `0` coins (total coins = `0`).
2. Move to `(0, 1)`, gaining `1` coin (total coins = `0 + 1 = 1`).
3. Move to `(1, 1)`, where there's a robber stealing `2` coins. The robot uses one neutralization here, avoiding the robbery (total coins = `1`).
4. Move to `(1, 2)`, gaining `3` coins (total coins = `1 + 3 = 4`).
5. Move to `(2, 2)`, gaining `4` coins (total coins = `4 + 4 = 8`).

**Example 2:**

**Input:** coins = [[10,10,10],[10,10,10]]

**Output:** 40

**Explanation:**

An optimal path for maximum coins is:

1. Start at `(0, 0)` with `10` coins (total coins = `10`).
2. Move to `(0, 1)`, gaining `10` coins (total coins = `10 + 10 = 20`).
3. Move to `(0, 2)`, gaining another `10` coins (total coins = `20 + 10 = 30`).
4. Move to `(1, 2)`, gaining the final `10` coins (total coins = `30 + 10 = 40`).

**Constraints:**

* `m == coins.length`
* `n == coins[i].length`
* `1 <= m, n <= 500`
* `-1000 <= coins[i][j] <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks for the maximum profit in a grid where we can neutralize up to 2 negative values (robbers). Since the robot only moves right or down, this is a classic pathfinding problem that can be solved using dynamic programming. We need to track our current position `(i, j)` and the number of neutralizations `k` remaining.

# Approach
1. We define a DP state `f[i][j][k]` representing the maximum coins collected reaching cell `(i, j)` with `k` neutralizations remaining.
2. The base case is the destination `(m-1, n-1)`. If we have neutralizations left and the cell is negative, we can choose to neutralize it (effectively treating the value as 0) or take the value as is.
3. For any other cell, we recursively explore moving down `(i+1, j)` or right `(i, j+1)`.
4. If the current cell `coins[i][j]` is negative and we have `k > 0` neutralizations, we have two choices: either treat the cell as a normal gain/loss or use a neutralization (treating the cell as 0).

### Visual Trace (Example 1: 3x3 grid)
| State (i, j, k) | Action | Result |
| :--- | :--- | :--- |
| (0, 0, 2) | Start | 0 + max(dfs(0,1,2), dfs(1,0,2)) |
| (0, 1, 2) | Gain 1 | 1 + max(dfs(0,2,2), dfs(1,1,2)) |
| (1, 1, 2) | Robber (-2) | Use 1: 0 + max(dfs(1,2,1), dfs(2,1,1)) |

# Complexity
- Time complexity: $$O(M \times N \times K)$$, where $$M, N \le 500$$ and $$K=3$$. This results in approximately $$7.5 \times 10^5$$ operations, well within the time limit.
- Space complexity: $$O(M \times N \times K)$$ to store the memoization table.

# Code
```cpp
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> f(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i >= m || j >= n) {
                return INT_MIN / 2;
            }
            if (f[i][j][k] != INT_MIN) {
                return f[i][j][k];
            }
            if (i == m - 1 && j == n - 1) {
                return k > 0 ? max(0, coins[i][j]) : coins[i][j];
            }
            int ans = coins[i][j] + max(dfs(i + 1, j, k), dfs(i, j + 1, k));
            if (coins[i][j] < 0 && k > 0) {
                ans = max({ans, dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1)});
            }
            return f[i][j][k] = ans;
        };
        return dfs(0, 0, 2);
    }
};
```
