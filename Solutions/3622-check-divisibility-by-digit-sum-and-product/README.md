# [3622. Check Divisibility by Digit Sum and Product](https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
You are given a positive integer `n`. Determine whether `n` is divisible by the **sum** of the following two values:

* The **digit sum** of `n` (the sum of its digits).
* The **digit** **product** of `n` (the product of its digits).

Return `true` if `n` is divisible by this sum; otherwise, return `false`.

**Example 1:**

**Input:** n = 99

**Output:** true

**Explanation:**

Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 \* 9 = 81) of its digits (total 99), the output is true.

**Example 2:**

**Input:** n = 23

**Output:** false

**Explanation:**

Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 \* 3 = 6) of its digits (total 11), the output is false.

**Constraints:**

* `1 <= n <= 106`

---

## Solution & Editorial
# Intuition
The problem requires calculating the sum and product of the digits of a given integer $n$ and checking if $n$ is divisible by their combined total. Since $n$ is at most $10^6$, we can extract digits iteratively using modulo and division operations.

# Approach
1. Initialize `sumDigit` to 0 and `productDigit` to 1.
2. Use a `while` loop to extract digits from `num` (a copy of $n$):
   - Extract the last digit using `num % 10`.
   - Add the digit to `sumDigit`.
   - Multiply the digit into `productDigit`.
   - Remove the last digit using `num /= 10`.
3. Finally, return `true` if `n % (sumDigit + productDigit) == 0`, otherwise `false`.

### Visual Trace (n = 23)
| Iteration | num | digit | sumDigit | productDigit |
|-----------|-----|-------|----------|--------------|
| Initial   | 23  | -     | 0        | 1            |
| 1         | 2   | 3     | 3        | 3            |
| 2         | 0   | 2     | 5        | 6            |

Result: 23 % (5 + 6) = 23 % 11 = 1 (False).

# Complexity
- Time complexity: $$O(\log_{10} n)$$, where $n$ is the input integer. The number of iterations is proportional to the number of digits in $n$.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool checkDivisibility(int n) {
        int sumDigit = 0;
        int productDigit = 1;
        int num = n;


        while (num > 0) {
            sumDigit += num % 10;
            productDigit *= num % 10;
            num /= 10;
        }


        return n % (sumDigit + productDigit) == 0;
    }
};
```
