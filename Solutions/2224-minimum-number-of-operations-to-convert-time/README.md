# [2224. Minimum Number of Operations to Convert Time](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/)
**Difficulty:** `Easy` | **Tags:** `string`, `greedy`

---

## Problem Description
You are given two strings `current` and `correct` representing two **24-hour times**.

24-hour times are formatted as `"HH:MM"`, where `HH` is between `00` and `23`, and `MM` is between `00` and `59`. The earliest 24-hour time is `00:00`, and the latest is `23:59`.

In one operation you can increase the time `current` by `1`, `5`, `15`, or `60` minutes. You can perform this operation **any** number of times.

Return *the **minimum number of operations** needed to convert* `current` *to* `correct`.

**Example 1:**

```
Input: current = "02:30", correct = "04:35"
Output: 3
Explanation:
We can convert current to correct in 3 operations as follows:
- Add 60 minutes to current. current becomes "03:30".
- Add 60 minutes to current. current becomes "04:30".
- Add 5 minutes to current. current becomes "04:35".
It can be proven that it is not possible to convert current to correct in fewer than 3 operations.
```

**Example 2:**

```
Input: current = "11:00", correct = "11:01"
Output: 1
Explanation: We only have to add one minute to current, so the minimum number of operations needed is 1.
```

**Constraints:**

* `current` and `correct` are in the format `"HH:MM"`
* `current <= correct`

---

## Solution & Editorial
# Intuition
To minimize the number of operations, we should always prioritize the largest possible time increments (60, 15, 5, 1). This is a classic greedy problem where the denominations allow for a simple decomposition of the total difference in minutes.

# Approach
1. Convert both `current` and `correct` times into total minutes from the start of the day (00:00). Since the format is fixed as "HH:MM", we can extract the values using character arithmetic: `(H1 * 600 + H2 * 60 + M1 * 10 + M2)`. 
2. Calculate the difference `d` in total minutes between `correct` and `current`.
3. Greedily subtract the largest possible increments:
   - Use as many 60-minute blocks as possible: `d / 60`.
   - Use as many 15-minute blocks as possible from the remainder: `(d % 60) / 15`.
   - Use as many 5-minute blocks as possible from the remainder: `(d % 60 % 15) / 5`.
   - Use 1-minute blocks for the remaining minutes: `d % 5`.

### Visual Trace (Example 1: "02:30" to "04:35")
- `current` = 150 mins, `correct` = 275 mins. `d` = 125.
- 125 / 60 = 2 (rem 5). Ops: 2.
- 5 / 15 = 0 (rem 5). Ops: 2 + 0 = 2.
- 5 / 5 = 1 (rem 0). Ops: 2 + 1 = 3.
- 0 % 5 = 0. Total Ops: 3.

# Complexity
- Time complexity: $$O(1)$$. The conversion and arithmetic operations are constant time regardless of the input values.
- Space complexity: $$O(1)$$. Only a few integer variables are used for calculation.

# Code
```cpp
class Solution {
public:
    int convertTime(string current, string correct) {
        auto toMin = [](string &s) { 
            return s[0] * 600 + s[1] * 60 + s[3] * 10 + s[4] ;
        };
        int d = toMin(correct) - toMin(current);
        return d / 60 + d % 60 / 15 + d % 15 / 5 + d % 5;
    }
};
```
