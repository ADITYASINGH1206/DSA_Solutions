# [1092. Shortest Common Supersequence ](https://leetcode.com/problems/shortest-common-supersequence/)
**Difficulty:** `Hard` | **Tags:** `string`, `dynamic-programming`, `longest-common-subsequence`

---

## Problem Description
Given two strings `str1` and `str2`, return *the shortest string that has both* `str1` *and* `str2` *as **subsequences***. If there are multiple valid strings, return **any** of them.

A string `s` is a **subsequence** of string `t` if deleting some number of characters from `t` (possibly `0`) results in the string `s`.

**Example 1:**

```
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
```

**Example 2:**

```
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
```

**Constraints:**

* `1 <= str1.length, str2.length <= 1000`
* `str1` and `str2` consist of lowercase English letters.

---

## Solution & Editorial
# Intuition
The Shortest Common Supersequence (SCS) problem is intimately tied to the Longest Common Subsequence (LCS). To form the shortest string that contains both `str1` and `str2` as subsequences, we must align their characters. The common characters in their LCS should appear only once, while all non-matching characters from both strings must be preserved and interleaved properly.

# Approach
1. Construct an LCS DP table where `dp[i][j]` stores the length of the longest common subsequence of `str1[0...i-1]` and `str2[0...j-1]`.
2. Iterate through `i` from `1` to `n1` and `j` from `1` to `n2`. If `str1[i-1] == str2[j-1]`, set `dp[i][j] = 1 + dp[i-1][j-1]`. Otherwise, set `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
3. Trace back from `i = n1` and `j = n2` to reconstruct the supersequence string in reverse:
   - If `str1[i-1] == str2[j-1]`, append the character to `ans` and decrement both `i` and `j`.
   - If `dp[i-1][j] > dp[i][j-1]`, append `str1[i-1]` and decrement `i`.
   - Otherwise, append `str2[j-1]` and decrement `j`.
4. Once either `i` or `j` reaches `0`, append any remaining characters from the non-exhausted string.
5. Reverse the accumulated `ans` string to yield the correct shortest common supersequence.

### Visual Trace Walkthrough (Example 1: str1 = "abac", str2 = "cab")
- `n1 = 4`, `n2 = 3`
- LCS DP matrix final row/col computes lengths.
- Backtracking from `i=4, j=3`:
  - `str1[3] ('c') != str2[2] ('b')`, and `dp[3][3] >= dp[4][2]`, append `str2[2] ('b')`, `j=2`
  - Match or path leads through remaining characters, collecting non-overlapping and overlapping elements in reverse and reversing at the end.
  - Resulting supersequence: `"cabac"`.

# Complexity
- Time complexity: $$O(n_1 \cdot n_2)$$ — Filling the 2D DP table of size $$(n_1+1) \times (n_2+1)$$ takes $O(n_1 \cdot n_2)$ operations, and the backtracking step takes at most $O(n_1 + n_2)$ time.
- Space complexity: $$O(n_1 \cdot n_2)$$ — Auxiliary space required for the 2D DP vector table.

# Code
```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        // for(int i =0;i<=n1;i++) dp[i][0] = 0;
        // for(int i =0;i<=n2;i++) dp[0][i] = 0;
        for(int i = 1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        string ans = "";
        int i = n1 , j= n2;
        while(i > 0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--,j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }

        while(i>0){
            ans += str1[i-1];
            i--;
        }
        while(j>0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
```
