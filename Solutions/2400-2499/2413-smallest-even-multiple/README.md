# [2413. Smallest Even Multiple](https://leetcode.com/problems/smallest-even-multiple/)
**Difficulty:** `Easy` | **Tags:** `math`, `number-theory`

---

## Problem Description
Given a **positive** integer `n`, return *the smallest positive integer that is a multiple of **both*** `2` *and* `n`.

**Example 1:**

```
Input: n = 5
Output: 10
Explanation: The smallest multiple of both 5 and 2 is 10.
```

**Example 2:**

```
Input: n = 6
Output: 6
Explanation: The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.
```

**Constraints:**

* `1 <= n <= 150`

---

## Solution & Editorial
# Intuition
The problem asks for the Least Common Multiple (LCM) of 2 and n. Since 2 is a prime number, the LCM is simply n if n is already divisible by 2, or 2 * n if n is odd.

# Approach
1. Initialize `ans` with the value of `n`.
2. Check if `n` is odd using the modulo operator (`n % 2 != 0`).
3. If `n` is odd, the smallest multiple of both 2 and `n` must be `n * 2`.
4. If `n` is even, `n` is already a multiple of 2, so return `n`.

### Visual Trace (n = 5)
| Step | Variable | Value | Logic |
| :--- | :--- | :--- | :--- |
| 1 | `n` | 5 | Input |
| 2 | `ans` | 5 | Initialize |
| 3 | `5 % 2` | 1 | Odd check (True) |
| 4 | `ans` | 10 | Return 5 * 2 |

# Complexity
- Time complexity: $$O(1)$$ — The solution performs a single arithmetic check and multiplication, independent of the input size.
- Space complexity: $$O(1)$$ — Only a single integer variable is used for storage.

# Code
```cpp
class Solution {
public:
    int smallestEvenMultiple(int n) {
        int ans =n;
        if(n%2 !=0){
            return ans = n*2;
        }
        return ans;
    }
};
```
