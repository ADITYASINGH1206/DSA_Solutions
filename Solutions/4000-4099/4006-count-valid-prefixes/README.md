# [4006. Count Valid Prefixes](https://leetcode.com/problems/count-valid-prefixes/)
**Difficulty:** `Easy` | **Tags:** `string`, `counting`

---

## Problem Description
You are given a binary string `s`.

A prefix of `s` is considered **valid** if its characters can be rearranged to form an **alternating** string.

Return the number of valid prefixes of `s`.

A string is considered **alternating** if no two adjacent characters are equal.

**Example 1:**

**Input:** s = "00101"

**Output:** 3

**Explanation:**

The valid prefixes are:

* `"0"`: It is already an alternating string.
* `"001"`: It can be rearranged into `"010"`, which is an alternating string.
* `"00101"`: It can be rearranged into `"01010"`, which is an alternating string.

Thus, the answer is 3.

**Example 2:**

**Input:** s = "101"

**Output:** 3

**Explanation:**

All prefixes of `s = "101"` are already alternating strings. Thus, the answer is 3.

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists only of `'0'` and `'1'`.

---

## Solution & Editorial
# Intuition
To determine if a binary string can be rearranged into an alternating string, we must observe the counts of '0's and '1's. An alternating string like "010" or "1010" can only exist if the difference between the count of '0's and '1's is at most 1. If the difference exceeds 1, there will inevitably be at least two identical characters adjacent to each other regardless of the arrangement.

# Approach
1. Initialize `zero` and `one` counters to track the frequency of characters in the current prefix.
2. Iterate through the string `s` character by character.
3. Update the respective counter (`zero` or `one`) based on the current character.
4. Check if the absolute difference `abs(zero - one)` is less than or equal to 1. If true, the current prefix is valid, and we increment `ans`.

### Visual Trace (s = "00101")
| Prefix | zero | one | abs(diff) | Valid? | ans |
| :--- | :--- | :--- | :--- | :--- | :--- |
| "0" | 1 | 0 | 1 | Yes | 1 |
| "00" | 2 | 0 | 2 | No | 1 |
| "001" | 2 | 1 | 1 | Yes | 2 |
| "0010" | 3 | 1 | 2 | No | 2 |
| "00101" | 3 | 2 | 1 | Yes | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for integer counters.

# Code
```cpp
class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0;
        int zero = 0;
        int one = 0;
        
        for (char c : s) {
            if (c == '0') {
                zero++;
            } else {
                one++;
            }
            
            if (abs(zero - one) <= 1) {
                ans++;
            }
        }
        
        return ans;
    }
};
```
