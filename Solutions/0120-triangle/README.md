# [120. Triangle](https://leetcode.com/problems/triangle/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
Given a `triangle` array, return *the minimum path sum from top to bottom*.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.

**Example 1:**

```
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
```

**Example 2:**

```
Input: triangle = [[-10]]
Output: -10
```

**Constraints:**

* `1 <= triangle.length <= 200`
* `triangle[0].length == 1`
* `triangle[i].length == triangle[i - 1].length + 1`
* `-104 <= triangle[i][j] <= 104`

**Follow up:** Could you do this using only `O(n)` extra space, where `n` is the total number of rows in the triangle?

---

## Solution & Editorial
# Intuition
To find the minimum path sum from top to bottom, we can think of the problem in reverse. Instead of starting from the top and branching downwards, we can start from the bottom-most row and propagate the minimum path sums upward until we reach the top element. This allows us to optimize space complexity from $O(N^2)$ to $O(N)$.

# Approach
1. Initialize a 1D vector `dp` of size equal to the last row of the `triangle`, populated with the values of the last row (`triangle[n - 1]`).
2. Iterate backwards from the second-to-last row (`row = n - 2`) up to the top row (`row = 0`).
3. For each element at column `col` in the current `row`, update `dp[col]` by adding the current triangle value `triangle[row][col]` to the minimum of its two adjacent children from the row below: `min(dp[col], dp[col + 1])`.
4. After completing the loop, the top element `dp[0]` will hold the minimum path sum from top to bottom.

### Visual Walkthrough (Example 1)
`triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]`
- Initial `dp` (last row): `[4, 1, 8, 3]`
- Row 2 (`row = 2`, values `[6, 5, 7]`):
  - `col = 0`: `6 + min(4, 1) = 7`
  - `col = 1`: `5 + min(1, 8) = 6`
  - `col = 2`: `7 + min(8, 3) = 10`
  - Updated `dp`: `[7, 6, 10, 3]`
- Row 1 (`row = 1`, values `[3, 4]`):
  - `col = 0`: `3 + min(7, 6) = 9`
  - `col = 1`: `4 + min(6, 10) = 10`
  - Updated `dp`: `[9, 10, 10, 3]`
- Row 0 (`row = 0`, values `[2]`):
  - `col = 0`: `2 + min(9, 10) = 11`
  - Updated `dp`: `[11, 10, 10, 3]`
- Final Result: `dp[0] = 11`

# Complexity
- Time complexity: $$O(N^2)$$ where $$N$$ is the number of rows in the triangle. We visit each element of the triangle exactly once during the bottom-up traversal.
- Space complexity: $$O(N)$$ where $$N$$ is the number of rows (and size of the bottom row), as we only store a single 1D vector of size equal to the bottom row for our tabulation state.

# Code
```cpp
//Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        return dp[0];
    }
};

//DP
// class Solution {
// public:
//     int dp(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& memo) {
//         if (row == triangle.size() - 1) {
//             return triangle[row][col];
//         }

//         if (memo[row][col] != -1) {
//             return memo[row][col];
//         }
//         int down = dp(row + 1, col, triangle, memo);
//         int downRight = dp(row + 1, col + 1, triangle, memo);

//         return memo[row][col] = triangle[row][col] + min(down, downRight);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         vector<vector<int>> memo(m,vector<int>(m,-1));
//         return dp(0,0,triangle,memo);
//     }
// };
```
