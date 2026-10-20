# [57. Insert Interval](https://leetcode.com/problems/insert-interval/)
**Difficulty:** `Medium` | **Tags:** `array`

---

## Problem Description
You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [starti, endi]` represent the start and the end of the `ith` interval and `intervals` is sorted in ascending order by `starti`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.

Two intervals are considered overlapping if they share **at least** one point.

Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `starti` and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return `intervals` *after the insertion*.

**Note** that you don't need to modify `intervals` in-place. You can make a new array and return it.

**Example 1:**

```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**Example 2:**

```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```

**Constraints:**

* `0 <= intervals.length <= 104`
* `intervals[i].length == 2`
* `0 <= starti <= endi <= 105`
* `intervals` is sorted by `starti` in **ascending** order.
* `newInterval.length == 2`
* `0 <= start <= end <= 105`

---

## Solution & Editorial
# Intuition
The problem asks us to insert a new interval into an already sorted, non-overlapping list of intervals and merge any overlaps if necessary. Since the input intervals are sorted by their start times, we can process them in three distinct linear phases: first, add all intervals that end strictly before the new interval begins; second, merge all overlapping intervals with the new interval; and finally, add all remaining intervals after the new interval.

# Approach
1. Initialize an empty result vector `ans` and pointer `i = 0` to iterate through the given `intervals`.
2. **Phase 1 (Before Overlap):** While `i < n` and the current interval's end time `intervals[i][1]` is less than `newInterval[0]`, push `intervals[i]` into `ans` and increment `i`.
3. **Phase 2 (During Overlap):** While `i < n` and the current interval's start time `intervals[i][0]` is less than or equal to `newInterval[1]`, merge them by updating `newInterval[0]` to the minimum start and `newInterval[1]` to the maximum end. Increment `i`.
4. Push the fully merged `newInterval` into `ans`.
5. **Phase 3 (After Overlap):** Push all remaining intervals from `intervals` into `ans`.
6. Return `ans`.

### Visual Trace Walkthrough (Example 1)
`intervals = [[1,3],[6,9]]`, `newInterval = [2,5]`

| Phase | Condition / Action | `i` | `newInterval` | `ans` | Explanation |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Phase 1** | `intervals[0][1] < 2` (3 < 2 is false) | `0` | `[2,5]` | `[]` | Stops before adding `[1,3]` because `3 >= 2` |
| **Phase 2** | `intervals[0][0] <= 5` (1 <= 5 is true) | `0` | `[min(2,1), max(5,3)] = [1,5]` | `[]` | Merged `[1,3]`, `i` becomes 1 |
| **Phase 2** | `intervals[1][0] <= 5` (6 <= 5 is false) | `1` | `[1,5]` | `[]` | Stops merging |
| **Push** | Push `newInterval` | `1` | `[1,5]` | `[[1,5]]` | Insert merged interval |
| **Phase 3** | Append remaining `intervals[1]` | `2` | `[1,5]` | `[[1,5],[6,9]]` | Loop terminates, returns `ans` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of intervals in `intervals`. Each interval is visited at most once across the three sequential `while` loops.
- Space complexity: $$O(N)$$ auxiliary space to store the resulting intervals in the output vector `ans` (excluding the output vector, space complexity is $$O(1)$$).

# Code
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;

    }
};
```
