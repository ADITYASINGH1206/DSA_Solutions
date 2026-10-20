# [1190. Reverse Substrings Between Each Pair of Parentheses](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `bracket-sequences`

---

## Problem Description
You are given a string `s` that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should **not** contain any brackets.

**Example 1:**

```
Input: s = "(abcd)"
Output: "dcba"
```

**Example 2:**

```
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
```

**Example 3:**

```
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
```

**Constraints:**

* `1 <= s.length <= 2000`
* `s` only contains lower case English characters and parentheses.
* It is guaranteed that all parentheses are balanced.

---

## Solution & Editorial
# Intuition
The problem asks us to reverse substrings contained within matching parentheses, starting from the innermost pairs. A stack data structure perfectly models this nested structure. By keeping track of the starting indices of substrings whenever we encounter an opening parenthesis `(`, we can easily reverse the newly formed string segment in `ans` when we encounter a closing parenthesis `)`.# Approach
1. Initialize an empty string `ans` to build the result and a stack `stk` to store the starting indices of substrings inside parentheses.
2. Iterate through each character of the input string `s` using an index `i` from `0` to `n - 1`:
   - If `s[i] == '('`, push the current length of `ans` (`ans.size()`) onto the stack `stk`. This marks the beginning of the substring formed inside the current parenthesis scope.
   - If `s[i] == ')'`, pop the top index from `stk` as `temp`, and reverse the substring in `ans` from `ans.begin() + temp` to `ans.end()`.
   - If `s[i]` is a lowercase English letter, append it directly to `ans`.
3. Return the fully constructed `ans` string after processing all characters.

### Visual Dry Run (Example 1: s = "(abcd)")
- `i = 0`, `s[0] = '('`: `stk.push(ans.size())` $ightarrow$ `stk` = `[0]`, `ans` = `""`
- `i = 1`, `s[1] = 'a'`: `ans` = `"a"`
- `i = 2`, `s[2] = 'b'`: `ans` = `"ab"`
- `i = 3`, `s[3] = 'c'`: `ans` = `"abc"`
- `i = 4`, `s[4] = 'd'`: `ans` = `"abcd"`
- `i = 5`, `s[5] = ')'`: `temp = stk.top() = 0`, `stk.pop()`, `reverse(ans.begin() + 0, ans.end())` $ightarrow$ `ans` = `"dcba"`

# Complexity
- Time complexity: $$O(N^2)$$, where $$N$$ is the length of string `s`. In the worst-case nested scenario, string reversal takes linear time with respect to the current length of `ans`, leading to quadratic time complexity overall.
- Space complexity: $$O(N)$$, required by the output string `ans` and the auxiliary stack `stk` storing at most $$O(N)$$ indices for nested parentheses.

# Code
```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        int n= s.size();
        string ans = "";
        stack<int> stk;
        for(int i = 0;i<n;i++){
            if(s[i] == '(') stk.push(ans.size());
            else if(s[i] == ')'){
                int temp = stk.top();
                stk.pop();
                reverse(ans.begin()+temp,ans.end());
            }else{
                ans += s[i];
            }
        }

        return ans;
    }
};
```
