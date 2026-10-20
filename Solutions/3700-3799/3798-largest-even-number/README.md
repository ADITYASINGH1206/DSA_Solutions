# [3798. Largest Even Number](https://leetcode.com/problems/largest-even-number/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given a string `s` consisting only of the characters `'1'` and `'2'`.

You may delete any number of characters from `s` without changing the order of the remaining characters.

Return the **largest possible resultant string** that represents an **even** integer. If there is no such string, return the empty string `""`.

**Example 1:**

**Input:** s = "1112"

**Output:** "1112"

**Explanation:**

The string already represents the largest possible even number, so no deletions are needed.

**Example 2:**

**Input:** s = "221"

**Output:** "22"

**Explanation:**

Deleting `'1'` results in the largest possible even number which is equal to 22.

**Example 3:**

**Input:** s = "1"

**Output:** ""

**Explanation:**

There is no way to get an even number.

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists only of the characters `'1'` and `'2'`.

---

## Solution & Editorial
# Intuition
To form the largest even number, we must ensure the last digit is even. Since the string only contains '1' and '2', the only even digit available is '2'. To maximize the number, we want to keep as many digits as possible, specifically all digits appearing before the first occurrence of '2' (from the right) and the '2' itself.

# Approach
1. Iterate through the string `s` from right to left.
2. Maintain a boolean flag `even` to track if we have encountered the first '2'.
3. If `even` is false and the current character is '2', we set `even` to true and include this '2' in our result `ans`.
4. If `even` is true, we include every subsequent character encountered (as they all contribute to a larger magnitude).
5. Finally, reverse `ans` because we collected characters from right to left.

### Visual Trace (s = "221")
| Iteration | Char | even | Action | ans |
|-----------|------|------|--------|-----|
| 0 (i=2)   | '1'  | F    | Skip   | ""  |
| 1 (i=1)   | '2'  | F->T | Add '2'| "2" |
| 2 (i=0)   | '2'  | T    | Add '2'| "22"|

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single pass over the string.
- Space complexity: $$O(N)$$ to store the resulting string.

# Code
```cpp
class Solution {
public:
    string largestEven(string s) {
        string ans = "";
        int n= s.size();
        bool even = false;
        for(int i =n-1;i>=0;i--){
            int temp = s[i]-'0';
            if(even){
                ans+= s[i];
            }
            if(!even){
                int temp = s[i] -'0';
                if(temp%2 == 0){
                    even = true;
                    ans+= s[i];
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
