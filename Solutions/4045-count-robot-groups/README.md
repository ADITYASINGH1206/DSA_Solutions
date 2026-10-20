# [4045. Count Robot Groups](https://leetcode.com/problems/count-robot-groups/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `monotonic-stack`

---

## Problem Description
You are given a strictly increasing integer array `position`, where `position[i]` is the initial position of the `ith` robot at time `t = 0`.

You are also given an integer array `speed`, where `speed[i]` is the constant speed of the `ith` robot in units per second, and an integer `distance`.

Time is **continuous** and measured in seconds. A robot or group with speed `v` moves `v * t` units to the right over any interval of `t` seconds.

Whenever the distance between two robots or groups becomes at most `distance`, they merge into a single group.

If multiple robots or groups satisfy the merging condition at the same time, all merges happen **simultaneously**. In particular, every connected collection of robots or groups whose consecutive positions differ by at most `distance` merges into one group.

After a merge, the resulting group takes the current position and speed of the **rightmost robot** in that group. Once merged, robots never separate.

Return the number of groups remaining after all possible merges have occurred.

**Example 1:**

**Input:** position = [1,5,6,20], speed = [4,3,2,3], distance = 1

**Output:** 2

**Explanation:**

* Initially, the groups are {R1}, {R2}, {R3}, and {R​​​​​​​4}.
* At `t = 0`, the robots R2 and R3 at positions 5 and 6, respectively, merge because they are 1 unit apart. The resulting group moves with the position and speed of the rightmost robot R3. The groups are now {R1}, {R2, R3}, and {R​4}.
* Later at `t = 2`, the robot R1 catches up to the group {R2, R3} and merges with it. The groups are now {R1, R2, R3} and {R​4}.

Thus, the answer is 2.

**Example 2:**

**Input:** position = [1,5,9], speed = [3,2,2], distance = 2

**Output:** 2

**Explanation:**

* Initially, the groups are {R1}, {R2}, and {R3}.
* At `t = 2`, the robot R1 catches up to the robot R2 and merges with it. The resulting group moves with the position and speed of the rightmost robot R2. The groups are now {R1, R2} and {R3}.

Thus, the answer is 2.

**Example 3:**

**Input:** position = [9], speed = [8], distance = 5

**Output:** 1

**Explanation:**

Initially, there is only one group. Therefore, the answer is 1.

**Constraints:**

* `1 <= position.length == speed.length <= 105`
* `1 <= position[i], speed[i], distance <= 109`
* `position` is strictly increasing.

---

## Solution & Editorial
# Intuition
The problem asks us to track groups of robots moving at constant speeds. A key observation is that when a robot (or group) catches up to another, they merge and adopt the properties of the rightmost entity. By processing the robots from right to left, we can maintain the state of the "current" group and determine if the robot to the left will eventually merge with it or form a new independent group.

# Approach
1. We iterate through the robots in reverse order (from `n-2` down to `0`).
2. We maintain the `s` variable, which represents the speed of the rightmost robot in the current group being tracked.
3. For each robot `i`, there are two conditions that force a merge with the group to its right:
   - The initial distance `position[i+1] - position[i]` is less than or equal to `distance`.
   - The current robot's speed `speed[i]` is strictly greater than the speed `s` of the group to its right, meaning it will eventually catch up.
4. If neither condition is met, the robot `i` cannot catch up to the group on its right, so it must form a new group. We increment the group count `ans` and update `s` to `speed[i]`.

### Visual Trace (Example 1: pos=[1,5,6,20], speed=[4,3,2,3], dist=1)
| Index | Pos | Speed | Group Speed (s) | Action | Groups (ans) |
|---|---|---|---|---|---|
| 3 | 20 | 3 | 3 | Initial | 1 |
| 2 | 6 | 2 | 3 | No merge (6-20 > 1, 2 < 3) | 1 |
| 1 | 5 | 3 | 3 | Merge (5-6 <= 1) | 1 |
| 0 | 1 | 4 | 3 | Merge (4 > 3) | 1 |
*Wait, the logic processes right-to-left to identify independent groups.*

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of robots. We perform a single linear pass over the arrays.
- Space complexity: $$O(1)$$, as we only use a few integer variables for tracking state.

# Code
```cpp
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int ans = 1;
        int s = speed[n-1];
        for(int i=n-2;i>=0;i--){
            if((position[i+1]-position[i])<=distance || speed[i]>s){
                continue;
            }
            s=speed[i];
            ans++;
        }
        return ans;
    }
};
```
