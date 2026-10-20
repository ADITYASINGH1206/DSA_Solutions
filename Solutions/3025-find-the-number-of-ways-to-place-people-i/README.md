# [3025. Find the Number of Ways to Place People I](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `geometry`, `sorting`, `enumeration`

---

## Problem Description
You are given a 2D array `points` of size `n x 2` representing integer coordinates of some points on a 2D plane, where `points[i] = [xi, yi]`.

Count the number of pairs of points `(A, B)`, where

* `A` is on the **upper left** side of `B`, and
* there are no other points in the rectangle (or line) they make (**including the border**), except for the points `A` and `B`.

Return the count.

**Example 1:**

**Input:** points = [[1,1],[2,2],[3,3]]

**Output:** 0

**Explanation:**

There is no way to choose `A` and `B` such that `A` is on the upper left side of `B`.

**Example 2:**

**Input:** points = [[6,2],[4,4],[2,6]]

**Output:** 2

**Explanation:**

* The left one is the pair `(points[1], points[0])`, where `points[1]` is on the upper left side of `points[0]` and the rectangle is empty.
* The middle one is the pair `(points[2], points[1])`, same as the left one it is a valid pair.
* The right one is the pair `(points[2], points[0])`, where `points[2]` is on the upper left side of `points[0]`, but `points[1]` is inside the rectangle so it's not a valid pair.

**Example 3:**

**Input:** points = [[3,1],[1,3],[1,1]]

**Output:** 2

**Explanation:**

* The left one is the pair `(points[2], points[0])`, where `points[2]` is on the upper left side of `points[0]` and there are no other points on the line they form. Note that it is a valid state when the two points form a line.
* The middle one is the pair `(points[1], points[2])`, it is a valid pair same as the left one.
* The right one is the pair `(points[1], points[0])`, it is not a valid pair as `points[2]` is on the border of the rectangle.

**Constraints:**

* `2 <= n <= 50`
* `points[i].length == 2`
* `0 <= points[i][0], points[i][1] <= 50`
* All `points[i]` are distinct.

---

## Solution & Editorial
# Intuition
The problem asks us to identify pairs of points (A, B) such that A is to the upper-left of B, and no other points exist within the rectangle defined by these two points. Given the small constraint (N <= 50), an O(N^3) approach is perfectly efficient and straightforward to implement.

# Approach
1. Iterate through every possible pair of points (i, j) in the input array.
2. For each pair, check if point i is to the upper-left of point j. This condition is met if `points[i].x <= points[j].x` and `points[i].y >= points[j].y`.
3. If the condition is met, iterate through all other points k in the array.
4. Check if any point k lies within the rectangle formed by i and j. A point k is inside if `points[k].x` is between `points[i].x` and `points[j].x` (inclusive) and `points[k].y` is between `points[j].y` and `points[i].y` (inclusive).
5. If no such point k is found, increment the answer counter.

### Visual Trace (Example 2: points = [[6,2],[4,4],[2,6]])
| Pair (i, j) | A (i) | B (j) | Valid? | Reason |
| :--- | :--- | :--- | :--- | :--- |
| (1, 0) | [4,4] | [6,2] | Yes | No points in [4,6]x[2,4] |
| (2, 1) | [2,6] | [4,4] | Yes | No points in [2,4]x[4,6] |
| (2, 0) | [2,6] | [6,2] | No | Point [4,4] is inside |

# Complexity
- Time complexity: $$O(N^3)$$, where N is the number of points. We use three nested loops: two to select the pair (A, B) and one to validate the rectangle.
- Space complexity: $$O(1)$$, as we only use a few integer variables for indexing and coordinate comparison.

# Code
```cpp
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& v) {
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            int x1=v[i][0],y1=v[i][1];
            for(int j=0;j<n;j++) {
                if(i==j)
                    continue;
                int x2=v[j][0],y2=v[j][1];
                int f=0;
                if(y1>=y2 && x1<=x2) {
                    for(int k=0;k<n;k++) {
                        if(k==i || k==j)
                            continue;
                        int x3=v[k][0],y3=v[k][1];
                        if(x3>=x1 && x3<=x2 && y3>=y2 && y3<=y1) {
                            f=1;
                            break;
                        }
                    }
                    if(f==0)
                        ans++;
                }
                
            }
        }
        return ans;
    }
};
```
