# [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
Given an integer `x`, return `true` if `x` is a **palindrome**, and `false` otherwise.

**Example 1:**

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

**Example 2:**

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

**Example 3:**

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

**Constraints:**

* `-231 <= x <= 231 - 1`

**Follow up:** Could you solve it without converting the integer to a string?

---

## Solution & Editorial
# Intuition
To determine if an integer is a palindrome without converting it to a string, we can reverse only the second half of the number and compare it with the first half. If the number has an odd number of digits, we can simply strip the middle digit from the reversed half before making the comparison.

# Approach
1. Check early return conditions: If `x < 0` or if `x > 0` and ends with `0` (e.g., `10`, `20`), it cannot be a palindrome.
2. Initialize a variable `y = 0` to store the reversed digits of the second half.
3. Run a loop that continues as long as `y < x`. In each iteration, extract the last digit of `x` using modulo (`x % 10`), append it to `y` (`y = y * 10 + x % 10`), and remove the last digit from `x` (`x /= 10`).
4. Once the loop terminates (meaning we have processed at least half the digits), check if the remaining first half `x` equals the reversed second half `y` (for even-length numbers) or `y / 10` (for odd-length numbers).

### Visual Trace Walkthrough (Example 1: `x = 121`)
- Initial state: `x = 121`, `y = 0`
- Check edge cases: `121 < 0` is false, `121 % 10 == 0` is false.
- Iteration 1:
  - Condition `y < x` ($0 < 121$) is true.
  - `y = 0 * 10 + 1 = 1`
  - `x = 121 / 10 = 12`
- Iteration 2:
  - Condition `y < x` ($1 < 12$) is true.
  - `y = 1 * 10 + 2 = 12`
  - `x = 12 / 10 = 1`
- Iteration 3:
  - Condition `y < x` ($12 < 1$) is false. Loop terminates.
- Final check: `x == y / 10` ($1 == 12 / 10 ightarrow 1 == 1$) returns `true`.

# Complexity
- Time complexity: $$O(\log_{10} n)$$ — We divide the input number `x` by 10 in each iteration, looping through roughly half of the total number of digits.
- Space complexity: $$O(1)$$ — Only a constant amount of extra memory is used for integer variables `x` and `y`.

# Code
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x && x % 10 == 0)) {
            return false;
        }
        int y = 0;
        for (; y < x; x /= 10) {
            y = y * 10 + x % 10;
        }
        return x == y || x == y / 10;
    }
};
```
