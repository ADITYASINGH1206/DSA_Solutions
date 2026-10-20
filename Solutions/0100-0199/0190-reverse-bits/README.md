# [190. Reverse Bits](https://leetcode.com/problems/reverse-bits/)
**Difficulty:** `Easy` | **Tags:** `divide-and-conquer`, `bit-manipulation`

---

## Problem Description
Reverse bits of a given 32 bits signed integer.

**Example 1:**

**Input:** n = 43261596

**Output:** 964176192

**Explanation:**

| Integer | Binary |
| --- | --- |
| 43261596 | 00000010100101000001111010011100 |
| 964176192 | 00111001011110000010100101000000 |

**Example 2:**

**Input:** n = 2147483644

**Output:** 1073741822

**Explanation:**

| Integer | Binary |
| --- | --- |
| 2147483644 | 01111111111111111111111111111100 |
| 1073741822 | 00111111111111111111111111111110 |

**Constraints:**

* `0 <= n <= 231 - 2`
* `n` is even.

**Follow up:** If this function is called many times, how would you optimize it?

---

## Solution & Editorial
# Intuition
The problem requires reversing the binary representation of a 32-bit integer. By iterating through all 32 bit positions, we can extract the least significant bit of the input integer and append it to our result integer, effectively building the reversed bit pattern from left to right.

# Approach
1. Initialize a result variable `res` to `0` to accumulate the reversed bits.
2. Loop exactly 32 times, once for each bit in a 32-bit integer.
3. In each iteration, left-shift `res` by 1 (`res <<= 1`) to make space for the incoming bit.
4. Check if the least significant bit of `n` is set (`n & 1`). If it is, increment `res` (`res++`).
5. Right-shift `n` by 1 (`n >>= 1`) to process the next bit in subsequent iterations.
6. Return `res` after 32 iterations.

### Visual Trace Walkthrough
Consider a 4-bit simplified example with `n = 2` (`0010`):

| Iteration `i` | Initial `n` | `n & 1` | `res` before shift | `res` after shift & add | Updated `n` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | `0010` | 0 | `0` | `0` | `0001` |
| 1 | `0001` | 1 | `0` | `1` | `0000` |
| 2 | `0000` | 0 | `1` | `2` (`0010`) | `0000` |
| 3 | `0000` | 0 | `2` | `4` (`0100`) | `0000` |

# Complexity
- Time complexity: $$O(1)$$ — The loop runs a fixed number of times ($32$), which is constant time regardless of the input value.
- Space complexity: $$O(1)$$ — Only a few primitive variables (`res`, `i`) are used, requiring constant auxiliary memory.

# Code
```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            if (n & 1) {
                res++;
            }
            n >>= 1;
        }
        return res;
    }
};
```
