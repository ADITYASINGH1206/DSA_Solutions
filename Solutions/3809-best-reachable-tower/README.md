# [3809. Best Reachable Tower](https://leetcode.com/problems/best-reachable-tower/)
**Difficulty:** `Medium` | **Tags:** `array`

---

## Problem Description
You are given a 2D integer array `towers`, where `towers[i] = [xi, yi, qi]` represents the coordinates `(xi, yi)` and quality factor `qi` of the `ith` tower.

You are also given an integer array `center = [cx, cy​​​​​​​]` representing your location, and an integer `radius`.

A tower is **reachable** if its **Manhattan distance** from `center` is **less than or equal** to `radius`.

Among all reachable towers:

* Return the coordinates of the tower with the **maximum** quality factor.
* If there is a tie, return the tower with the **lexicographically smallest** coordinate. If no tower is reachable, return `[-1, -1]`.

The **Manhattan Distance** between two cells `(xi, yi)` and `(xj, yj)` is `|xi - xj| + |yi - yj|`.

A coordinate `[xi, yi]` is **lexicographically smaller** than `[xj, yj]` if `xi < xj`, or `xi == xj` and `yi < yj`.

`|x|` denotes the **absolute** **value** of `x`.

**Example 1:**

**Input:** towers = [[1,2,5], [2,1,7], [3,1,9]], center = [1,1], radius = 2

**Output:** [3,1]

**Explanation:**

* Tower `[1, 2, 5]`: Manhattan distance = `|1 - 1| + |2 - 1| = 1`, reachable.
* Tower `[2, 1, 7]`: Manhattan distance = `|2 - 1| + |1 - 1| = 1`, reachable.
* Tower `[3, 1, 9]`: Manhattan distance = `|3 - 1| + |1 - 1| = 2`, reachable.

All towers are reachable. The maximum quality factor is 9, which corresponds to tower `[3, 1]`.

**Example 2:**

**Input:** towers = [[1,3,4], [2,2,4], [4,4,7]], center = [0,0], radius = 5

**Output:** [1,3]

**Explanation:**

* Tower `[1, 3, 4]`: Manhattan distance = `|1 - 0| + |3 - 0| = 4`, reachable.
* Tower `[2, 2, 4]`: Manhattan distance = `|2 - 0| + |2 - 0| = 4`, reachable.
* Tower `[4, 4, 7]`: Manhattan distance = `|4 - 0| + |4 - 0| = 8`, not reachable.

Among the reachable towers, the maximum quality factor is 4. Both `[1, 3]` and `[2, 2]` have the same quality, so the lexicographically smaller coordinate is `[1, 3]`.

**Example 3:**

**Input:** towers = [[5,6,8], [0,3,5]], center = [1,2], radius = 1

**Output:** [-1,-1]

**Explanation:**

* Tower `[5, 6, 8]`: Manhattan distance = `|5 - 1| + |6 - 2| = 8`, not reachable.
* Tower `[0, 3, 5]`: Manhattan distance = `|0 - 1| + |3 - 2| = 2`, not reachable.

No tower is reachable within the given radius, so `[-1, -1]` is returned.

**Constraints:**

* `1 <= towers.length <= 105`
* `towers[i] = [xi, yi, qi]`
* `center = [cx, cy]`
* `0 <= xi, yi, qi, cx, cy <= 105`​​​​​​​
* `0 <= radius <= 105`

---

## Solution & Editorial
# Intuition
To identify the best reachable tower, we must iterate through the entire list of towers exactly once. For each tower, we check if it falls within the specified Manhattan distance from the center and maintain the state of the "best" tower found so far based on the quality factor and lexicographical order.

# Approach
1. Initialize `m` (max quality) to `INT_MIN` and `ans` to `{-1, -1}` to handle the case where no tower is reachable.
2. Iterate through each tower `towers[i]`:
   - Calculate the Manhattan distance: `dist = abs(xi - cx) + abs(yi - cy)`.
   - If `dist <= radius`, the tower is reachable.
   - If `towers[i][2] > m`, update `m` to the current quality and `ans` to the current coordinates `[xi, yi]`.
   - If `towers[i][2] == m`, update `ans` to the lexicographical minimum of `ans` and `[xi, yi]` using `std::min`.

### Visual Trace (Example 2)
`towers = [[1,3,4], [2,2,4], [4,4,7]], center = [0,0], radius = 5`

| Iteration | Tower | Dist | Reachable | Quality | Current Best (ans, m) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | [1,3,4] | 4 | Yes | 4 | {[1,3], 4} |
| 2 | [2,2,4] | 4 | Yes | 4 | min({[1,3], [2,2]}, 4) -> {[1,3], 4} |
| 3 | [4,4,7] | 8 | No | - | {[1,3], 4} |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of towers. We perform a single pass over the input array.
- Space complexity: $$O(1)$$, as we only use a few integer variables to track the maximum quality and the best coordinates.

# Code
```cpp
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int m = INT_MIN;
        vector<int>ans(2,-1);
        for(int i = 0 ; i<towers.size();i++){
            int dist = abs(towers[i][0]-center[0])+abs(towers[i][1]-center[1]);
            if(dist<=radius){
                if(towers[i][2]>m){
                    ans={towers[i][0],towers[i][1]};
                    m=towers[i][2];
                }else if(towers[i][2]==m){
                    ans=min(ans,{towers[i][0],towers[i][1]});
                }
            }
        }
        return ans;
    }
};
```
