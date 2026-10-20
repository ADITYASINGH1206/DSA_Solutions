# [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)
**Difficulty:** `Medium` | **Tags:** `array`, `sorting`, `quicksort`

---

## Problem Description
Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

**Example 1:**

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

**Example 2:**

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**Example 3:**

```
Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
```

**Constraints:**

* `1 <= intervals.length <= 104`
* `intervals[i].length == 2`
* `0 <= starti <= endi <= 104`

---

## Solution & Editorial
# Intuition
By sorting the intervals based on their starting times, we ensure that any overlapping intervals will appear adjacent to each other in the sequence. This property transforms the problem into a straightforward linear scan where we can maintain and extend the current merged interval.

# Approach
1. Retrieve the size of the input `intervals` array and sort the array lexicographically using `std::sort`. This places intervals with smaller starting points first.
2. Initialize an empty dynamic array `ans` to store the resulting merged intervals.
3. Iterate through each interval in the sorted `intervals` array:
   - If `ans` is empty or the current interval's start time (`intervals[i][0]`) is strictly greater than the last interval's end time in `ans` (`ans.back()[1]`), no overlap exists. Push the current interval directly into `ans`.
   - Otherwise, an overlap exists. Update the end time of the last interval in `ans` to the maximum of its current end time and the current interval's end time (`max(ans.back()[1], intervals[i][1])`).
4. Return the finalized `ans` vector.

### Visual Trace Walkthrough (Example 1)
Input: `intervals = [[1,3],[2,6],[8,10],[15,18]]` (Already sorted)

| i | intervals[i] | Condition (`ans.empty()` or `start > end`) | Action | `ans` state after iteration |
|---|---|---|---|---|
| 0 | `[1,3]` | `ans.empty()` is true | Push `[1,3]` | `[[1,3]]` |
| 1 | `[2,6]` | `2 > 3` is false (Overlap) | Update `ans.back()[1] = max(3, 6)` | `[[1,6]]` |
| 2 | `[8,10]` | `8 > 6` is true | Push `[8,10]` | `[[1,6], [8,10]]` |
| 3 | `[15,18]` | `15 > 10` is true | Push `[15,18]` | `[[1,6], [8,10], [15,18]]` |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of intervals. The dominant operation is sorting the input array, while the subsequent linear scan takes $$O(N)$$ time.
- Space complexity: $$O(N)$$, required for the auxiliary `ans` vector storing the output intervals (ignoring sorting stack space).

# Code
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back({intervals[i][0],intervals[i][1]});
            }else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};
```
