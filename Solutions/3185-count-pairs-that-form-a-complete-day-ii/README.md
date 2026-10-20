# [3185. Count Pairs That Form a Complete Day II](https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
Given an integer array `hours` representing times in **hours**, return an integer denoting the number of pairs `i`, `j` where `i < j` and `hours[i] + hours[j]` forms a **complete day**.

A **complete day** is defined as a time duration that is an **exact** **multiple** of 24 hours.

For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.

**Example 1:**

**Input:** hours = [12,12,30,24,24]

**Output:** 2

**Explanation:** The pairs of indices that form a complete day are `(0, 1)` and `(3, 4)`.

**Example 2:**

**Input:** hours = [72,48,24,3]

**Output:** 3

**Explanation:** The pairs of indices that form a complete day are `(0, 1)`, `(0, 2)`, and `(1, 2)`.

**Constraints:**

* `1 <= hours.length <= 5 * 105`
* `1 <= hours[i] <= 109`

---

## Solution & Editorial
# Intuition
To determine if two numbers sum to a multiple of 24, we only care about their remainders when divided by 24. Specifically, if `hours[i] % 24` is `r`, we need to find how many previous elements had a remainder of `(24 - r) % 24`.

# Approach
1. Initialize a frequency array (or hash map) of size 24 to store the counts of remainders encountered so far.
2. Iterate through the `hours` array. For each `hour`:
   - Calculate `remaining = hour % 24`.
   - If `remaining == 0`, we need to pair it with previous elements that also had a remainder of `0`.
   - If `remaining > 0`, we need to pair it with previous elements that had a remainder of `24 - remaining`.
   - Add the count of these matching remainders to the total `ans`.
   - Increment the frequency count for the current `remaining`.

### Visual Trace (Example 1: [12, 12, 30, 24, 24])
| Step | Hour | Remainder | Target | Count[Target] | Ans | Count State (mod 24) |
|---|---|---|---|---|---|---|
| 1 | 12 | 12 | 12 | 0 | 0 | {12: 1} |
| 2 | 12 | 12 | 12 | 1 | 1 | {12: 2} |
| 3 | 30 | 6 | 18 | 0 | 1 | {12: 2, 6: 1} |
| 4 | 24 | 0 | 0 | 0 | 1 | {12: 2, 6: 1, 0: 1} |
| 5 | 24 | 0 | 0 | 1 | 2 | {12: 2, 6: 1, 0: 2} |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the `hours` array, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, because the frequency map/array size is fixed at 24, regardless of the input size.

# Code
```cpp
using ll = long long;
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<ll,ll>count;
        ll ans = 0;
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
