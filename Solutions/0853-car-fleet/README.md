# [853. Car Fleet](https://leetcode.com/problems/car-fleet/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `sorting`, `monotonic-stack`

---

## Problem Description
There are `n` cars at given miles away from the starting mile 0, traveling to reach the mile `target`.

You are given two integer arrays `position` and `speed`, both of length `n`, where `position[i]` is the starting mile of the `ith` car and `speed[i]` is the speed of the `ith` car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A **car fleet** is a single car or a group of cars driving next to each other. The speed of the car fleet is the **minimum** speed of any car in the fleet.

If a car catches up to a car fleet at the mile `target`, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.

**Example 1:**

**Input:** target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

**Output:** 3

**Explanation:**

* The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at `target`.
* The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
* The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches `target`.

**Example 2:**

**Input:** target = 10, position = [3], speed = [3]

**Output:** 1

**Explanation:**

There is only one car, hence there is only one fleet.

**Example 3:**

**Input:** target = 100, position = [0,2,4], speed = [4,2,1]

**Output:** 1

**Explanation:**

* The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
* Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches `target`.

**Constraints:**

* `n == position.length == speed.length`
* `1 <= n <= 105`
* `0 < target <= 106`
* `0 <= position[i] < target`
* All the values of `position` are **unique**.
* `0 < speed[i] <= 106`

---

## Solution & Editorial
# Intuition
To determine the number of car fleets that arrive at the destination, we can calculate the time each car takes to reach the target. Cars starting closer to the target cannot pass cars ahead of them. Instead, if a car catches up to a car behind/ahead, they merge into a fleet. By processing cars in order of their starting positions closest to the target first, we can use a monotonic tracking mechanism to see if a car merges with an existing fleet or forms a new one.

# Approach
1. Use an ordered associative container (`std::map`) where keys are negated starting positions (`-pos[i]`) to naturally sort cars from closest to the target to furthest from the target.
2. Compute the time required for each car to reach the target as `(target - pos[i]) / speed[i]` and store it as the map value.
3. Iterate through the sorted map, maintaining a variable `cur` representing the time taken by the leading car or fleet.
4. If a subsequent car's time to the target (`it.second`) is strictly greater than `cur`, it means this car cannot catch up to the fleet ahead of it, thus forming a new fleet. Increment the answer and update `cur` to this new car's time.

### Visual Walkthrough (Example 1)
Given `target = 12`, `position = [10, 8, 0, 5, 3]`, `speed = [2, 4, 1, 1, 3]`:
- Cars mapped by position descending (-pos $ightarrow$ time):
  - `-10`: $(12 - 10) / 2 = 1.0$
  - `-8`: $(12 - 8) / 4 = 1.0$
  - `-5`: $(12 - 5) / 1 = 7.0$
  - `-3`: $(12 - 3) / 3 = 3.0$
  - `-0`: $(12 - 0) / 1 = 12.0$
- Iteration:
  - `it = (-10, 1.0)`: `1.0 > 0` $ightarrow$ `ans = 1`, `cur = 1.0`
  - `it = (-8, 1.0)`: `1.0 <= 1.0` (catches up) $ightarrow$ merged
  - `it = (-5, 7.0)`: `7.0 > 1.0` $ightarrow$ `ans = 2`, `cur = 7.0`
  - `it = (-3, 3.0)`: `3.0 <= 7.0` (catches up) $ightarrow$ merged
  - `it = (0, 12.0)`: `12.0 > 7.0` $ightarrow$ `ans = 3`, `cur = 12.0`
- Total fleets: `3`.

# Complexity
- Time complexity: $$O(N \log N)$$ — Inserting $$N$$ elements into a `std::map` takes $$O(N \log N)$$ time, and iterating through the map takes $$O(N)$$ time.
- Space complexity: $$O(N)$$ — The `std::map` stores up to $$N$$ unique position-time pairs.

# Code
```cpp
class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        map<int, double> m;

        for (int i = 0; i < pos.size(); i++){
            m[-pos[i]] = (double)(target - pos[i]) / speed[i];
        }
        int ans = 0;
        double cur = 0;

        for (auto it : m) if (it.second > cur){
            cur = it.second;
            ans++;
        }
        return ans;
    }
};
```
