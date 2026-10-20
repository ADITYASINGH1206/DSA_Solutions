# [3130. Find All Possible Stable Binary Arrays II](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/)
**Difficulty:** `Hard` | **Tags:** `dynamic-programming`, `prefix-sum`

---

## Problem Description
You are given 3 positive integers `num_zeros`, `num_ones`, and `limit`.

A binary array `arr` is called **stable** if:

* The number of occurrences of 0 in `arr` is **exactly** `num_zeros`.
* The number of occurrences of 1 in `arr` is **exactly** `num_ones`.
* Each subarray of `arr` with a size greater than `limit` must contain **at least** one occurrence of **both** 0 and 1.

Return an integer denoting the *total* number of **stable** binary arrays.

Since the answer may be very large, return it **modulo** `109 + 7`.

**Example 1:**

**Input:** zero = 1, one = 1, limit = 2

**Output:** 2

**Explanation:**

The two possible stable binary arrays are `[1,0]` and `[0,1]`.

**Example 2:**

**Input:** zero = 1, one = 2, limit = 1

**Output:** 1

**Explanation:**

The only possible stable binary array is `[1,0,1]`.

**Example 3:**

**Input:** zero = 3, one = 3, limit = 2

**Output:** 14

**Explanation:**

All the possible stable binary arrays are `[0,0,1,0,1,1]`, `[0,0,1,1,0,1]`, `[0,1,0,0,1,1]`, `[0,1,0,1,0,1]`, `[0,1,0,1,1,0]`, `[0,1,1,0,0,1]`, `[0,1,1,0,1,0]`, `[1,0,0,1,0,1]`, `[1,0,0,1,1,0]`, `[1,0,1,0,0,1]`, `[1,0,1,0,1,0]`, `[1,0,1,1,0,0]`, `[1,1,0,0,1,0]`, and `[1,1,0,1,0,0]`.

**Constraints:**

* `1 <= zero, one, limit <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks us to count binary arrays with exactly `zero` zeros and `one` ones such that no sequence of identical digits exceeds `limit`. This is a classic dynamic programming problem where the state depends on the remaining counts of zeros and ones, and the last digit placed. To optimize the transition, we observe that adding a digit of the same type as the previous one is constrained by `limit`, which can be efficiently handled using prefix sums or sliding window subtraction.

# Approach
1. Define `dp[i][j][k]` as the number of stable arrays using `i` zeros and `j` ones, ending with digit `k` (0 or 1).
2. To calculate `dp[i][j][0]`, we can append a 0 to any valid sequence of length `(i-1, j)`. However, we must exclude cases where the sequence of 0s exceeds `limit`. This is done by subtracting the count of sequences that ended in 1 at `(i - limit - 1, j)`.
3. The recurrence relation is:
   - `dp[i][j][0] = sum(dp[i-1][j][0], dp[i-1][j][1]) - dp[i-limit-1][j][1]`
   - `dp[i][j][1] = sum(dp[i][j-1][0], dp[i][j-1][1]) - dp[i][j-limit-1][0]`
4. We use memoization to store results, ensuring each state is computed once.

### Visual Trace (zero=1, one=1, limit=2)
- `dfs(1, 1, 0)`: Ends in 0. Can be `[1, 0]`. Result: 1.
- `dfs(1, 1, 1)`: Ends in 1. Can be `[0, 1]`. Result: 1.
- Total: `dfs(1, 1, 0) + dfs(1, 1, 1) = 2`.

# Complexity
- Time complexity: $$O(zero \times one)$$. Each state `(i, j, k)` is computed exactly once, and transitions are $O(1)$ due to the sliding window subtraction.
- Space complexity: $$O(zero \times one)$$ to store the memoization table.

# Code
```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        using ll = long long;
        vector<vector<array<ll, 2>>> f = vector<vector<array<ll, 2>>>(zero + 1, vector<array<ll, 2>>(one + 1, {-1, -1}));
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> ll {
            if (i < 0 || j < 0) {
                return 0;
            }
            if (i == 0) {
                return k == 1 && j <= limit;
            }
            if (j == 0) {
                return k == 0 && i <= limit;
            }
            ll& res = f[i][j][k];
            if (res != -1) {
                return res;
            }
            if (k == 0) {
                res = (dfs(i - 1, j, 0) + dfs(i - 1, j, 1) - dfs(i - limit - 1, j, 1) + mod) % mod;
            } else {
                res = (dfs(i, j - 1, 0) + dfs(i, j - 1, 1) - dfs(i, j - limit - 1, 0) + mod) % mod;
            }
            return res;
        };
        return (dfs(zero, one, 0) + dfs(zero, one, 1)) % mod;
    }
};
```
