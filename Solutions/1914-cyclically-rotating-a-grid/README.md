# [1914. Cyclically Rotating a Grid](https://leetcode.com/problems/cyclically-rotating-a-grid/)
**Difficulty:** `Medium` | **Tags:** `array`, `matrix`, `simulation`

---

## Problem Description
You are given an `m x n` integer matrix `grid`​​​, where `m` and `n` are both **even** integers, and an integer `k`.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

A cyclic rotation of the matrix is done by cyclically rotating **each layer** in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the **counter-clockwise** direction. An example rotation is shown below:

Return *the matrix after applying* `k` *cyclic rotations to it*.

**Example 1:**

```

Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]
Explanation: The figures above represent the grid at every state.
```

**Example 2:**

  

```

Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
Explanation: The figures above represent the grid at every state.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `2 <= m, n <= 50`
* Both `m` and `n` are **even** integers.
* `1 <= grid[i][j] <= 5000`
* `1 <= k <= 109`

---

## Solution & Editorial
# Intuition
The problem asks us to rotate concentric layers of a matrix independently. Since each layer is independent, we can decompose the matrix into its constituent rings, extract the elements of each ring into a linear array, perform the cyclic shift using modular arithmetic, and map the elements back to their new positions.

# Approach
1. Identify the number of layers: There are `min(m, n) / 2` layers in an `m x n` matrix.
2. For each layer `p` (where `p` ranges from `0` to `min(m, n)/2 - 1`):
   - Extract elements in counter-clockwise order: top row (left to right), right column (top to bottom), bottom row (right to left), and left column (bottom to top).
   - Store these in a linear vector `nums`.
   - Calculate the effective rotation `k % nums.size()` to handle large `k` values.
   - Re-assign the elements back into the grid by iterating through the same path, starting from the index `k` in the `nums` vector.

### Visual Trace (Example 1: 2x2 grid, k=1)
- Layer 0: `[40, 10, 20, 30]` (Top row, Right col, Bottom row, Left col)
- `k = 1 % 4 = 1`
- New order: `nums[1], nums[2], nums[3], nums[0]` -> `10, 20, 30, 40`
- Map back: `grid[0][0]=10, grid[0][1]=20, grid[1][1]=30, grid[1][0]=40`

# Complexity
- Time complexity: $$O(M \times N)$$. We visit each cell in the matrix exactly once to extract it into a linear array and once more to place it back into the grid.
- Space complexity: $$O(M \times N)$$. In the worst case, the outermost layer contains a significant fraction of the total elements, requiring auxiliary storage proportional to the number of elements in the layer, bounded by the total number of cells.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        auto rotate = [&](int p, int k) {
            vector<int> nums;
            for (int j = p; j < n - p - 1; ++j) {
                nums.push_back(grid[p][j]);
            }
            for (int i = p; i < m - p - 1; ++i) {
                nums.push_back(grid[i][n - p - 1]);
            }
            for (int j = n - p - 1; j > p; --j) {
                nums.push_back(grid[m - p - 1][j]);
            }
            for (int i = m - p - 1; i > p; --i) {
                nums.push_back(grid[i][p]);
            }
            int l = nums.size();
            k %= l;
            if (k == 0) {
                return;
            }
            for (int j = p; j < n - p - 1; ++j) {
                grid[p][j] = nums[k++ % l];
            }
            for (int i = p; i < m - p - 1; ++i) {
                grid[i][n - p - 1] = nums[k++ % l];
            }
            for (int j = n - p - 1; j > p; --j) {
                grid[m - p - 1][j] = nums[k++ % l];
            }
            for (int i = m - p - 1; i > p; --i) {
                grid[i][p] = nums[k++ % l];
            }
        };
        for (int p = 0; p < min(m, n) / 2; ++p) {
            rotate(p, k);
        }
        return grid;
    }
};
```
