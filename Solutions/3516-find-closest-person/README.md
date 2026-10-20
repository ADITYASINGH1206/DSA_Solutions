# [3516. Find Closest Person](https://leetcode.com/problems/find-closest-person/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
You are given three integers `x`, `y`, and `z`, representing the positions of three people on a number line:

* `x` is the position of Person 1.
* `y` is the position of Person 2.
* `z` is the position of Person 3, who does **not** move.

Both Person 1 and Person 2 move toward Person 3 at the **same** speed.

Determine which person reaches Person 3 **first**:

* Return 1 if Person 1 arrives first.
* Return 2 if Person 2 arrives first.
* Return 0 if both arrive at the **same** time.

Return the result accordingly.

**Example 1:**

**Input:** x = 2, y = 7, z = 4

**Output:** 1

**Explanation:**

* Person 1 is at position 2 and can reach Person 3 (at position 4) in 2 steps.
* Person 2 is at position 7 and can reach Person 3 in 3 steps.

Since Person 1 reaches Person 3 first, the output is 1.

**Example 2:**

**Input:** x = 2, y = 5, z = 6

**Output:** 2

**Explanation:**

* Person 1 is at position 2 and can reach Person 3 (at position 6) in 4 steps.
* Person 2 is at position 5 and can reach Person 3 in 1 step.

Since Person 2 reaches Person 3 first, the output is 2.

**Example 3:**

**Input:** x = 1, y = 5, z = 3

**Output:** 0

**Explanation:**

* Person 1 is at position 1 and can reach Person 3 (at position 3) in 2 steps.
* Person 2 is at position 5 and can reach Person 3 in 2 steps.

Since both Person 1 and Person 2 reach Person 3 at the same time, the output is 0.

**Constraints:**

* `1 <= x, y, z <= 100`

---

## Solution & Editorial
# Intuition
Since both people move at the same speed, the time taken to reach Person 3 is directly proportional to the distance between their starting positions and the target position `z`. We can determine the winner by comparing the absolute differences between their positions and `z`.

# Approach
1. Calculate the distance of Person 1 as `dist1 = abs(x - z)`.
2. Calculate the distance of Person 2 as `dist2 = abs(y - z)`.
3. Compare `dist1` and `dist2`:
   - If `dist1 < dist2`, Person 1 is closer, return 1.
   - If `dist1 > dist2`, Person 2 is closer, return 2.
   - If `dist1 == dist2`, they arrive simultaneously, return 0.

### Visual Trace (Example 1: x=2, y=7, z=4)
| Variable | Value | Calculation |
| :--- | :--- | :--- |
| x | 2 | - |
| y | 7 | - |
| z | 4 | - |
| dist1 | 2 | abs(2 - 4) = 2 |
| dist2 | 3 | abs(7 - 4) = 3 |
| Result | 1 | 2 < 3, so return 1 |

# Complexity
- Time complexity: $$O(1)$$. The solution performs a constant number of arithmetic operations and comparisons regardless of input size.
- Space complexity: $$O(1)$$. No additional data structures are used.

# Code
```cpp
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int ans = 0;
        if(abs(x-z) < abs(y-z)){
            ans = 1;
        } 
        else if(abs(x-z) > abs(y-z)){
            ans = 2;
        }
        return ans;
    }
};
```
