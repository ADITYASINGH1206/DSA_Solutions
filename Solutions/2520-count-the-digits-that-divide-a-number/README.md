# [2520. Count the Digits That Divide a Number](https://leetcode.com/problems/count-the-digits-that-divide-a-number/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
Given an integer `num`, return *the number of digits in `num` that divide* `num`.

An integer `val` divides `nums` if `nums % val == 0`.

**Example 1:**

```
Input: num = 7
Output: 1
Explanation: 7 divides itself, hence the answer is 1.
```

**Example 2:**

```
Input: num = 121
Output: 2
Explanation: 121 is divisible by 1, but not 2. Since 1 occurs twice as a digit, we return 2.
```

**Example 3:**

```
Input: num = 1248
Output: 4
Explanation: 1248 is divisible by all of its digits, hence the answer is 4.
```

**Constraints:**

* `1 <= num <= 109`
* `num` does not contain `0` as one of its digits.

---

## Solution & Editorial
# Intuition
To determine if each digit of an integer divides the number itself, we must isolate each digit and perform a modulo operation. Since the number of digits in an integer $N$ is logarithmic relative to its value, we can process the number by repeatedly extracting the last digit using the modulo operator and reducing the number using integer division.

# Approach
1. Initialize a counter `ans` to 0 and create a temporary variable `n` initialized to `num` to preserve the original value for divisibility checks.
2. Use a `while` loop that continues as long as `n > 0`.
3. In each iteration, extract the last digit using `n % 10`.
4. Check if `num` is divisible by this digit using `num % (n % 10) == 0`. If true, increment `ans`.
5. Update `n` by performing integer division `n / 10` to discard the processed digit.
6. Return `ans` after the loop terminates.

### Visual Trace (num = 121)
| Iteration | n | Digit (n % 10) | num % Digit == 0 | ans |
|-----------|---|----------------|------------------|-----|
| 1         | 121 | 1              | 121 % 1 == 0     | 1   |
| 2         | 12  | 2              | 121 % 2 != 0     | 1   |
| 3         | 1   | 1              | 121 % 1 == 0     | 2   |

# Complexity
- Time complexity: $$O(\log_{10} N)$$ where $N$ is the input number. The number of iterations is equal to the number of digits in $N$, which is $\lfloor \log_{10} N \rfloor + 1$.
- Space complexity: $$O(1)$$ as we only use a constant amount of extra space for variables `ans` and `n`.

# Code
```cpp
class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int n = num;
        while(n>0){
            if(num%(n%10)==0) ans++;
            n = n/10;
        }
        return ans;
    }
};
```
