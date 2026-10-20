# [3184. Count Pairs That Form a Complete Day I](https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
Given an integer array `hours` representing times in **hours**, return an integer denoting the number of pairs `i`, `j` where `i < j` and `hours[i] + hours[j]` forms a **complete day**.

A **complete day** is defined as a time duration that is an **exact** **multiple** of 24 hours.

For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.

**Example 1:**

**Input:** hours = [12,12,30,24,24]

**Output:** 2

**Explanation:**

The pairs of indices that form a complete day are `(0, 1)` and `(3, 4)`.

**Example 2:**

**Input:** hours = [72,48,24,3]

**Output:** 3

**Explanation:**

The pairs of indices that form a complete day are `(0, 1)`, `(0, 2)`, and `(1, 2)`.

**Constraints:**

* `1 <= hours.length <= 100`
* `1 <= hours[i] <= 109`

---

## Solution & Editorial
# Intuition
To determine if the sum of two numbers `hours[i]` and `hours[j]` is a multiple of 24, we only care about their remainders when divided by 24. Specifically, `(hours[i] + hours[j]) % 24 == 0` is equivalent to `(hours[i] % 24 + hours[j] % 24) % 24 == 0`.

# Approach
1. We use a hash map `count` to store the frequency of remainders encountered so far.
2. For each `hour` in the input array, calculate its remainder `remaining = hour % 24`.
3. If `remaining` is 0, we need to find how many previous numbers had a remainder of 0 to form a sum divisible by 24.
4. If `remaining` is non-zero, we need to find how many previous numbers had a remainder of `24 - remaining`.
5. Add the frequency of the required remainder to `ans` and increment the frequency of the current `remaining` in the map.

### Visual Trace (Example 1: [12, 12, 30, 24, 24])
| Step | Hour | Remainder | Target | Map State | Ans |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 12 | 12 | 12 | {12: 1} | 0 |
| 2 | 12 | 12 | 12 | {12: 2} | 1 |
| 3 | 30 | 6 | 18 | {12: 2, 6: 1} | 1 |
| 4 | 24 | 0 | 0 | {12: 2, 6: 1, 0: 1} | 1 |
| 5 | 24 | 0 | 0 | {12: 2, 6: 1, 0: 2} | 2 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the `hours` array. We iterate through the array exactly once, performing constant-time hash map lookups and insertions.
- Space complexity: $$O(1)$$, because the hash map stores at most 24 unique remainders (0 through 23), which is constant regardless of the input size.

# Code
```cpp
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int>count;
        int ans = 0;
        for(int hour:hours){
            int remaining = hour%24;
            if(remaining==0){
                ans+=count[remaining];
            }else{
                ans+=count[24-remaining];
            }
            count[remaining]++;
        }
        return ans;
    }
};
```
