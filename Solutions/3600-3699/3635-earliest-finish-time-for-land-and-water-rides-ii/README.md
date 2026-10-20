# [3635. Earliest Finish Time for Land and Water Rides II](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `binary-search`, `greedy`, `sorting`

---

## Problem Description
You are given two categories of theme park attractions: **land rides** and **water rides**.

* **Land rides**
  + `landStartTime[i]` – the earliest time the `ith` land ride can be boarded.
  + `landDuration[i]` – how long the `ith` land ride lasts.
* **Water rides**
  + `waterStartTime[j]` – the earliest time the `jth` water ride can be boarded.
  + `waterDuration[j]` – how long the `jth` water ride lasts.

A tourist must experience **exactly one** ride from **each** category, in **either order**.

* A ride may be started at its opening time or **any later moment**.
* If a ride is started at time `t`, it finishes at time `t + duration`.
* Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.

Return the **earliest possible time** at which the tourist can finish both rides.

**Example 1:**

**Input:** landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]

**Output:** 9

**Explanation:**​​​​​​​

* Plan A (land ride 0 → water ride 0):
  + Start land ride 0 at time `landStartTime[0] = 2`. Finish at `2 + landDuration[0] = 6`.
  + Water ride 0 opens at time `waterStartTime[0] = 6`. Start immediately at `6`, finish at `6 + waterDuration[0] = 9`.
* Plan B (water ride 0 → land ride 1):
  + Start water ride 0 at time `waterStartTime[0] = 6`. Finish at `6 + waterDuration[0] = 9`.
  + Land ride 1 opens at `landStartTime[1] = 8`. Start at time `9`, finish at `9 + landDuration[1] = 10`.
* Plan C (land ride 1 → water ride 0):
  + Start land ride 1 at time `landStartTime[1] = 8`. Finish at `8 + landDuration[1] = 9`.
  + Water ride 0 opened at `waterStartTime[0] = 6`. Start at time `9`, finish at `9 + waterDuration[0] = 12`.
* Plan D (water ride 0 → land ride 0):
  + Start water ride 0 at time `waterStartTime[0] = 6`. Finish at `6 + waterDuration[0] = 9`.
  + Land ride 0 opened at `landStartTime[0] = 2`. Start at time `9`, finish at `9 + landDuration[0] = 13`.

Plan A gives the earliest finish time of 9.

**Example 2:**

**Input:** landStartTime = [5], landDuration = [3], waterStartTime = [1], waterDuration = [10]

**Output:** 14

**Explanation:**​​​​​​​

* Plan A (water ride 0 → land ride 0):
  + Start water ride 0 at time `waterStartTime[0] = 1`. Finish at `1 + waterDuration[0] = 11`.
  + Land ride 0 opened at `landStartTime[0] = 5`. Start immediately at `11` and finish at `11 + landDuration[0] = 14`.
* Plan B (land ride 0 → water ride 0):
  + Start land ride 0 at time `landStartTime[0] = 5`. Finish at `5 + landDuration[0] = 8`.
  + Water ride 0 opened at `waterStartTime[0] = 1`. Start immediately at `8` and finish at `8 + waterDuration[0] = 18`.

Plan A provides the earliest finish time of 14.**​​​​​​​**

**Constraints:**

* `1 <= n, m <= 5 * 104`
* `landStartTime.length == landDuration.length == n`
* `waterStartTime.length == waterDuration.length == m`
* `1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 105`

---

## Solution & Editorial
# Intuition
The problem asks for the earliest finish time of two rides (one land, one water) in either order. Since the order is fixed for a specific sequence (e.g., Land then Water), we can simplify the problem by calculating the minimum finish time for both possible orderings (Land $\to$ Water and Water $\to$ Land) and taking the global minimum.

# Approach
1. Define a helper function `calc(first_rides, second_rides)` that computes the minimum finish time if we perform any ride from `first_rides` followed by any ride from `second_rides`.
2. In `calc`, first find the minimum possible finish time of any ride in `first_rides`. Let this be `minEnd`. This represents the earliest time we can possibly finish the first ride.
3. For every ride in `second_rides`, the finish time is `max(minEnd, second_ride_start_time) + second_ride_duration`. We want to minimize this value across all possible `second_rides`.
4. The final answer is `min(calc(land, water), calc(water, land))`.

### Visual Trace (Example 1)
`land = [2,8], landDur = [4,1], water = [6], waterDur = [3]`

- `calc(land, water)`:
  - `minEnd` (land finish) = `min(2+4, 8+1) = 6`.
  - `ans` = `min(max(6, 6) + 3) = 9`.
- `calc(water, land)`:
  - `minEnd` (water finish) = `6+3 = 9`.
  - `ans` = `min(max(9, 2) + 4, max(9, 8) + 1) = min(13, 10) = 10`.
- Result: `min(9, 10) = 9`.

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the number of land and water rides respectively. We iterate through each array exactly once in each `calc` call.
- Space complexity: $$O(1)$$, as we only use a few integer variables for tracking minimums.

# Code
```cpp
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int x = calc(landStartTime, landDuration, waterStartTime, waterDuration);
        int y = calc(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(x, y);
    }

    int calc(vector<int>& a1, vector<int>& t1, vector<int>& a2, vector<int>& t2) {
        int minEnd = INT_MAX;
        for (int i = 0; i < a1.size(); ++i) {
            minEnd = min(minEnd, a1[i] + t1[i]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < a2.size(); ++i) {
            ans = min(ans, max(minEnd, a2[i]) + t2[i]);
        }
        return ans;
    }
};
```
