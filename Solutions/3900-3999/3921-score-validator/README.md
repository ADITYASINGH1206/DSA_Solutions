# [3921. Score Validator](https://leetcode.com/problems/score-validator/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`, `simulation`

---

## Problem Description
You are given a string array `events`.

Initially, `score = 0` and `counter = 0`. Each element in `events` is one of the following:

* `"0"`, `"1"`, `"2"`, `"3"`, `"4"`, `"6"`: Add that value to the total score.
* `"W"`: Increase the counter by 1. No score is added.
* `"WD"`: Add 1 to the total score.
* `"NB"`: Add 1 to the total score.

Process the array from left to right. Stop processing when either:

* All elements in `events` have been processed, or
* The counter becomes 10.

Return an integer array `[score, counter]`, where:

* `score` is the final total score.
* `counter` is the final counter value.

**Example 1:**

**Input:** events = ["1","4","W","6","WD"]

**Output:** [12,1]

**Explanation:**

| Event | Score | Counter |
| --- | --- | --- |
| `"1"` | 1 | 0 |
| `"4"` | 5 | 0 |
| `"W"` | 5 | 1 |
| `"6"` | 11 | 1 |
| `"WD"` | 12 | 1 |

Final result: `[12, 1]`.

**Example 2:**

**Input:** events = ["WD","NB","0","4","4"]

**Output:** [10,0]

**Explanation:**

| Event | Score | Counter |
| --- | --- | --- |
| `"WD"` | 1 | 0 |
| `"NB"` | 2 | 0 |
| `"0"` | 2 | 0 |
| `"4"` | 6 | 0 |
| `"4"` | 10 | 0 |

Final result: `[10, 0]`.

**Example 3:**

**Input:** events = ["W","W","W","W","W","W","W","W","W","W","W"]

**Output:** [0,10]

**Explanation:**

After 10 occurrences of `"W"`, the counter reaches 10, so processing stops. The remaining events are ignored.

**Constraints:**

* `1 <= events.length <= 1000`
* `events[i]` is one of `"0"`, `"1"`, `"2"`, `"3"`, `"4"`, `"6"`, `"W"`, `"WD"`, or `"NB"`.

---

## Solution & Editorial
# Intuition
The problem requires a straightforward simulation of game events. We maintain a running total for the score and a counter for specific events, terminating the process immediately when the counter reaches the threshold of 10.

# Approach
1. Initialize `ans` as a vector of two integers: `ans[0]` for the score and `ans[1]` for the counter.
2. Iterate through the `events` array using a loop.
3. For each event:
   - If the event is "W", increment `ans[1]`.
   - If the event is "WD" or "NB", increment `ans[0]` by 1.
   - Otherwise, convert the string to an integer using `stoi` and add it to `ans[0]`.
4. After processing each event, check if `ans[1]` equals 10. If true, terminate the loop and return the current `ans`.

### Visual Trace (Example 1: ["1","4","W","6","WD"])
| Step | Event | Score (`ans[0]`) | Counter (`ans[1]`) |
| :--- | :--- | :--- | :--- |
| 1 | "1" | 1 | 0 |
| 2 | "4" | 5 | 0 |
| 3 | "W" | 5 | 1 |
| 4 | "6" | 11 | 1 |
| 5 | "WD" | 12 | 1 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of events. We iterate through the list at most once.
- Space complexity: $$O(1)$$, as we only use a fixed-size vector to store the result regardless of the input size.

# Code
```cpp
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans{0,0};
        int n = events.size();
        for(int i = 0;i<n;i++){
            string temp = events[i];
            if(events[i] == "W") ans[1]++;
            else if(events[i] == "WD") ans[0]++;
            else if(events[i] == "NB") ans[0]++;
            else{
                int run = stoi(temp);
                ans[0] += run;
            }
            if(ans[1] == 10)return ans;
        }
        return ans;
    }
};
```
