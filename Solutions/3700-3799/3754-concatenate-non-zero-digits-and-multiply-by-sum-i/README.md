# [3754. Concatenate Non-Zero Digits and Multiply by Sum I](https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
You are given an integer `n`.

Form a new integer `x` by concatenating all the **non-zero digits** of `n` in their original order. If there are no **non-zero** digits, `x = 0`.

Let `sum` be the **sum of digits** in `x`.

Return an integer representing the value of `x * sum`.

**Example 1:**

**Input:** n = 10203004

**Output:** 12340

**Explanation:**

* The non-zero digits are 1, 2, 3, and 4. Thus, `x = 1234`.
* The sum of digits is `sum = 1 + 2 + 3 + 4 = 10`.
* Therefore, the answer is `x * sum = 1234 * 10 = 12340`.

**Example 2:**

**Input:** n = 1000

**Output:** 1

**Explanation:**

* The non-zero digit is 1, so `x = 1` and `sum = 1`.
* Therefore, the answer is `x * sum = 1 * 1 = 1`.

**Constraints:**

* `0 <= n <= 109`

---

## Solution & Editorial
# Intuition
To solve this problem, we need to extract non-zero digits from the integer `n` while maintaining their relative order. Since the digits are processed from least significant to most significant using the modulo operator, we can reconstruct the number `x` by maintaining a `place` multiplier and adding the digits to the front of the current `x` value.

# Approach
1. Initialize `x` (the concatenated number) and `sum` (the sum of non-zero digits) to 0. Use a `place` variable initialized to 1 to track the positional weight of digits as we reconstruct `x` from right to left.
2. Iterate through `n` using a `while` loop until `n` becomes 0. In each iteration:
   - Extract the last digit `d = n % 10`.
   - If `d` is non-zero, update `x` by adding `d * place` to it, increment `place` by a factor of 10, and add `d` to `sum`.
   - Divide `n` by 10 to move to the next digit.
3. Return the product `x * sum`.

### Visual Trace (n = 10203004)
| Iteration | n | d | x | place | sum |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 10203004 | 4 | 4 | 10 | 4 |
| 1 | 1020300 | 0 | 4 | 10 | 4 |
| 2 | 102030 | 0 | 4 | 10 | 4 |
| 3 | 10203 | 3 | 34 | 100 | 7 |
| 4 | 1020 | 0 | 34 | 100 | 7 |
| 5 | 102 | 2 | 234 | 1000 | 9 |
| 6 | 10 | 0 | 234 | 1000 | 9 |
| 7 | 1 | 1 | 1234 | 10000 | 10 |

# Complexity
- Time complexity: $$O(\log_{10} n)$$, as we process each digit of the input integer exactly once.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for variables `x`, `sum`, `place`, and `d`.

# Code
```cpp
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long place = 1;

        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                x = d * place + x;
                place *= 10;
                sum += d;
            }
            n /= 10;
        }

        return x * sum;
    }
};
```
