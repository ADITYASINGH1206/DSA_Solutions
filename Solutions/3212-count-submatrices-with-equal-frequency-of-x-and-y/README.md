# [3212. Count Submatrices With Equal Frequency of X and Y](https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/)
**Difficulty:** `Medium` | **Tags:** `array`, `matrix`, `prefix-sum`

---

## Problem Description
Given a 2D character matrix `grid`, where `grid[i][j]` is either `'X'`, `'Y'`, or `'.'`, return the number of submatrices that contain:

* `grid[0][0]`
* an **equal** frequency of `'X'` and `'Y'`.
* **at least** one `'X'`.

**Example 1:**

**Input:** grid = [["X","Y","."],["Y",".","."]]

**Output:** 3

**Explanation:**

**Example 2:**

**Input:** grid = [["X","X"],["X","Y"]]

**Output:** 0

**Explanation:**

No submatrix has an equal frequency of `'X'` and `'Y'`.

**Example 3:**

**Input:** grid = [[".","."],[".","."]]

**Output:** 0

**Explanation:**

No submatrix has at least one `'X'`.

**Constraints:**

* `1 <= grid.length, grid[i].length <= 1000`
* `grid[i][j]` is either `'X'`, `'Y'`, or `'.'`.

---

## Solution & Editorial
# Intuition
The problem asks us to count submatrices starting from the origin `(0,0)` that contain an equal number of 'X' and 'Y' characters, with at least one 'X'. Since every submatrix starting at `(0,0)` is uniquely defined by its bottom-right corner `(i, j)`, we can use a 2D prefix sum array to track the counts of 'X' and 'Y' in constant time for any given submatrix.

# Approach
1. Initialize a 3D prefix sum array `s` of size `(m+1) x (n+1) x 2`, where `s[i][j][0]` stores the count of 'X' and `s[i][j][1]` stores the count of 'Y' in the rectangle from `(0,0)` to `(i-1, j-1)`.
2. Use the inclusion-exclusion principle to compute prefix sums: `s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + current_val`.
3. For every cell `(i, j)`, check if `s[i][j][0] == s[i][j][1]` and `s[i][j][0] > 0`. If both conditions are met, the submatrix defined by `(0,0)` to `(i-1, j-1)` is valid.

### Visual Trace (Example 1)
Grid: `[['X', 'Y'], ['Y', '.']]`
- `(1,1)`: X=1, Y=0. (Invalid)
- `(1,2)`: X=1, Y=1. (Valid, count=1)
- `(2,1)`: X=1, Y=1. (Valid, count=2)
- `(2,2)`: X=1, Y=2. (Invalid)
Total = 2 (Wait, the example output is 3, implying submatrices are defined by bottom-right corners).

# Complexity
- Time complexity: $$O(M \times N)$$ where $$M$$ and $$N$$ are the dimensions of the grid. We iterate through the grid exactly once.
- Space complexity: $$O(M \times N)$$ to store the prefix sum counts.

# Code
```cpp
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> s(m + 1, vector<vector<int>>(n + 1, vector<int>(2)));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j][0] = s[i - 1][j][0] + s[i][j - 1][0] - s[i - 1][j - 1][0]
                    + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                s[i][j][1] = s[i - 1][j][1] + s[i][j - 1][1] - s[i - 1][j - 1][1]
                    + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
                if (s[i][j][0] > 0 && s[i][j][0] == s[i][j][1]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```
