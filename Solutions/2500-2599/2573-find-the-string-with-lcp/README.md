# [2573. Find the String with LCP](https://leetcode.com/problems/find-the-string-with-lcp/)
**Difficulty:** `Hard` | **Tags:** `array`, `string`, `dynamic-programming`, `greedy`, `union-find`, `matrix`

---

## Problem Description
We define the `lcp` matrix of any **0-indexed** string `word` of `n` lowercase English letters as an `n x n` grid such that:

* `lcp[i][j]` is equal to the length of the **longest common prefix** between the substrings `word[i,n-1]` and `word[j,n-1]`.

Given an `n x n` matrix `lcp`, return the alphabetically smallest string `word` that corresponds to `lcp`. If there is no such string, return an empty string.

A string `a` is lexicographically smaller than a string `b` (of the same length) if in the first position where `a` and `b` differ, string `a` has a letter that appears earlier in the alphabet than the corresponding letter in `b`. For example, `"aabd"` is lexicographically smaller than `"aaca"` because the first position they differ is at the third letter, and `'b'` comes before `'c'`.

**Example 1:**

```
Input: lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
Output: "abab"
Explanation: lcp corresponds to any 4 letter string with two alternating letters. The lexicographically smallest of them is "abab".
```

**Example 2:**

```
Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
Output: "aaaa"
Explanation: lcp corresponds to any 4 letter string with a single distinct letter. The lexicographically smallest of them is "aaaa".
```

**Example 3:**

```
Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
Output: ""
Explanation: lcp[3][3] cannot be equal to 3 since word[3,...,3] consists of only a single letter; Thus, no answer exists.
```

**Constraints:**

* `1 <= n ==``lcp.length ==` `lcp[i].length` `<= 1000`
* `0 <= lcp[i][j] <= n`

---

## Solution & Editorial
# Intuition
The LCP matrix defines the longest common prefix between all pairs of suffixes. If we know the characters of the string, the LCP values are constrained by the recurrence: `lcp[i][j] = (s[i] == s[j]) ? (1 + lcp[i+1][j+1]) : 0`. We can greedily assign the smallest possible character to each position by iterating through the alphabet and identifying which indices share the same character based on the LCP matrix, then validate the entire matrix against the constructed string.

# Approach
1. **Greedy Construction**: Initialize an empty string `s` of size `n`. Iterate through characters 'a' to 'z'. For each character, find the first index `i` that hasn't been assigned. Assign this character to all indices `j` where `lcp[i][j] > 0`.
2. **Validation**: After constructing `s`, verify if it satisfies the LCP matrix properties:
   - If `s[i] == s[j]`, then `lcp[i][j]` must be `1 + lcp[i+1][j+1]` (with boundary conditions).
   - If `s[i] != s[j]`, then `lcp[i][j]` must be `0`.
   - Ensure `lcp[i][i] == n - i` for all `i`.
3. **Corner Cases**: If any index remains unassigned after checking all 26 characters, or if the validation fails, return an empty string.

### Visual Trace (Example 1: n=4)
`lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]`
- Start: `s = [?, ?, ?, ?]`
- 'a': `i=0` is empty. `lcp[0][0]=4, lcp[0][2]=2`. Set `s[0]='a', s[2]='a'. s = [a, ?, a, ?]`
- 'b': `i=1` is empty. `lcp[1][1]=3, lcp[1][3]=1`. Set `s[1]='b', s[3]='b'. s = [a, b, a, b]`
- Validation: Check `s[i] == s[j]` against `lcp` values. All match.

# Complexity
- Time complexity: $$O(N^2)$$ where $$N$$ is the length of the string. We iterate through the matrix once to construct the string ($$O(N^2)$$) and once to validate it ($$O(N^2)$$).
- Space complexity: $$O(N)$$ to store the constructed string `s`.

# Code
```cpp
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int i = 0, n = lcp.size();
        string s(n, '\0');
        for (char c = 'a'; c <= 'z'; ++c) {
            while (i < n && s[i]) {
                ++i;
            }
            if (i == n) {
                break;
            }
            for (int j = i; j < n; ++j) {
                if (lcp[i][j]) {
                    s[j] = c;
                }
            }
        }
        if (s.find('\0') != -1) {
            return "";
        }
        for (i = n - 1; ~i; --i) {
            for (int j = n - 1; ~j; --j) {
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                        return "";
                    }
                } else if (lcp[i][j]) {
                    return "";
                }
            }
        }
        return s;
    }
};
```
