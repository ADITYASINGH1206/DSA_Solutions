# [231. Power of Two](https://leetcode.com/problems/power-of-two/)
**Difficulty:** `Easy` | **Tags:** `math`, `bit-manipulation`, `recursion`

---

## Problem Description
Given an integer `n`, return *`true` if it is a power of two. Otherwise, return `false`*.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2x`.

**Example 1:**

```
Input: n = 1
Output: true
Explanation: 20 = 1
```

**Example 2:**

```
Input: n = 16
Output: true
Explanation: 24 = 16
```

**Example 3:**

```
Input: n = 3
Output: false
```

**Constraints:**

* `-231 <= n <= 231 - 1`

**Follow up:** Could you solve it without loops/recursion?

---

## Solution & Editorial
# Intuition
An integer is a power of two if and only if it is strictly greater than zero and can be repeatedly divided by 2 until it reaches 1 without leaving any non-zero remainder.

# Approach
1. Handle the base case where `n == 0`. Return `false` because zero cannot be a power of two.
2. Handle the base case where `n == 1`. Return `true` because $2^0 = 1$.
3. Check if `n` is divisible by 2 using the modulo operator (`n % 2 == 0`). If it is, recursively call `isPowerOfTwo(n / 2)`.
4. If `n` is odd and not equal to 1, return `false` as it cannot be formed by powers of 2.

### Visual Dry Run (Example 2: n = 16)
- `isPowerOfTwo(16)` -> `16 % 2 == 0` -> calls `isPowerOfTwo(8)`
- `isPowerOfTwo(8)` -> `8 % 2 == 0` -> calls `isPowerOfTwo(4)`
- `isPowerOfTwo(4)` -> `4 % 2 == 0` -> calls `isPowerOfTwo(2)`
- `isPowerOfTwo(2)` -> `2 % 2 == 0` -> calls `isPowerOfTwo(1)`
- `isPowerOfTwo(1)` -> matches `n == 1` -> returns `true`

# Complexity
- Time complexity: $$O(\log n)$$ — The input `n` is divided by 2 at each recursive step, leading to a logarithmic number of operations.
- Space complexity: $$O(\log n)$$ — The maximum depth of the recursive call stack is proportional to the number of divisions, which is $$\log_2 n$$.

# Code
```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if(n==1) return true;
        if(n%2==0) return isPowerOfTwo(n/2);

        return false;
    }
};
```
