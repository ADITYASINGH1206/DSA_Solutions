# [2652. Sum Multiples](https://leetcode.com/problems/sum-multiples/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
Given a positive integer `n`, find the sum of all integers in the range `[1, n]` **inclusive** that are divisible by `3`, `5`, or `7`.

Return *an integer denoting the sum of all numbers in the given range satisfying the constraint.*

**Example 1:**

```
Input: n = 7
Output: 21
Explanation: Numbers in the range [1, 7] that are divisible by 3, 5, or 7 are 3, 5, 6, 7. The sum of these numbers is 21.
```

**Example 2:**

```
Input: n = 10
Output: 40
Explanation: Numbers in the range [1, 10] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9, 10. The sum of these numbers is 40.
```

**Example 3:**

```
Input: n = 9
Output: 30
Explanation: Numbers in the range [1, 9] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9. The sum of these numbers is 30.
```

**Constraints:**

* `1 <= n <= 103`

---

## Solution & Editorial
# Intuition
To find the sum of all integers in the range `[1, n]` divisible by 3, 5, or 7, we can iterate through every integer from 1 to `n` and check the divisibility condition for each.

# Approach
1. Initialize an integer variable `ans` to 0 to store the cumulative sum.
2. Iterate through each integer `i` from 1 up to `n` (inclusive).
3. For each `i`, check if it is divisible by 3, 5, or 7 using the modulo operator (`i % 3 == 0 || i % 5 == 0 || i % 7 == 0`).
4. If the condition evaluates to true, add `i` to `ans`.
5. Return `ans` after the loop completes.

### Visual Trace (n = 7)
| i | Divisible by 3, 5, or 7? | ans (Running Sum) |
|---|---|---|
| 1 | No | 0 |
| 2 | No | 0 |
| 3 | Yes | 3 |
| 4 | No | 3 |
| 5 | Yes | 8 |
| 6 | Yes | 14 |
| 7 | Yes | 21 |

# Complexity
- Time complexity: $$O(n)$$ — We perform a single pass from 1 to `n`, executing constant-time arithmetic and logical operations at each step.
- Space complexity: $$O(1)$$ — We only use a single integer variable `ans` to maintain the state, regardless of the input size `n`.

# Code
```cpp
class Solution {
public:
    int sumOfMultiples(int n) {
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if((i%3 ==0) || (i%5 ==0) || (i%7 ==0)) ans+= i;
        }
        return ans;
    }
};
```
