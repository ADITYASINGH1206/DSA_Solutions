# [1009. Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer/)
**Difficulty:** `Easy` | **Tags:** `bit-manipulation`

---

## Problem Description
The **complement** of an integer is the integer you get when you flip all the `0`'s to `1`'s and all the `1`'s to `0`'s in its binary representation.

* For example, The integer `5` is `"101"` in binary and its **complement** is `"010"` which is the integer `2`.

Given an integer `n`, return *its complement*.

**Example 1:**

```
Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
```

**Example 2:**

```
Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
```

**Example 3:**

```
Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
```

**Constraints:**

* `0 <= n < 109`

**Note:** This question is the same as 476: <https://leetcode.com/problems/number-complement/>

---

## Solution & Editorial
# Intuition
The bitwise complement of a non-negative integer can be obtained by examining each bit from the least significant bit (LSB) to the most significant bit (MSB). For each bit position, we invert the bit (turning 0 into 1 and 1 into 0) and shift it to its correct place value.

# Approach
1. Handle the edge case where `n == 0` explicitly, since its binary representation is `0` and its complement is `1`.
2. Initialize an accumulator variable `ans = 0` and a bit position counter `i = 0`.
3. Loop while `n > 0`:
   - Extract the lowest bit using `n & 1` and invert it using XOR with 1 (`n & 1 ^ 1`).
   - Shift the inverted bit left by `i` positions using `<< (i++)`.
   - Bitwise OR this value into `ans`.
   - Right shift `n` by 1 (`n >>= 1`) to process the next bit.
4. Return `ans` once `n` becomes 0.

### Visual Walkthrough for Example 1: `n = 5` (`101` in binary)

| Iteration | `n` (binary) | LSB (`n & 1`) | Inverted (`n & 1 ^ 1`) | `i` | Shifted Value (`<< i`) | `ans` (binary) | `n` after `>>= 1` |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `101` | `1` | `0` | `0` | `0` | `000` (`0`) | `10` |
| 2 | `10` | `0` | `1` | `1` | `10` (`2`) | `010` (`2`) | `1` |
| 3 | `1` | `1` | `0` | `2` | `0` | `010` (`2`) | `0` |

# Complexity
- Time complexity: $$O(\log n)$$ — The while loop runs once for each bit in the binary representation of `n`, which is at most 31 iterations for standard 32-bit integers.
- Space complexity: $$O(1)$$ — Only a few primitive integer variables (`ans`, `i`) are used, requiring constant auxiliary space.

# Code
```cpp
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 0, i = 0;
        while (n != 0) {
            ans |= (n & 1 ^ 1) << (i++);
            n >>= 1;
        }
        return ans;
    }
};
```
