# [2697. Lexicographically Smallest Palindrome](https://leetcode.com/problems/lexicographically-smallest-palindrome/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`, `greedy`

---

## Problem Description
You are given a string `s` consisting of **lowercase English letters**, and you are allowed to perform operations on it. In one operation, you can **replace** a character in `s` with another lowercase English letter.

Your task is to make `s` a **palindrome** with the **minimum** **number** **of operations** possible. If there are **multiple palindromes** that can be made using the **minimum** number of operations, make the **lexicographically smallest** one.

A string `a` is lexicographically smaller than a string `b` (of the same length) if in the first position where `a` and `b` differ, string `a` has a letter that appears earlier in the alphabet than the corresponding letter in `b`.

Return *the resulting palindrome string.*

**Example 1:**

```
Input: s = "egcfe"
Output: "efcfe"
Explanation: The minimum number of operations to make "egcfe" a palindrome is 1, and the lexicographically smallest palindrome string we can get by modifying one character is "efcfe", by changing 'g'.
```

**Example 2:**

```
Input: s = "abcd"
Output: "abba"
Explanation: The minimum number of operations to make "abcd" a palindrome is 2, and the lexicographically smallest palindrome string we can get by modifying two characters is "abba".
```

**Example 3:**

```
Input: s = "seven"
Output: "neven"
Explanation: The minimum number of operations to make "seven" a palindrome is 1, and the lexicographically smallest palindrome string we can get by modifying one character is "neven".
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consists of only lowercase English letters**.**

---

## Solution & Editorial
# Intuition
To make a string a palindrome with the minimum number of operations, we must ensure that for every index `i`, the character at `s[i]` matches the character at `s[n-1-i]`. If they differ, we must change one of them. To achieve the lexicographically smallest result, we greedily choose the smaller of the two characters and assign it to both positions.

# Approach
1. Initialize two pointers: `l` at the start (0) and `r` at the end (`n-1`) of the string.
2. Iterate while `l < r`:
   - Compare `s[l]` and `s[r]`.
   - If they are not equal, replace both with the character that is lexicographically smaller (i.e., `min(s[l], s[r])`).
   - Increment `l` and decrement `r` to move towards the center.
3. Return the modified string.

### Visual Trace (Example 1: "egcfe")
| Iteration | l | r | s[l] | s[r] | Action | Result |
|-----------|---|---|------|------|--------|--------|
| 1 | 0 | 4 | 'e' | 'e' | Match | "egcfe" |
| 2 | 1 | 3 | 'g' | 'f' | Replace 'g' with 'f' | "efcfe" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We traverse the string exactly once using two pointers.
- Space complexity: $$O(1)$$, as we modify the string in-place and use only a constant amount of extra space for pointers.

# Code
```cpp
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r= n-1;
        while(l<r){
            if(s[l] != s[r]){
                if(s[l]-'a' > s[r] - 'a'){
                    s[l] = s[r];
                }else{
                    s[r] = s[l];
                }
            }
            l++,r--;
        }

        return s;
    }
};
```
