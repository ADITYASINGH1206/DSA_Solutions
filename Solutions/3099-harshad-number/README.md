# [3099. Harshad Number](https://leetcode.com/problems/harshad-number/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
An integer divisible by the **sum** of its digits is said to be a **Harshad** number. You are given an integer `x`. Return *the sum of the digits* of`x`if`x`is a **Harshad** number, otherwise, return`-1`*.*

**Example 1:**

**Input:** x = 18

**Output:** 9

**Explanation:**

The sum of digits of `x` is `9`. `18` is divisible by `9`. So `18` is a Harshad number and the answer is `9`.

**Example 2:**

**Input:** x = 23

**Output:** -1

**Explanation:**

The sum of digits of `x` is `5`. `23` is not divisible by `5`. So `23` is not a Harshad number and the answer is `-1`.

**Constraints:**

* `1 <= x <= 100`

---

## Solution & Editorial
# Intuition
A Harshad number is defined by its divisibility by the sum of its own digits. To solve this, we must first extract each digit of the integer `x`, compute their sum, and then perform a simple modulo check to verify the Harshad property.

# Approach
1. Initialize `sum_d` to 0 to store the sum of digits and `temp` to store the original value of `x`.
2. Use a `while` loop to extract digits from `x` using the modulo operator (`x % 10`) and update `x` by integer division (`x /= 10`).
3. Add each extracted digit to `sum_d`.
4. After the loop, check if `temp` is divisible by `sum_d` using the modulo operator (`temp % sum_d == 0`).
5. If true, return `sum_d`; otherwise, return `-1`.

### Visual Trace (x = 18)
| Iteration | x (before) | digit | x (after) | sum_d |
|-----------|------------|-------|-----------|-------|
| 1         | 18         | 8     | 1         | 8     |
| 2         | 1          | 1     | 0         | 9     |

Check: 18 % 9 == 0? Yes. Return 9.

# Complexity
- Time complexity: $$O(\log_{10}(x))$$ — The number of iterations is equal to the number of digits in `x`, which is logarithmic relative to the value of `x`.
- Space complexity: $$O(1)$$ — We only use a constant amount of extra space for variables `sum_d`, `temp`, and `digit`.

# Code
```cpp
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum_d = 0;
        int temp = x;
        while(x){
            int digit = x%10;
            x/=10;
            sum_d += digit;
        }
        if(temp%sum_d == 0) return sum_d;
        return -1;
    }
};
```
