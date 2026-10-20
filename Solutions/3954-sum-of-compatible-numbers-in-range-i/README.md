# [3954. Sum of Compatible Numbers in Range I](https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/)
**Difficulty:** `Easy` | **Tags:** `dynamic-programming`, `bit-manipulation`, `enumeration`

---

## Problem Description
You are given two integers `n` and `k`.

A **positive** integer `x` is called **compatible** if it satisfies both of the following conditions:

* `abs(n - x) <= k`
* `(n & x) == 0`

Return the sum of all **compatible** integers `x`.

**Note**:

* Here, `&` denotes the **bitwise AND** operator.
* The **absolute** difference between integers `i` and `j` is defined as `abs(i - j)`.

**Example 1:**

**Input:** n = 2, k = 3

**Output:** 10

**Explanation:**

The compatible integers are:

* `x = 1`, since `abs(2 - 1) = 1` and `2 & 1 = 0`.
* `x = 4`, since `abs(2 - 4) = 2` and `2 & 4 = 0`.
* `x = 5`, since `abs(2 - 5) = 3` and `2 & 5 = 0`.

Thus, the answer is `1 + 4 + 5 = 10`.

**Example 2:**

**Input:** n = 5, k = 1

**Output:** 0

**Explanation:**

There are no compatible integers in the range `[4, 6]`. Thus, the answer is 0.

**Constraints:**

* `1 <= n <= 100`
* `1 <= k <= 100`

---

## Solution & Editorial
# Intuition
Since the constraints on $n$ and $k$ are very small ($n, k \le 100$), the range of potential integers $x$ that satisfy $|n - x| \le k$ is bounded within $[n-k, n+k]$. We can directly iterate through this range and verify the two conditions for each integer.

# Approach
1. Define the search range for $x$ as $[max(1, n-k), n+k]$. We use $max(1, n-k)$ because the problem specifies $x$ must be a positive integer.
2. For each integer $i$ in this range, check the two conditions:
   - $|n - i| \le k$ (implicitly satisfied by the loop bounds).
   - $(n \& i) == 0$ (bitwise AND condition).
3. Accumulate the sum of all $i$ that satisfy the bitwise condition.

### Visual Trace (n=2, k=3)
Range: $[max(1, 2-3), 2+3] = [1, 5]$

| $i$ | $|2-i| \le 3$ | $2 \& i == 0$ | Action |
|---|---|---|---|
| 1 | True | $0010 \& 0001 = 0$ | Add 1 |
| 2 | True | $0010 \& 0010 = 2$ | Skip |
| 3 | True | $0010 \& 0011 = 2$ | Skip |
| 4 | True | $0010 \& 0100 = 0$ | Add 4 |
| 5 | True | $0010 \& 0101 = 0$ | Add 5 |

Total Sum: $1 + 4 + 5 = 10$.

# Complexity
- Time complexity: $$O(k)$$, as we iterate through a range of size at most $2k+1$.
- Space complexity: $$O(1)$$, as we only use a single integer variable for the accumulator.

# Code
```cpp
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans=0;
        for(int i=max(1,n-k);i<=n+k;i++){
            if((n&i)==0)ans+=i;
        }
        return ans;
    }
};
```
