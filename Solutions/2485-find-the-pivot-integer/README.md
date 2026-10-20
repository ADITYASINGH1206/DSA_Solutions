# [2485. Find the Pivot Integer](https://leetcode.com/problems/find-the-pivot-integer/)
**Difficulty:** `Easy` | **Tags:** `math`, `prefix-sum`

---

## Problem Description
Given a positive integer `n`, find the **pivot integer** `x` such that:

* The sum of all elements between `1` and `x` inclusively equals the sum of all elements between `x` and `n` inclusively.

Return *the pivot integer* `x`. If no such integer exists, return `-1`. It is guaranteed that there will be at most one pivot index for the given input.

**Example 1:**

```
Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
```

**Example 2:**

```
Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
```

**Example 3:**

```
Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
```

**Constraints:**

* `1 <= n <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks for an integer $x$ such that the sum of integers from $1$ to $x$ equals the sum of integers from $x$ to $n$. Since the sum of integers from $1$ to $n$ is a known arithmetic series, we can iterate through all possible candidates for $x$ and verify the condition efficiently.

# Approach
1. Calculate the total sum of the arithmetic series from $1$ to $n$ using the formula $\frac{n(n+1)}{2}$.
2. Iterate through each integer $i$ from $1$ to $n$, maintaining a running `l_sum` (sum from $1$ to $i$).
3. For each $i$, calculate the `r_sum` (sum from $i$ to $n$). Since the total sum includes $i$ twice if we simply subtract `l_sum` from `total`, we calculate `r_sum` as `(total - l_sum) + i`.
4. If `l_sum == r_sum`, then $i$ is the pivot integer. Return $i$.
5. If the loop completes without finding a match, return -1.

### Visual Trace (n = 8)
| i | l_sum | r_sum | Match? |
|---|---|---|---|
| 1 | 1 | 36 | No |
| ... | ... | ... | ... |
| 6 | 21 | 21 | Yes (Return 6) |

# Complexity
- Time complexity: $$O(n)$$ — We perform a single pass from $1$ to $n$, performing constant-time arithmetic operations at each step.
- Space complexity: $$O(1)$$ — We only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        int sum = (n*(n+1))/2;
        int l_sum = 0;
        int r_sum = 0;
        int total = (n*(n+1))/2;
        for(int i =1;i<=n;i++){
            l_sum += i;
            r_sum = (total-l_sum)+i;
            if(l_sum == r_sum) return i;
        }
        return -1;
    }
};
```
