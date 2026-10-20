# [3402. Minimum Operations to Make Columns Strictly Increasing](https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`, `matrix`

---

## Problem Description
You are given a `m x n` matrix `grid` consisting of **non-negative** integers.

In one operation, you can increment the value of any `grid[i][j]` by 1.

Return the **minimum** number of operations needed to make all columns of `grid` **strictly increasing**.

**Example 1:**

**Input:** grid = [[3,2],[1,3],[3,4],[0,1]]

**Output:** 15

**Explanation:**

* To make the `0th` column strictly increasing, we can apply 3 operations on `grid[1][0]`, 2 operations on `grid[2][0]`, and 6 operations on `grid[3][0]`.
* To make the `1st` column strictly increasing, we can apply 4 operations on `grid[3][1]`.

**Example 2:**

**Input:** grid = [[3,2,1],[2,1,0],[1,2,3]]

**Output:** 12

**Explanation:**

* To make the `0th` column strictly increasing, we can apply 2 operations on `grid[1][0]`, and 4 operations on `grid[2][0]`.
* To make the `1st` column strictly increasing, we can apply 2 operations on `grid[1][1]`, and 2 operations on `grid[2][1]`.
* To make the `2nd` column strictly increasing, we can apply 2 operations on `grid[1][2]`.

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `0 <= grid[i][j] < 2500`

```
 
```

---

## Solution & Editorial
# Intuition
To make each column strictly increasing, the value at `grid[j][i]` must be at least `grid[j-1][i] + 1`. Since we can only increment values, this is a local greedy problem: for every cell starting from the second row, we ensure it satisfies the condition relative to the cell immediately above it.

# Approach
1. Iterate through each column `i` from `0` to `n-1`.
2. For each column, iterate through rows `j` from `1` to `m-1`.
3. Compare `grid[j][i]` with `grid[j-1][i]`. If `grid[j][i] <= grid[j-1][i]`, the current cell is not strictly greater than the one above it.
4. Calculate the required increment: `diff = grid[j-1][i] - grid[j][i] + 1`.
5. Add `diff` to the total operations `ans` and update `grid[j][i]` to `grid[j-1][i] + 1` to maintain the strictly increasing property for subsequent rows.

### Visual Trace (Example 1: Column 0)
`grid = [[3,2],[1,3],[3,4],[0,1]]`

| Row (j) | grid[j][0] (Initial) | Condition (grid[j] > grid[j-1]) | Operations | grid[j][0] (Updated) |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 3 | - | 0 | 3 |
| 1 | 1 | 1 <= 3 (False) | 3 - 1 + 1 = 3 | 4 |
| 2 | 3 | 3 <= 4 (False) | 4 - 3 + 1 = 2 | 5 |
| 3 | 0 | 0 <= 5 (False) | 5 - 0 + 1 = 6 | 6 |

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ is the number of rows and $$N$$ is the number of columns. We visit each cell exactly once.
- Space complexity: $$O(1)$$, as we modify the input matrix in-place and use only a few integer variables.

# Code
```cpp
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m ==1) return 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[j-1][i] >= grid[j][i]){
                    ans += grid[j-1][i]-grid[j][i]+1;
                    grid[j][i]= grid[j-1][i]+1;
                }
            }
        }
        return ans;
    }
};
```
