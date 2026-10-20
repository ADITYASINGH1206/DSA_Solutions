# [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
**Difficulty:** `Easy` | **Tags:** `math`, `dynamic-programming`, `memoization`

---

## Problem Description
You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

**Example 1:**

```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2:**

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

**Constraints:**

* `1 <= n <= 45`

---

## Solution & Editorial
# Intuition
The problem asks for the number of distinct ways to climb a staircase of `n` steps, given that we can take either `1` or `2` steps at a time. This naturally exhibits optimal substructure and overlapping subproblems: to reach step `i`, we must have come from either step `i-1` (by taking 1 step) or step `i-2` (by taking 2 steps). Thus, the total ways to reach step `i` is the sum of ways to reach step `i-1` and step `i-2`, which is identical to the Fibonacci sequence.

# Approach
1. Handle base cases where `n == 0` or `n == 1` by returning `1` directly since there is only 1 way to stay or take a single step.
2. Initialize a dynamic programming table `dp` of size `n + 1` to store the number of ways to reach each step from `0` to `n`.
3. Set base states `dp[0] = 1` and `dp[1] = 1`.
4. Iterate from `i = 2` to `n`, updating `dp[i] = dp[i-1] + dp[i-2]` at each step.
5. Return the final result stored in `dp[n]`.

### Visual Walkthrough for $n = 3$

| Step `i` | `dp[i]` Calculation | `dp` Array State | Explanation |
| :--- | :--- | :--- | :--- |
| 0 | Base Case | `[1, 1, 0, 0]` | Start position |
| 1 | Base Case | `[1, 1, 0, 0]` | 1 step |
| 2 | `dp[1] + dp[0]` ($1 + 1$) | `[1, 1, 2, 0]` | Reaching step 2 |
| 3 | `dp[2] + dp[1]` ($2 + 1$) | `[1, 1, 2, 3]` | Reaching step 3 (Target) |

# Complexity
- Time complexity: $$O(n)$$ — A single loop runs from `2` to `n`, performing constant time addition at each iteration.
- Space complexity: $$O(n)$$ — An auxiliary vector `dp` of size `n + 1` is allocated to store the subproblem results.

# Code
```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
```
