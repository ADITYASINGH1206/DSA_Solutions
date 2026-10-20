# [1010. Pairs of Songs With Total Durations Divisible by 60](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
You are given a list of songs where the `ith` song has a duration of `time[i]` seconds.

Return *the number of pairs of songs for which their total duration in seconds is divisible by* `60`. Formally, we want the number of indices `i`, `j` such that `i < j` with `(time[i] + time[j]) % 60 == 0`.

**Example 1:**

```
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
```

**Example 2:**

```
Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
```

**Constraints:**

* `1 <= time.length <= 6 * 104`
* `1 <= time[i] <= 500`

---

## Solution & Editorial
# Intuition
To find pairs of songs whose total duration is divisible by 60, we can use modular arithmetic. Two song durations `t1` and `t2` sum to a multiple of 60 if and only if `(t1 % 60 + t2 % 60) % 60 == 0`. By maintaining a frequency map of remainder values seen so far, we can count valid pairs in a single pass.

# Approach
1. Initialize an unordered map `count` to track the frequencies of each remainder modulo 60, and an integer `ans` initialized to 0.
2. Iterate through each duration `t` in the `time` array:
   - Compute its remainder `song = t % 60`.
   - Calculate the required complementary remainder `required = (60 - song) % 60`.
   - Add the frequency of `required` found in `count` to `ans`.
   - Increment the frequency of `song` in `count`.
3. Return the total accumulated pairs `ans`.

### Visual Walkthrough (Example 1: `time = [30, 20, 150, 100, 40]`)
| Iteration | `t` | `song = t % 60` | `required` | Frequency of `required` | `ans` (cumulative) | `count` State After Step |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 30 | 30 | 30 | 0 | 0 | `{30: 1}` |
| 2 | 20 | 20 | 40 | 0 | 0 | `{30: 1, 20: 1}` |
| 3 | 150 | 30 | 30 | 1 | 1 | `{30: 2, 20: 1}` |
| 4 | 100 | 40 | 20 | 1 | 2 | `{30: 2, 20: 1, 40: 1}` |
| 5 | 40 | 40 | 20 | 1 (from 20) | 3 | `{30: 2, 20: 1, 40: 2}` |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the `time` array. We traverse the input array once, performing constant time hash map lookups and insertions.
- Space complexity: $$O(1)$$ auxiliary space since the hash map `count` can store at most 60 distinct remainder keys (from `0` to `59`).

# Code
```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>count;
        int ans =0;
        for(int t:time){
            int song = t%60;
            int required = (60-song)%60;
            ans+=count[required];
            count[song]++;
        }
        return ans;
    }
};
```
