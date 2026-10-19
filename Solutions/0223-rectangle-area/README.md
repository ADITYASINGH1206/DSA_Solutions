# [223. Rectangle Area](https://leetcode.com/problems/rectangle-area/)
**Difficulty:** `Medium` | **Tags:** `math`, `geometry`

---

## Problem Description
Given the coordinates of two **rectilinear** rectangles in a 2D plane, return *the total area covered by the two rectangles*.

The first rectangle is defined by its **bottom-left** corner `(ax1, ay1)` and its **top-right** corner `(ax2, ay2)`.

The second rectangle is defined by its **bottom-left** corner `(bx1, by1)` and its **top-right** corner `(bx2, by2)`.

**Example 1:**

```
Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45
```

**Example 2:**

```
Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16
```

**Constraints:**

* `-104 <= ax1 <= ax2 <= 104`
* `-104 <= ay1 <= ay2 <= 104`
* `-104 <= bx1 <= bx2 <= 104`
* `-104 <= by1 <= by2 <= 104`

---

## Solution & Editorial
# Intuition
The total area covered by two rectilinear rectangles can be computed using the Principle of Inclusion-Exclusion. We sum the areas of both individual rectangles and subtract the area of their overlapping intersection to avoid double-counting.

# Approach
1. Calculate the area of the first rectangle using `areaA = (ax2 - ax1) * (ay2 - ay1)`.
2. Calculate the area of the second rectangle using `areaB = (bx2 - bx1) * (by2 - by1)`.
3. Determine the overlap width by finding the intersection of the x-intervals `[ax1, ax2]` and `[bx1, bx2]`, which is given by `min(ax2, bx2) - max(ax1, bx1)`. If the rectangles do not overlap horizontally, this value may be negative, so we clamp it to zero using `max(0, ...)`. Similarly, compute the overlap height using the y-intervals.
4. Compute the intersection area `overlapArea = overlapWidth * overlapHeight`.
5. Return the final result as `areaA + areaB - overlapArea`.

### Visual Trace Walkthrough (Example 1)
- `ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4` $ightarrow$ `areaA = 6 * 4 = 24`
- `bx1 = 0, by1 = -1, bx2 = 9, by2 = 2` $ightarrow$ `areaB = 9 * 3 = 27`
- `overlapWidth = min(3, 9) - max(-3, 0) = 3 - 0 = 3`
- `overlapHeight = min(4, 2) - max(0, -1) = 2 - 0 = 2`
- `overlapArea = 3 * 2 = 6`
- `Total Area = 24 + 27 - 6 = 45`

# Complexity
- Time complexity: $$O(1)$$ — Only a fixed number of arithmetic and comparison operations are executed.
- Space complexity: $$O(1)$$ — No auxiliary memory or data structures are used.

# Code
```cpp
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {
        int areaA = (ax2 - ax1) * (ay2 - ay1);
        int areaB = (bx2 - bx1) * (by2 - by1);
        int overlapWidth  =
            max(0, min(ax2, bx2) - max(ax1, bx1));
        int overlapHeight =
            max(0, min(ay2, by2) - max(ay1, by1));
        int overlapArea = overlapWidth * overlapHeight;
        return areaA + areaB - overlapArea;
    }
};
```
