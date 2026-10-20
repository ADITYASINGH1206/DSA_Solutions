# [401. Binary Watch](https://leetcode.com/problems/binary-watch/)
**Difficulty:** `Easy` | **Tags:** `backtracking`, `bit-manipulation`

---

## Problem Description
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

* For example, the below binary watch reads `"4:51"`.

Given an integer `turnedOn` which represents the number of LEDs that are currently on (ignoring the PM), return *all possible times the watch could represent*. You may return the answer in **any order**.

The hour must not contain a leading zero.

* For example, `"01:00"` is not valid. It should be `"1:00"`.

The minute must consist of two digits and may contain a leading zero.

* For example, `"10:2"` is not valid. It should be `"10:02"`.

**Example 1:**

```
Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
```

**Example 2:**

```
Input: turnedOn = 9
Output: []
```

**Constraints:**

* `0 <= turnedOn <= 10`

---

## Solution & Editorial
# Intuition
The binary watch problem restricts the search space to a fixed, very small domain: hours from $0$ to $11$ and minutes from $0$ to $59$. Since the total number of valid time combinations is extremely small ($12 \times 60 = 720$), we can simply iterate through every possible hour and minute, count the total number of set bits (LEDs turned on) in both values, and collect those that match the requested `turnedOn` count.

# Approach
1. Initialize a string vector `ans` to store the resulting valid time strings.
2. Iterate through all possible hours `i` from $0$ to $11$.
3. For each hour, iterate through all possible minutes `j` from $0$ to $59$.
4. Use the built-in intrinsic `__builtin_popcount(i) + __builtin_popcount(j)` to count the total number of set bits across the hour and minute.
5. If the total set bits equal `turnedOn`, format the time string correctly (ensuring a two-digit zero-padded minute representation) and append it to `ans`.
6. Return `ans` after checking all combinations.

### Visual Walkthrough for `turnedOn = 1` (Partial Iteration)
| i (Hour) | j (Minute) | `__builtin_popcount(i)` | `__builtin_popcount(j)` | Total Bits | Match? | Added Time |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 1 | 0 | 1 | 1 | Yes | "0:01" |
| 0 | 2 | 0 | 1 | 1 | Yes | "0:02" |
| 1 | 0 | 1 | 0 | 1 | Yes | "1:00" |
| 2 | 3 | 1 | 2 | 3 | No | - |

# Complexity
- Time complexity: $$O(1)$$
The outer loop runs exactly 12 times and the inner loop runs exactly 60 times. Thus, the total operations are bounded by a constant $12 \times 60 = 720$ iterations, executing in $O(1)$ time.

- Space complexity: $$O(1)$$
The auxiliary space consists only of the result vector `ans` which holds at most 720 strings, requiring constant maximum memory.

# Code
```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {
                    ans.push_back(to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j));
                }
            }
        }
        return ans;
    }
};
```
