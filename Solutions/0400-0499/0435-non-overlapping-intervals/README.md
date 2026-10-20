# [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `greedy`, `sorting`

---

## Problem Description
Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`, return *the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping*.

**Note** that intervals which only touch at a point are **non-overlapping**. For example, `[1, 2]` and `[2, 3]` are non-overlapping.

**Example 1:**

```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
```

**Example 2:**

```
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
```

**Example 3:**

```
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
```

**Constraints:**

* `1 <= intervals.length <= 105`
* `intervals[i].length == 2`
* `-5 * 104 <= starti < endi <= 5 * 104`

---

## Solution & Editorial
# Intuition
To minimize the number of removed intervals to eliminate all overlaps, we can maximize the number of mutually compatible intervals we keep. This is a classic interval scheduling problem. By greedily selecting intervals that finish as early as possible, we leave the maximum possible room for subsequent intervals.

# Approach
1. Check if the `intervals` vector is empty; if so, return `0`.
2. Sort the `intervals` array in ascending order based on their end times (`a[1] < b[1]`).
3. Initialize `ans = 0` to count the removed intervals and `last_end = intervals[0][1]` to track the end time of the last kept interval.
4. Iterate from `i = 1` to the end of the `intervals` vector:
   - If the current interval's start time `intervals[i][0]` is strictly less than `last_end`, an overlap occurs. We must remove this interval, so increment `ans++`.
   - Otherwise, no overlap occurs. Update `last_end = intervals[i][1]`.
5. Return `ans`.

### Visual Trace (Example 1)
Input: `intervals = [[1,2],[2,3],[3,4],[1,3]]`
After sorting by end times: `[[1,2], [2,3], [1,3], [3,4]]`

| `i` | Current Interval | `last_end` | Overlap? (`start < last_end`) | Action | `ans` | Updated `last_end` |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 | `[2,3]` | 2 | No (`2 < 2` is false) | Keep | 0 | 3 |
| 2 | `[1,3]` | 3 | Yes (`1 < 3` is true) | Remove | 1 | 3 |
| 3 | `[3,4]` | 3 | No (`3 < 3` is false) | Keep | 1 | 4 |

Final Output: `1`

# Complexity
- Time complexity: $$O(N \log N)$$ where $$N$$ is the number of intervals. Sorting the intervals takes $$O(N \log N)$$ time, and the subsequent linear scan takes $$O(N)$$ time.
- Space complexity: $$O(1)$$ auxiliary space (ignoring sorting stack overhead which depends on the sorting implementation).

# Code
```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int last_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last_end) {
                ans++; 
            } else {
                last_end = intervals[i][1];
            }
        }
        return ans;
    }
};
```
