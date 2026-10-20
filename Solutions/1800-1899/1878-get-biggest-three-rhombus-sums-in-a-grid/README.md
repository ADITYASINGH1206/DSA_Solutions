# [1878. Get Biggest Three Rhombus Sums in a Grid](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `sorting`, `heap-priority-queue`, `matrix`, `prefix-sum`

---

## Problem Description
You are given an `m x n` integer matrix `grid`​​​.

A **rhombus sum** is the sum of the elements that form **the** **border** of a regular rhombus shape in `grid`​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each **rhombus sum**:

Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return *the biggest three **distinct rhombus sums** in the* `grid` *in **descending order****. If there are less than three distinct values, return all of them*.

**Example 1:**

```
Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
```

**Example 2:**

```
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
```

**Example 3:**

```
Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `1 <= grid[i][j] <= 105`

---

## Solution & Editorial
# Intuition
To find the biggest rhombus sums, we must efficiently calculate the sum of elements along the borders of all possible rhombi. A rhombus is defined by its center $(i, j)$ and its size $k$. Since the grid size is small ($50 \times 50$), we can iterate through all possible centers and sizes, using diagonal prefix sums to calculate the border sum in $O(1)$ time per rhombus.

# Approach
1. **Diagonal Prefix Sums**: We precompute two 2D arrays, `s1` and `s2`. `s1[i][j]` stores the sum of elements along the diagonal from top-left to bottom-right, and `s2[i][j]` stores the sum along the diagonal from top-right to bottom-left. This allows us to compute the sum of any line segment on these diagonals in constant time.
2. **Iteration**: We iterate over every cell $(i, j)$ as a potential center and every possible radius $k$. 
3. **Sum Calculation**: For a center $(i, j)$ and radius $k$, the rhombus border consists of four segments. Using our prefix sum arrays, we calculate the sum of these segments. We subtract the corners to avoid double-counting.
4. **Tracking**: We use a `std::set` to store distinct sums. By keeping the set size at most 3, we ensure we only track the largest values. 

### Visual Trace (Example 2: 3x3 Grid)
- Center (1, 1), Radius 0: Sum = `grid[1][1]` = 5.
- Center (1, 1), Radius 1: Sum = `grid[0][1] + grid[1][0] + grid[1][2] + grid[2][1]` = 2 + 4 + 6 + 8 = 20.
- The set maintains the top 3 distinct values found during the traversal.

# Complexity
- Time complexity: $$O(M \cdot N \cdot \min(M, N))$$ where $M$ and $N$ are grid dimensions. We iterate over $M \times N$ centers and up to $\min(M, N)/2$ radii. Each sum calculation is $O(1)$.
- Space complexity: $$O(M \cdot N)$$ to store the prefix sum matrices `s1` and `s2`.

```cpp []
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> s1(m + 1, vector<int>(n + 2));
        vector<vector<int>> s2(m + 1, vector<int>(n + 2));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        set<int> ss;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int l = min({i - 1, m - i, j - 1, n - j});
                ss.insert(grid[i - 1][j - 1]);
                for (int k = 1; k <= l; ++k) {
                    int a = s1[i + k][j] - s1[i][j - k];
                    int b = s1[i][j + k] - s1[i - k][j];
                    int c = s2[i][j - k] - s2[i - k][j];
                    int d = s2[i + k][j] - s2[i][j + k];
                    ss.insert(a + b + c + d - grid[i + k - 1][j - 1] - grid[i - k - 1][j - 1] - grid[i - 1][j - k - 1] - grid[i - 1][j + k - 1]);
                }
                while (ss.size() > 3) {
                    ss.erase(ss.begin());
                }
            }
        }
        return vector<int>(ss.rbegin(), ss.rend());
    }
};
```

# Code
```cpp
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> s1(m + 1, vector<int>(n + 2));
        vector<vector<int>> s2(m + 1, vector<int>(n + 2));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        set<int> ss;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int l = min({i - 1, m - i, j - 1, n - j});
                ss.insert(grid[i - 1][j - 1]);
                for (int k = 1; k <= l; ++k) {
                    int a = s1[i + k][j] - s1[i][j - k];
                    int b = s1[i][j + k] - s1[i - k][j];
                    int c = s2[i][j - k] - s2[i - k][j];
                    int d = s2[i + k][j] - s2[i][j + k];
                    ss.insert(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
                }
                while (ss.size() > 3) {
                    ss.erase(ss.begin());
                }
            }
        }
        return vector<int>(ss.rbegin(), ss.rend());
    }
};
```
