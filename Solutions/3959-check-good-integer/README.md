# [3959. Check Good Integer](https://leetcode.com/problems/check-good-integer/)
**Difficulty:** `Easy` | **Tags:** `math`, `simulation`

---

## Problem Description
You are given a positive integer `n`.

Let `digitSum` be the sum of the digits of `n`, and let `squareSum` be the sum of the squares of the digits of `n`.

An integer is called **good** if `squareSum - digitSum >= 50`.

Return `true` if `n` is good. Otherwise, return `false`.

**Example 1:**

**Input:** n = 1000

**Output:** false

**Explanation:**

* The digits of 1000 are 1, 0, 0, and 0.
* The `digitSum` is `1 + 0 + 0 + 0 = 1`.
* The `squareSum` is `12 + 02 + 02 + 02 = 1`.
* The `squareSum - digitSum` is `1 - 1 = 0`. As 0 is not greater than or equal to 50, the output is `false`.

**Example 2:**

**Input:** n = 19

**Output:** true

**Explanation:**

* The digits of 19 are 1 and 9.
* The `digitSum` is `1 + 9 = 10`.
* The `squareSum` is `12 + 92 = 1 + 81 = 82`.
* The `squareSum - digitSum` is `82 - 10 = 72`. As 72 is greater than or equal to 50, the output is `true`.

**Constraints:**

* `1 <= n <= 109`

---

## Solution & Editorial
# Intuition
To determine if an integer is "good," we must compute two properties based on its decimal representation: the sum of its digits and the sum of the squares of its digits. Since the number of digits in an integer $n$ is logarithmic relative to its value ($O(\log_{10} n)$), we can efficiently extract each digit using modulo and division operations.

# Approach
1. Initialize two `long long` variables, `digitSum` and `squareSum`, to zero to store the running totals.
2. Use a `while` loop to process the integer $n$ as long as $n > 0$:
   - Extract the last digit using `n % 10`.
   - Add the digit to `digitSum`.
   - Add the square of the digit to `squareSum`.
   - Update $n$ by performing integer division `n /= 10` to remove the processed digit.
3. After the loop terminates, evaluate the condition `squareSum - digitSum >= 50` and return the boolean result.

### Visual Trace (n = 19)
| Iteration | n (start) | digit | digitSum | squareSum | n (end) |
|-----------|-----------|-------|----------|-----------|---------|
| 1         | 19        | 9     | 9        | 81        | 1       |
| 2         | 1         | 1     | 10       | 82        | 0       |

Result: 82 - 10 = 72. Since 72 >= 50, return `true`.

# Complexity
- Time complexity: $$O(\log_{10} n)$$, as the number of iterations is equal to the number of digits in $n$.
- Space complexity: $$O(1)$$, as we only use a fixed amount of extra space for integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool checkGoodInteger(int n) {
        long long digitSum = 0;
        long long squareSum = 0;
        while(n){
            int digit = n%10;
            int squareDigit = digit*digit;
            digitSum += digit;
            squareSum += squareDigit;
            n/=10;
        }

        return (squareSum-digitSum >= 50);
    }
};
```
