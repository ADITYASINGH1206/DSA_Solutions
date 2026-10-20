# [3884. First Matching Character From Both Ends](https://leetcode.com/problems/first-matching-character-from-both-ends/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`

---

## Problem Description
You are given a string `s` of length `n` consisting of lowercase English letters.

Return the smallest index `i` such that `s[i] == s[n - i - 1]`.

If no such index exists, return -1.

**Example 1:**

**Input:** s = "abcacbd"

**Output:** 1

**Explanation:**

At index `i = 1`, `s[1]` and `s[5]` are both `'b'`.

No smaller index satisfies the condition, so the answer is 1.

**Example 2:**

**Input:** s = "abc"

**Output:** 1

**Explanation:**

​​​​​​​At index `i = 1`, the two compared positions coincide, so both characters are `'b'`.

No smaller index satisfies the condition, so the answer is 1.

**Example 3:**

**Input:** s = "abcdab"

**Output:** -1

**Explanation:**

​​​​​​​For every index `i`, the characters at positions `i` and `n - i - 1` are different.

Therefore, no valid index exists, so the answer is -1.

**Constraints:**

* `1 <= n == s.length <= 100`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks for the smallest index `i` where the character at the front matches the character at the corresponding position from the back. Since we need the *smallest* index, a simple linear scan from left to right is optimal.

# Approach
1. Calculate the length `n` of the string `s`.
2. Iterate through the string using an index `i` from `0` to `n - 1`.
3. At each index `i`, compare `s[i]` with `s[n - i - 1]`.
4. The first index that satisfies the condition `s[i] == s[n - i - 1]` is returned immediately.
5. If the loop completes without finding a match, return `-1`.

### Visual Trace (Example 1: s = "abcacbd")
| i | s[i] | n-i-1 | s[n-i-1] | Match? |
|---|---|---|---|---|
| 0 | 'a' | 6 | 'd' | No |
| 1 | 'b' | 5 | 'b' | Yes (Return 1) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single pass over the string.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for the loop variable and string length.

# Code
```cpp
class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();

        for(int i =0;i<n;i++){
            if(s[i] == s[n-i-1]){
                return i;
            }
        }
        return -1;
    }
};
```
