# [1621. Number of Sets of K Non-Overlapping Line Segments](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/)
**Difficulty:** `Medium` | **Tags:** `math`, `dynamic-programming`, `combinatorics`, `prefix-sum`

---

## Problem Description
Given `n` points on a 1-D plane, where the `ith` point (from `0` to `n-1`) is at `x = i`, find the number of ways we can draw **exactly** `k` **non-overlapping** line segments such that each segment covers two or more points. The endpoints of each segment must have **integral coordinates**. The `k` line segments **do not** have to cover all `n` points, and they are **allowed** to share endpoints.

Return *the number of ways we can draw* `k` *non-overlapping line segments**.* Since this number can be huge, return it **modulo** `109 + 7`.

**Example 1:**

```
Input: n = 4, k = 2
Output: 5
Explanation: The two line segments are shown in red and blue.
The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.
```

**Example 2:**

```
Input: n = 3, k = 1
Output: 3
Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.
```

**Example 3:**

```
Input: n = 30, k = 7
Output: 796297179
Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.
```

**Constraints:**

* `2 <= n <= 1000`
* `1 <= k <= n-1`

---

## Solution & Editorial
# Intuition
The problem asks for the number of ways to choose $k$ non-overlapping line segments from $n$ points. By transforming the problem into a stars and bars scenario, we can map the selection of segments to a selection of points. Specifically, choosing $k$ segments is equivalent to choosing $2k$ points out of $n$ points, where we allow segments to share endpoints. This is equivalent to choosing $2k$ items from $n+k-1$ available slots.

# Approach
1. **Mathematical Transformation**: The problem of selecting $k$ segments from $n$ points is equivalent to selecting $2k$ points from $n$ points with replacement allowed, or more simply, choosing $2k$ distinct points from a set of $n+k-1$ points. This is a classic combinatorial identity: $\binom{n+k-1}{2k}$.
2. **Combinatorial Calculation**: We compute the binomial coefficient $\binom{n+k-1}{2k} \pmod{10^9 + 7}$.
3. **Factorial Precomputation**: We precompute factorials and their modular inverses using Fermat's Little Theorem ($a^{MOD-2} \pmod{MOD}$) to compute the combination in $O(N)$ time.

### Visual Trace (n=4, k=2)
- Total points $n=4$, segments $k=2$.
- Formula: $\binom{4+2-1}{2 \times 2} = \binom{5}{4} = 5$.
- The 5 ways are: {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.

# Complexity
- Time complexity: $$O(N)$$ — We iterate up to $n+k$ to precompute factorials and perform modular exponentiation in $O(\log MOD)$.
- Space complexity: $$O(N)$$ — We store factorials and inverse factorials in vectors of size $n+k$.

# Code
```cpp
class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1)
                result = result * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }

    int numberOfSets(int n, int k) {
        int total = n + k - 1;
        int choose = 2 * k;

        vector<long long> fact(total + 1);
        vector<long long> invFact(total + 1);

        fact[0] = 1;

        for (int i = 1; i <= total; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[total] = power(fact[total], MOD - 2);

        for (int i = total; i > 0; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        return fact[total] * invFact[choose] % MOD
             * invFact[total - choose] % MOD;
    }
};
```
