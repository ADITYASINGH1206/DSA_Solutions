# [342. Power of Four](https://leetcode.com/problems/power-of-four/)
**Difficulty:** `Easy` | **Tags:** `math`, `bit-manipulation`, `recursion`

---

## Problem Description
Given an integer `n`, return *`true` if it is a power of four. Otherwise, return `false`*.

An integer `n` is a power of four, if there exists an integer `x` such that `n == 4x`.

**Example 1:**

```
Input: n = 16
Output: true
```

**Example 2:**

```
Input: n = 5
Output: false
```

**Example 3:**

```
Input: n = 1
Output: true
```

**Constraints:**

* `-231 <= n <= 231 - 1`

**Follow up:** Could you solve it without loops/recursion?

---

## Solution & Editorial
# Intuition
An integer is a power of four if it is strictly greater than zero and can be repeatedly divided by $4$ until it reduces to $1$.

# Approach
1. Check if `n <= 0`. If so, return `false` immediately since powers of four are strictly positive.
2. Use a `while` loop to continuously divide `n` by $4$ as long as `n % 4 == 0` is true.
3. After the loop terminates, check if the remaining value of `n` equals `1`. If it does, `n` was an exact power of four.

### Visual Trace Walkthrough (Example 1: n = 16)
- Initial: `n = 16`, `16 <= 0` is false.
- Iteration 1: `16 % 4 == 0` is true $\rightarrow$ `n = 16 / 4 = 4`.
- Iteration 2: `4 % 4 == 0` is true $\rightarrow$ `n = 4 / 4 = 1`.
- Iteration 3: `1 % 4 == 0` is false. Loop terminates.
- Return `n == 1` $\rightarrow$ `1 == 1` is true.

# Complexity
- Time complexity: $$O(\log_4 n)$$ — In each iteration, `n` is divided by $4$, resulting in at most $\log_4 n$ divisions.
- Space complexity: $$O(1)$$ — Only uses primitive variables, requiring constant auxiliary space.

# Code
```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        while(n % 4==0){
            n /=4;
        }
        return n==1;
    }
};
```
