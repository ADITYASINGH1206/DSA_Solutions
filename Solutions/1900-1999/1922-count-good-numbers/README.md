# [1922. Count Good Numbers](https://leetcode.com/problems/count-good-numbers/)
**Difficulty:** `Medium` | **Tags:** `math`, `recursion`

---

## Problem Description
A digit string is **good** if the digits **(0-indexed)** at **even** indices are **even** and the digits at **odd** indices are **prime** (`2`, `3`, `5`, or `7`).

* For example, `"2582"` is good because the digits (`2` and `8`) at even positions are even and the digits (`5` and `2`) at odd positions are prime. However, `"3245"` is **not** good because `3` is at an even index but is not even.

Given an integer `n`, return *the **total** number of good digit strings of length* `n`. Since the answer may be large, **return it modulo** `109 + 7`.

A **digit string** is a string consisting of digits `0` through `9` that may contain leading zeros.

**Example 1:**

```
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
```

**Example 2:**

```
Input: n = 4
Output: 400
```

**Example 3:**

```
Input: n = 50
Output: 564908303
```

**Constraints:**

* `1 <= n <= 1015`

---

## Solution & Editorial
# Intuition
To form a "good" number of length $n$, we must satisfy two independent constraints based on the index parity. Even indices (0, 2, 4, ...) can be filled with any of the 5 even digits {0, 2, 4, 6, 8}, while odd indices (1, 3, 5, ...) can be filled with any of the 4 prime digits {2, 3, 5, 7}. Since these choices are independent, the total count is the product of the possibilities for each position.

# Approach
1. Calculate the number of even indices as `even_pos = (n + 1) / 2` and odd indices as `odd_pos = n / 2`.
2. The total number of good strings is $5^{even\_pos} \times 4^{odd\_pos} \pmod{10^9 + 7}$.
3. Use Binary Exponentiation (Modular Exponentiation) to compute these powers in logarithmic time, preventing overflow by applying the modulo operator at each multiplication step.

### Visual Trace (n = 4)
- `even_pos` = (4 + 1) / 2 = 2
- `odd_pos` = 4 / 2 = 2
- Result = $5^2 \times 4^2 = 25 \times 16 = 400$

| Index | 0 | 1 | 2 | 3 |
| :--- | :--- | :--- | :--- | :--- |
| Type | Even | Odd | Even | Odd |
| Choices | 5 | 4 | 5 | 4 |

# Complexity
- Time complexity: $$O(\log n)$$ due to the binary exponentiation algorithm which halves the exponent in each iteration.
- Space complexity: $$O(1)$$ as we only use a few variables for calculation.

# Code
```cpp
class Solution {
private:
    int MOD = 1e9 + 7;
    
    long long power(long long base, long long exp) {
        long long result = 1;
        base = base % MOD; 
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp = exp / 2;
        }
        
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long even_pos = (n + 1) / 2;
        long long odd_pos = n / 2;
        
        long long even_c = power(5, even_pos);
        long long odd_c = power(4, odd_pos);
        
        return (even_c * odd_c) % MOD;
    }
};
```
