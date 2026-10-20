# [1910. Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `simulation`

---

## Problem Description
Given two strings `s` and `part`, perform the following operation on `s` until **all** occurrences of the substring `part` are removed:

* Find the **leftmost** occurrence of the substring `part` and **remove** it from `s`.

Return `s` *after removing all occurrences of* `part`.

A **substring** is a contiguous sequence of characters in a string.

**Example 1:**

```
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
```

**Example 2:**

```
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
```

**Constraints:**

* `1 <= s.length <= 1000`
* `1 <= part.length <= 1000`
* `s`​​​​​​ and `part` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To efficiently remove all occurrences of `part`, we can simulate the process using a stack-based approach. By processing the string `s` character by character and pushing them onto a result string (acting as a stack), we can check if the end of our stack matches `part` whenever we push the last character of `part`.

# Approach
1. Initialize an empty string `stk` to act as our stack and pre-calculate the length `tn` and the last character `te` of `part`.
2. Iterate through each character `c` in the input string `s`:
   - Append `c` to `stk`.
   - If `c` matches `te` and the current size of `stk` is at least `tn`, check if the suffix of `stk` of length `tn` equals `part`.
   - If it matches, remove the last `tn` characters from `stk` using `erase`.
3. After processing all characters, `stk` contains the final string.

### Visual Trace (s = "daabc", part = "abc")
| Step | Char | Stack State | Action |
| :--- | :--- | :--- | :--- |
| 1 | 'd' | "d" | Push |
| 2 | 'a' | "da" | Push |
| 3 | 'a' | "daa" | Push |
| 4 | 'b' | "daab" | Push |
| 5 | 'c' | "daabc" -> "d" | Push, Match, Erase |

# Complexity
- Time complexity: $$O(N \cdot M)$$, where $$N$$ is the length of `s` and $$M$$ is the length of `part`. In the worst case, for every character in `s`, we perform a substring comparison and erasure of length $$M$$.
- Space complexity: $$O(N)$$, as the stack `stk` can grow up to the size of the input string `s` in the worst case.

# Code
```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stk;
        int tn = part.size();
        char te = part.back();

        for (char c : s) {
            stk.push_back(c);

            if (c == te && stk.size() >= tn) {
                if (stk.substr(stk.size() - tn) == part) {
                    stk.erase(stk.size() - tn);
                }
            }
        }
        return stk;
    }
};
```
