# [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `sorting`

---

## Problem Description
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

**Example 1:**

**Input:** s = "anagram", t = "nagaram"

**Output:** true

**Example 2:**

**Input:** s = "rat", t = "car"

**Output:** false

**Constraints:**

* `1 <= s.length, t.length <= 5 * 104`
* `s` and `t` consist of lowercase English letters.

**Follow up:** What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

---

## Solution & Editorial
# Intuition
An anagram contains the exact same characters with the same frequencies, just potentially in a different order. If two strings have different lengths, they cannot be anagrams. Otherwise, we can count the frequency of each character in the first string and decrement the frequencies using the second string. If all counts end up at zero, the strings are anagrams.

# Approach
1. Check if the sizes of strings `s` and `t` stored in `n` and `r` respectively are equal. If `n != r`, immediately return `false`.
2. Initialize a frequency vector `ch` of size 26 with all zeros to track lowercase English letter counts.
3. Iterate through `s` from index `0` to `n - 1`, incrementing the count in `ch` corresponding to each character `s[i] - 'a'`.
4. Iterate through `t` from index `0` to `r - 1`, decrementing the count in `ch` corresponding to each character `t[i] - 'a'`.
5. Iterate through the `ch` array from `0` to `25`. If any count is non-zero, return `false`. Otherwise, return `true`.

### Visual Walkthrough (Example 1: s = "anagram", t = "nagaram")
- **Step 1**: Sizes match (`n = 7`, `r = 7`). Frequency vector initialized to all 0s.
- **Step 2**: Process string `s` ("anagram") -> `ch` accumulates counts: `a: 3, g: 1, m: 1, n: 1, r: 1`.
- **Step 3**: Process string `t` ("nagaram") -> `ch` decrements counts: all elements return to `0`.
- **Step 4**: Verify all elements in `ch` are `0`. Returns `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of string `s`. We perform a constant number of linear scans over the strings and a fixed-size scan of 26 elements.
- Space complexity: $$O(1)$$ auxiliary space, as the frequency vector `ch` is of fixed size 26 regardless of input string length.

# Code
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ch(26,0);
        int n = s.size();
        int r = t.size();
        if(n != r) return false;
        for(int i =0;i<n;i++){
            ch[s[i]-'a']++;
        }        
        for(int i =0;i<r;i++){
            ch[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(ch[i] != 0){
                return false;
            }
        }
        return true;
    
    }
};
```
