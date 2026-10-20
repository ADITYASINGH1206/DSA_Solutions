# [3908. Valid Digit Number](https://leetcode.com/problems/valid-digit-number/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
You are given an integer `n` and a digit `x`.

A number is considered **valid** if:

* It contains **at least one** occurrence of digit `x`, and
* It **does not start** with digit `x`.

Return `true` if `n` is **valid**, otherwise return `false`.

**Example 1:**

**Input:** n = 101, x = 0

**Output:** true

**Explanation:**

The number contains digit 0 at index 1. It does not start with 0, so it satisfies both conditions. Thus, the answer is `true`​​​​​​​.

**Example 2:**

**Input:** n = 232, x = 2

**Output:** false

**Explanation:**

The number starts with 2, which violates the condition. Thus, the answer is `false`.

**Example 3:**

**Input:** n = 5, x = 1

**Output:** false

**Explanation:**

The number does not contain digit 1. Thus, the answer is `false`.

**Constraints:**

* `0 <= n <= 105​​​​​​​`
* `0 <= x <= 9`

---

## Solution & Editorial
# Intuition
To determine if a number is valid, we must verify two conditions: the presence of the target digit `x` and the absence of `x` at the most significant position. Since the constraints on `n` are small (up to 10^5), we can efficiently extract digits using modulo and division operations.

# Approach
1. Handle the edge case where `n == 0` immediately, as it cannot satisfy the conditions based on the problem logic.
2. Use a `while` loop to iterate through the digits of `n` from right to left using `temp % 10`.
3. Maintain a boolean flag `found` to track if the digit `x` appears anywhere in the number.
4. Track the `first` digit (the most significant digit) by checking when `temp` becomes 0 after division.
5. Return `true` if `found` is true AND `first` is not equal to `x`.

### Visual Trace (n = 101, x = 0)
| Iteration | temp | digit | found | first |
|-----------|------|-------|-------|-------|
| 1         | 10   | 1     | false | 0     |
| 2         | 1    | 0     | true  | 0     |
| 3         | 0    | 1     | true  | 1     |

Final check: `found` (true) && `first` (1) != `x` (0) -> `true`.

# Complexity
- Time complexity: $$O(\log_{10} n)$$, as we process each digit of the number exactly once.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool validDigit(int n, int x) {
        if (n == 0) return false;
        
        int temp = n;
        bool found = false;
        int first = 0;
        
        while (temp) {
            int digit = temp % 10;
            if (digit == x) {
                found = true; 
            }
            temp /= 10;
            if (temp == 0) {
                first = digit;
            }
        }

        return found && (first != x);
    }
};
```
