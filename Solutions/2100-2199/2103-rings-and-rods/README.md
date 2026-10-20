# [2103. Rings and Rods](https://leetcode.com/problems/rings-and-rods/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`

---

## Problem Description
There are `n` rings and each ring is either red, green, or blue. The rings are distributed **across ten rods** labeled from `0` to `9`.

You are given a string `rings` of length `2n` that describes the `n` rings that are placed onto the rods. Every two characters in `rings` forms a **color-position pair** that is used to describe each ring where:

* The **first** character of the `ith` pair denotes the `ith` ring's **color** (`'R'`, `'G'`, `'B'`).
* The **second** character of the `ith` pair denotes the **rod** that the `ith` ring is placed on (`'0'` to `'9'`).

For example, `"R3G2B1"` describes `n == 3` rings: a red ring placed onto the rod labeled 3, a green ring placed onto the rod labeled 2, and a blue ring placed onto the rod labeled 1.

Return *the number of rods that have **all three colors** of rings on them.*

**Example 1:**

```
Input: rings = "B0B6G0R6R0R6G9"
Output: 1
Explanation: 
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.
```

**Example 2:**

```
Input: rings = "B0R0G0R9R0B0G0"
Output: 1
Explanation: 
- The rod labeled 0 holds 6 rings with all colors: red, green, and blue.
- The rod labeled 9 holds only a red ring.
Thus, the number of rods with all three colors is 1.
```

**Example 3:**

```
Input: rings = "G4"
Output: 0
Explanation: 
Only one ring is given. Thus, no rods have all three colors.
```

**Constraints:**

* `rings.length == 2 * n`
* `1 <= n <= 100`
* `rings[i]` where `i` is **even** is either `'R'`, `'G'`, or `'B'` (**0-indexed**).
* `rings[i]` where `i` is **odd** is a digit from `'0'` to `'9'` (**0-indexed**).

---

## Solution & Editorial
# Intuition
Since there are only 10 rods and 3 possible colors, we can track the presence of each color on each rod using a fixed-size data structure. A 2D boolean array `mp[10][3]` is sufficient to record whether a specific color (Red, Green, or Blue) has appeared on a specific rod (0-9).

# Approach
1. Initialize a 2D boolean vector `mp` of size 10x3, where `mp[rod][color_index]` tracks if a color exists on a rod.
2. Iterate through the `rings` string with a step of 2. For each pair `(color, rod)`:
   - Convert the character `rings[i+1]` to an integer `idx` (0-9).
   - Map 'R' to index 0, 'G' to index 1, and 'B' to index 2.
   - Set `mp[idx][color_index]` to `true`.
3. After processing all rings, iterate through the 10 rods. If `mp[i][0]`, `mp[i][1]`, and `mp[i][2]` are all `true`, increment the counter `ans`.

### Visual Trace (Example: "B0G0R0")
| Step | Input Pair | Rod | Color | `mp[0]` State |
| :--- | :--- | :--- | :--- | :--- |
| 1 | B0 | 0 | B | [F, F, T] |
| 2 | G0 | 0 | G | [F, T, T] |
| 3 | R0 | 0 | R | [T, T, T] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rings. We iterate through the string once, performing constant-time operations for each pair.
- Space complexity: $$O(1)$$, as the storage required for the 10x3 boolean matrix is constant regardless of the input size.

# Code
```cpp
class Solution {
public:
    int countPoints(string rings) {
        vector<vector<bool>> mp(10, vector<bool>(3, false));
        int n = rings.size();
        for(int i = 0 ;i < n;i+=2){

            int idx = rings[i+1] - '0';

            if(rings[i] == 'R') mp[idx][0] = true;
            else if(rings[i] == 'G') mp[idx][1] = true;
            else if(rings[i] == 'B')mp[idx][2] = true;
        }
        int ans = 0;
        for(int i =0;i<10;i++) {
            if(mp[i][0] && mp[i][1] && mp[i][2]) {
                ans++;
            }
        }
        return ans;
    }
};
```
