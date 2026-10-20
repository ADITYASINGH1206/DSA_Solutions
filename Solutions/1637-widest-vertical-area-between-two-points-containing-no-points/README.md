# [1637. Widest Vertical Area Between Two Points Containing No Points](https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`

---

## Problem Description
Given `n` `points` on a 2D plane where `points[i] = [xi, yi]`, Return*the **widest vertical area** between two points such that no points are inside the area.*

A **vertical area** is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The **widest vertical area** is the one with the maximum width.

Note that points **on the edge** of a vertical area **are not** considered included in the area.

**Example 1:**

​

```
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.
```

**Example 2:**

```
Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3
```

**Constraints:**

* `n == points.length`
* `2 <= n <= 105`
* `points[i].length == 2`
* `0 <= xi, yi <= 109`

---

## Solution & Editorial
# Intuition
The problem asks for the maximum horizontal distance between any two adjacent points when projected onto the x-axis. Since the y-coordinates do not affect the width of a vertical area, we only care about the x-coordinates. By sorting the points based on their x-coordinates, the widest vertical area must exist between two consecutive points in the sorted list.

# Approach
1. Extract or focus on the x-coordinates of the given `points`. Since we only need the x-values, sorting the entire `vector<vector<int>>` based on the first element (x-coordinate) is sufficient.
2. Initialize a variable `ans` to 0 to store the maximum width found.
3. Iterate through the sorted points from index `0` to `n-2`.
4. Calculate the difference between the x-coordinate of the current point `points[i+1][0]` and the previous point `points[i][0]`.
5. Update `ans` with the maximum of its current value and the calculated difference.

### Visual Trace (Example 1: [[8,7],[9,9],[7,4],[9,7]])
1. Sort: `[[7,4], [8,7], [9,9], [9,7]]`
2. Iteration 1: `points[1][0] - points[0][0]` = `8 - 7` = `1`. `ans = 1`.
3. Iteration 2: `points[2][0] - points[1][0]` = `9 - 8` = `1`. `ans = max(1, 1) = 1`.
4. Iteration 3: `points[3][0] - points[2][0]` = `9 - 9` = `0`. `ans = max(1, 0) = 1`.
Result: `1`

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of points. This is dominated by the sorting step.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we perform the sort in-place and use only a constant amount of extra space for the result variable.

# Code
```cpp
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 0;
        for(int i =0;i<points.size()-1;i++){
            ans = max(ans,points[i+1][0] - points[i][0]);
        }
        return ans;
    }
};
```
