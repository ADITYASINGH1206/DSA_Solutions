# [1727. Largest Submatrix With Rearrangements](https://leetcode.com/problems/largest-submatrix-with-rearrangements/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`, `matrix`

---

## Problem Description
You are given a binary matrix `matrix` of size `m x n`, and you are allowed to rearrange the **columns** of the `matrix` in any order.

Return *the area of the largest submatrix within* `matrix` *where **every** element of the submatrix is* `1` *after reordering the columns optimally.*

**Example 1:**

```
Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
```

**Example 2:**

```
Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
```

**Example 3:**

```
Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m * n <= 105`
* `matrix[i][j]` is either `0` or `1`.

---

## Solution & Editorial
# Intuition
To solve this problem, we observe that for any fixed row, the number of consecutive 1s ending at that row in each column acts like the height of a bar in a histogram. Since we can rearrange columns arbitrarily, we can sort these heights in non-increasing order to maximize the area of a rectangle formed by these bars.

# Approach
1. **Precompute Heights**: Iterate through the matrix row by row. If `matrix[i][j]` is 1, update it to `matrix[i-1][j] + 1`. This transforms the matrix into a collection of histogram heights for each row.
2. **Sort and Calculate**: For each row, sort the heights in descending order. By sorting, we ensure that for any width `w` (from 1 to `n`), we are using the `w` tallest available columns, which maximizes the area for that specific row.
3. **Maximize Area**: For each sorted row, iterate through the columns and calculate `(j + 1) * row[j]`, where `j + 1` is the width and `row[j]` is the minimum height among those columns.

### Visual Trace (Example 1)
`matrix = [[0,0,1],[1,1,1],[1,0,1]]`

1. **After height calculation:**
   Row 0: `[0, 0, 1]`
   Row 1: `[1, 1, 2]`
   Row 2: `[2, 0, 3]`

2. **Processing Row 2:**
   Sorted: `[3, 2, 0]`
   - `j=0`: `(0+1) * 3 = 3`
   - `j=1`: `(1+1) * 2 = 4`
   - `j=2`: `(2+1) * 0 = 0`
   Max area found: `4`

# Complexity
- Time complexity: $$O(M \cdot N \log N)$$, where $$M$$ is the number of rows and $$N$$ is the number of columns. We iterate through each row ($$M$$) and perform a sort ($$N \log N$$).
- Space complexity: $$O(1)$$ auxiliary space, as we modify the input matrix in-place.

# Code
```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (auto& row : matrix) {
            sort(row.rbegin(), row.rend());
            for (int j = 0; j < n; ++j) {
                ans = max(ans, (j + 1) * row[j]);
            }
        }
        return ans;
    }
};
```
