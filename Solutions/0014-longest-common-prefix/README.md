# [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`, `trie`

---

## Problem Description
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

**Example 1:**

```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

**Example 2:**

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

**Constraints:**

* `1 <= strs.length <= 200`
* `0 <= strs[i].length <= 200`
* `strs[i]` consists of only lowercase English letters if it is non-empty.

---

## Solution & Editorial
# Intuition
The longest common prefix of an array of strings must be a prefix of the first string. By scanning each character position of the first string vertically across all other strings, we can immediately identify where the common prefix ends.

# Approach
1. Get the number of strings `n` from `strs.size()`.
2. Iterate through each character index `i` from `0` to `strs[0].size() - 1`.
3. For each character index `i`, iterate through all other strings starting from index `j = 1` up to `n - 1`.
4. Check if the current string `strs[j]` is shorter than or equal to `i` (i.e., `strs[j].size() <= i`) or if the character at the current position does not match `strs[0][i]` (i.e., `strs[j][i] != strs[0][i]`). If either condition is true, return the substring of `strs[0]` from index `0` to `i`.
5. If the outer loop completes without any mismatch, return the entire `strs[0]` as it is the longest common prefix.

### Visual Walkthrough (Example 1: `strs = ["flower", "flow", "flight"]`)
- `i = 0`: Character `'f'`
  - `j = 1 ("flow")`: `strs[1][0] == 'f'` (Match)
  - `j = 2 ("flight")`: `strs[2][0] == 'f'` (Match)
- `i = 1`: Character `'l'`
  - `j = 1 ("flow")`: `strs[1][1] == 'l'` (Match)
  - `j = 2 ("flight")`: `strs[2][1] == 'l'` (Match)
- `i = 2`: Character `'o'`
  - `j = 1 ("flow")`: `strs[1][2] == 'o'` (Match)
  - `j = 2 ("flight")`: `strs[2][2] == 'i'` (Mismatch! `strs[2][2] != strs[0][2]`)
- Returns `strs[0].substr(0, 2)` -> `"fl"`.

# Complexity
- Time complexity: $$O(S)$$ where $$S$$ is the sum of all characters across all strings in the array. In the worst-case scenario, all strings are identical, and we compare every character, taking $$O(N \times M)$$ where $$N$$ is the number of strings and $$M$$ is the length of the first string.
- Space complexity: $$O(1)$$ auxiliary space, as we only use a few scalar variables for indexing and return a substring whose memory is accounted for by the output.

# Code
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
```
