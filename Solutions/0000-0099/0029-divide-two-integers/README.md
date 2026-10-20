# [29. Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)
**Difficulty:** `Medium` | **Tags:** `math`, `bit-manipulation`

---

## Problem Description
Given two integers `dividend` and `divisor`, divide two integers **without** using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, `8.345` would be truncated to `8`, and `-2.7335` would be truncated to `-2`.

Return *the **quotient** after dividing* `dividend` *by* `divisor`.

**Note:** Assume we are dealing with an environment that could only store integers within the **32-bit** signed integer range: `[−231, 231 − 1]`. For this problem, if the quotient is **strictly greater than** `231 - 1`, then return `231 - 1`, and if the quotient is **strictly less than** `-231`, then return `-231`.

**Example 1:**

```
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
```

**Example 2:**

```
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
```

**Constraints:**

* `-231 <= dividend, divisor <= 231 - 1`
* `divisor != 0`

---

## Solution & Editorial
# Intuition
The problem requires dividing two integers without using multiplication, division, or modulo operators. The core observation is that we can perform division efficiently by using bit-shifting (doubling the divisor using left shifts) to subtract large multiples of the divisor from the dividend simultaneously, similar to long division in binary.

# Approach
1. Handle the special overflow case where `dividend` is `INT_MIN` and `divisor` is `-1`, which would overflow 32-bit signed integers.
2. Determine the sign of the final quotient by checking if `dividend` and `divisor` have different signs using XOR, and convert both operands to `long long` positive values to prevent overflow during absolute value operations.
3. Iterate while `n >= m` (where `n` is the absolute dividend and `m` is the absolute divisor). Inside, find the largest power of 2 such that `m << i` is less than or equal to `n`.
4. Accumulate `1 << i` into the `ans` accumulator and subtract `m << i` from `n`.
5. Apply the determined sign to `ans`, clamp the result within the 32-bit signed integer range `[INT_MIN, INT_MAX]`, and return.

### Visual Trace (Example 1: `dividend = 10`, `divisor = 3`)
- `n = 10`, `m = 3`, `sign = positive`
- Iteration 1:
  - Find max `i` such that `3 << i <= 10` $ightarrow$ `i = 1` (`3 << 1 = 6`).
  - `ans += (1 << 1)` $ightarrow$ `ans = 2`.
  - `n -= 6` $ightarrow$ `n = 4`.
- Iteration 2:
  - Find max `i` such that `3 << i <= 4` $ightarrow$ `i = 0` (`3 << 0 = 3`).
  - `ans += (1 << 0)` $ightarrow$ `ans = 2 + 1 = 3`.
  - `n -= 3` $ightarrow$ `n = 1`.
- Loop terminates since `n < m` ($1 < 3$). Result = `3`.

# Complexity
- Time complexity: $$O(\log N)$$ — The algorithm subtracts powers of two of the divisor, reducing the dividend exponentially in each outer loop, similar to binary search or bit length.
- Space complexity: $$O(1)$$ — Only a few primitive variables are used for state tracking.

# Code
```cpp
/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    let q = dividend/divisor
    let result = q > 0 ? Math.floor(q) : Math.ceil(q)
    if (result <= -2147483648) {
        result = -2147483648;
    } else if (result >= 2147483647) {
        result = 2147483647;
    }    
    return result;
    
};
```
