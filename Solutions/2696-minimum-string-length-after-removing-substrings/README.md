# [2696. Minimum String Length After Removing Substrings](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/)
**Difficulty:** `Easy` | **Tags:** `string`, `stack`, `simulation`

---

## Problem Description
You are given a string `s` consisting only of **uppercase** English letters.

You can apply some operations to this string where, in one operation, you can remove **any** occurrence of one of the substrings `"AB"` or `"CD"` from `s`.

Return *the **minimum** possible length of the resulting string that you can obtain*.

**Note** that the string concatenates after removing the substring and could produce new `"AB"` or `"CD"` substrings.

**Example 1:**

```
Input: s = "ABFCACDB"
Output: 2
Explanation: We can do the following operations:
- Remove the substring "ABFCACDB", so s = "FCACDB".
- Remove the substring "FCACDB", so s = "FCAB".
- Remove the substring "FCAB", so s = "FC".
So the resulting length of the string is 2.
It can be shown that it is the minimum length that we can obtain.
```

**Example 2:**

```
Input: s = "ACBBD"
Output: 5
Explanation: We cannot do any operations on the string so the length remains the same.
```

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists only of uppercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks us to repeatedly remove "AB" or "CD" substrings. Since removing a substring can create new instances of these patterns, a stack-based approach is ideal. By processing the string character by character, we can maintain a "running" result and check if the current character completes a removable pair with the top of our stack.

# Approach
1. Initialize an empty string `out` to act as a stack.
2. Iterate through each character `s[i]` in the input string.
3. If `out` is empty, push the current character.
4. If `out` is not empty, check the top element (`out.back()`):
   - If the top is 'A' and the current character is 'B', pop the 'A' from `out` (effectively removing "AB").
   - If the top is 'C' and the current character is 'D', pop the 'C' from `out` (effectively removing "CD").
   - Otherwise, push the current character onto `out`.
5. The final size of `out` represents the minimum possible length.

### Visual Trace (Example 1: "ABFCACDB")
| Step | Char | Stack (`out`) | Action |
| :--- | :--- | :--- | :--- |
| 1 | A | "A" | Push |
| 2 | B | "" | Pop (AB found) |
| 3 | F | "F" | Push |
| 4 | C | "FC" | Push |
| 5 | A | "FCA" | Push |
| 6 | C | "FCAC" | Push |
| 7 | D | "FCA" | Pop (CD found) |
| 8 | B | "FC" | Pop (AB found) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We traverse the string exactly once, and each character is pushed and popped from the stack at most once.
- Space complexity: $$O(N)$$, as in the worst case (no removals), the stack will store all characters of the input string.

# Code
```cpp
class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        string out = "";
        for(int i = 0;i<n;i++){
            if(out.empty()) out.push_back(s[i]);
            else{
                if(out.back() == 'A' && s[i] == 'B') out.pop_back();
                else if(out.back() == 'C' && s[i] == 'D') out.pop_back();
                else out.push_back(s[i]);
            }
        }
        return out.size();
    }
};
```
