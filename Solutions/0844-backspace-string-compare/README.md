# [844. Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`, `stack`, `simulation`

---

## Problem Description
Given two strings `s` and `t`, return `true` *if they are equal when both are typed into empty text editors*. `'#'` means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

**Example 1:**

```
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
```

**Example 2:**

```
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
```

**Example 3:**

```
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
```

**Constraints:**

* `1 <= s.length, t.length <= 200`
* `s` and `t` only contain lowercase letters and `'#'` characters.

**Follow up:** Can you solve it in `O(n)` time and `O(1)` space?

---

## Solution & Editorial
# Intuition
The problem requires us to simulate typing two strings into text editors where the '#' character acts as a backspace, removing the most recently typed character. A stack naturally models this Last-In-First-Out (LIFO) behavior. By using strings as character stacks, we can process each string independently and compare the final resulting states.

# Approach
1. Initialize two empty string buffers `s1` and `s2` to act as stacks for strings `s` and `t` respectively.
2. Iterate through each character of string `s` using a standard `for` loop:
   - If the current character `s[i]` is '#' and `s1` is empty, do nothing.
   - If `s[i]` is '#' and `s1` is not empty, pop the last character using `s1.pop_back()`.
   - Otherwise, append the valid character to `s1` using `s1 += s[i]`.
3. Repeat the exact same simulation process for string `t`, storing the result in `s2`.
4. Finally, return the boolean result of comparing `s1 == s2`.

### Visual Trace Walkthrough (Example 1)
Input: `s = "ab#c"`, `t = "ad#c"`

- **Processing `s`:**
  - `i = 0`, `s[0] = 'a'` -> `s1 = "a"`
  - `i = 1`, `s[1] = 'b'` -> `s1 = "ab"`
  - `i = 2`, `s[2] = '#'` -> `s1.pop_back()` -> `s1 = "a"`
  - `i = 3`, `s[3] = 'c'` -> `s1 = "ac"`

- **Processing `t`:**
  - `i = 0`, `t[0] = 'a'` -> `s2 = "a"`
  - `i = 1`, `t[1] = 'd'` -> `s2 = "ad"`
  - `i = 2`, `t[2] = '#'` -> `s2.pop_back()` -> `s2 = "a"`
  - `i = 3`, `t[3] = 'c'` -> `s2 = "ac"`

- **Comparison:** `s1 == s2` (`"ac" == "ac"`) -> Returns `true`.

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the lengths of strings `s` and `t` respectively. Each character is visited once, and stack operations (`push_back`, `pop_back`) operate in amortized $$O(1)$$ time.
- Space complexity: $$O(N + M)$$ auxiliary space required to store the processed resulting strings `s1` and `s2`.

# Code
```cpp
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        string s1;
        for(int i = 0;i<n;i++){
            if(s[i] == '#' && s1.empty()) continue;
            if(s[i] == '#' && !s1.empty()){
                s1.pop_back();
            }
            else{
                s1 += s[i];
            }
        }
    
        n = t.size();
        string s2;
        for(int i = 0;i<n;i++){
            if(t[i] == '#' && s2.empty()) continue;
            if(t[i] == '#' && !s2.empty()){
                s2.pop_back();
            }
            else{
                s2 += t[i];
            }
        }

        return (s1 == s2);
    }
};
```
