# [3714. Longest Balanced Substring II](https://leetcode.com/problems/longest-balanced-substring-ii/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `prefix-sum`

---

## Problem Description
You are given a string `s` consisting only of the characters `'a'`, `'b'`, and `'c'`.

A **substring** of `s` is called **balanced** if all **distinct** characters in the **substring** appear the **same** number of times.

Return the **length of the longest balanced substring** of `s`.

**Example 1:**

**Input:** s = "abbac"

**Output:** 4

**Explanation:**

The longest balanced substring is `"abba"` because both distinct characters `'a'` and `'b'` each appear exactly 2 times.

**Example 2:**

**Input:** s = "aabcc"

**Output:** 3

**Explanation:**

The longest balanced substring is `"abc"` because all distinct characters `'a'`, `'b'` and `'c'` each appear exactly 1 time.

**Example 3:**

**Input:** s = "aba"

**Output:** 2

**Explanation:**

One of the longest balanced substrings is `"ab"` because both distinct characters `'a'` and `'b'` each appear exactly 1 time. Another longest balanced substring is `"ba"`.

**Constraints:**

* `1 <= s.length <= 105`
* `s` contains only the characters `'a'`, `'b'`, and `'c'`.

---

## Solution & Editorial
# Intuition
To determine if a substring is balanced, we need the counts of all present characters to be equal. Since the string only contains 'a', 'b', and 'c', we can break the problem into two parts: substrings containing only two distinct characters and substrings containing all three distinct characters. By using prefix sums to track the relative differences between character counts, we can identify balanced segments in linear time.

# Approach
1. **Two-Character Substrings**: For every pair of characters (e.g., 'a' and 'b'), we treat one as +1 and the other as -1. If we encounter the third character, the balance resets. We use a hash map to store the first occurrence of each balance value to find the longest subarray with a net balance of 0.
2. **Three-Character Substrings**: We maintain three running counts (`ca`, `cb`, `cc`) for 'a', 'b', and 'c'. A substring from index `j+1` to `i` is balanced if `(ca[i]-ca[j]) == (cb[i]-cb[j]) == (cc[i]-cc[j])`. This is equivalent to `ca[i]-cb[i] == ca[j]-cb[j]` and `cb[i]-cc[i] == cb[j]-cc[j]`. We store the tuple of differences `(ca-cb, cb-cc)` in a hash map to detect these segments.
3. **Visual Trace (Example 1: "abbac")**:
   - Initial `max_len` = 1 (single chars).
   - Pair ('a', 'b'):
     - i=0 ('a'): balance=1, map={0:-1, 1:0}
     - i=1 ('b'): balance=0, found in map, len=1-(-1)=2
     - i=2 ('b'): balance=-1, map={0:-1, 1:0, -1:2}
     - i=3 ('a'): balance=0, found in map, len=3-(-1)=4
     - i=4 ('c'): reset balance.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the string. We iterate through the string a constant number of times (once for each pair and once for the triplet case).
- Space complexity: $$O(N)$$ to store the hash map entries for prefix differences.

# Code
```cpp
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int max_len = 0;
        int current_run = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i-1]) {
                current_run++;
            } else {
                current_run = 1;
            }
            max_len = max(max_len, current_run);
        }
        char pairs[3][3] = {
            {'a', 'b', 'c'},
            {'a', 'c', 'b'},
            {'b', 'c', 'a'}
        };

        for (auto& p : pairs) {
            char c1 = p[0];
            char c2 = p[1];
            char forbidden = p[2];

            unordered_map<int, int> mp;
            mp[0] = -1; 
            int balance = 0;

            for (int i = 0; i < n; ++i) {
                if (s[i] == forbidden) {
                    balance = 0;
                    mp.clear();
                    mp[0] = i; 
                } else {
                    if (s[i] == c1) balance++;
                    else if (s[i] == c2) balance--;
                    
                    if (mp.count(balance)) {
                        max_len = max(max_len, i - mp[balance]);
                    } else {
                        mp[balance] = i;
                    }
                }
            }
        }

        unordered_map<string, int> diff_map;
        diff_map["0#0"] = -1; 
        
        int ca = 0, cb = 0, cc = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else if (s[i] == 'c') cc++;
            int d1 = ca - cb;
            int d2 = cb - cc;
            string key = to_string(d1) + "#" + to_string(d2);

            if (diff_map.count(key)) {
                max_len = max(max_len, i - diff_map[key]);
            } else {
                diff_map[key] = i;
            }
        }

        return max_len;
    }
};
```
