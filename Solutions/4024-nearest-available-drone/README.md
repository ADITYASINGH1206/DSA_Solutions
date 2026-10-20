# [4024. Nearest Available Drone](https://leetcode.com/problems/nearest-available-drone/)
**Difficulty:** `Easy` | **Tags:** `array`, `enumeration`

---

## Problem Description
You are given a 2D integer array `drones`, where `drones[i] = [xi, yi, rangei]` represents the x-coordinate, y-coordinate, and travel range of the `ith` drone.

You are also given an integer array `target = [tx, ty]`, representing the coordinates of the target.

A drone `drones[i]` can reach the target if the Manhattan distance between its coordinates and the target coordinates is **less than or equal** to its `rangei`.

Return the **index** of the reachable drone with the **minimum Manhattan distance** to the target. If there is a tie, return the **smallest index**. If no drone can reach the target, return `-1`.

**Example 1:**

**Input:** drones = [[0,0,8],[2,2,9]], target = [3,4]

**Output:** 1

**Explanation:**

* The distance between `drones[0]` and `target` is `|0 - 3| + |0 - 4| = 7`, which is within its range of 8.
* The distance between `drones[1]` and `target` is `|2 - 3| + |2 - 4| = 3`, which is within its range of 9.
* Since `drones[1]` is the nearest drone, the answer is 1.

**Example 2:**

**Input:** drones = [[2,1,5],[4,4,5],[6,6,8]], target = [5,5]

**Output:** 1

**Explanation:**

* The distance between `drones[0]` and `target` is `|2 - 5| + |1 - 5| = 7`, which is greater than its range of 5.
* The distance between `drones[1]` and `target` is `|4 - 5| + |4 - 5| = 2`, which is within its range of 5.
* The distance between `drones[2]` and `target` is `|6 - 5| + |6 - 5| = 2`, which is within its range of 8.
* Both `drones[1]` and `drones[2]` are the nearest drones. Since we should return the smallest index, the answer is 1.

**Example 3:**

**Input:** drones = [[4,4,5]], target = [8,6]

**Output:** -1

**Explanation:**

* The distance between `drones[0]` and `target` is `|4 - 8| + |4 - 6| = 6`, which is greater than its range of 5.
* No drone can reach the target, so the answer is -1.

**Constraints:**

* `1 <= drones.length <= 100`
* `drones[i] = [xi, yi, rangei]`
* `target = [tx, ty]`
* `-25 <= xi, yi, tx, ty <= 25`
* `1 <= rangei <= 100`

---

## Solution & Editorial
# Intuition
To identify the nearest reachable drone, we must calculate the Manhattan distance for every drone and verify if it falls within the drone's specified range. Since we need the minimum distance and the smallest index in case of ties, a single linear pass is sufficient to track the best candidate found so far.

# Approach
1. Initialize `minDist` to `INT_MAX` and `idx` to `-1` to track the best reachable drone found.
2. Iterate through the `drones` array using index `i`.
3. For each drone, calculate the Manhattan distance: `dist = abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1])`.
4. Check if `dist <= drones[i][2]` (the drone's range). If true, compare `dist` with `minDist`.
5. If `dist < minDist`, update `minDist` to `dist` and `idx` to `i`. Because we use a strict inequality (`<`), we naturally preserve the smallest index in the event of a tie.

### Visual Trace (Example 2: drones = [[2,1,5],[4,4,5],[6,6,8]], target = [5,5])
| Index | Dist | Range | Reachable? | MinDist | Result Index |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 7 | 5 | No | INF | -1 |
| 1 | 2 | 5 | Yes | 2 | 1 |
| 2 | 2 | 8 | Yes | 2 | 1 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of drones, as we perform a single pass over the input array.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& t) {
        int minDist = INT_MAX;
        int idx = -1;

        for (int i = 0; i < drones.size(); i++) {
            int dist = abs(t[0] - drones[i][0])
                     + abs(t[1] - drones[i][1]);

            if (dist <= drones[i][2] && minDist > dist) {
                minDist = dist;
                idx = i;
            }
        }

        return idx;
    }
};
```
