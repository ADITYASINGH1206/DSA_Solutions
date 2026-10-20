# [2946. Matrix Similarity After Cyclic Shifts](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `matrix`, `simulation`

---

## Problem Description
You are given an `m x n` integer matrix `mat` and an integer `k`. The matrix rows are 0-indexed.

The following process happens `k` times:

* **Even-indexed** rows (0, 2, 4, ...) are cyclically shifted to the left.

* **Odd-indexed** rows (1, 3, 5, ...) are cyclically shifted to the right.

Return `true` if the final modified matrix after `k` steps is identical to the original matrix, and `false` otherwise.

**Example 1:**

**Input:** mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4

**Output:** false

**Explanation:**

In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).

**Example 2:**

**Input:** mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2

**Output:** true

**Explanation:**

**Example 3:**

**Input:** mat = [[2,2],[2,2]], k = 3

**Output:** true

**Explanation:**

As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.

**Constraints:**

* `1 <= mat.length <= 25`
* `1 <= mat[i].length <= 25`
* `1 <= mat[i][j] <= 25`
* `1 <= k <= 50`

---

## Solution & Editorial
# Intuition
The problem asks whether a matrix remains identical after $k$ cyclic shifts. Since cyclic shifts are periodic with period $n$ (the number of columns), shifting by $k$ is equivalent to shifting by $k \pmod n$. Instead of simulating the shifts, we can directly verify if each element at index $j$ matches the element that would occupy that position after the shift.

# Approach
1. Normalize $k$ by taking $k \pmod n$. This reduces the number of operations significantly.
2. For each row $i$ and column $j$:
   - If $i$ is odd, the row is shifted right by $k$. The element at `mat[i][j]` must equal the element that was originally at `(j - k + n) % n` to satisfy the condition. Equivalently, we check if `mat[i][j] == mat[i][(j + k) % n]`.
   - If $i$ is even, the row is shifted left by $k$. The element at `mat[i][j]` must equal the element that was originally at `(j + k) % n`.
3. If any mismatch is found, return `false`. If the loops complete, return `true`.

### Visual Trace (Example 1: mat = [[1,2,3]], k = 4, n = 3)
- $k = 4 \pmod 3 = 1$.
- Row 0 (Even): Left shift by 1. `mat[0][j]` should equal `mat[0][(j + 1) % 3]`.
- $j=0: 1 \neq 2$ (False).

# Complexity
- Time complexity: $$O(m \times n)$$, where $m$ is the number of rows and $n$ is the number of columns. We iterate through every element exactly once.
- Space complexity: $$O(1)$$, as we perform the check in-place without allocating extra memory.

# Code
```cpp
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i % 2 == 1 && mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
                if (i % 2 == 0 && mat[i][j] != mat[i][(j - k + n) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
