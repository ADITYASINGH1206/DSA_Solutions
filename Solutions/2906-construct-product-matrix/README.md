# [2906. Construct Product Matrix](https://leetcode.com/problems/construct-product-matrix/)
**Difficulty:** `Medium` | **Tags:** `array`, `matrix`, `prefix-sum`

---

## Problem Description
Given a **0-indexed** 2D integer matrix `grid` of size `n * m`, we define a **0-indexed** 2D matrix `p` of size `n * m` as the **product** matrix of `grid` if the following condition is met:

* Each element `p[i][j]` is calculated as the product of all elements in `grid` except for the element `grid[i][j]`. This product is then taken modulo `12345`.

Return *the product matrix of* `grid`.

**Example 1:**

```
Input: grid = [[1,2],[3,4]]
Output: [[24,12],[8,6]]
Explanation: p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
So the answer is [[24,12],[8,6]].
```

**Example 2:**

```
Input: grid = [[12345],[2],[1]]
Output: [[2],[0],[0]]
Explanation: p[0][0] = grid[0][1] * grid[0][2] = 2 * 1 = 2.
p[0][1] = grid[0][0] * grid[0][2] = 12345 * 1 = 12345. 12345 % 12345 = 0. So p[0][1] = 0.
p[0][2] = grid[0][0] * grid[0][1] = 12345 * 2 = 24690. 24690 % 12345 = 0. So p[0][2] = 0.
So the answer is [[2],[0],[0]].
```

**Constraints:**

* `1 <= n == grid.length <= 105`
* `1 <= m == grid[i].length <= 105`
* `2 <= n * m <= 105`
* `1 <= grid[i][j] <= 109`

---

## Solution & Editorial
# Intuition
To compute the product of all elements except the current one efficiently, we can use the prefix and suffix product technique. By precomputing the product of all elements to the left and all elements to the right of each position, we can derive the result for any index `(i, j)` as `prefix_product[i][j] * suffix_product[i][j]`.

# Approach
1. Initialize a result matrix `p` of the same dimensions as `grid`.
2. Perform a backward pass: Iterate through the matrix from the last element to the first. Maintain a running `suf` product (modulo 12345) and store it in `p[i][j]`. This `p[i][j]` now holds the product of all elements appearing *after* `(i, j)` in row-major order.
3. Perform a forward pass: Iterate through the matrix from the first element to the last. Maintain a running `pre` product (modulo 12345). Update `p[i][j]` by multiplying it with the current `pre` value. This effectively combines the prefix and suffix products.

### Visual Trace (Example 1: grid = [[1, 2], [3, 4]])
- **Backward Pass (Suffixes):**
  - Start `suf = 1`
  - `p[1][1] = 1`, `suf = 1 * 4 = 4`
  - `p[1][0] = 4`, `suf = 4 * 3 = 12`
  - `p[0][1] = 12`, `suf = 12 * 2 = 24`
  - `p[0][0] = 24`, `suf = 24 * 1 = 24`
  - `p` becomes `[[24, 12], [4, 1]]`
- **Forward Pass (Prefixes):**
  - Start `pre = 1`
  - `p[0][0] = 24 * 1 = 24`, `pre = 1 * 1 = 1`
  - `p[0][1] = 12 * 1 = 12`, `pre = 1 * 2 = 2`
  - `p[1][0] = 4 * 2 = 8`, `pre = 2 * 3 = 6`
  - `p[1][1] = 1 * 6 = 6`, `pre = 6 * 4 = 24`
  - Final `p`: `[[24, 12], [8, 6]]`

# Complexity
- Time complexity: $$O(N \times M)$$, where $$N$$ and $$M$$ are the dimensions of the grid. We perform two linear passes over the matrix elements.
- Space complexity: $$O(N \times M)$$ to store the resulting product matrix.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        long long suf = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                p[i][j] = suf;
                suf = suf * grid[i][j] % mod;
            }
        }
        long long pre = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = p[i][j] * pre % mod;
                pre = pre * grid[i][j] % mod;
            }
        }
        return p;
    }
};
```
