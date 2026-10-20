# [1828. Queries on Number of Points Inside a Circle](https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `geometry`

---

## Problem Description
You are given an array `points` where `points[i] = [xi, yi]` is the coordinates of the `ith` point on a 2D plane. Multiple points can have the **same** coordinates.

You are also given an array `queries` where `queries[j] = [xj, yj, rj]` describes a circle centered at `(xj, yj)` with a radius of `rj`.

For each query `queries[j]`, compute the number of points **inside** the `jth` circle. Points **on the border** of the circle are considered **inside**.

Return *an array* `answer`*, where* `answer[j]` *is the answer to the* `jth` *query*.

**Example 1:**

```
Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
Explanation: The points and circles are shown above.
queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.
```

**Example 2:**

```
Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
Output: [2,3,2,4]
Explanation: The points and circles are shown above.
queries[0] is green, queries[1] is red, queries[2] is blue, and queries[3] is purple.
```

**Constraints:**

* `1 <= points.length <= 500`
* `points[i].length == 2`
* `0 <= x​​​​​​i, y​​​​​​i <= 500`
* `1 <= queries.length <= 500`
* `queries[j].length == 3`
* `0 <= xj, yj <= 500`
* `1 <= rj <= 500`
* All coordinates are integers.

**Follow up:** Could you find the answer for each query in better complexity than `O(n)`?

---

## Solution & Editorial
# Intuition
To determine if a point $(x, y)$ lies within a circle centered at $(a, b)$ with radius $r$, we use the geometric distance formula. A point is inside or on the boundary if the squared Euclidean distance from the center is less than or equal to the squared radius: $(x - a)^2 + (y - b)^2 \le r^2$. Given the constraints ($N, M \le 500$), a direct simulation is efficient enough.

# Approach
1. Initialize an empty vector `ans` to store the results for each query.
2. Iterate through each query in `queries`. For each query, extract the center $(a, b)$ and radius $r$.
3. For every query, iterate through all points in `points`. Extract the coordinates $(x, y)$ of the current point.
4. Calculate the squared distance $(x - a)^2 + (y - b)^2$ and compare it against $r^2$. If the condition holds, increment a local `count` variable.
5. After checking all points for a specific query, append the `count` to `ans`.

### Visual Trace (Example 1)
Points: `P0(1,3), P1(3,3), P2(5,3), P3(2,2)`
Query 0: `(2,3,1)` -> $r^2 = 1$
- P0: $(1-2)^2 + (3-3)^2 = 1 \le 1$ (Inside)
- P1: $(3-2)^2 + (3-3)^2 = 1 \le 1$ (Inside)
- P2: $(5-2)^2 + (3-3)^2 = 9 \not\le 1$ (Outside)
- P3: $(2-2)^2 + (2-3)^2 = 1 \le 1$ (Inside)
Result: 3

# Complexity
- Time complexity: $$O(N \times M)$$, where $N$ is the number of points and $M$ is the number of queries. We perform a constant time check for every point against every query.
- Space complexity: $$O(1)$$ auxiliary space (excluding the output vector), as we only use a few integer variables for calculation.

# Code
```cpp
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i = 0 ; i<queries.size();i++){
            int a =queries[i][0],b=queries[i][1],r=queries[i][2];
            int count = 0;
            for(int j = 0 ;j<points.size();j++){
                int x = points[j][0],y=points[j][1];
                if ( (pow(x - a, 2) + pow(y - b, 2)) <= pow(r, 2) ){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
```
