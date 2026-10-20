# [693. Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/)
**Difficulty:** `Easy` | **Tags:** `bit-manipulation`

---

## Problem Description
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

**Example 1:**

```
Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101
```

**Example 2:**

```
Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.
```

**Example 3:**

```
Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
```

**Constraints:**

* `1 <= n <= 231 - 1`

---

## Solution & Editorial
# Intuition
The problem asks us to verify if all adjacent bits in the binary representation of a given positive integer $n$ are distinct (alternating). We can extract bits from right to left using bitwise operations and compare each bit with its preceding neighbor.

# Approach
1. Initialize a variable `prev` to `-1` to keep track of the previously processed bit.
2. Iterate with a `while (n)` loop as long as $n$ is greater than `0`.
3. Inside the loop, extract the lowest bit using `curr = n & 1`.
4. Compare `prev` with `curr`. If they are equal, return `false` immediately because two adjacent bits are identical.
5. Otherwise, update `prev = curr` and shift $n$ to the right by `1` using `n >>= 1` to process the next bit.
6. If the loop terminates without finding any adjacent matching bits, return `true`.

### Visual Dry Run (Example 1: n = 5)
Binary of 5 is `101`.
- Iteration 1: `n = 5`, `curr = 5 & 1 = 1`. `prev` is `-1`. Not equal. Update `prev = 1`, `n = 2` (`10` in binary).
- Iteration 2: `n = 2`, `curr = 2 & 1 = 0`. `prev` is `1`. Not equal. Update `prev = 0`, `n = 1` (`1` in binary).
- Iteration 3: `n = 1`, `curr = 1 & 1 = 1`. `prev` is `0`. Not equal. Update `prev = 1`, `n = 0`.
- Loop terminates. Returns `true`.

# Complexity
- Time complexity: $$O(\log n)$$ — The number of iterations is proportional to the number of bits in $n$, which is $\lfloor \log_2 n \rfloor + 1$.
- Space complexity: $$O(1)$$ — Only a constant amount of extra memory (`prev`, `curr`) is used.

# Code
```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while (n) {
            int curr = n & 1;
            if (prev == curr) return false;
            prev = curr;
            n >>= 1;
        }
        return true;
    }
};
```
