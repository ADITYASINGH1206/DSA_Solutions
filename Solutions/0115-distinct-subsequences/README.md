# [115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)
**Difficulty:** `Hard` | **Tags:** `string`, `dynamic-programming`

---

## Problem Description
Given two strings s and t, return *the number of distinct* ***subsequences*** *of* s *which equals* t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

**Example 1:**

```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
```

**Example 2:**

```
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
```

**Constraints:**

* `1 <= s.length, t.length <= 1000`
* `s` and `t` consist of English letters.

---

## Solution & Editorial
# Intuition
To count the number of distinct subsequences of `s` that equal `t`, we can leverage recursion with memoization (Top-Down Dynamic Programming). For every character in `s` and `t`, we decide whether to include the current character of `s` to match `t[j]` or skip it.

# Approach
1. Define a recursive function `f(i, j, s, t, dp)` that returns the number of distinct subsequences of `s[0...i]` that match `t[0...j]`.
2. Base Cases:
   - If `j < 0`, we have successfully matched all characters of `t`, so return `1` (found a valid subsequence).
   - If `i < 0`, we exhausted `s` without fully matching `t`, so return `0`.
3. Memoization:
   - Check if `dp[i][j]` is already computed. If so, return the cached result.
4. Transitions:
   - If `s[i] == t[j]`, we have two choices: either use `s[i]` to match `t[j]` (`f(i-1, j-1, ...)`), or skip `s[i]` (`f(i-1, j, ...)`). Sum both possibilities.
   - If `s[i] != t[j]`, we must skip `s[i]`, hence return `f(i-1, j, ...)`.

### Visual Trace (Example 1: s = "rabbbit", t = "rabbit")
- `n = 7, m = 6`
- `f(6, 5)` evaluates `s[6] == t[5]` ('t' == 't') -> `f(5, 4) + f(5, 5)`
- Branching explores matching characters backwards, accumulating valid paths until `j` drops below 0.

# Complexity
- Time complexity: $$O(N \times M)$$ where $$N$$ is the length of `s` and $$M$$ is the length of `t`. There are $$N \times M$$ distinct subproblems, each solved in $$O(1)$$ time thanks to memoization.
- Space complexity: $$O(N \times M)$$ for the 2D memoization table `dp`, plus $$O(N + M)$$ for the maximum recursion stack depth.

# Code
```cpp
class Solution {
public:
    int f(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);

        return dp[i][j] = f(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};
```
