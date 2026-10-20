# [4000. Largest Integer With Given Digit Sum](https://leetcode.com/problems/largest-integer-with-given-digit-sum/)
**Difficulty:** `Easy` | **Tags:** `math`, `greedy`

---

## Problem Description
You are given two non-negative integers `n` and `s`.

Return the **largest** integer that has **at most** `n` digits and whose sum of digits is `s`. If no such integer exists, return -1.

**Example 1:**

**Input:** n = 2, s = 9

**Output:** 90

**Explanation:**

The largest integer with at most 2 digits that has a sum of digits of 9 is 90.

**Example 2:**

**Input:** n = 2, s = 19

**Output:** -1

**Explanation:**

There is no integer with at most 2 digits that has a sum of digits of 19, so the answer is -1.

**Example 3:**

**Input:** n = 5, s = 0

**Output:** 0

**Explanation:**

The only non-negative integer whose digits sum to 0 is 0.

**Constraints:**

* `1 <= n <= 5`
* `0 <= s <= 100`

---

## Solution & Editorial
# Intuition
To maximize an integer with a fixed number of digits and a target digit sum, we must prioritize placing the largest possible digits (9) in the most significant positions (leftmost). Since we are allowed at most $n$ digits, we can greedily fill $n$ positions from left to right.

# Approach
1. Handle edge cases: If $s=0$, the only valid number is 0. If $s > 9 \times n$, it is impossible to reach the sum with $n$ digits, so return -1.
2. Iterate $n$ times to construct the number digit by digit.
3. In each iteration, pick the largest possible digit $d = \min(9, s)$. Append $d$ to the result string and subtract $d$ from the remaining sum $s$.
4. Convert the resulting string to an integer.

### Visual Trace (n=2, s=9)
| Iteration | Remaining s | Digit (min(9, s)) | Result String |
|-----------|-------------|-------------------|---------------|
| 1         | 9           | 9                 | "9"           |
| 2         | 0           | 0                 | "90"          |

# Complexity
- Time complexity: $$O(n)$$, where $n$ is the maximum number of digits. We perform a constant number of operations per digit.
- Space complexity: $$O(n)$$, required to store the string representation of the digits before conversion.

# Code
```cpp
class Solution {
public:
    int largestInteger(int n, int s) {
        if(s==0){
            return 0;
        }
        else if(s>9*n){
            return -1;
        }

        string ans = "";
        for(int i =0;i<n;i++){
            int digit = min(9,s);
            ans+=char(digit+'0');
            s-=digit;
        }
        return stoi(ans);
    }
};
```
