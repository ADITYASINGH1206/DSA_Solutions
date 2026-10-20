# [424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `sliding-window`

---

## Problem Description
You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return *the length of the longest substring containing the same letter you can get after performing the above operations*.

**Example 1:**

```
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
```

**Example 2:**

```
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of only uppercase English letters.
* `0 <= k <= s.length`

---

## Solution & Editorial
# Intuition
The problem asks for the longest substring containing identical characters after modifying at most $k$ characters. We can maintain a sliding window over the string such that the number of characters we need to replace does not exceed $k$. The number of replacements required in the current window of length `len` is `len - maxFreq`, where `maxFreq` is the frequency of the most frequent character in the current window.

# Approach
1. Initialize pointers `l = 0` and `r = 0` for the sliding window, `ans = 0` to track the maximum valid window length, and `maxFreq = 0` to store the highest frequency of any single character in the current window. Use an `unordered_map<char, int> mp` to store character counts.
2. Expand the window by iterating `r` from `0` to `n - 1`. Increment `mp[s[r]]` and update `maxFreq` if the new frequency exceeds `maxFreq`.
3. Compute the current window length as `len = r - l + 1`. Check if `len - maxFreq <= k`. If valid, update `ans = max(ans, len)`.
4. If the condition `len - maxFreq <= k` is violated, shrink the window from the left by decrementing `mp[s[l]]` and incrementing `l`. Note that `maxFreq` is not explicitly decreased when shrinking, which is a standard optimized sliding window property since only an increase in `maxFreq` can lead to a larger valid window.
5. Increment `r` and repeat until the end of the string is reached.

### Visual Trace Walkthrough (Example 1: s = "ABAB", k = 2)
| r | s[r] | mp | maxFreq | l | len | len - maxFreq | Valid? | ans |
|---|---|---|---|---|---|---|---|---|
| 0 | 'A' | {'A': 1} | 1 | 0 | 1 | 0 <= 2 | Yes | 1 |
| 1 | 'B' | {'A': 1, 'B': 1} | 1 | 0 | 2 | 2 - 1 = 1 <= 2 | Yes | 2 |
| 2 | 'A' | {'A': 2, 'B': 1} | 2 | 0 | 3 | 3 - 2 = 1 <= 2 | Yes | 3 |
| 3 | 'B' | {'A': 2, 'B': 2} | 2 | 0 | 4 | 4 - 2 = 2 <= 2 | Yes | 4 |

# Complexity
- Time complexity: $$O(N)$$ — Each character is visited at most twice (once by `r` expanding and at most once by `l` shrinking), where $N$ is the length of string `s`. Hash map insertions and lookups take average $$O(1)$$ time.
- Space complexity: $$O(1)$$ — The hash map `mp` stores at most 26 uppercase English letters, consuming constant auxiliary space.

# Code
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        int maxFreq = 0;
        unordered_map<char,int> mp;
        int l = 0;
        int r = 0;
        while(r<n){
            mp[s[r]]++;
            if(mp[s[r]] > maxFreq){
                maxFreq = mp[s[r]];
            }
            int len = r-l+1;
            if(len-maxFreq <= k){
                ans = max(ans,r-l+1);
            }else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
```
