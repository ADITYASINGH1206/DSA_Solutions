# [3783. Mirror Distance of an Integer](https://leetcode.com/problems/mirror-distance-of-an-integer/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
You are given an integer `n`.

Define its **mirror distance** as: `abs(n - reverse(n))`​​​​​​​ where `reverse(n)` is the integer formed by reversing the digits of `n`.

Return an integer denoting the mirror distance of `n`​​​​​​​.

`abs(x)` denotes the absolute value of `x`.

**Example 1:**

**Input:** n = 25

**Output:** 27

**Explanation:**

* `reverse(25) = 52`.
* Thus, the answer is `abs(25 - 52) = 27`.

**Example 2:**

**Input:** n = 10

**Output:** 9

**Explanation:**

* `reverse(10) = 01` which is 1.
* Thus, the answer is `abs(10 - 1) = 9`.

**Example 3:**

**Input:** n = 7

**Output:** 0

**Explanation:**

* `reverse(7) = 7`.
* Thus, the answer is `abs(7 - 7) = 0`.

**Constraints:**

* `1 <= n <= 109`

---

## Solution & Editorial
# Intuition
The problem asks for the absolute difference between an integer and its digit-reversed counterpart. Since the number of digits in an integer $n$ is logarithmic relative to its value ($O(\log_{10} n)$), we can compute the reverse by iteratively extracting the last digit using the modulo operator and building the new number.

# Approach
1. Define a helper function or lambda to compute the reverse of $n$. Initialize a variable `y` to 0.
2. While $n > 0$, extract the last digit using `n % 10`, append it to `y` by shifting `y` left (multiplying by 10), and update $n$ by dividing by 10.
3. Return the absolute difference `abs(n - reverse(n))`.

### Visual Trace (Example 1: n = 25)
| Iteration | n (input) | y (reversed) | Operation |
|-----------|-----------|--------------|-----------|
| Start     | 25        | 0            | -         |
| 1         | 2         | 5            | y = 0*10 + 5 |
| 2         | 0         | 52           | y = 5*10 + 2 |

Result: `abs(25 - 52) = 27`.

# Complexity
- Time complexity: $$O(\log_{10} n)$$, as we process each digit of the number exactly once.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int mirrorDistance(int n) {
        auto reverse = [](int x) -> int {
            int y = 0;
            for (; x; x /= 10) {
                y = y * 10 + x % 10;
            }
            return y;
        };
        return abs(n - reverse(n));
    }
};
```
