# [3661. Maximum Walls Destroyed by Robots](https://leetcode.com/problems/maximum-walls-destroyed-by-robots/)
**Difficulty:** `Hard` | **Tags:** `array`, `binary-search`, `dynamic-programming`, `sorting`

---

## Problem Description
There is an endless straight line populated with some robots and walls. You are given integer arrays `robots`, `distance`, and `walls`:

* `robots[i]` is the position of the `ith` robot.
* `distance[i]` is the **maximum** distance the `ith` robot's bullet can travel.
* `walls[j]` is the position of the `jth` wall.

Every robot has **one** bullet that can either fire to the left or the right **at most** `distance[i]` meters.

A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it **immediately stops** at that robot and cannot continue.

Return the **maximum** number of **unique** walls that can be destroyed by the robots.

Notes:

* A wall and a robot may share the same position; the wall can be destroyed by the robot at that position.
* Robots are not destroyed by bullets.

**Example 1:**

**Input:** robots = [4], distance = [3], walls = [1,10]

**Output:** 1

**Explanation:**

* `robots[0] = 4` fires **left** with `distance[0] = 3`, covering `[1, 4]` and destroys `walls[0] = 1`.
* Thus, the answer is 1.

**Example 2:**

**Input:** robots = [10,2], distance = [5,1], walls = [5,2,7]

**Output:** 3

**Explanation:**

* `robots[0] = 10` fires **left** with `distance[0] = 5`, covering `[5, 10]` and destroys `walls[0] = 5` and `walls[2] = 7`.
* `robots[1] = 2` fires **left** with `distance[1] = 1`, covering `[1, 2]` and destroys `walls[1] = 2`.
* Thus, the answer is 3.

**Example 3:**

**Input:** robots = [1,2], distance = [100,1], walls = [10]

**Output:** 0

**Explanation:**

In this example, only `robots[0]` can reach the wall, but its shot to the **right** is blocked by `robots[1]`; thus the answer is 0.

**Constraints:**

* `1 <= robots.length == distance.length <= 105`
* `1 <= walls.length <= 105`
* `1 <= robots[i], walls[j] <= 109`
* `1 <= distance[i] <= 105`
* All values in `robots` are **unique**
* All values in `walls` are **unique**

---

## Solution & Editorial
# Intuition
To maximize the number of unique walls destroyed, we must recognize that each robot's firing range is constrained by its neighbors. Since robots act as obstacles, a robot at index `i` can only fire left up to the position of robot `i-1` and right up to the position of robot `i+1`. By sorting robots and walls, we can use dynamic programming to decide for each robot whether to fire left or right, considering the state of the previous robot.

# Approach
1. **Preprocessing**: Pair each robot with its distance and sort both `robots` and `walls` arrays. Sorting allows us to use binary search (`std::lower_bound`) to efficiently count walls within any range `[L, R]`.
2. **DP State**: Define `dfs(i, j)` where `i` is the current robot index and `j` is a flag indicating if the previous robot `i+1` fired right (blocking `i`'s rightward shot). 
3. **Transitions**:
   - **Fire Left**: The range is `[max(robot[i].pos - dist[i], robot[i-1].pos + 1), robot[i].pos]`. We count walls in this range using binary search.
   - **Fire Right**: The range is `[robot[i].pos, min(robot[i].pos + dist[i], limit)]`, where `limit` is determined by the next robot's position and its firing direction.
4. **Memoization**: Store results in `f[i][j]` to avoid redundant calculations.

### Visual Trace (Example 2: robots=[2, 10], dist=[1, 5], walls=[2, 5, 7])
- Sorted: `R0(2, 1), R1(10, 5)`. Walls: `[2, 5, 7]`.
- `dfs(1, 1)`: 
  - Left: `[10-5, 10] = [5, 10]`. Walls: `5, 7` (count 2).
  - Right: `[10, 10+5] = [10, 15]`. Walls: none (count 0).
- `dfs(0, 0)`: 
  - Left: `[2-1, 2] = [1, 2]`. Walls: `2` (count 1).

# Complexity
- Time complexity: $$O(N \log N + N \log W)$$, where $$N$$ is the number of robots and $$W$$ is the number of walls. Sorting takes $$O(N \log N)$$, and each DP state performs binary searches on the walls array ($$O(\log W)$$).
- Space complexity: $$O(N)$$ to store the memoization table and the sorted robot array.

```cpp []
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {robots[i], distance[i]};
        }
        ranges::sort(arr, {}, &pair<int, int>::first);
        ranges::sort(walls);
        vector f(n, vector<int>(2, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0) return 0;
            if (f[i][j] != -1) return f[i][j];
            int left = arr[i].first - arr[i].second;
            if (i > 0) left = max(left, arr[i - 1].first + 1);
            int l = ranges::lower_bound(walls, left) - walls.begin();
            int r = ranges::lower_bound(walls, arr[i].first + 1) - walls.begin();
            int ans = dfs(i - 1, 0) + (r - l);
            int right = arr[i].first + arr[i].second;
            if (i + 1 < n) {
                if (j == 0) right = min(right, arr[i + 1].first - arr[i + 1].second - 1);
                else right = min(right, arr[i + 1].first - 1);
            }
            l = ranges::lower_bound(walls, arr[i].first) - walls.begin();
            r = ranges::lower_bound(walls, right + 1) - walls.begin();
            ans = max(ans, dfs(i - 1, 1) + (r - l));
            return f[i][j] = ans;
        };
        return dfs(n - 1, 1);
    }
};

# Code
```cpp
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {robots[i], distance[i]};
        }
        ranges::sort(arr, {}, &pair<int, int>::first);
        ranges::sort(walls);

        vector f(n, vector<int>(2, -1));

        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }

            int left = arr[i].first - arr[i].second;
            if (i > 0) {
                left = max(left, arr[i - 1].first + 1);
            }
            int l = ranges::lower_bound(walls, left) - walls.begin();
            int r = ranges::lower_bound(walls, arr[i].first + 1) - walls.begin();
            int ans = dfs(i - 1, 0) + (r - l);

            int right = arr[i].first + arr[i].second;
            if (i + 1 < n) {
                if (j == 0) {
                    right = min(right, arr[i + 1].first - arr[i + 1].second - 1);
                } else {
                    right = min(right, arr[i + 1].first - 1);
                }
            }
            l = ranges::lower_bound(walls, arr[i].first) - walls.begin();
            r = ranges::lower_bound(walls, right + 1) - walls.begin();
            ans = max(ans, dfs(i - 1, 1) + (r - l));

            return f[i][j] = ans;
        };

        return dfs(n - 1, 1);
    }
};
```
