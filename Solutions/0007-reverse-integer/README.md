# [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/)
**Difficulty:** `Medium` | **Tags:** `math`

---

## Problem Description
Given a signed 32-bit integer `x`, return `x` *with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-231, 231 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

**Example 1:**

```
Input: x = 123
Output: 321
```

**Example 2:**

```
Input: x = -123
Output: -321
```

**Example 3:**

```
Input: x = 120
Output: 21
```

**Constraints:**

* `-231 <= x <= 231 - 1`

---

## Solution & Editorial
# Intuition
Reversing an integer mathematically requires continuously stripping the least significant digit via modulo operations and appending it to the accumulated result via decimal shifting. To respect 32-bit signed integer limits without using 64-bit types, overflow checks must be performed prior to multiplying by 10.

# Approach
1. Define `ans = 0` to store the reversed integer.
2. Iteratively process digits while `x != 0`:
   - Check if `ans < INT_MIN / 10` or `ans > INT_MAX / 10`. If either condition is true, shifting `ans` by one decimal place will exceed 32-bit bounds (`[-2147483648, 2147483647]`), so return `0` immediately.
   - Note: Because 32-bit integer limits start with `2` (`2,147,483,647`), any 10-digit number that reaches `ans == INT_MAX / 10` can only have a final appended digit of `1` or `2`, which will never exceed `7` or `-8`. Thus, checking `ans > INT_MAX / 10` and `ans < INT_MIN / 10` is both necessary and sufficient.
   - Update `ans = ans * 10 + (x % 10)`.
   - Discard the processed digit using integer division: `x /= 10`.
3. Return `ans` once `x` becomes `0`.

### Trace Walkthrough (Example 1: `x = 123`)

| Step | `x` (before) | `x % 10` | `ans` (before) | Overflow Condition Check | `ans` (after) | `x` (after) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `123` | `3` | `0` | False (`0` is within bounds) | `0 * 10 + 3 = 3` | `12` |
| 2 | `12` | `2` | `3` | False (`3` is within bounds) | `3 * 10 + 2 = 32` | `1` |
| 3 | `1` | `1` | `32` | False (`32` is within bounds) | `32 * 10 + 1 = 321` | `0` |

Loop terminates as `x == 0`. Returns `321`.

# Complexity
- Time complexity: $$O(\log_{10}|x|)$$ — We iterate once per decimal digit of $$x$$. A 32-bit signed integer has at most 10 digits, bounding the loop to at most 10 iterations ($$\approx O(1)$$).
- Space complexity: $$O(1)$$ — Only scalar 32-bit variables (`ans`, bounds) are utilized without auxiliary heap or stack allocations.

# Code
```cpp
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const mi = -(2 ** 31);
    const mx = 2 ** 31 - 1;
    let ans = 0;
    for (; x != 0; x = ~~(x / 10)) {
        if (ans < ~~(mi / 10) || ans > ~~(mx / 10)) {
            return 0;
        }
        ans = ans * 10 + (x % 10);
    }
    return ans;
};
```
