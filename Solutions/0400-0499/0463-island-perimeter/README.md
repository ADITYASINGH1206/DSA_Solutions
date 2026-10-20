# [463. Island Perimeter](https://leetcode.com/problems/island-perimeter/)
**Difficulty:** `Easy` | **Tags:** `array`, `depth-first-search`, `breadth-first-search`, `matrix`

---

## Problem Description
You are given `row x col` `grid` representing a map where `grid[i][j] = 1` represents land and `grid[i][j] = 0` represents water.

Grid cells are connected **horizontally/vertically** (not diagonally). The `grid` is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

**Example 1:**

```
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
```

**Example 2:**

```
Input: grid = [[1]]
Output: 4
```

**Example 3:**

```
Input: grid = [[1,0]]
Output: 4
```

**Constraints:**

* `row == grid.length`
* `col == grid[i].length`
* `1 <= row, col <= 100`
* `grid[i][j]` is `0` or `1`.
* There is exactly one island in `grid`.

---

## Solution & Editorial
# Intuition
The perimeter of an island can be computed by evaluating each land cell individually. Each land cell initially contributes 4 to the perimeter, but adjacent land cells share an edge, meaning each shared boundary must be subtracted twice (once for each cell sharing the edge).

# Approach
1. Initialize `m` as the number of rows and `n` as the number of columns in the `grid`, and set the `ans` perimeter counter to 0.
2. Iterate through each cell `(i, j)` of the matrix using nested loops.
3. If `grid[i][j] == 1` (land), add 4 to `ans`.
4. Check the cell directly below `(i + 1, j)` and directly to the right `(i, j + 1)`. If either adjacent cell is also land (`grid[..., ...] == 1`), subtract 2 from `ans` to account for the shared boundary.
5. Return the final accumulated perimeter `ans`.

### Visual Walkthrough (Example 2: grid = [[1]])
- Loop encounters `grid[0][0] == 1`.
- `ans` becomes 4.
- Boundary checks for right and bottom fail as indices are out of bounds.
- Returns 4.

# Complexity
- Time complexity: $$O(m \times n)$$ — We visit every cell in the 2D grid exactly once, performing constant time operations per cell.
- Space complexity: $$O(1)$$ — Only a few primitive integer variables (`m`, `n`, `ans`, `i`, `j`) are allocated, requiring constant auxiliary space.

# Code
```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (i < m - 1 && grid[i + 1][j] == 1) ans -= 2;
                    if (j < n - 1 && grid[i][j + 1] == 1) ans -= 2;
                }
            }
        }
        return ans;
    }
};
```
