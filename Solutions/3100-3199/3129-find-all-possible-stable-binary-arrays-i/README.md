# [3129. Find All Possible Stable Binary Arrays I](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/)
**Difficulty:** `Medium` | **Tags:** `dynamic-programming`, `prefix-sum`

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

The two possible stable binary arrays are `[1,0]` and `[0,1]`, as both arrays have a single 0 and a single 1, and no subarray has a length greater than 2.

**Example 2:**

**Input:** zero = 1, one = 2, limit = 1

**Output:** 1

**Explanation:**

The only possible stable binary array is `[1,0,1]`.

Note that the binary arrays `[1,1,0]` and `[0,1,1]` have subarrays of length 2 with identical elements, hence, they are not stable.

**Example 3:**

**Input:** zero = 3, one = 3, limit = 2

**Output:** 14

**Explanation:**

All the possible stable binary arrays are `[0,0,1,0,1,1]`, `[0,0,1,1,0,1]`, `[0,1,0,0,1,1]`, `[0,1,0,1,0,1]`, `[0,1,0,1,1,0]`, `[0,1,1,0,0,1]`, `[0,1,1,0,1,0]`, `[1,0,0,1,0,1]`, `[1,0,0,1,1,0]`, `[1,0,1,0,0,1]`, `[1,0,1,0,1,0]`, `[1,0,1,1,0,0]`, `[1,1,0,0,1,0]`, and `[1,1,0,1,0,0]`.

**Constraints:**

* `1 <= zero, one, limit <= 200`

---

## Solution & Editorial
# Intuition
The problem asks for the number of binary arrays with a fixed count of 0s and 1s such that no sequence of identical elements exceeds `limit`. This constraint implies that if we decide to place a 0, we can place between 1 and `limit` consecutive 0s. This structure suggests a dynamic programming approach where we track the current counts of 0s and 1s and the last placed element.

# Approach
1. Define `dp[i][j][k]` as the number of stable arrays using `i` zeros and `j` ones, ending with element `k` (where `k=0` for '0' and `k=1` for '1').
2. To compute `dp[i][j][0]`, we consider placing a block of `x` zeros (where `1 <= x <= limit`) after a sequence ending in 1. This leads to the recurrence: `dp[i][j][0] = sum(dp[i-x][j][1])` for `1 <= x <= limit`.
3. To optimize this from $O(N^3)$ to $O(N^2)$, we observe that `dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] - dp[i-limit-1][j][1]`. This sliding window sum allows us to compute the state in constant time using memoization.
4. Base cases: If `i=0`, we can only form a valid array if `j <= limit` and the last element was 1. Similarly for `j=0`.

### Visual Trace (zero=1, one=1, limit=2)
| State (i, j, k) | Calculation | Result |
| :--- | :--- | :--- |
| (1, 1, 0) | dp(0, 1, 1) | 1 |
| (1, 1, 1) | dp(1, 0, 0) | 1 |
| Total | (1, 1, 0) + (1, 1, 1) | 2 |

# Complexity
- Time complexity: $$O(zero \times one)$$ — Each state `(i, j, k)` is computed exactly once due to memoization, and each computation takes $O(1)$ time.
- Space complexity: $$O(zero \times one)$$ — We store the results in a 3D array of size `(zero+1) * (one+1) * 2`.

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
