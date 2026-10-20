# [788. Rotated Digits](https://leetcode.com/problems/rotated-digits/)
**Difficulty:** `Medium` | **Tags:** `math`, `dynamic-programming`

---

## Problem Description
An integer `x` is a **good** if after rotating each digit individually by 180 degrees, we get a valid number that is different from `x`. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

* `0`, `1`, and `8` rotate to themselves,
* `2` and `5` rotate to each other (in this case they are rotated in a different direction, in other words, `2` or `5` gets mirrored),
* `6` and `9` rotate to each other, and
* the rest of the numbers do not rotate to any other number and become invalid.

Given an integer `n`, return *the number of **good** integers in the range* `[1, n]`.

**Example 1:**

```
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
```

**Example 2:**

```
Input: n = 1
Output: 0
```

**Example 3:**

```
Input: n = 2
Output: 1
```

**Constraints:**

* `1 <= n <= 104`

---

## Solution & Editorial
# Intuition
To determine if an integer is "good", every digit must rotate to a valid digit (0, 1, 8, 2, 5, 6, 9), and the rotated number must be strictly different from the original number. Since the constraint is small ($n \le 10^4$), we can simulate the rotation for every number in the range $[1, n]$ using a direct lookup table.

# Approach
1. Initialize a lookup array `d` of size 10 representing the 180-degree rotation mapping for each digit: `0` $\rightarrow$ `0`, `1` $\rightarrow$ `1`, `2` $\rightarrow$ `5`, `3` $\rightarrow$ invalid (`-1`), `4` $\rightarrow$ invalid (`-1`), `5` $\rightarrow$ `2`, `6` $\rightarrow$ `9`, `7` $\rightarrow$ invalid (`-1`), `8` $\rightarrow$ `8`, `9` $\rightarrow$ `6`.
2. Define a lambda function `check(int x)` that extracts each digit of $x$, maps it using array `d`, and constructs the rotated number $y$. If any digit maps to `-1`, return `false`. Also ensure that $x \neq y$.
3. Iterate from $i = 1$ to $n$, accumulating the count of numbers for which `check(i)` returns `true` into `ans`.

### Visual Walkthrough for $n = 10$
- $i = 1$: Digits map to 1. $x = y = 1$, not good ($1 \neq 1$ fails).
- $i = 2$: Digit 2 maps to 5. $x = 2, y = 5$, good ($2 \neq 5$).
- $i = 5$: Digit 5 maps to 2. $x = 5, y = 2$, good ($5 \neq 2$).
- $i = 6$: Digit 6 maps to 9. $x = 6, y = 9$, good ($6 \neq 9$).
- $i = 10$: Digits map to 10. $x = y = 10$, not good.

# Complexity
- Time complexity: $$O(n \log_{10} n)$$ — We iterate $n$ times, and for each number, extracting and transforming digits takes proportional to the number of digits, which is $\log_{10} n$.
- Space complexity: $$O(1)$$ — Only a fixed-size array of 10 integers and a few scalar variables are used.

# Code
```cpp
class Solution {
public:
    int rotatedDigits(int n) {
        int d[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        auto check = [&](int x) -> bool {
            int y = 0, t = x;
            int k = 1;
            while (t) {
                int v = t % 10;
                if (d[v] == -1) {
                    return false;
                }
                y = d[v] * k + y;
                k *= 10;
                t /= 10;
            }
            return x != y;
        };
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += check(i);
        }
        return ans;
    }
};
```
