# [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`, `longest-common-subsequence`

---

## Problem Description
Given two strings `text1` and `text2`, return *the length of their longest **common subsequence**.* If there is no **common subsequence**, return `0`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

* For example, `"ace"` is a subsequence of `"abcde"`.

A **common subsequence** of two strings is a subsequence that is common to both strings.

**Example 1:**

```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
```

**Example 2:**

```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

**Example 3:**

```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

**Constraints:**

* `1 <= text1.length, text2.length <= 1000`
* `text1` and `text2` consist of only lowercase English characters.

---

## Solution & Editorial
# Intuition
To find the longest common subsequence between two strings, we can break the problem down into overlapping subproblems. If the current characters of both strings match, we extend a common subsequence of length one plus the result from the previous prefixes. If they do not match, we take the maximum subsequence length by either dropping a character from the first string or dropping a character from the second string.

# Approach
1. Initialize two integer variables `n1` and `n2` representing the lengths of `text1` and `text2` respectively.
2. Construct a 2D `vector<vector<int>>` table named `dp` of dimensions `(n1 + 1) × (n2 + 1)` initialized to `0`. The base cases where either string has a length of `0` are naturally handled by the initial zeros.
3. Iterate `i` from `1` to `n1` and `j` from `1` to `n2` to fill the table.
4. Within the loops, compare `text1[i - 1]` and `text2[j - 1]`. If they are equal, set `dp[i][j] = 1 + dp[i - 1][j - 1]`. Otherwise, set `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`.
5. Return the final result stored at `dp[n1][n2]`.

### Visual Trace Walkthrough
For `text1 = "abcde"`, `text2 = "ace"`:

| | "" | a | c | e |
|---|---|---|---|---|
| **""** | 0 | 0 | 0 | 0 |
| **a** | 0 | 1 | 1 | 1 |
| **b** | 0 | 1 | 1 | 1 |
| **c** | 0 | 1 | 2 | 2 |
| **d** | 0 | 1 | 2 | 2 |
| **e** | 0 | 1 | 2 | 3 |

# Complexity
- Time complexity: $$O(n_1 \times n_2)$$ where $$n_1$$ and $$n_2$$ are the lengths of `text1` and `text2`. We iterate through a grid of size $$(n_1 + 1) \times (n_2 + 1)$$ doing constant time operations.
- Space complexity: $$O(n_1 \times n_2)$$ required for storing the 2D DP table.

# Code
```cpp
//Tabulation
class Solution{
public:
    int longestCommonSubsequence(string text1, string text2){
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i =0;i<=n1;i++)dp[i][0] =0;
        for(int i =0;i<=n2;i++)dp[0][i] =0;
        for(int i = 1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};

//MEMO
// class Solution {
// public:
//     int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
//         if(i == 0 || j ==0)return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];

//         if(s1[i-1]==s2[j-1]) return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);

//         return dp[i][j] = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1= text1.size();
//         int n2 = text2.size();

//         vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
//         return f(n1,n2,text1,text2,dp);
//     }
// };
```
