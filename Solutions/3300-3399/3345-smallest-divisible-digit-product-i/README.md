# [3345. Smallest Divisible Digit Product I](https://leetcode.com/problems/smallest-divisible-digit-product-i/)
**Difficulty:** `Easy` | **Tags:** `math`, `enumeration`

---

## Problem Description
You are given two integers `n` and `t`. Return the **smallest** number greater than or equal to `n` such that the **product of its digits** is divisible by `t`.

**Example 1:**

**Input:** n = 10, t = 2

**Output:** 10

**Explanation:**

The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

**Example 2:**

**Input:** n = 15, t = 3

**Output:** 16

**Explanation:**

The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

**Constraints:**

* `1 <= n <= 100`
* `1 <= t <= 10`

---

## Solution & Editorial
# Intuition
Since the constraints on $n$ are very small ($n \le 100$), we can simply iterate upwards starting from $n$ and check the digit product condition for each integer. The first integer that satisfies the condition is guaranteed to be the smallest.

# Approach
1. Define a helper function `productOfDigits(int num)` that calculates the product of the digits of a given integer. Note that if a number contains the digit 0, the product will be 0.
2. In the main function `smallestNumber(int n, int t)`, use a `while` loop to increment $n$ until `productOfDigits(n) % t == 0`.
3. Return the current value of $n$ once the condition is met.

### Visual Trace (n=15, t=3)
| Iteration | Current n | Digits | Product | Product % 3 == 0? |
|-----------|-----------|--------|---------|-------------------|
| 1         | 15        | 1, 5   | 5       | No (5 % 3 = 2)    |
| 2         | 16        | 1, 6   | 6       | Yes (6 % 3 = 0)   |

# Complexity
- Time complexity: $$O(K \cdot \log_{10}(N+K))$$ where $K$ is the number of steps taken until the condition is met. Given the constraints, this is effectively constant time.
- Space complexity: $$O(1)$$ as we only use a few integer variables for calculation.

# Code
```cpp
class Solution {
public:
    int productOfDigits(int num){
        int product = 1;

        while(num){
            product *= num % 10;
            num /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {
        while(productOfDigits(n) % t != 0)
            n++;

        return n;
    }
};
```
