# [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
**Difficulty:** `Easy` | **Tags:** `math`, `dynamic-programming`, `recursion`, `memoization`

---

## Problem Description
The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given `n`, calculate `F(n)`.

**Example 1:**

```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

**Example 2:**

```
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

**Example 3:**

```
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

**Constraints:**

* `0 <= n <= 30`

---

## Solution & Editorial
# Intuition
The Fibonacci sequence is defined recursively, but naive recursion results in redundant overlapping subproblems with exponential time complexity. By introducing a memoization table (`dp`), we store the results of solved states and eliminate redundant computations, reducing the time complexity to linear.

# Approach
1. In the `fib` function, initialize a memoization vector `dp` of size `n + 1` filled with `-1` to represent uncomputed states.
2. Pass `n` and `dp` to the helper function `f(int n, vector<int>& dp)`.
3. Base Case: If `n <= 1`, return `n` directly since $F(0) = 0$ and $F(1) = 1$.
4. Memoization Check: If `dp[n] != -1`, return the already computed result `dp[n]`.
5. Recursive Step: Compute `dp[n] = f(n - 1, dp) + f(n - 2, dp)`, store it, and return the result.

### Visual Trace (Example 1: n = 2)
- `fib(2)` initializes `dp` of size 3 as `[-1, -1, -1]`, calls `f(2, dp)`.
- `f(2)` checks `dp[2] == -1`, splits into `f(1)` + `f(0)`.
- `f(1)` returns `1` (base case).
- `f(0)` returns `0` (base case).
- `f(2)` computes `1 + 0 = 1`, stores `dp[2] = 1`, and returns `1`.

# Complexity
- Time complexity: $$O(N)$$ — Each state from `0` to `N` is computed exactly once due to memoization.
- Space complexity: $$O(N)$$ — The `dp` vector requires $$O(N)$$ space, and the recursion call stack goes up to a maximum depth of $$N$$.

# Code
```cpp
class Solution {
public:
    int f(int n,vector<int>& dp){
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = f(n-1,dp) + f(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans = f(n,dp);

        return ans;
    }
};
```
