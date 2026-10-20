# [733. Flood Fill](https://leetcode.com/problems/flood-fill/)
**Difficulty:** `Easy` | **Tags:** `array`, `depth-first-search`, `breadth-first-search`, `matrix`

---

## Problem Description
You are given an image represented by an `m x n` grid of integers `image`, where `image[i][j]` represents the pixel value of the image. You are also given three integers `sr`, `sc`, and `color`. Your task is to perform a **flood fill** on the image starting from the pixel `image[sr][sc]`.

To perform a **flood fill**:

1. Begin with the starting pixel and change its color to `color`.
2. Perform the same process for each pixel that is **directly adjacent** (pixels that share a side with the original pixel, either horizontally or vertically) and shares the **same color** as the starting pixel.
3. Keep **repeating** this process by checking neighboring pixels of the *updated* pixels and modifying their color if it matches the original color of the starting pixel.
4. The process **stops** when there are **no more** adjacent pixels of the original color to update.

Return the **modified** image after performing the flood fill.

**Example 1:**

**Input:** image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

**Output:** [[2,2,2],[2,2,0],[2,0,1]]

**Explanation:**

From the center of the image with position `(sr, sc) = (1, 1)` (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is **not** colored 2, because it is not horizontally or vertically connected to the starting pixel.

**Example 2:**

**Input:** image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

**Output:** [[0,0,0],[0,0,0]]

**Explanation:**

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

**Constraints:**

* `m == image.length`
* `n == image[i].length`
* `1 <= m, n <= 50`
* `0 <= image[i][j], color < 216`
* `0 <= sr < m`
* `0 <= sc < n`

---

## Solution & Editorial
# Intuition
The problem requires us to traverse a connected component of pixels starting from `(sr, sc)` and replace their color with a new one. A Depth-First Search (DFS) approach naturally fits graph and grid traversal problems. We can explore all four adjacent directions (up, down, left, right) recursively from the starting pixel, provided they share the original color (`oldColor`).

# Approach
1. Store the initial color of the starting pixel `image[sr][sc]` into a variable `oldColor`.
2. Check if `oldColor` is equal to the target `color`. If it is, no changes are needed, and we can immediately return the original image to prevent infinite recursion.
3. Define a recursive helper function `dfs(r, c, image, oldColor, newColor)`:
   - Check boundary conditions (`r < 0`, `c < 0`, `r >= n`, `c >= m`) and verify if `image[r][c] == oldColor`. If any condition fails, return.
   - Update the current pixel `image[r][c] = newColor`.
   - Recursively call `dfs` for all four neighbors: `(r - 1, c)`, `(r + 1, c)`, `(r, c - 1)`, and `(r, c + 1)`.
4. Call `dfs` from the starting coordinates `(sr, sc)` and return the modified `image`.

### Visual Walkthrough for Example 1
`image = [[1,1,1],[1,1,0],[1,0,1]]`, `sr = 1`, `sc = 1`, `color = 2`
- `oldColor = image[1][1] = 1`. Since `1 != 2`, we proceed.
- `dfs(1, 1)` updates `image[1][1] = 2` and branches out to its 4 neighbors:
  - `dfs(0, 1)`: updates `image[0][1] = 2` -> recursively reaches `(0,0)` and `(0,2)`, updating both to `2`.
  - `dfs(2, 1)`: encounters `image[2][1] = 0`, which does not equal `oldColor` (1), so it returns immediately.
  - `dfs(1, 0)`: updates `image[1][0] = 2` -> recursively reaches `(2,0)` updating it to `2`.
  - `dfs(1, 2)`: encounters `image[1][2] = 0`, so it returns immediately.
- Final modified image becomes `[[2,2,2],[2,2,0],[2,0,1]]`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the total number of pixels in the grid ($$m \times n$$). In the worst-case scenario, every pixel in the grid is visited once.
- Space complexity: $$O(N)$$ in the worst-case scenario due to the recursive call stack when the grid is entirely filled with pixels of the same color.

# Code
```cpp
class Solution {
public:

    void dfs(int r, int c,vector<vector<int>>& image,int oldColor,int newColor) {
        int n = image.size();
        int m = image[0].size();

        if(r < 0 || c < 0 ||r >= n || c >= m ||image[r][c] != oldColor) return;

        image[r][c] = newColor;

        dfs(r - 1, c, image, oldColor, newColor);
        dfs(r + 1, c, image, oldColor, newColor);
        dfs(r, c - 1, image, oldColor, newColor);
        dfs(r, c + 1, image, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color)
            return image;
        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};
```
