# [2267.  Check if There Is a Valid Parentheses String Path](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`, `matrix`, `bracket-sequences`

---

## Problem Description
A parentheses string is a **non-empty** string consisting only of `'('` and `')'`. It is **valid** if **any** of the following conditions is **true**:

* It is `()`.
* It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid parentheses strings.
* It can be written as `(A)`, where `A` is a valid parentheses string.

You are given an `m x n` matrix of parentheses `grid`. A **valid parentheses string path** in the grid is a path satisfying **all** of the following conditions:

* The path starts from the upper left cell `(0, 0)`.
* The path ends at the bottom-right cell `(m - 1, n - 1)`.
* The path only ever moves **down** or **right**.
* The resulting parentheses string formed by the path is **valid**.

Return `true` *if there exists a **valid parentheses string path** in the grid.* Otherwise, return `false`.

**Example 1:**

```
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.
```

**Example 2:**

```
Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 100`
* `grid[i][j]` is either `'('` or `')'`.

---

## Solution & Editorial
# Intuition
To determine if a path forms a valid parentheses string, we must track the "balance" of parentheses (number of open minus number of closed) at each cell. A path is valid if the balance never drops below zero and ends exactly at zero. Since the path length is fixed at $m+n-1$, we can use dynamic programming to maintain the set of all possible balances reachable at each cell $(i, j)$.

# Approach
1. **State Representation**: We use a 2D array of `std::bitset<102>` where `dp[i][j]` stores all possible balances reachable at cell $(i, j)$. A bit at index $k$ is set if a balance of $k$ is possible.
2. **Transitions**: For each cell $(i, j)$, if the character is '(', the balance increases by 1. If ')', it decreases by 1. We shift the bitset accordingly: `(dp[i][j] << 1)` for '(', and `(dp[i][j] >> 1)` for ')'.
3. **Pruning**: If the balance ever becomes negative, that path is invalid. The bitset naturally handles this by shifting out negative indices. We also check parity: if the total path length $(m+n-1)$ is odd, it's impossible to form a valid string.
4. **Optimization**: Using `std::bitset` allows us to perform set updates for all possible balances in $O(1)$ (or $O((M+N)/64)$) time per cell, significantly outperforming a naive boolean DP table.

### Visual Trace (Example 1: 2x2 subset)
Grid: `[['(', '('], [')', ')']]`
- `dp[0][0]` starts with balance 1 (bit 1 set).
- Move to `(0, 1)`: `dp[0][1]` gets balance 2 (bit 2 set).
- Move to `(1, 0)`: `dp[1][0]` gets balance 0 (bit 0 set).
- Final `dp[1][1]` combines paths, checking if bit 0 is set.

# Complexity
- Time complexity: $$O(M \cdot N \cdot \frac{M+N}{64})$$ — We iterate over each cell $(M \times N)$ and perform bitset operations which take $O((M+N)/64)$ time.
- Space complexity: $$O(M \cdot N \cdot (M+N))$$ — We store a bitset of size $(M+N)$ for each cell in the grid.

# Code
```cpp
class Solution {
public:
    bool hasValidPath(auto& A) {
        int m = A.size(), n = A[0].size();

        if ((m + n - 1) & 1 || (A[0][0] & 1))
            return 0;

        vector dp(m + 1, vector<bitset<102>>(n + 1));
        dp[0][0].set(0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                auto b = (dp[i][j] << 1) >> ((A[i][j] & 1) << 1);

                dp[i + 1][j] |= b;
                dp[i][j + 1] |= b;
            }
        }

        return dp[m][n - 1].test(0);
    }
};
```
