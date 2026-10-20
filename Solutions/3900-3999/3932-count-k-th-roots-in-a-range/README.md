# [3932. Count K-th Roots in a Range](https://leetcode.com/problems/count-k-th-roots-in-a-range/)
**Difficulty:** `Medium` | **Tags:** `math`, `binary-search`

---

## Problem Description
You are given three integers `l`, `r`, and `k`.

An integer `y` is said to be a **perfect kth power** if there exists an integer `x` such that `y = xk`.

Return the number of integers `y` in the range `[l, r]` (inclusive) that are **perfect kth powers**.

**Example 1:**

**Input:** l = 1, r = 9, k = 3

**Output:** 2

**Explanation:**

The perfect cubes in the range `[1, 9]` are:

* `1 = 13`
* `8 = 23`

Hence, the answer is 2.

**Example 2:**

**Input:** l = 8, r = 30, k = 2

**Output:** 3

**Explanation:**

The perfect squares in the range `[8, 30]` are:

* `9 = 32`
* `16 = 42`
* `25 = 52`

Hence, the answer is 3.

**Constraints:**

* `0 <= l <= r <= 109`
* `1 <= k <= 30`

---

## Solution & Editorial
# Intuition
To find the number of perfect $k^{th}$ powers in the range $[l, r]$, we need to identify the range of integers $[x_{min}, x_{max}]$ such that $l \le x^k \le r$. This is equivalent to finding the range of integers $x$ such that $\sqrt[k]{l} \le x \le \sqrt[k]{r}$.

# Approach
1. Calculate the lower bound $x_{min} = \lceil \sqrt[k]{l} \rceil$. We use `pow(l, 1.0/k)` and subtract a small epsilon (`1e-9`) before applying `ceil` to handle floating-point precision errors.
2. Calculate the upper bound $x_{max} = \lfloor \sqrt[k]{r} \rfloor$. We use `pow(r, 1.0/k)` and add a small epsilon (`1e-9`) before applying `floor` to ensure values like $2.9999999999$ correctly round to $3$.
3. The count of integers in the range $[x_{min}, x_{max}]$ is given by $x_{max} - x_{min} + 1$. If $x_{min} > x_{max}$, the count is 0.

### Visual Trace (Example 2: l=8, r=30, k=2)
| Variable | Calculation | Result |
| :--- | :--- | :--- |
| `l_min` | `ceil(pow(8, 0.5) - 1e-9)` | `ceil(2.828 - 1e-9)` = 3 |
| `r_max` | `floor(pow(30, 0.5) + 1e-9)` | `floor(5.477 + 1e-9)` = 5 |
| `ans` | `5 - 3 + 1` | 3 |

# Complexity
- Time complexity: $$O(1)$$. The `pow` function and basic arithmetic operations execute in constant time regardless of the input values.
- Space complexity: $$O(1)$$. No auxiliary data structures are used.

# Code
```cpp
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int ans = 0;
        int l_min = ceil(pow(l,1.0/k) - 1e-9);
        int r_max = floor(pow(r,1.0/k) + 1e-9);
        ans = max(ans, r_max - l_min +1);

        return ans;
    }
};
```
