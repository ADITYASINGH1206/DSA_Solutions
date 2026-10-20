# [1941. Check if All Characters Have Equal Number of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `counting`

---

## Problem Description
Given a string `s`, return `true` *if* `s` *is a **good** string, or* `false` *otherwise*.

A string `s` is **good** if **all** the characters that appear in `s` have the **same** number of occurrences (i.e., the same frequency).

**Example 1:**

```
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
```

**Example 2:**

```
Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To determine if a string is "good," we must ensure every character present in the string appears with the exact same frequency. Since the input consists only of lowercase English letters, we can efficiently map each character to its frequency using a fixed-size array.

# Approach
1. Initialize a frequency array `freq` of size 26 to store the count of each character ('a' through 'z').
2. Iterate through the input string `s` and increment the corresponding index in `freq` for each character encountered.
3. Iterate through the string again, comparing the frequency of the current character `s[i]` with the frequency of the previous character `s[i-1]`.
4. If any two adjacent characters in the string have different frequencies, return `false`. Otherwise, return `true` after the loop completes.

### Visual Trace (Example 1: "abacbc")
- `freq` array after counting: `freq['a']=2, freq['b']=2, freq['c']=2`
- Loop iterations:
  - `i=1`: `s[1]='b'`, `s[0]='a'`. `freq['b'] == freq['a']` (2 == 2). Continue.
  - `i=2`: `s[2]='a'`, `s[1]='b'`. `freq['a'] == freq['b']` (2 == 2). Continue.
  - `i=3`: `s[3]='c'`, `s[2]='a'`. `freq['c'] == freq['a']` (2 == 2). Continue.
  - `i=4`: `s[4]='b'`, `s[3]='c'`. `freq['b'] == freq['c']` (2 == 2). Continue.
  - `i=5`: `s[5]='c'`, `s[4]='b'`. `freq['c'] == freq['b']` (2 == 2). Continue.
- Result: `true`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform one pass to count frequencies and one pass to verify them.
- Space complexity: $$O(1)$$, as the frequency array size is constant (26), regardless of the input string length.

# Code
```cpp
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(int i = 1 ;i<s.size();i++){
            if(freq[s[i]-'a']!=freq[s[i-1]-'a']){
                return false;
            }
        }
        return true;
    }
};
```
