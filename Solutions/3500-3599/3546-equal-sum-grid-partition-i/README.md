# [3546. Equal Sum Grid Partition I](https://leetcode.com/problems/equal-sum-grid-partition-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `matrix`, `enumeration`, `prefix-sum`

---

## Problem Description
You are given an `m x n` matrix `grid` of positive integers. Your task is to determine if it is possible to make **either one horizontal or one vertical cut** on the grid such that:

* Each of the two resulting sections formed by the cut is **non-empty**.
* The sum of the elements in both sections is **equal**.

Return `true` if such a partition exists; otherwise return `false`.

**Example 1:**

**Input:** grid = [[1,4],[2,3]]

**Output:** true

**Explanation:**

A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is `true`.

**Example 2:**

**Input:** grid = [[1,3],[2,4]]

**Output:** false

**Explanation:**

No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is `false`.

**Constraints:**

* `1 <= m == grid.length <= 105`
* `1 <= n == grid[i].length <= 105`
* `2 <= m * n <= 105`
* `1 <= grid[i][j] <= 105`

---

## Solution & Editorial
# Intuition
To partition the grid into two sections with equal sums, the total sum of all elements in the grid must be even. If the total sum is odd, it is impossible to split it into two equal integer halves. If the sum is even, we simply need to check if there exists a horizontal cut (between rows) or a vertical cut (between columns) such that the sum of one section equals exactly half of the total sum.

# Approach
1. Calculate the total sum `s` of all elements in the grid. If `s % 2 != 0`, return `false` immediately.
2. **Horizontal Cut Check**: Iterate through each row, maintaining a running prefix sum `pre`. If `pre` equals `s / 2` and the current row is not the last row (ensuring non-empty sections), return `true`.
3. **Vertical Cut Check**: Iterate through each column, maintaining a running prefix sum `pre`. If `pre` equals `s / 2` and the current column is not the last column, return `true`.
4. If neither check succeeds, return `false`.

### Visual Trace (Example 1: grid = [[1,4],[2,3]])
- Total Sum `s` = 1 + 4 + 2 + 3 = 10. Target = 5.
- **Horizontal Check**:
  - Row 0: `pre` = 1 + 4 = 5. `pre * 2 == 10` is true. `i + 1 < m` (0 + 1 < 2) is true. Return `true`.

# Complexity
- Time complexity: $$O(M \times N)$$, where $M$ is the number of rows and $N$ is the number of columns. We traverse the grid once to calculate the total sum, once for horizontal checks, and once for vertical checks.
- Space complexity: $$O(1)$$, as we only use a few variables for tracking sums and indices, regardless of the grid size.

# Code
```cpp
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long s = 0;
        for (const auto& row : grid) {
            for (int x : row) {
                s += x;
            }
        }
        if (s % 2 != 0) {
            return false;
        }
        int m = grid.size(), n = grid[0].size();
        long long pre = 0;
        for (int i = 0; i < m; ++i) {
            for (int x : grid[i]) {
                pre += x;
            }
            if (pre * 2 == s && i + 1 < m) {
                return true;
            }
        }
        pre = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                pre += grid[i][j];
            }
            if (pre * 2 == s && j + 1 < n) {
                return true;
            }
        }
        return false;
    }
};
```
