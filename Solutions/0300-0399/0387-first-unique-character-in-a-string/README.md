# [387. First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `queue`, `counting`

---

## Problem Description
Given a string `s`, find the **first** non-repeating character in it and return its index. If it **does not** exist, return `-1`.

**Example 1:**

**Input:** s = "leetcode"

**Output:** 0

**Explanation:**

The character `'l'` at index 0 is the first character that does not occur at any other index.

**Example 2:**

**Input:** s = "loveleetcode"

**Output:** 2

**Example 3:**

**Input:** s = "aabb"

**Output:** -1

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of only lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem requires finding the very first character in a string that appears only once. Since the input contains only lowercase English letters, we can leverage a fixed-size frequency array of 26 elements to track the occurrence count of each character in linear time.

# Approach
1. Initialize a frequency vector `hash` of size 26 with all zeros to store character counts.
2. Iterate through each character `c` in string `s` using a range-based for loop and increment its corresponding frequency at `hash[c - 'a']`.
3. Perform a second linear scan over the string using an index `i` from 0 to `s.size() - 1`.
4. Check the frequency of `s[i]` via `hash[s[i] - 'a']`. The first character encountered with a frequency equal to 1 is returned immediately as its index `i`.
5. If the loop completes without finding any character with a frequency of 1, return `-1`.

### Visual Walkthrough (Example 1: `s = "leetcode"`)
- Frequency count pass:
  - `'l'`: 1, `'e'`: 3, `'t'`: 1, `'c'`: 1, `'o'`: 1, `'d'`: 1
- Index scan pass (`i` from 0 to 7):
  - `i = 0`, `s[0] = 'l'`: `hash['l' - 'a'] == 1` $ightarrow$ Return `0` immediately.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of string `s`. We perform exactly two linear passes over the string: one to populate the frequency array and one to find the first unique character.
- Space complexity: $$O(1)$$ auxiliary space since the frequency array size is bounded by 26, which is constant regardless of the input string length.

# Code
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26,0);
        for(char c:s){
            hash[c-'a']++;
        }
        for(int i =0;i<s.size();i++){
            if(hash[s[i]-'a']== 1){
                return i;
            }
        }
        return -1;
    }
};
```
