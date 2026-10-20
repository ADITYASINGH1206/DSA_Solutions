# [3951. Minimum Energy to Maintain Brightness](https://leetcode.com/problems/minimum-energy-to-maintain-brightness/)
**Difficulty:** `Medium` | **Tags:** `array`, `sorting`

---

## Problem Description
You are given an integer `n`, representing `n` light bulbs arranged in a line and indexed from 0 to `n - 1`.

You are also given an integer `brightness` and a 2D integer array `intervals`, where `intervals[i] = [starti, endi]` represents an **inclusive** time interval during which the lighting requirement **must** be satisfied.

At each time unit, every bulb can independently be either on or off. A bulb that is on **illuminates** its own position and its **adjacent** positions, if they exist.

The **total illumination** at a time unit is the number of **illuminated** positions. Each position is counted **at most once**.

For every integer time unit covered by **at least** one interval in `intervals`, the **total illumination** must be **at least** `brightness`. At time units not covered by any interval, all bulbs may remain off. Each bulb that is on consumes 1 unit of energy for that time unit.

Return an integer denoting the **minimum** total energy required.

**Example 1:**

**Input:** n = 5, brightness = 5, intervals = [[6,12]]

**Output:** 14

**Explanation:**

* Turn on the light bulbs at positions 1 and 4.
* Current state of line: `0 1 0 0 1`.
* All 5 positions are illuminated, so the required brightness is reached.
* The active interval has length `12 - 6 + 1 = 7`, so the total energy is `2 * 7 = 14`.

**Example 2:**

**Input:** n = 2, brightness = 1, intervals = [[0,0],[2,2]]

**Output:** 2

**Explanation:**

* Turn on one light bulb during each active interval.
* Each interval has length 1, so the total active time is `1 + 1 = 2`.
* The total energy is `1 * 2 = 2`.

**Example 3:**

**Input:** n = 4, brightness = 2, intervals = [[1,3],[2,4]]

**Output:** 4

**Explanation:**

* Turn on one light bulb. It can illuminate at least 2 positions.
* The active intervals overlap, so the total active time is the length of `[1,4]`, which is 4.
* The total energy is `1 * 4 = 4`.

**Constraints:**

* `1 <= n <= 106`
* `1 <= brightness <= n`
* `1 <= intervals.length <= 105`
* `intervals[i] == [starti, endi]`
* `0 <= starti <= endi <= 109`

---

## Solution & Editorial
# Intuition
To minimize energy, we must first determine the minimum number of bulbs required to achieve the target `brightness`. Since each bulb at position `i` illuminates `i-1`, `i`, and `i+1`, a single bulb covers 3 positions (or 2 at the boundaries). Thus, to cover `brightness` positions, we need at least `ceil(brightness / 3)` bulbs. Since the energy consumption is constant per time unit, we simply need to calculate the total duration of all active intervals by merging overlapping ones.

# Approach
1. **Calculate Minimum Bulbs**: Each bulb covers 3 positions. The minimum bulbs required is `(brightness + 2) / 3` using integer division.
2. **Merge Intervals**: Sort the `intervals` by start time. Iterate through the sorted list, maintaining a `start` and `end` for the current merged interval. If the next interval overlaps with the current one, update the `end` to the maximum of both. If it doesn't overlap, add the duration `(end - start + 1)` to `totalTime` and reset the current interval.
3. **Calculate Energy**: Multiply the total merged duration by the minimum bulbs required.

### Visual Trace (Example 3: n=4, brightness=2, intervals=[[1,3],[2,4]])
| Step | Interval | Merged Start | Merged End | Total Time |
| :--- | :--- | :--- | :--- | :--- |
| Init | [1,3] | 1 | 3 | 0 |
| Merge | [2,4] | 1 | 4 | 0 |
| Final | - | - | - | 4 |

# Complexity
- Time complexity: $$O(M \log M)$$, where $$M$$ is the number of intervals, due to the sorting step. The subsequent linear scan takes $$O(M)$$.
- Space complexity: $$O(1)$$ (or $$O(M)$$ depending on the sorting implementation's stack usage), as we only store a few variables for interval merging.

# Code
```cpp
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long ans = 0;
        if (intervals.empty() || brightness <= 0) {
            return 0;
        }
        
        long long energy = (brightness + 2) / 3;
        
        sort(intervals.begin(), intervals.end());
        
        long long totalTime = 0;
        long long start = intervals[0][0];
        long long end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(end, (long long)intervals[i][1]);
            } else {
                totalTime += (end - start + 1);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        totalTime += (end - start + 1);
        ans = totalTime * energy;
        
        return ans;
    }
};
```
