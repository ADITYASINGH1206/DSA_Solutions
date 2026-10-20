# [2124. Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
Given a string `s` consisting of **only** the characters `'a'` and `'b'`, return `true` *if **every*** `'a'` *appears before **every*** `'b'` *in the string*. Otherwise, return `false`.

**Example 1:**

```
Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
```

**Example 2:**

```
Input: s = "abab"
Output: false
Explanation:
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.
```

**Example 3:**

```
Input: s = "bbb"
Output: true
Explanation:
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.
```

**Constraints:**

* `1 <= s.length <= 100`
* `s[i]` is either `'a'` or `'b'`.

---

## Solution & Editorial
# Intuition
The condition "every 'a' appears before every 'b'" is equivalent to saying that there is no occurrence of 'a' that immediately follows a 'b'. If we find any instance where 'a' appears at index `i` and 'b' appears at index `i-1`, the condition is violated.

# Approach
1. Iterate through the string starting from the second character (index 1).
2. For each index `i`, check if the current character `s[i]` is 'a' and the previous character `s[i-1]` is 'b'.
3. If this condition is met, return `false` immediately as the sequence is invalid.
4. If the loop completes without finding such a pair, return `true`.

### Visual Trace (Example: "abab")
| Index (i) | s[i-1] | s[i] | Condition (s[i]=='a' && s[i-1]=='b') | Result |
|-----------|--------|------|--------------------------------------|--------|
| 1         | 'a'    | 'b'  | False                                | Cont.  |
| 2         | 'b'    | 'a'  | True                                 | Return false |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single linear scan.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space.

# Code
```cpp
class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for(int i = 1;i<n;i++){
            if(s[i]=='a'&& s[i-1] == 'b') return false;
        }
        return true;
    }
};
```
