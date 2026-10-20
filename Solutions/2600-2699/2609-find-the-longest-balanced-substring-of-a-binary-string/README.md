# [2609. Find the Longest Balanced Substring of a Binary String](https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given a binary string `s` consisting only of zeroes and ones.

A substring of `s` is considered balanced if **all zeroes are before ones** and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.

Return *the length of the longest balanced substring of* `s`.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

```
Input: s = "01000111"
Output: 6
Explanation: The longest balanced substring is "000111", which has length 6.
```

**Example 2:**

```
Input: s = "00111"
Output: 4
Explanation: The longest balanced substring is "0011", which has length 4. 
```

**Example 3:**

```
Input: s = "111"
Output: 0
Explanation: There is no balanced substring except the empty substring, so the answer is 0.
```

**Constraints:**

* `1 <= s.length <= 50`
* `'0' <= s[i] <= '1'`

---

## Solution & Editorial
# Intuition
A balanced substring requires all '0's to precede all '1's with equal counts. We can track the consecutive counts of '0's and '1's in a single pass. Whenever we encounter a '0' after some '1's, we reset the counters, as a new potential balanced sequence must start fresh.

# Approach
1. Maintain two counters: `zero` (count of consecutive '0's) and `one` (count of consecutive '1's).
2. Iterate through the string `s`:
   - If `ch == '0'`: If we haven't started counting '1's yet, increment `zero`. If we have already seen '1's, this '0' marks the start of a new potential sequence, so reset `zero = 1` and `one = 0`.
   - If `ch == '1'`: If we have seen at least one '0' (`zero > 0`), increment `one`. The length of the current balanced portion is `2 * min(zero, one)`. Update `ans` with the maximum value found.
3. Return `ans`.

### Visual Trace (s = "01000111")
| Char | zero | one | ans | Note |
| :--- | :--- | :--- | :--- | :--- |
| '0' | 1 | 0 | 0 | Start sequence |
| '1' | 1 | 1 | 2 | Balanced: "01" |
| '0' | 1 | 0 | 2 | Reset (new '0') |
| '0' | 2 | 0 | 2 | Count '0's |
| '0' | 3 | 0 | 2 | Count '0's |
| '1' | 3 | 1 | 2 | Balanced: "01" |
| '1' | 3 | 2 | 4 | Balanced: "0011" |
| '1' | 3 | 3 | 6 | Balanced: "000111" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single linear scan.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        int zero = 0 , one = 0;
        for(char ch:s){
            if(ch=='0'){
                if(one==0){
                    zero++;
                }else{
                    zero=1;
                    one = 0;
                }
            }else{
                if(zero>0){
                    one++;
                    ans=max(ans,2*min(one,zero));
                }
            }
        }
        return ans;
    }
};
```
