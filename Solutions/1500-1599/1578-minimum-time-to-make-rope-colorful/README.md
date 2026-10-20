# [1578. Minimum Time to Make Rope Colorful](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `dynamic-programming`, `greedy`

---

## Problem Description
Alice has `n` balloons arranged on a rope. You are given a **0-indexed** string `colors` where `colors[i]` is the color of the `ith` balloon.

Alice wants the rope to be **colorful**. She does not want **two consecutive balloons** to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it **colorful**. You are given a **0-indexed** integer array `neededTime` where `neededTime[i]` is the time (in seconds) that Bob needs to remove the `ith` balloon from the rope.

Return *the **minimum time** Bob needs to make the rope **colorful***.

**Example 1:**

```
Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
```

**Example 2:**

```
Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
```

**Example 3:**

```
Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
```

**Constraints:**

* `n == colors.length == neededTime.length`
* `1 <= n <= 105`
* `1 <= neededTime[i] <= 104`
* `colors` contains only lowercase English letters.

---

## Solution & Editorial
# Intuition
To make the rope colorful, we must ensure no two adjacent balloons have the same color. When we encounter a sequence of identical consecutive colors, we must remove all but one balloon. To minimize the total time, we should always keep the balloon with the maximum `neededTime` and remove all others in that group.

# Approach
1. Iterate through the `colors` string starting from the second balloon (index 1).
2. If the current balloon `colors[i]` matches the previous one `colors[i-1]`, we have a conflict.
3. To resolve the conflict, add the smaller of the two `neededTime` values to our total `sum` (representing the cost of removing the cheaper balloon).
4. Update the current balloon's `neededTime` to be the maximum of the two values. This effectively "carries forward" the cost of the most expensive balloon encountered so far in the current consecutive group, ensuring it remains for future comparisons.

### Visual Trace (Example: colors = "abaac", neededTime = [1,2,3,4,5])
| Index (i) | colors[i] == colors[i-1] | Action | sum | time[i] (updated) |
| :--- | :--- | :--- | :--- | :--- |
| 1 | No | - | 0 | 2 |
| 2 | No | - | 0 | 3 |
| 3 | Yes ('a'=='a') | sum += min(3, 4) | 3 | 4 |
| 4 | No | - | 3 | 5 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of balloons. We perform a single linear pass through the input arrays.
- Space complexity: $$O(1)$$, as we only use a few integer variables and modify the input array in-place.

# Code
```cpp
class Solution {
public:
    int minCost(string col, vector<int>& time) {
        int n = col.size(), sum = 0;
        
        for (int i = 1; i < n; i++) {
            if (col[i] == col[i - 1]) {
                sum += min(time[i], time[i - 1]);
                time[i] = max(time[i], time[i - 1]);
            }
        }
        return sum;
    }
};
```
