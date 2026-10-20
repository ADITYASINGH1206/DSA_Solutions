# [1680. Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/)
**Difficulty:** `Medium` | **Tags:** `math`, `bit-manipulation`, `simulation`

---

## Problem Description
Given an integer `n`, return *the **decimal value** of the binary string formed by concatenating the binary representations of* `1` *to* `n` *in order, **modulo*** `109 + 7`.

**Example 1:**

```
Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1.
```

**Example 2:**

```
Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
```

**Example 3:**

```
Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
```

**Constraints:**

* `1 <= n <= 105`

---

## Solution & Editorial
# Intuition
To concatenate binary representations of numbers from 1 to $n$, we observe that appending a number $i$ to an existing binary sequence is equivalent to shifting the current sequence left by the number of bits required to represent $i$, then performing a bitwise OR with $i$. Since we need the result modulo $10^9 + 7$, we apply the modulo operation at each step.

# Approach
1. Initialize `ans` as a `long long` to prevent overflow during intermediate calculations.
2. Iterate through each integer $i$ from 1 to $n$.
3. Determine the number of bits required to represent $i$. Using `__builtin_clz(i)`, which counts leading zeros in a 32-bit integer, the number of bits is `32 - __builtin_clz(i)`.
4. Shift `ans` left by the calculated bit count and add $i$ using bitwise OR.
5. Apply the modulo $10^9 + 7$ at each iteration to keep the value within bounds.

### Visual Trace (n = 3)
| i | Binary | Bits | Operation | Result (Decimal) |
|---|---|---|---|---|
| 1 | 1 | 1 | (0 << 1) | 1 | 1 |
| 2 | 10 | 2 | (1 << 2) | 2 | 6 (110) |
| 3 | 11 | 2 | (6 << 2) | 3 | 27 (11011) |

# Complexity
- Time complexity: $$O(n)$$ — We iterate from 1 to $n$ exactly once. The `__builtin_clz` function is a constant-time hardware instruction.
- Space complexity: $$O(1)$$ — We only use a single `long long` variable to store the running result.

# Code
```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans << (32 - __builtin_clz(i)) | i) % mod;
        }
        return ans;
    }
};
```
