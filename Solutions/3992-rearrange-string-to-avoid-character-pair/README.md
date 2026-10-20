# [3992. Rearrange String to Avoid Character Pair](https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`, `sorting`

---

## Problem Description
You are given a string `s` and two distinct lowercase English letters `x` and `y`.

Rearrange the characters of `s` to construct a new string `t` such that:

* `t` is a permutation of `s`.
* Every occurrence of `y` appears before every occurrence of `x` in `t`.

Return any valid string `t`.

**Example 1:**

**Input:** s = "aabc", x = "a", y = "c"

**Output:** "cbaa"

**Explanation:**

The string `"cbaa"` is a permutation of `"aabc"`, and every occurrence of `'c'` appears before every occurrence of `'a'`.

**Example 2:**

**Input:** s = "dcab", x = "d", y = "b"

**Output:** "cabd"

**Explanation:**

The string `"cabd"` is a permutation of `"dcab"`, and every occurrence of `'b'` appears before every occurrence of `'d'`.

**Example 3:**

**Input:** s = "axe", x = "o", y = "x"

**Output:** "axe"

**Explanation:**

The string `"axe"` is already valid. Since `'o'` does not occur in the string, the required condition is automatically satisfied.

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists of lowercase English letters.
* `x` and `y` are lowercase English letters.
* `x != y`

---

## Solution & Editorial
# Intuition
The problem requires that all occurrences of character `y` appear before all occurrences of character `x`. Since the relative order of other characters does not matter, we can simply partition the string into three distinct groups: all `y`s, all `x`s, and everything else. Concatenating these groups in the order `y`s + `others` + `x`s guarantees the condition is satisfied.

# Approach
1. Initialize three empty strings: `ys` to store all occurrences of `y`, `xs` to store all occurrences of `x`, and `others` to store all other characters.
2. Iterate through the input string `s` once. For each character `c`:
   - If `c == y`, append it to `ys`.
   - Else if `c == x`, append it to `xs`.
   - Otherwise, append it to `others`.
3. Concatenate the strings in the order `ys + others + xs` to form the result.

### Visual Trace (Example 1: s = "aabc", x = 'a', y = 'c')
| Iteration | Char | ys | xs | others |
|-----------|------|----|----|--------|
| 1 | 'a' | "" | "a" | "" |
| 2 | 'a' | "" | "aa" | "" |
| 3 | 'b' | "" | "aa" | "b" |
| 4 | 'c' | "c" | "aa" | "b" |

Result: `ys` + `others` + `xs` = "c" + "b" + "aa" = "cbaa"

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string `s`. We perform a single pass over the string and constant-time string concatenations.
- Space complexity: $$O(N)$$, as we store the characters of the input string in three auxiliary strings whose total length equals $$N$.

# Code
```cpp
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ys = "";
        string xs = "";
        string others = "";
        
        for (char c : s) {
            if (c == y) {
                ys += c;
            } else if (c == x) {
                xs += c;
            } else {
                others += c;
            }
        }
        
        string ans = ys + others + xs;
        
        return ans;
    }
};
```
