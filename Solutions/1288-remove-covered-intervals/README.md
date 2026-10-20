# [1288. Remove Covered Intervals](https://leetcode.com/problems/remove-covered-intervals/)
**Difficulty:** `Medium` | **Tags:** `array`, `sorting`

---

## Problem Description
Given an array `intervals` where `intervals[i] = [li, ri]` represent the interval `[li, ri)`, remove all intervals that are covered by another interval in the list.

The interval `[a, b)` is covered by the interval `[c, d)` if and only if `c <= a` and `b <= d`.

Return *the number of remaining intervals*.

**Example 1:**

```
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
```

**Example 2:**

```
Input: intervals = [[1,4],[2,3]]
Output: 1
```

**Constraints:**

* `1 <= intervals.length <= 1000`
* `intervals[i].length == 2`
* `0 <= li < ri <= 105`
* All the given intervals are **unique**.

---

## Solution & Editorial
# Intuition
The problem asks us to remove all intervals that are completely covered by another interval. By sorting the intervals primarily by their starting points in ascending order, and secondarily by their ending points in descending order, we can process each interval sequentially and maintain the maximum ending point seen so far to detect coverage.

# Approach
1. Sort the input vector `A` using `ranges::sort` with a custom projection key: `pair{x[0], -x[1]}`. This sorts by start time ascending, and in case of ties, by end time descending.
2. Initialize `res = 0` to count the remaining intervals and `r = 0` to track the maximum end point encountered among processed intervals.
3. Iterate through each interval `x` in the sorted array `A`:
   - Check if `x[1] > r`. If true, the current interval extends beyond the maximum end point seen so far, meaning it is not covered, so we increment `res`.
   - Update `r = max(r, x[1])` to incorporate the current interval's end point.
4. Return `res` as the total number of remaining non-covered intervals.

### Visual Walkthrough (Example 1: `[[1,4],[3,6],[2,8]]`)
After sorting with `pair{start, -end}`, the intervals become: `[[1,4], [2,8], [3,6]]`.

| Iteration | Interval `x` | `x[1] > r` Check | Result `res` | Max End `r` | Action |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `[1, 4]` | `4 > 0` (True) | `1` | `4` | Kept |
| 2 | `[2, 8]` | `8 > 4` (True) | `2` | `8` | Kept |
| 3 | `[3, 6]` | `6 > 8` (False) | `2` | `8` | Covered & Removed |

Final output: `2`.

# Complexity
- Time complexity: $$O(N \log N)$$ — Dominated by the sorting step using `ranges::sort`. The subsequent linear scan runs in $$O(N)$$ time.
- Space complexity: $$O(\log N)$$ or $$O(N)$$ auxiliary space depending on the standard library implementation of sorting recursion stack.

# Code
```cpp
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& A) {
        ranges::sort(A, {}, [](auto& x) {
            return pair{x[0], -x[1]};
        });

        int res = 0, r = 0;

        for (auto& x : A) {
            res += x[1] > r;
            r = max(r, x[1]);
        }

        return res;
    }
};
```
