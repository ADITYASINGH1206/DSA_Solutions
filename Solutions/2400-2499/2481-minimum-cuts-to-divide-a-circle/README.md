# [2481. Minimum Cuts to Divide a Circle](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/)
**Difficulty:** `Easy` | **Tags:** `math`, `geometry`

---

## Problem Description
A **valid cut** in a circle can be:

* A cut that is represented by a straight line that touches two points on the edge of the circle and passes through its center, or
* A cut that is represented by a straight line that touches one point on the edge of the circle and its center.

Some valid and invalid cuts are shown in the figures below.

Given the integer `n`, return *the **minimum** number of cuts needed to divide a circle into* `n` *equal slices*.

**Example 1:**

```
Input: n = 4
Output: 2
Explanation: 
The above figure shows how cutting the circle twice through the middle divides it into 4 equal slices.
```

**Example 2:**

```
Input: n = 3
Output: 3
Explanation:
At least 3 cuts are needed to divide the circle into 3 equal slices. 
It can be shown that less than 3 cuts cannot result in 3 slices of equal size and shape.
Also note that the first cut will not divide the circle into distinct parts.
```

**Constraints:**

* `1 <= n <= 100`

---

## Solution & Editorial
# Intuition
To divide a circle into $n$ equal slices, we must consider the geometry of the cuts. A single cut passing through the center creates two slices. If $n$ is even, we can use $n/2$ diameter cuts to create $n$ equal slices. If $n$ is odd, each cut can only contribute to one new slice boundary effectively, requiring $n$ cuts to create $n$ equal sectors. The case $n=1$ is trivial as no cuts are needed.

# Approach
1. Handle the base case: If $n = 1$, return 0, as no cuts are required to have one "slice" (the whole circle).
2. Check parity: If $n$ is even, each cut through the center creates two slices. Thus, $n/2$ cuts are sufficient.
3. Handle odd $n$: If $n$ is odd, we cannot use diameter cuts to create an even number of slices. We must perform $n$ cuts to achieve $n$ equal sectors.

### Visual Trace (n = 4)
| Step | Action | Slices Created |
| :--- | :--- | :--- |
| 1 | Cut 1 (Diameter) | 2 |
| 2 | Cut 2 (Diameter, perpendicular) | 4 |

### Visual Trace (n = 3)
| Step | Action | Slices Created |
| :--- | :--- | :--- |
| 1 | Cut 1 | 1 (partial) |
| 2 | Cut 2 | 2 (partial) |
| 3 | Cut 3 | 3 (full) |

# Complexity
- Time complexity: $$O(1)$$. The solution uses simple arithmetic operations and conditional checks, independent of the input size.
- Space complexity: $$O(1)$$. No auxiliary data structures are used.

# Code
```cpp
class Solution {
public:
    int numberOfCuts(int n) {
        if(n==1)return 0;
        if (n % 2 == 0) return n / 2;
        return n;
    }
};
```
