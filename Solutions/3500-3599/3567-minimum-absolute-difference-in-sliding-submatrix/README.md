# [3567. Minimum Absolute Difference in Sliding Submatrix](https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/)
**Difficulty:** `Medium` | **Tags:** `array`, `sorting`, `matrix`

---

## Problem Description
You are given an `m x n` integer matrix `grid` and an integer `k`.

For every contiguous `k x k` **submatrix** of `grid`, compute the **minimum absolute** difference between any two **distinct** values within that **submatrix**.

Return a 2D array `ans` of size `(m - k + 1) x (n - k + 1)`, where `ans[i][j]` is the minimum absolute difference in the submatrix whose top-left corner is `(i, j)` in `grid`.

**Note**: If all elements in the submatrix have the same value, the answer will be 0.

A submatrix `(x1, y1, x2, y2)` is a matrix that is formed by choosing all cells `matrix[x][y]` where `x1 <= x <= x2` and `y1 <= y <= y2`.

**Example 1:**

**Input:** grid = [[1,8],[3,-2]], k = 2

**Output:** [[2]]

**Explanation:**

* There is only one possible `k x k` submatrix: `[[1, 8], [3, -2]]`.
* Distinct values in the submatrix are `[1, 8, 3, -2]`.
* The minimum absolute difference in the submatrix is `|1 - 3| = 2`. Thus, the answer is `[[2]]`.

**Example 2:**

**Input:** grid = [[3,-1]], k = 1

**Output:** [[0,0]]

**Explanation:**

* Both `k x k` submatrix has only one distinct element.
* Thus, the answer is `[[0, 0]]`.

**Example 3:**

**Input:** grid = [[1,-2,3],[2,3,5]], k = 2

**Output:** [[1,2]]

**Explanation:**

* There are two possible `k × k` submatrix:
  + Starting at `(0, 0)`: `[[1, -2], [2, 3]]`.
    - Distinct values in the submatrix are `[1, -2, 2, 3]`.
    - The minimum absolute difference in the submatrix is `|1 - 2| = 1`.
  + Starting at `(0, 1)`: `[[-2, 3], [3, 5]]`.
    - Distinct values in the submatrix are `[-2, 3, 5]`.
    - The minimum absolute difference in the submatrix is `|3 - 5| = 2`.
* Thus, the answer is `[[1, 2]]`.

**Constraints:**

* `1 <= m == grid.length <= 30`
* `1 <= n == grid[i].length <= 30`
* `-105 <= grid[i][j] <= 105`
* `1 <= k <= min(m, n)`

---

## Solution & Editorial
# Intuition
Given the constraints (M, N <= 30), a brute-force approach is highly efficient. For every possible $k \times k$ submatrix, we can extract all elements, sort them, and find the minimum difference between adjacent distinct elements.

# Approach
1. Iterate through every possible top-left corner $(i, j)$ of a $k \times k$ submatrix, where $0 \le i \le m-k$ and $0 \le j \le n-k$.
2. For each submatrix, collect all $k^2$ elements into a temporary vector `nums`.
3. Sort `nums` in non-decreasing order.
4. Iterate through the sorted `nums` and calculate the absolute difference between adjacent elements. If `nums[t] != nums[t-1]`, update the minimum difference `d`.
5. If all elements are identical, the difference remains `INT_MAX` (or effectively 0 as per problem requirements).

### Visual Trace (Example 1: grid = [[1,8],[3,-2]], k = 2)
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Extract submatrix at (0,0) | `nums = [1, 8, 3, -2]` |
| 2 | Sort `nums` | `nums = [-2, 1, 3, 8]` |
| 3 | Compare adjacent | `|-2-1|=3, |1-3|=2, |3-8|=5` |
| 4 | Min difference | `d = 2` |

# Complexity
- Time complexity: $$O((M-K+1)(N-K+1) \cdot K^2 \log(K^2))$$ — We iterate over $(M-K+1)(N-K+1)$ submatrices. For each, we collect $K^2$ elements and sort them, taking $O(K^2 \log(K^2))$. Given $M, N \le 30$, this is well within limits.
- Space complexity: $$O(K^2)$$ — We store $K^2$ elements in the `nums` vector for each submatrix calculation.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                vector<int> nums;
                for (int x = i; x < i + k; ++x) {
                    for (int y = j; y < j + k; ++y) {
                        nums.push_back(grid[x][y]);
                    }
                }
                sort(nums.begin(), nums.end());
                int d = INT_MAX;
                for (int t = 1; t < nums.size(); ++t) {
                    if (nums[t] != nums[t - 1]) {
                        d = min(d, abs(nums[t] - nums[t - 1]));
                    }
                }
                ans[i][j] = (d == INT_MAX) ? 0 : d;
            }
        }
        return ans;
    }
};
```
