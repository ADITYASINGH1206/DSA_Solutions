# [807. Max Increase to Keep City Skyline](https://leetcode.com/problems/max-increase-to-keep-city-skyline/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `matrix`

---

## Problem Description
There is a city composed of `n x n` blocks, where each block contains a single building shaped like a vertical square prism. You are given a **0-indexed** `n x n` integer matrix `grid` where `grid[r][c]` represents the **height** of the building located in the block at row `r` and column `c`.

A city's **skyline** is the outer contour formed by all the building when viewing the side of the city from a distance. The **skyline** from each cardinal direction north, east, south, and west may be different.

We are allowed to increase the height of **any number of buildings by any amount** (the amount can be different per building). The height of a `0`-height building can also be increased. However, increasing the height of a building should **not** affect the city's **skyline** from any cardinal direction.

Return *the **maximum total sum** that the height of the buildings can be increased by **without** changing the city's **skyline** from any cardinal direction*.

**Example 1:**

```
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: The building heights are shown in the center of the above image.
The skylines when viewed from each cardinal direction are drawn in red.
The grid after increasing the height of buildings without affecting skylines is:
gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]
```

**Example 2:**

```
Input: grid = [[0,0,0],[0,0,0],[0,0,0]]
Output: 0
Explanation: Increasing the height of any building will result in the skyline changing.
```

**Constraints:**

* `n == grid.length`
* `n == grid[r].length`
* `2 <= n <= 50`
* `0 <= grid[r][c] <= 100`

---

## Solution & Editorial
# Intuition
The core observation is that to keep the city skyline from the north, south, east, and west unchanged, the maximum height of a building at position `(i, j)` can at most be constrained by the maximum height in its row (`row_max`) and the maximum height in its column (`col_max`). Specifically, the new height of a building at `(i, j)` can be safely increased up to `min(row_max, col_max)` without altering any cardinal skyline view.

# Approach
1. Initialize `n` as the dimension of the square `grid` and create an `n x n` matrix `newGrid` to store the maximum allowed building heights.
2. Iterate through each cell `(i, j)` in the grid. For each cell, compute `col_max` by finding the maximum value across row `i`, and compute `row_max` by finding the maximum value down column `j`.
3. Assign `newGrid[i][j] = min(col_max, row_max)` as the maximum height the building at `(i, j)` can reach without affecting the skyline.
4. Iterate through the grid a second time to accumulate the total difference `newGrid[i][j] - grid[i][j]` into `ans`, representing the maximum total height increase.
5. Return `ans`.

### Visual Walkthrough (Example 1)
Given `grid = [[3, 0, 8, 4], [2, 4, 5, 7], [9, 2, 6, 3], [0, 3, 1, 0]]`, for cell `(0, 1)` where `grid[0][1] = 0`:
- Row 0 maximum (`col_max` in code logic): `max(3, 0, 8, 4) = 8`
- Column 1 maximum (`row_max` in code logic): `max(0, 4, 2, 3) = 4`
- `newGrid[0][1] = min(8, 4) = 4`
- Height increase for `(0, 1)`: `4 - 0 = 4`

# Complexity
- Time complexity: $$O(n^2)$$ — We iterate through each of the $$n^2$$ cells, and for each cell, we perform scanning operations of length $$n$$ for rows and columns, resulting in $$O(n^3)$$ or optimized $$O(n^2)$$ depending on precomputation (here implemented directly in nested loops yielding $$O(n^3)$$, which runs instantly for $$n \le 50$$).
- Space complexity: $$O(n^2)$$ — We allocate an auxiliary $$n \times n$$ matrix `newGrid` to store the updated building heights.

# Code
```cpp
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans =0;
        vector<vector<int>> newGrid(n,vector<int>(n));
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                int col_max =0,row_max =0;
                for(int x=0;x<n;x++){
                    col_max = max(col_max,grid[i][x]);
                }
                for(int y=0;y<n;y++){
                    row_max = max(row_max,grid[y][j]);
                }
                newGrid[i][j] = min(col_max,row_max);
            }
        }
        for(int i=0 ; i<n ;i++){
            for(int j=0;j<n;j++){
                ans+= newGrid[i][j]-grid[i][j];
            }
        }
        return ans;
    }
};
```
