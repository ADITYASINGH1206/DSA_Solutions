# [2446. Determine if Two Events Have Conflict](https://leetcode.com/problems/determine-if-two-events-have-conflict/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
You are given two arrays of strings that represent two inclusive events that happened **on the same day**, `event1` and `event2`, where:

* `event1 = [startTime1, endTime1]` and
* `event2 = [startTime2, endTime2]`.

Event times are valid 24 hours format in the form of `HH:MM`.

A **conflict** happens when two events have some non-empty intersection (i.e., some moment is common to both events).

Return `true` *if there is a conflict between two events. Otherwise, return* `false`.

**Example 1:**

```
Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
Output: true
Explanation: The two events intersect at time 2:00.
```

**Example 2:**

```
Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
Output: true
Explanation: The two events intersect starting from 01:20 to 02:00.
```

**Example 3:**

```
Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
Output: false
Explanation: The two events do not intersect.
```

**Constraints:**

* `event1.length == event2.length == 2`
* `event1[i].length == event2[i].length == 5`
* `startTime1 <= endTime1`
* `startTime2 <= endTime2`
* All the event times follow the `HH:MM` format.

---

## Solution & Editorial
# Intuition
Since the events are given in "HH:MM" format, they can be treated as lexicographically comparable strings or converted into total minutes from the start of the day. A conflict exists if the start time of one event is less than or equal to the end time of the other, and vice versa.

# Approach
1. Convert each time string "HH:MM" into an integer representing the total minutes from 00:00. This is done by extracting the hours and minutes using `(s[0]-'0')*10 + (s[1]-'0')` and `(s[3]-'0')*10 + (s[4]-'0')`.
2. Let the intervals be `[start1, end1]` and `[start2, end2]`. Two intervals conflict if and only if `start1 <= end2` AND `start2 <= end1`.
3. The code checks the inverse: if `end1 < start2` OR `start1 > end2`, there is no conflict, and we return `false`. Otherwise, we return `true`.

### Visual Trace (Example 1)
`event1 = ["01:15", "02:00"], event2 = ["02:00", "03:00"]`
- `start1 = 75`, `end1 = 120`
- `start2 = 120`, `end2 = 180`
- Check: `end1 < start2` (120 < 120) is `false`.
- Check: `start1 > end2` (75 > 180) is `false`.
- Result: `true` (Conflict detected).

# Complexity
- Time complexity: $$O(1)$$. The conversion and comparison operations are constant time, as the input size is fixed at 4 strings of length 5.
- Space complexity: $$O(1)$$. No auxiliary data structures are used; only a few integer variables are stored.

# Code
```cpp
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(value(event1[1])<value(event2[0])||(value(event1[0])>value(event2[1]))){
            return false;
        }
        return true;
    }
    int value(string s){
        int hour = (((s[0]-'0')*10)+(s[1]-'0'))*60;
        int min = ((s[3]-'0')*10+(s[4]-'0'));
        return hour+min;
    }
};
```
