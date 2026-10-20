# [4056. Number of Intersecting Interval Pairs I](https://leetcode.com/problems/number-of-intersecting-interval-pairs-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `binary-search`, `sorting`, `enumeration`

---

## Problem Description
You are given a 2D integer array `intervals` of `n` elements, where `intervals[i] = [starti, endi]` represents the **closed** interval from `starti` to `endi`.

Return the number of pairs of indices `(i, j)` such that `0 <= i < j < n` and `intervals[i]` and `intervals[j]` **intersect**.

Two intervals **intersect** if they have at least one point in common, including when they only share an endpoint.

**Example 1:**

**Input:** intervals = [[1,2],[2,3],[3,4]]

**Output:** 2

**Explanation:**

There are 2 intersecting interval pairs:

* Intervals `[1, 2]` and `[2, 3]` intersect at the point 2.
* Intervals `[2, 3]` and `[3, 4]` intersect at the point 3.

**Example 2:**

**Input:** intervals = [[1,5],[2,4],[3,6]]

**Output:** 3

**Explanation:**

There are 3 intersecting interval pairs:

* The intersection of `[1, 5]` and `[2, 4]` is `[2, 4]`.
* The intersection of `[1, 5]` and `[3, 6]` is `[3, 5]`.
* The intersection of `[2, 4]` and `[3, 6]` is `[3, 4]`.

**Example 3:**

**Input:** intervals = [[1,2],[3,4],[5,6]]

**Output:** 0

**Explanation:**

There are no intersecting interval pairs. Hence, the answer is 0.

**Constraints:**

* `2 <= n == intervals.length <= 100`
* `intervals[i] = [starti, endi]`
* `0 <= starti <= endi <= 100`

---

## Solution & Editorial
# Intuition
Two closed intervals $[a, b]$ and $[c, d]$ intersect if and only if the start of one is less than or equal to the end of the other, and vice versa. Specifically, they intersect if $a \le d$ and $c \le b$. Given the small constraint ($N \le 100$), a brute-force comparison of all pairs is optimal and efficient.

# Approach
1. Initialize a counter `cnt` to 0.
2. Iterate through all pairs of indices $(i, j)$ such that $0 \le i < j < n$.
3. Extract the bounds for each interval: `c1, c2` for `intervals[i]` and `c3, c4` for `intervals[j]`.
4. Apply the intersection condition: `c1 <= c4 && c3 <= c2`. If true, increment `cnt`.
5. Return `cnt` after checking all pairs.

### Visual Trace (Example 1: [[1,2],[2,3],[3,4]])
| Pair (i, j) | Intervals | c1, c2 | c3, c4 | Condition (c1<=c4 && c3<=c2) | Result |
| :--- | :--- | :--- | :--- | :--- | :--- |
| (0, 1) | [1,2], [2,3] | 1, 2 | 2, 3 | 1<=3 && 2<=2 (True) | cnt=1 |
| (0, 2) | [1,2], [3,4] | 1, 2 | 3, 4 | 1<=4 && 3<=2 (False) | cnt=1 |
| (1, 2) | [2,3], [3,4] | 2, 3 | 3, 4 | 2<=4 && 3<=3 (True) | cnt=2 |

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the number of intervals. We iterate through all pairs using nested loops.
- Space complexity: $$O(1)$$ as we only use a few integer variables for counting and comparison.

# Code
```cpp
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        for(int i = 0; i < intervals.size(); i++){
            for(int j = i + 1; j < intervals.size(); j++){
                int c1 = intervals[i][0];
                int c2 = intervals[i][1];
                int c3 = intervals[j][0];
                int c4 = intervals[j][1];
                if(c1 <= c4 && c3 <= c2)cnt++;
            }
        }
        return cnt;
    }
};
```
