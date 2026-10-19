# [205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`

---

## Problem Description
Given two strings `s` and `t`, *determine if they are isomorphic*.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Example 1:**

**Input:** s = "egg", t = "add"

**Output:** true

**Explanation:**

The strings `s` and `t` can be made identical by:

* Mapping `'e'` to `'a'`.
* Mapping `'g'` to `'d'`.

**Example 2:**

**Input:** s = "f11", t = "b23"

**Output:** false

**Explanation:**

The strings `s` and `t` can not be made identical as `'1'` needs to be mapped to both `'2'` and `'3'`.

**Example 3:**

**Input:** s = "paper", t = "title"

**Output:** true

**Constraints:**

* `1 <= s.length <= 5 * 104`
* `t.length == s.length`
* `s` and `t` consist of any valid ascii character.

---

## Solution & Editorial
# Intuition
To determine if two strings are isomorphic, we must enforce a bijection (one-to-one correspondence) between the characters of string `s` and string `t`. This means not only must each character in `s` map to a unique character in `t`, but no two distinct characters in `s` can map to the same character in `t`. We can efficiently maintain this mapping constraint using two frequency or last-seen index tracking arrays.

# Approach
1. Initialize two fixed-size integer arrays `m1` and `m2` of size 256 (covering all standard ASCII characters) to zero. These arrays store the 1-based index of the last occurrence of each character in `s` and `t` respectively.
2. Iterate through both strings simultaneously using a loop from index `0` to `n - 1`.
3. At each index `i`, check if `m1[s[i]]` is equal to `m2[t[i]]`. If they are not equal, it implies that the historical mapping pattern or last seen position of these two characters diverge, violating the isomorphism condition, so return `false`.
4. Update both `m1[s[i]]` and `m2[t[i]]` to `i + 1` (storing the current 1-based position).
5. If the loop completes without finding any mismatch, return `true`.

### Visual Dry Run (Example 1: s = "egg", t = "add")

| i | s[i] | t[i] | m1['e'], m2['a'] before | m1 vs m2 check | Action / Update m1, m2 | State after |
|---|---|---|---|---|---|---|
| 0 | 'e' | 'a' | m1['e']=0, m2['a']=0 | 0 == 0 (Valid) | m1['e']=1, m2['a']=1 | m1['e']=1, m2['a']=1 |
| 1 | 'g' | 'd' | m1['g']=0, m2['d']=0 | 0 == 0 (Valid) | m1['g']=2, m2['d']=2 | m1['g']=2, m2['d']=2 |
| 2 | 'g' | 'd' | m1['g']=2, m2['d']=2 | 2 == 2 (Valid) | m1['g']=3, m2['d']=3 | m1['g']=3, m2['d']=3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of strings `s` and `t`. We perform a single linear scan through the strings of length $$N$$, doing constant time $$O(1)$$ array lookups and updates.
- Space complexity: $$O(1)$$. The auxiliary space consumed consists of two constant-sized integer arrays of size 256, which require fixed memory irrespective of input string size $$N$.

# Code
```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0};
        int m2[256] = {0};
        
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(m1[s[i]] != m2[t[i]]) {
                return false;
            }
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        
        return true;
    }
};
```
