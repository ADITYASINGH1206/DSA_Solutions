# [940. Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/)
**Difficulty:** `Hard` | **Tags:** `string`, `dynamic-programming`

---

## Problem Description
Given a string s, return *the number of **distinct non-empty subsequences** of* `s`. Since the answer may be very large, return it **modulo** `109 + 7`.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not.

**Example 1:**

```
Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
```

**Example 2:**

```
Input: s = "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".
```

**Example 3:**

```
Input: s = "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
```

**Constraints:**

* `1 <= s.length <= 2000`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To find the number of distinct non-empty subsequences, we can use dynamic programming where `dp[i]` represents the number of distinct subsequences ending strictly at index `i`. By ensuring that we only append the current character to previous distinct subsequences ending at indices with different characters, we avoid duplicate counting.

# Approach
1. Initialize a `dp` vector of size `n` with all elements set to `1` (each individual character `s[i]` forms a valid distinct subsequence of length 1). Also define `MOD = 1e9 + 7`.
2. Iterate through each index `i` from `0` to `n - 1`. For each `i`, iterate through all prior indices `j` from `0` to `i - 1`.
3. If `s[i] != s[j]`, add `dp[j]` to `dp[i]` modulo `MOD`. This accounts for appending `s[i]` to all valid distinct subsequences ending at index `j` without duplication.
4. Accumulate `dp[i]` into the running total `result` modulo `MOD`.
5. Return `result` as the final count.

### Visual Dry Run (Example 1: s = "abc")
- **i = 0 ('a')**: `dp[0] = 1`. `result = 1`.
- **i = 1 ('b')**: 
  - `j = 0 ('a')`: `s[1] != s[0]`, so `dp[1] = (1 + dp[0]) % MOD = 2`.
  - `result = (1 + 2) % MOD = 3`.
- **i = 2 ('c')**:
  - `j = 0 ('a')`: `s[2] != s[0]`, so `dp[2] = (1 + dp[0]) = 2`.
  - `j = 1 ('b')`: `s[2] != s[1]`, so `dp[2] = (2 + dp[1]) = 4`.
  - `result = (3 + 4) % MOD = 7`.

# Complexity
- Time complexity: $$O(N^2)$$ — We have a nested loop where the outer loop runs `N` times and the inner loop runs up to `N` times.
- Space complexity: $$O(N)$$ — We use a single `dp` array of size `N` to store subsequence counts for each index.

# Code
```cpp
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;

        vector<int> dp(n, 1);
        int result = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(s[i] != s[j]) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
            result = (result + dp[i]) % MOD;
        }
        return result;
    }
};
```
