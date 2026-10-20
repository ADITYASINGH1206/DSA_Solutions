# [3894. Traffic Signal Color](https://leetcode.com/problems/traffic-signal-color/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`, `simulation`

---

## Problem Description
You are given an integer `timer` representing the remaining time (in seconds) on a traffic signal.

The signal follows these rules:

* If `timer == 0`, the signal is `"Green"`
* If `timer == 30`, the signal is `"Orange"`
* If `30 < timer <= 90`, the signal is `"Red"`

Return the current state of the signal. If none of the above conditions are met, return `"Invalid"`.

**Example 1:**

**Input:** timer = 60

**Output:** "Red"

**Explanation:**

Since `timer = 60`, and `30 < timer <= 90`, the answer is `"Red"`.

**Example 2:**

**Input:** timer = 5

**Output:** "Invalid"

**Explanation:**

Since `timer = 5`, it does not satisfy any of the given conditions, the answer is `"Invalid"`.

**Constraints:**

* `0 <= timer <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires mapping specific integer ranges and values to categorical string outputs. Since the conditions are mutually exclusive and based on simple arithmetic comparisons, a direct conditional branching approach is the most efficient and readable solution.

# Approach
1. Check if `timer` is exactly 0. If true, return "Green".
2. Check if `timer` is exactly 30. If true, return "Orange".
3. Check if `timer` falls within the range (30, 90] using the expression `timer > 30 && timer <= 90`. If true, return "Red".
4. If none of the above conditions are met, return "Invalid".

### Visual Trace (Example 1: timer = 60)
| Step | Condition | Evaluation | Result |
| :--- | :--- | :--- | :--- |
| 1 | `timer == 0` | 60 == 0 | False |
| 2 | `timer == 30` | 60 == 30 | False |
| 3 | `timer > 30 && timer <= 90` | 60 > 30 && 60 <= 90 | True |
| 4 | Return | - | "Red" |

# Complexity
- Time complexity: $$O(1)$$. The solution performs a constant number of integer comparisons regardless of the input value.
- Space complexity: $$O(1)$$. No auxiliary data structures are used; the function operates entirely in-place.

# Code
```cpp
class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0) {
            return "Green";
        }
        if (timer == 30) {
            return "Orange";
        }
        if (timer > 30 && timer <= 90) {
            return "Red";
        }
        return "Invalid";
    }
};
```
