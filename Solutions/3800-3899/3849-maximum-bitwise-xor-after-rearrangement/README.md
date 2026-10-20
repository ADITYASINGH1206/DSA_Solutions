# [3849. Maximum Bitwise XOR After Rearrangement](https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement/)
**Difficulty:** `Medium` | **Tags:** `string`, `greedy`, `bit-manipulation`

---

## Problem Description
You are given two binary strings `s` and `t`​​​​​​​, each of length `n`.

You may **rearrange** the characters of `t` in any order, but `s` **must remain unchanged**.

Return a **binary string** of length `n` representing the **maximum** integer value obtainable by taking the bitwise **XOR** of `s` and rearranged `t`.

**Example 1:**

**Input:** s = "101", t = "011"

**Output:** "110"

**Explanation:**

* One optimal rearrangement of `t` is `"011"`.
* The bitwise XOR of `s` and rearranged `t` is `"101" XOR "011" = "110"`, which is the maximum possible.

**Example 2:**

**Input:** s = "0110", t = "1110"

**Output:** "1101"

**Explanation:**

* One optimal rearrangement of `t` is `"1011"`.
* The bitwise XOR of `s` and rearranged `t` is `"0110" XOR "1011" = "1101"`, which is the maximum possible.

**Example 3:**

**Input:** s = "0101", t = "1001"

**Output:** "1111"

**Explanation:**

* One optimal rearrangement of `t` is `"1010"`.
* The bitwise XOR of `s` and rearranged `t` is `"0101" XOR "1010" = "1111"`, which is the maximum possible.

**Constraints:**

* `1 <= n == s.length == t.length <= 2 * 105`
* `s[i]` and `t[i]` are either `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
To maximize the result of a bitwise XOR, we want the most significant bits to be '1'. Since we can rearrange `t` arbitrarily, we essentially have a fixed pool of '0's and '1's from `t` that we can place at any position to XOR against the corresponding bit in `s`.

# Approach
1. Count the total number of '0's and '1's available in string `t`.
2. Iterate through each bit of `s` from left to right (most significant to least significant).
3. For each bit in `s`:
   - If `s[i]` is '1', we prefer to XOR it with a '0' from `t` to get a '1' in the result.
   - If `s[i]` is '0', we prefer to XOR it with a '1' from `t` to get a '1' in the result.
   - If our preferred bit is unavailable, we are forced to use the other available bit, which will result in a '0' in the output.

### Visual Trace (Example 1: s="101", t="011")
- Initial: `zeros` = 1, `ones` = 2
- i=0: s[0]='1'. Prefer '0'. Available? Yes. Result="1", `zeros`=0, `ones`=2.
- i=1: s[1]='0'. Prefer '1'. Available? Yes. Result="11", `zeros`=0, `ones`=1.
- i=2: s[2]='1'. Prefer '0'. Available? No. Use '1'. Result="110", `zeros`=0, `ones`=0.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the strings. We perform one pass to count characters in `t` and one pass to construct the result string.
- Space complexity: $$O(N)$$ to store the resulting string.

# Code
```cpp
class Solution {
public:
    string maximumXor(string s,string t) {
        int zeros = 0;
        int ones = 0;
        for (char c : t) {
            if (c == '0') zeros++;
            else ones++;
        }
        
        string result = "";
        
        for (char c : s) {
            if (c == '1') {
                if (zeros > 0) {
                    result += '1';
                    zeros--;
                } else {
                    result += '0';
                    ones--;
                }
            } else { 
                if (ones > 0) {
                    result += '1';
                    ones--;
                } else {
                    result += '0';
                    zeros--;
                }
            }
        }
        
        return result;
    }
};
```
