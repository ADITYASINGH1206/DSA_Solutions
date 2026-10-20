# [583. Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`, `longest-common-subsequence`

---

## Problem Description
Given two strings `word1` and `word2`, return *the minimum number of **steps** required to make* `word1` *and* `word2` *the same*.

In one **step**, you can delete exactly one character in either string.

**Example 1:**

```
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
```

**Example 2:**

```
Input: word1 = "leetcode", word2 = "etco"
Output: 4
```

**Constraints:**

* `1 <= word1.length, word2.length <= 500`
* `word1` and `word2` consist of only lowercase English letters.

---

## Solution & Editorial
# Intuition
The minimum number of deletions required to make two strings identical is directly related to their Longest Common Subsequence (LCS). If we find the length of the LCS, the characters not part of the LCS in both strings must be deleted. Thus, the answer is the total length of both strings minus twice the length of their LCS.

# Approach
1. Define a helper function `f(i, j, s1, s2, dp)` using memoized recursion (top-down dynamic programming) to compute the LCS length of prefixes `s1[0...i-1]` and `s2[0...j-1]`.
2. Base cases: If either index `i == 0` or `j == 0`, the LCS length is `0` because one of the string prefixes is empty.
3. State transition: If characters match (`s1[i-1] == s2[j-1]`), add `1` and recurse to `f(i-1, j-1)`. Otherwise, take the maximum of excluding one character from either string: `max(f(i-1, j), f(i, j-1))`.
4. Memoize results in a 2D table `dp` initialized with `-1` to avoid overlapping subproblems.
5. Compute the final answer as `n1 + n2 - 2 * lcs`.

### Visual Trace Walkthrough (Example 1: word1 = "sea", word2 = "eat")
- `n1 = 3`, `n2 = 3`
- `f(3, 3)` compares `word1[2] ('a')` and `word2[2] ('t')` -> no match -> `max(f(2, 3), f(3, 2))`
- Eventually finds LCS length = `2` ("ea").
- Result calculation: `3 + 3 - (2 * 2) = 2`.

# Complexity
- Time complexity: $$O(n_1 \times n_2)$$ where $$n_1$$ and $$n_2$$ are the lengths of `word1` and `word2`. There are $$n_1 \times n_2$$ unique subproblems, each solved in $$O(1)$$ time due to memoization.
- Space complexity: $$O(n_1 \times n_2)$$ for the 2D `dp` table and up to $$O(n_1 + n_2)$$ call stack depth during recursion.

# Code
```cpp
class Solution {
public:
    int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i == 0 || j ==0)return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1]==s2[j-1]) return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);

        return dp[i][j] = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        int lcs = f(n1,n2,word1,word2,dp);
        int ans = n1 + n2 - (2*lcs);
        return ans;
    }
};
```
