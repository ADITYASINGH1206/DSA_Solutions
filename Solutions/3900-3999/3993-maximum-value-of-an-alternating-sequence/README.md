# [3993. Maximum Value of an Alternating Sequence](https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/)
**Difficulty:** `Medium` | **Tags:** `math`, `greedy`

---

## Problem Description
You are given three integers `n`, `s`, and `m`.

A sequence `seq` of integers of length `n` is considered **valid** if:

* `seq[0] = s`.
* The sequence is **alternating**, meaning that either:
  + `seq[0] > seq[1] < seq[2] > ...`, or
  + `seq[0] < seq[1] > seq[2] < ...`.
* For every adjacent pair, `|seq[i] - seq[i - 1]| <= m`.

A sequence of length 1 is considered alternating.

Return the **maximum** possible element that can appear in any valid sequence.

**Example 1:**

**Input:** n = 4, s = 3, m = 5

**Output:** 12

**Explanation:**

* One valid sequence is `[3, 8, 7, 12]`.
* The maximum element in the sequence is 12.

**Example 2:**

**Input:** n = 2, s = 4, m = 3

**Output:** 7

**Explanation:**

* One valid sequence is `[4, 7]`.
* The maximum element in the sequence is 7.

**Constraints:**

* `1 <= n, s <= 109`
* `1 <= m <= 105`

---

## Solution & Editorial
# Intuition
To maximize the value in an alternating sequence of length $n$ starting with $s$, we want to increase the value as much as possible at every "up" step. Since we are constrained by $|seq[i] - seq[i-1]| \le m$, each increase step can add at most $m$. To maintain the alternating property, we must decrease the value by at least 1 at every "down" step.

# Approach
1. If $n=1$, the sequence is just $[s]$, so the maximum is $s$.
2. For $n > 1$, we want to maximize the number of "up" steps. In an alternating sequence starting with $s$, the sequence follows the pattern $s \to s+m \to s+m-1 \to s+2m-1 \to s+2m-2 \dots$
3. The number of "up" steps is $\lceil (n-1)/2 \rceil$, which is $n/2$ using integer division if we consider the first step as an "up" step. Specifically, for $n$ elements, there are $n-1$ transitions. The number of upward transitions is $\lfloor n/2 \rfloor$ and the number of downward transitions is $\lceil n/2 \rceil - 1$.
4. Each upward transition adds $m$, and each downward transition subtracts $1$. The total gain is $(n/2) \times m - (n/2 - 1) \times 1$.

### Visual Trace (n=4, s=3, m=5)
| Step | Operation | Value |
| :--- | :--- | :--- |
| 0 | Start | 3 |
| 1 | Up (+5) | 8 |
| 2 | Down (-1) | 7 |
| 3 | Up (+5) | 12 |

# Complexity
- Time complexity: $$O(1)$$
- Space complexity: $$O(1)$$

# Code
```cpp
class Solution {
public:
    long long maximumValue(long long n, long long s, long long m) {
        if (n == 1) return s;
        
        long long up = n / 2; 
        long long dn = up - 1; 
        
        return s + (up * m) - dn;
    }
};
```
