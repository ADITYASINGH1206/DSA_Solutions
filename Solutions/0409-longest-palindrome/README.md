# [409. Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `greedy`

---

## Problem Description
Given a string `s` which consists of lowercase or uppercase letters, return the length of the **longest palindrome** that can be built with those letters.

Letters are **case sensitive**, for example, `"Aa"` is not considered a palindrome.

**Example 1:**

```
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
```

**Example 2:**

```
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
```

**Constraints:**

* `1 <= s.length <= 2000`
* `s` consists of lowercase **and/or** uppercase English letters only.

---

## Solution & Editorial
# Intuition
A palindrome can be formed by pairing up characters of the same type symmetrically around a center. By keeping track of character frequencies using a hash map and dynamically maintaining the count of characters with odd frequencies, we can determine the maximum possible length of a palindrome without constructing it explicitly.

# Approach
1. Initialize an unordered map `ump` to store character frequencies and an integer `oddCount` to track how many characters currently have an odd frequency count.
2. Iterate through each character `ch` in string `s`, increment its frequency in `ump`, and update `oddCount`: if the new frequency is odd, increment `oddCount`; otherwise, decrement `oddCount`.
3. After processing all characters, if `oddCount` is greater than 1, it means we have more than one character type with an odd frequency that cannot all be placed in the center. We subtract `oddCount - 1` from the total length of the string `s.length()` to account for the excess odd characters that must be left unpaired.
4. If `oddCount <= 1`, all characters can be utilized either in pairs or with at most one odd character in the exact center, so the entire length `s.length()` is returned.

### Visual Trace Walkthrough for Example 1: `s = "abccccdd"`

| Character | Action | `ump` State | `oddCount` |
| :--- | :--- | :--- | :--- |
| `'a'` | `ump['a'] = 1` (odd) | `{'a': 1}` | `1` |
| `'b'` | `ump['b'] = 1` (odd) | `{'a': 1, 'b': 1}` | `2` |
| `'c'` | `ump['c'] = 1` (odd) | `{'a': 1, 'b': 1, 'c': 1}` | `3` |
| `'c'` | `ump['c'] = 2` (even) | `{'a': 1, 'b': 1, 'c': 2}` | `2` |
| `'c'` | `ump['c'] = 3` (odd) | `{'a': 1, 'b': 1, 'c': 3}` | `3` |
| `'c'` | `ump['c'] = 4` (even) | `{'a': 1, 'b': 1, 'c': 4}` | `2` |
| `'d'` | `ump['d'] = 1` (odd) | `{'a': 1, 'b': 1, 'c': 4, 'd': 1}` | `3` |
| `'d'` | `ump['d'] = 2` (even) | `{'a': 1, 'b': 1, 'c': 4, 'd': 2}` | `2` |

Final check: `oddCount` is `2` (> 1), so return `8 - 2 + 1 = 7`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the string `s`. We traverse the string once, and hash map insertions/lookups take $$O(1)$$ average time.
- Space complexity: $$O(K)$$ where $$K$$ is the number of unique characters in `s` (at most 52 for English letters), which uses constant auxiliary space $$O(1)$$.

# Code
```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char, int> ump;
        for(char ch : s) {
            ump[ch]++;
            if (ump[ch] % 2 == 1)
                oddCount++;
            else    
                oddCount--;
        }
        if (oddCount > 1)
            return s.length() - oddCount + 1;
        return s.length();
    }
};
```
