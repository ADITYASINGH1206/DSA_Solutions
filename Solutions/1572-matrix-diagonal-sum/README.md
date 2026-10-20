# [1572. Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)
**Difficulty:** `Easy` | **Tags:** `array`, `matrix`

---

## Problem Description
Given a square matrix `mat`, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

**Example 1:**

```
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
```

**Example 2:**

```
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
```

**Example 3:**

```
Input: mat = [[5]]
Output: 5
```

**Constraints:**

* `n == mat.length == mat[i].length`
* `1 <= n <= 100`
* `1 <= mat[i][j] <= 100`

---

## Solution & Editorial
# Intuition
To calculate the diagonal sum of a square matrix, we observe that the primary diagonal consists of elements where the row index equals the column index (`mat[i][i]`), and the secondary diagonal consists of elements where the column index is `n - 1 - i` (`mat[i][n - 1 - i]`). The only potential overlap occurs at the center of the matrix when the dimension `n` is odd.

# Approach
1. Initialize `ans` to 0. Iterate through the matrix rows using index `i` from `0` to `n-1`.
2. In each iteration, add both the primary diagonal element `mat[i][i]` and the secondary diagonal element `mat[i][n - 1 - i]` to `ans`.
3. After the loop, check if the matrix dimension `m` is odd. If it is, the center element `mat[m/2][m/2]` was added twice (once for each diagonal). Subtract this element once to correct the sum.

### Visual Trace (Example 1: 3x3 Matrix)
| i | mat[i][i] | mat[i][2-i] | ans (running) |
|---|---|---|---|
| 0 | 1 | 3 | 4 |
| 1 | 5 | 5 | 14 |
| 2 | 9 | 7 | 30 |

*Correction*: Since `m=3` (odd), subtract `mat[1][1]` (5): `30 - 5 = 25`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the matrix. We perform a single pass over the rows.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int ans = 0;
        for(int i = 0;i<m;i++){
            ans += mat[i][i];
            ans += mat[i][m-i-1];
        }
        if(m%2){
            int mid = m/2;
            ans -= mat[mid][mid];
        }
        return ans;
    }
};
```
