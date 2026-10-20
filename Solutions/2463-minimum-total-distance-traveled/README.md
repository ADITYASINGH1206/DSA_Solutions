# [2463. Minimum Total Distance Traveled](https://leetcode.com/problems/minimum-total-distance-traveled/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`, `sorting`

---

## Problem Description
There are some robots and factories on the X-axis. You are given an integer array `robot` where `robot[i]` is the position of the `ith` robot. You are also given a 2D integer array `factory` where `factory[j] = [positionj, limitj]` indicates that `positionj` is the position of the `jth` factory and that the `jth` factory can repair at most `limitj` robots.

The positions of each robot are **unique**. The positions of each factory are also **unique**. Note that a robot can be **in the same position** as a factory initially.

All the robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.

**At any moment**, you can set the initial direction of moving for **some** robot. Your target is to minimize the total distance traveled by all the robots.

Return *the minimum total distance traveled by all the robots*. The test cases are generated such that all the robots can be repaired.

**Note that**

* All robots move at the same speed.
* If two robots move in the same direction, they will never collide.
* If two robots move in opposite directions and they meet at some point, they do not collide. They cross each other.
* If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.
* If the robot moved from a position `x` to a position `y`, the distance it moved is `|y - x|`.

**Example 1:**

```
Input: robot = [0,4,6], factory = [[2,2],[6,2]]
Output: 4
Explanation: As shown in the figure:
- The first robot at position 0 moves in the positive direction. It will be repaired at the first factory.
- The second robot at position 4 moves in the negative direction. It will be repaired at the first factory.
- The third robot at position 6 will be repaired at the second factory. It does not need to move.
The limit of the first factory is 2, and it fixed 2 robots.
The limit of the second factory is 2, and it fixed 1 robot.
The total distance is |2 - 0| + |2 - 4| + |6 - 6| = 4. It can be shown that we cannot achieve a better total distance than 4.
```

**Example 2:**

```
Input: robot = [1,-1], factory = [[-2,1],[2,1]]
Output: 2
Explanation: As shown in the figure:
- The first robot at position 1 moves in the positive direction. It will be repaired at the second factory.
- The second robot at position -1 moves in the negative direction. It will be repaired at the first factory.
The limit of the first factory is 1, and it fixed 1 robot.
The limit of the second factory is 1, and it fixed 1 robot.
The total distance is |2 - 1| + |(-2) - (-1)| = 2. It can be shown that we cannot achieve a better total distance than 2.
```

**Constraints:**

* `1 <= robot.length, factory.length <= 100`
* `factory[j].length == 2`
* `-109 <= robot[i], positionj <= 109`
* `0 <= limitj <= robot.length`
* The input will be generated such that it is always possible to repair every robot.

---

## Solution & Editorial
# Intuition
To minimize the total distance, we must assign each robot to a factory such that the total displacement is minimized. Since robots and factories are on a 1D line, sorting both allows us to process them in a linear order. This structure suggests that for any subset of robots, we can decide whether to assign them to the current factory or skip it, leading to an optimal substructure solvable via Dynamic Programming.

# Approach
1. **Sorting**: Sort both `robot` and `factory` arrays by position. This ensures that if we assign a range of robots to a factory, they will be contiguous in the sorted list.
2. **State Definition**: Use `dfs(i, j)` to represent the minimum cost to repair robots from index `i` to `n-1` using factories from index `j` to `m-1`.
3. **Transitions**:
   - **Option 1 (Skip)**: Skip the current factory `j` and move to `dfs(i, j + 1)`.
   - **Option 2 (Assign)**: Assign `k` robots (where `1 <= k <= limit_j`) to factory `j`. The cost is the sum of distances of these `k` robots to `factory[j]` plus the result of `dfs(i + k, j + 1)`.
4. **Memoization**: Use a 2D table `f[i][j]` to store results of subproblems to avoid redundant calculations.

### Visual Trace (Example 1: robot=[0,4,6], factory=[[2,2],[6,2]])
| State (i, j) | Action | Cost Calculation | Result |
| :--- | :--- | :--- | :--- |
| (0, 0) | Assign 2 | |2-0| + |2-4| + dfs(2, 1) | 4 |
| (2, 1) | Assign 1 | |6-6| + dfs(3, 2) | 0 |
| (3, 2) | Base Case | Return 0 | 0 |

# Complexity
- Time complexity: $$O(R^2 \cdot F)$$, where $$R$$ is the number of robots and $$F$$ is the number of factories. For each state $$(i, j)$$, we iterate up to $$R$$ robots to assign to the current factory.
- Space complexity: $$O(R \cdot F)$$ to store the memoization table.

# Code
```cpp
using ll = long long;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<ll>> f(robot.size(), vector<ll>(factory.size()));
        function<ll(int i, int j)> dfs = [&](int i, int j) -> ll {
            if (i == robot.size()) return 0;
            if (j == factory.size()) return 1e15;
            if (f[i][j]) return f[i][j];
            ll ans = dfs(i, j + 1);
            ll t = 0;
            for (int k = 0; k < factory[j][1]; ++k) {
                if (i + k >= robot.size()) break;
                t += abs(robot[i + k] - factory[j][0]);
                ans = min(ans, t + dfs(i + k + 1, j + 1));
            }
            f[i][j] = ans;
            return ans;
        };
        return dfs(0, 0);
    }
};
```
