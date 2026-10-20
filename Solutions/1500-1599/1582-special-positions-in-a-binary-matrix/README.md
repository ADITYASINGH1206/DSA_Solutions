# [1582. Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)
**Difficulty:** `Easy` | **Tags:** `array`, `matrix`

---

## Problem Description
Given an `m x n` binary matrix `mat`, return *the number of special positions in* `mat`*.*

A position `(i, j)` is called **special** if `mat[i][j] == 1` and all other elements in row `i` and column `j` are `0` (rows and columns are **0-indexed**).

**Example 1:**

```
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
```

**Example 2:**

```
Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
```

**Constraints:**

* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 100`
* `mat[i][j]` is either `0` or `1`.

---

## Solution & Editorial
# Intuition
A position (i, j) is special if it contains a 1 and is the only 1 in its row and column. By pre-calculating the sum of each row and each column, we can determine if a cell is special in constant time by checking if the cell value is 1 and both its row sum and column sum are exactly 1.

# Approach
1. Initialize two vectors, `rows` of size `m` and `cols` of size `n`, to store the sum of elements for each row and column respectively.
2. Iterate through the matrix once to populate these vectors. `rows[i]` will hold the count of 1s in row `i`, and `cols[j]` will hold the count of 1s in column `j`.
3. Iterate through the matrix a second time. For every cell `mat[i][j]`, check if `mat[i][j] == 1`, `rows[i] == 1`, and `cols[j] == 1`. If all conditions are met, increment the answer counter.

### Visual Trace (Example 1: mat = [[1,0,0],[0,0,1],[1,0,0]])
- `rows` = [1, 1, 1]
- `cols` = [2, 0, 1]
- Check (0,0): mat=1, rows[0]=1, cols[0]=2 -> False
- Check (1,2): mat=1, rows[1]=1, cols[2]=1 -> True (ans=1)
- Check (2,0): mat=1, rows[2]=1, cols[0]=2 -> False

# Complexity
- Time complexity: $$O(m \times n)$$, where $$m$$ is the number of rows and $$n$$ is the number of columns. We traverse the matrix twice.
- Space complexity: $$O(m + n)$$ to store the row and column sums.

# Code
```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rows(m);
        vector<int> cols(n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
```
