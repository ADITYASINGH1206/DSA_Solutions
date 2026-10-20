# [3986. Number of Elapsed Seconds Between Two Times](https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`

---

## Problem Description
You are given two valid times `startTime` and `endTime`, each represented as a string in the format `"HH:MM:SS"`.

Return the number of seconds that have elapsed from `startTime` to `endTime`.

**Example 1:**

**Input:** startTime = "01:00:00", endTime = "01:00:25"

**Output:** 25

**Explanation:**

`endTime` is 25 seconds ahead of `startTime`.

**Example 2:**

**Input:** startTime = "12:34:56", endTime = "13:00:00"

**Output:** 1504

**Explanation:**

`endTime` is 25 minutes and 4 seconds ahead of `startTime`, which equals 1504 seconds.

**Constraints:**

* `startTime.length == 8`
* `endTime.length == 8`
* `startTime` and `endTime` are valid times in the format `"HH:MM:SS"`
* `00 <= HH <= 23`
* `00 <= MM <= 59`
* `00 <= SS <= 59`
* `endTime` is not earlier than `startTime`

---

## Solution & Editorial
# Intuition
To calculate the elapsed time between two timestamps, the most efficient approach is to convert both times into a single scalar unit: total seconds from the start of the day (00:00:00). Once both times are represented as integers, the elapsed duration is simply the difference between them.

# Approach
1. Define a helper function `timeToSeconds` that parses the "HH:MM:SS" string format.
2. Extract the hours, minutes, and seconds using `substr` and convert them to integers using `stoi`.
3. Calculate the total seconds using the formula: `(hours * 3600) + (minutes * 60) + seconds`.
4. Apply this helper to both `startTime` and `endTime`.
5. Return the difference `timeToSeconds(endTime) - timeToSeconds(startTime)`.

### Visual Trace (Example 2: "12:34:56" to "13:00:00")
| Time | H | M | S | Total Seconds |
| :--- | :--- | :--- | :--- | :--- |
| 12:34:56 | 12 | 34 | 56 | (12*3600) + (34*60) + 56 = 45296 |
| 13:00:00 | 13 | 00 | 00 | (13*3600) + (0*60) + 0 = 46800 |
| **Result** | | | | 46800 - 45296 = 1504 |

# Complexity
- Time complexity: $$O(1)$$. The string length is fixed at 8 characters, and parsing involves a constant number of arithmetic operations.
- Space complexity: $$O(1)$$. We only use a few integer variables to store the parsed time components.

# Code
```cpp
class Solution {
public:
    int timeToSeconds(string& timeStr) {
        int h = stoi(timeStr.substr(0, 2));
        int m = stoi(timeStr.substr(3, 2));
        int s = stoi(timeStr.substr(6, 2));
        
        return (h * 3600) + (m * 60) + s;
    }
    int secondsBetweenTimes(string startTime,string endTime) {
        return timeToSeconds(endTime) - timeToSeconds(startTime);
    }
};
```
