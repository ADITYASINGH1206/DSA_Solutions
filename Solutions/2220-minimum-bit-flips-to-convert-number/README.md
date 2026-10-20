# [2220. Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/)
**Difficulty:** `Easy` | **Tags:** `bit-manipulation`

---

## Problem Description
A **bit flip** of a number `x` is choosing a bit in the binary representation of `x` and **flipping** it from either `0` to `1` or `1` to `0`.

* For example, for `x = 7`, the binary representation is `111` and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get `110`, flip the second bit from the right to get `101`, flip the fifth bit from the right (a leading zero) to get `10111`, etc.

Given two integers `start` and `goal`, return *the **minimum** number of **bit flips** to convert* `start` *to* `goal`.

**Example 1:**

```
Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
```

**Example 2:**

```
Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.
```

**Constraints:**

* `0 <= start, goal <= 109`

**Note:** This question is the same as [461: Hamming Distance.](https://leetcode.com/problems/hamming-distance/description/)

---

## Solution & Editorial
# Intuition
The problem asks for the minimum number of bit flips to transform `start` into `goal`. This is equivalent to finding the number of positions where the bits of `start` and `goal` differ, which is the definition of the Hamming distance between two integers.

# Approach
1. Use the XOR (`^`) operator to identify the differing bits. The XOR operation results in a `1` at every bit position where `start` and `goal` have different values, and `0` where they are the same.
2. Count the number of set bits (1s) in the resulting XOR value. This count represents exactly how many bits need to be flipped.
3. Utilize the built-in compiler intrinsic `__builtin_popcount()` for an efficient, hardware-accelerated count of set bits.

### Visual Trace (Example 1: start = 10, goal = 7)
| Operation | Binary Representation |
| :--- | :--- |
| `start` (10) | `1010` |
| `goal` (7) | `0111` |
| `start ^ goal` | `1101` |
| `popcount(1101)` | `3` |

# Complexity
- Time complexity: $$O(1)$$. The XOR operation and the `__builtin_popcount` function (which typically maps to a single CPU instruction like `POPCNT` on modern architectures) execute in constant time regardless of the input size.
- Space complexity: $$O(1)$$. No auxiliary data structures are used; the calculation is performed in-place using registers.

# Code
```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};
```
