# [836. Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/)
**Difficulty:** `Easy` | **Tags:** `math`, `geometry`

---

## Problem Description
An axis-aligned rectangle is represented as a list `[x1, y1, x2, y2]`, where `(x1, y1)` is the coordinate of its bottom-left corner, and `(x2, y2)` is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the area of their intersection is **positive**. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two axis-aligned rectangles `rec1` and `rec2`, return `true` *if they overlap, otherwise return* `false`.

**Example 1:**

**Input:** rec1 = [0,0,2,2], rec2 = [1,1,3,3]

**Output:** true

**Explanation:**

The rectangles overlap in the region with corners at `(1,1)`, `(2,1)`, `(1,2)`, and `(2,2)`.

This region has positive area, so the rectangles overlap.

**Example 2:**

**Input:** rec1 = [0,0,1,1], rec2 = [1,0,2,1]

**Output:** false

**Explanation:**

The rectangles share the vertical edge where `x = 1`, but they do not have any common interior region.

Since their intersection has zero area, the rectangles do not overlap.

**Example 3:**

**Input:** rec1 = [0,0,1,1], rec2 = [2,2,3,3]

**Output:** false

**Explanation:**

The rectangles are completely separate. Rectangle `rec1` ends at `x = 1` and `y = 1`, while `rec2` starts at `x = 2` and `y = 2`.

Therefore, they have no common points and do not overlap.

**Constraints:**

* `rec1.length == 4`
* `rec2.length == 4`
* `-109 <= rec1[i], rec2[i] <= 109`
* `rec1` and `rec2` represent a valid rectangle with a non-zero area.

---

## Solution & Editorial
# Intuition
Instead of checking if two rectangles overlap directly, it is much easier to check when they **do not** overlap. Two axis-aligned rectangles are completely separate if one is strictly to the left, to the right, above, or below the other. By negating these non-overlapping conditions, we can determine whether they intersect with a positive area.

# Approach
1. Extract or reference the coordinates of both rectangles: `rec1` = `[x1_1, y1_1, x2_1, y2_1]` and `rec2` = `[x1_2, y1_2, x2_2, y2_2]` (represented by array indexing).
2. Identify the four conditions where the rectangles are mutually exclusive:
   - `rec1` is strictly to the left of `rec2`: `rec1[2] <= rec2[0]`
   - `rec1` is strictly to the right of `rec2`: `rec1[0] >= rec2[2]`
   - `rec1` is strictly below `rec2`: `rec1[3] <= rec2[1]`
   - `rec1` is strictly above `rec2`: `rec1[1] >= rec2[3]`
3. Combine these conditions using logical OR (`||`) to capture all non-overlapping scenarios, and negate the entire expression using NOT (`!`) to return true if they overlap.

### Visual Dry Run (Example 1)
Given `rec1 = [0, 0, 2, 2]` and `rec2 = [1, 1, 3, 3]`:
- Is `rec1` to the left? `rec1[2] (2) <= rec2[0] (1)` $ightarrow$ `false`
- Is `rec1` to the right? `rec1[0] (0) >= rec2[2] (3)` $ightarrow$ `false`
- Is `rec1` below? `rec1[3] (2) <= rec2[1] (1)` $ightarrow$ `false`
- Is `rec1` above? `rec1[1] (0) >= rec2[3] (3)` $ightarrow$ `false`

All non-overlap checks evaluate to `false`. Negating `false` gives `true`, correctly indicating an overlap.

# Complexity
- Time complexity: $$O(1)$$ — performs a fixed number of constant-time arithmetic comparisons.
- Space complexity: $$O(1)$$ — no extra auxiliary data structures or recursion stacks are used.

# Code
```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[2] <= rec2[0] ||
                 rec1[0] >= rec2[2] ||
                 rec1[3] <= rec2[1] ||
                 rec1[1] >= rec2[3]);
    }
};
```
