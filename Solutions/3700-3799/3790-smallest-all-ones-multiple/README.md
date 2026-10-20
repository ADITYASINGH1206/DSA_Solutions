# [3790. Smallest All-Ones Multiple](https://leetcode.com/problems/smallest-all-ones-multiple/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `math`

---

## Problem Description
You are given a positive integer `k`.

Find the **smallest** integer `n` divisible by `k` that consists of **only the digit 1** in its decimal representation (e.g., 1, 11, 111, ...).

Return an integer denoting the **number of digits** in the decimal representation of `n`. If no such `n` exists, return `-1`.

**Example 1:**

**Input:** k = 3

**Output:** 3

**Explanation:**

`n = 111` because 111 is divisible by 3, but 1 and 11 are not. The length of `n = 111` is 3.

**Example 2:**

**Input:** k = 7

**Output:** 6

**Explanation:**

`n = 111111`. The length of `n = 111111` is 6.

**Example 3:**

**Input:** k = 2

**Output:** -1

**Explanation:**

There does not exist a valid `n` that is a multiple of 2.

**Constraints:**

* `2 <= k <= 105`

---

## Solution & Editorial
# Intuition
To find the smallest integer $n$ consisting only of 1s that is divisible by $k$, we observe that $n$ can be represented as a sequence of digits where each term is $10 \times \text{previous} + 1$. By working with remainders modulo $k$, we can detect divisibility without ever constructing the potentially massive integer $n$.

# Approach
1. **Divisibility Check**: Any number consisting only of 1s is not divisible by 2 or 5, as it ends in 1. If $k$ is divisible by 2 or 5, return -1 immediately.
2. **Modular Iteration**: We maintain a running remainder `rem` initialized to 0. In each iteration $i$ (from 1 to $k$), we update `rem = (rem * 10 + 1) % k`.
3. **Termination**: If `rem` becomes 0, the current length $i$ is the smallest number of digits required.

### Visual Trace (k = 3)
| Iteration (i) | Calculation: (rem * 10 + 1) % 3 | New Remainder |
| :--- | :--- | :--- |
| 1 | (0 * 10 + 1) % 3 | 1 |
| 2 | (1 * 10 + 1) % 3 | 2 |
| 3 | (2 * 10 + 1) % 3 | 0 (Found!) |

# Complexity
- Time complexity: $$O(k)$$ — We iterate at most $k$ times due to the Pigeonhole Principle; if a remainder repeats, we would have already found the cycle.
- Space complexity: $$O(1)$$ — We only store a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        
        int rem = 0;

        for (int i = 1; i <= k; i++) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) {
                return i;
            }
        }
        
        return -1;
    }
};
```
