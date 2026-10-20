# [258. Add Digits](https://leetcode.com/problems/add-digits/)
**Difficulty:** `Easy` | **Tags:** `math`, `simulation`, `number-theory`

---

## Problem Description
Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.

**Example 1:**

```
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
```

**Example 2:**

```
Input: num = 0
Output: 0
```

**Constraints:**

* `0 <= num <= 231 - 1`

**Follow up:** Could you do it without any loop/recursion in `O(1)` runtime?

---

## Solution & Editorial
# Intuition
The problem requires repeatedly summing the digits of an integer until a single-digit number remains. This can be naturally modeled as a recursive process where each step extracts the digits of the current number, accumulates their sum, and checks if the result requires further reduction.

# Approach
1. Define a recursive helper function `helper(int& x, int& ans)` that takes the current integer value `x` and accumulates the sum of its digits into `ans`.
2. Inside the helper function, extract each digit using modulo 10 (`n % 10`), add it to `ans`, and reduce `n` by integer division (`n /= 10`).
3. After summing the digits, check if the accumulated sum `ans` is still greater than or equal to 10. If so, recursively call `helper(ans, ans)` to perform another round of digit summation.
4. In the main `addDigits` function, initialize `ans`, invoke `helper(num, ans)`, and return the final single-digit result.

### Visual Walkthrough (Example 1: num = 38)
- **Initial Call:** `addDigits(38)` calls `helper(38, ans)`.
- **First Helper Execution (`n = 38`):**
  - Digit `8`: `ans = 8`, `n = 3`
  - Digit `3`: `ans = 11`, `n = 0`
  - Since `ans (11) >= 10`, recurse `helper(11, ans)`.
- **Second Helper Execution (`n = 11`):**
  - Digit `1`: `ans = 1`, `n = 1`
  - Digit `1`: `ans = 2`, `n = 0`
  - Since `ans (2) < 10`, recursion terminates.
- **Return:** `ans = 2`.

# Complexity
- Time complexity: $$O(\log_{10} \text{num})$$ — Each recursive step processes the number of digits of the current value, which decreases logarithmically with base 10 at each reduction phase.
- Space complexity: $$O(\log_{10} \text{num})$$ — Auxiliary stack space required by the recursion depth, which is proportional to the number of reduction steps.

# Code
```cpp
class Solution {
public:
    void helper(int& x,int& ans){
        int n = x;
        ans = 0;
        while(n>0){
            int digit = n%10;
            ans+= digit;
            n/=10;
        }

        if(ans>=10) {
            helper(ans,ans);
        } 
    }

    int addDigits(int num) {
        int ans = 0;
        helper(num,ans);
        return ans;
    }
};
```
