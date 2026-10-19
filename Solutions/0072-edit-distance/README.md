# [72. Edit Distance](https://leetcode.com/problems/edit-distance/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`

---

## Problem Description
Given two strings `word1` and `word2`, return *the minimum number of operations required to convert `word1` to `word2`*.

You have the following three operations permitted on a word:

* Insert a character
* Delete a character
* Replace a character

**Example 1:**

```
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

**Example 2:**

```
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

**Constraints:**

* `0 <= word1.length, word2.length <= 500`
* `word1` and `word2` consist of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks for the minimum operations (insert, delete, replace) to convert `word1` into `word2`. This can be naturally framed as a substructure optimization problem where we compare strings from their right ends to the left. If characters match, no operation is needed; otherwise, we take the minimum of the three possible operations plus one.

# Code
```cpp
class Solution {
public:
    int f(int i,int j,string& w1,string& w2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(w1[i] == w2[j]) return dp[i][j] = f(i-1,j-1,w1,w2,dp);
        return dp[i][j] = 1 + min(f(i-1,j,w1,w2,dp),min(f(i,j-1,w1,w2,dp),f(i-1,j-1,w1,w2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,word1,word2,dp);
        
    }
};
```
