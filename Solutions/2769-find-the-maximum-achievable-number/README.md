# [2769. Find the Maximum Achievable Number](https://leetcode.com/problems/find-the-maximum-achievable-number/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
Given two integers, `num` and `t`. A **number** `x`is **achievable** if it can become equal to `num` after applying the following operation **at most** `t` times:

* Increase or decrease `x` by `1`, and *simultaneously* increase or decrease `num` by `1`.

Return the **maximum** possible value of `x`.

**Example 1:**

**Input:** num = 4, t = 1

**Output:** 6

**Explanation:**

Apply the following operation once to make the maximum achievable number equal to `num`:

* Decrease the maximum achievable number by 1, and increase `num` by 1.

**Example 2:**

**Input:** num = 3, t = 2

**Output:** 7

**Explanation:**

Apply the following operation twice to make the maximum achievable number equal to `num`:

* Decrease the maximum achievable number by 1, and increase `num` by 1.

**Constraints:**

* `1 <= num, t <= 50`

---

## Solution & Editorial
# Intuition
To make a number $x$ equal to $num$ in $t$ operations where both change by 1, we observe that each operation allows us to change the difference between $x$ and $num$ by 2. Specifically, if we decrease $x$ by 1 and increase $num$ by 1, the gap between them decreases by 2. To maximize $x$, we perform this operation $t$ times, effectively shifting $x$ away from $num$ by $2t$.

# Approach
1. Let the initial difference be $D = x - num$. 
2. In one operation, we can change $x$ by $\pm 1$ and $num$ by $\pm 1$. To maximize $x$, we choose to decrease $x$ and increase $num$ by 1 in each step.
3. After $t$ steps, the new value of $x$ becomes $x - t$ and the new value of $num$ becomes $num + t$. 
4. Setting these equal: $x - t = num + t$, which simplifies to $x = num + 2t$.

### Visual Trace (Example 1: num=4, t=1)
| Step | x | num | Operation |
| :--- | :--- | :--- | :--- |
| Initial | 6 | 4 | N/A |
| 1 | 5 | 5 | x-1, num+1 |

# Complexity
- Time complexity: $$O(1)$$ — The calculation involves a single arithmetic expression.
- Space complexity: $$O(1)$$ — No auxiliary space is used.

# Code
```cpp
class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num+2*t;
    }
};
```
