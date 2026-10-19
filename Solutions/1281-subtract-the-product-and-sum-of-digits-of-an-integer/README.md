# [1281. Subtract the Product and Sum of Digits of an Integer](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
Given an integer number `n`, return the difference between the product of its digits and the sum of its digits.

**Example 1:**

```
Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
```

**Example 2:**

```
Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21
```

**Constraints:**

* `1 <= n <= 10^5`

---

## Solution & Editorial
# Intuition
The problem requires us to compute two values from the digits of an integer `n`: their product and their sum, and then return their difference. Since the digits of any number can be extracted iteratively from right to left using modulo and division by 10, we can compute both metrics in a single pass.

# Approach
1. Initialize `product` to 1 (since multiplication identity is 1) and `sum` to 0 (additive identity).
2. Run a `while` loop as long as `n > 0`.
3. Extract the last digit of `n` using `digit = n % 10` and strip it from `n` using `n /= 10`.
4. Update `product *= digit` and `sum += digit`.
5. Return `product - sum` once `n` becomes 0.

### Visual Trace (Example 1: n = 234)

| Iteration | `n` (before) | `digit = n % 10` | `n` (after) | `product` | `sum` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 234 | 4 | 23 | 4 | 4 |
| 2 | 23 | 3 | 2 | 12 | 7 |
| 3 | 2 | 2 | 0 | 24 | 9 |

Result = `product - sum` = `24 - 9 = 15`.

# Complexity
- Time complexity: $$O(\log_{10} n)$$ — The number of iterations equals the number of digits in `n`, which is bounded by $$\log_{10} n + 1$.
- Space complexity: $$O(1)$$ — Only a constant number of scalar variables are maintained.

# Code
```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1,sum=0;
        while(n>0){
            int digit = n%10;
            n/=10;
            product*=digit;
            sum+=digit;
        
        }
        return product-sum;
    }
};
```
