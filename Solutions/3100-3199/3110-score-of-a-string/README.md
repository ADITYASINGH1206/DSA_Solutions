# [3110. Score of a String](https://leetcode.com/problems/score-of-a-string/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given a string `s`. The **score** of a string is defined as the sum of the absolute difference between the **ASCII** values of adjacent characters.

Return the **score** of`s`.

**Example 1:**

**Input:** s = "hello"

**Output:** 13

**Explanation:**

The **ASCII** values of the characters in `s` are: `'h' = 104`, `'e' = 101`, `'l' = 108`, `'o' = 111`. So, the score of `s` would be `|104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13`.

**Example 2:**

**Input:** s = "zaz"

**Output:** 50

**Explanation:**

The **ASCII** values of the characters in `s` are: `'z' = 122`, `'a' = 97`. So, the score of `s` would be `|122 - 97| + |97 - 122| = 25 + 25 = 50`.

**Constraints:**

* `2 <= s.length <= 100`
* `s` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks for the sum of absolute differences between adjacent characters. Since we only need to process each adjacent pair once, a single linear pass through the string is sufficient to compute the total score.

# Approach
1. Initialize an integer `ans` to 0 to store the cumulative score.
2. Iterate through the string from index `0` to `s.length() - 2`.
3. In each iteration, calculate the absolute difference between the current character `s[i]` and the next character `s[i+1]` using `abs(s[i] - s[i+1])`.
4. Add this difference to `ans`.
5. Return `ans` after the loop completes.

### Visual Trace (Example 1: "hello")
| Iteration | i | s[i] | s[i+1] | abs(s[i]-s[i+1]) | ans |
|-----------|---|------|--------|------------------|-----|
| 1         | 0 | 'h'  | 'e'    | |104-101| = 3 | 3   |
| 2         | 1 | 'e'  | 'l'    | |101-108| = 7 | 10  |
| 3         | 2 | 'l'  | 'l'    | |108-108| = 0 | 10  |
| 4         | 3 | 'l'  | 'o'    | |108-111| = 3 | 13  |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a single integer variable for the accumulator.

# Code
```cpp
class Solution {
public:
    int scoreOfString(string s) {
        int ans=0 ;
        for(int i = 0 ; i < s.length()-1;i++){
            ans+=abs((s[i]-s[i+1]));
        }
        return ans;
    }
};
```
