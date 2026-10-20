# [516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`

---

## Problem Description
Given a string `s`, find *the longest palindromic **subsequence**'s length in* `s`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

```
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```

**Example 2:**

```
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem of finding the longest palindromic subsequence in a string `s` is equivalent to finding the Longest Common Subsequence (LCS) between `s` and its reversed version `s2`. Reversing the string ensures that any common subsequence formed between `s` and `s2` represents a valid palindrome in the original string.

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
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s1.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(n,n,s1,s2,dp);
        
    }
};
```
