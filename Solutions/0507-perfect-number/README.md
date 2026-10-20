# [507. Perfect Number](https://leetcode.com/problems/perfect-number/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
A [**perfect number**](https://en.wikipedia.org/wiki/Perfect_number) is a **positive integer** that is equal to the sum of its **positive divisors**, excluding the number itself. A **divisor** of an integer `x` is an integer that can divide `x` evenly.

Given an integer `n`, return `true` *if* `n` *is a perfect number, otherwise return* `false`.

**Example 1:**

```
Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
```

**Example 2:**

```
Input: num = 7
Output: false
```

**Constraints:**

* `1 <= num <= 108`

---

## Solution & Editorial
# Intuition
A perfect number is defined as a positive integer that equals the sum of its proper positive divisors (excluding the number itself). We can directly verify this definition by checking every integer from $1$ up to $num - 1$ to accumulate all divisors.

# Approach
1. Initialize an accumulator variable `pf` to $0$ to keep track of the sum of divisors.
2. Iterate through every integer `i` from $1$ to $num - 1$.
3. Check if `i` divides `num` evenly using the modulo operator (`num % i == 0`). If it does, add `i` to `pf`.
4. After the loop completes, compare `pf` with `num`. If they are equal, return `true`; otherwise, return `false`.

### Visual Trace Walkthrough (Example 1: `num = 28`)
- Initial state: `pf = 0`
- `i = 1`: `28 % 1 == 0` -> `pf = 1`
- `i = 2`: `28 % 2 == 0` -> `pf = 1 + 2 = 3`
- `i = 3`: `28 % 3 != 0` -> `pf = 3`
- `i = 4`: `28 % 4 == 0` -> `pf = 3 + 4 = 7`
- ...continuing through up to `i = 14`: `pf = 1 + 2 + 4 + 7 + 14 = 28`
- Final check: `pf == 28` evaluates to `true`.

# Complexity
- Time complexity: $$O(n)$$ — The loop iterates from $1$ to $num - 1$, performing constant-time modulo and addition operations at each step.
- Space complexity: $$O(1)$$ — Only a single scalar integer variable `pf` is allocated, requiring constant auxiliary memory.

# Code
```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int pf = 0;
        for(int i =1 ; i < num ; i++){
            if(num%i ==0){
            pf += i;
            }
        }
        if(pf == num){
            return true;
        }
        else{
            return false;
        }
    }
};
```
