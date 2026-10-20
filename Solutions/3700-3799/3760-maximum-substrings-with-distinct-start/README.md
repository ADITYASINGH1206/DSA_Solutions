# [3760. Maximum Substrings With Distinct Start](https://leetcode.com/problems/maximum-substrings-with-distinct-start/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters.

Return an integer denoting the **maximum** number of substrings you can split `s` into such that each **substring** starts with a **distinct** character (i.e., no two substrings start with the same character).

**Example 1:**

**Input:** s = "abab"

**Output:** 2

**Explanation:**

* Split `"abab"` into `"a"` and `"bab"`.
* Each substring starts with a distinct character i.e `'a'` and `'b'`. Thus, the answer is 2.

**Example 2:**

**Input:** s = "abcd"

**Output:** 4

**Explanation:**

* Split `"abcd"` into `"a"`, `"b"`, `"c"`, and `"d"`.
* Each substring starts with a distinct character. Thus, the answer is 4.

**Example 3:**

**Input:** s = "aaaa"

**Output:** 1

**Explanation:**

* All characters in `"aaaa"` are `'a'`.
* Only one substring can start with `'a'`. Thus, the answer is 1.

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks for the maximum number of substrings such that each starts with a unique character. Since we want to maximize the number of substrings, we should greedily start a new substring as soon as we encounter a character that hasn't been used as a starting character yet. Because there are only 26 lowercase English letters, the maximum possible number of such substrings is 26.

# Approach
1. Initialize an integer array `cnt` of size 26 to track which characters have already been used as the start of a substring.
2. Iterate through the string `s` character by character.
3. For each character `c`, increment its corresponding count in `cnt`.
4. If the count becomes exactly 1, it means this is the first time we have encountered this character in the string. Since we can treat this character as the start of a new substring, increment the answer counter `ans`.
5. Return `ans` after the loop finishes.

### Visual Trace (Example 1: s = "abab")
| Iteration | Char | `cnt` state (a, b) | `ans` |
|-----------|------|--------------------|-------|
| 1         | 'a'  | [1, 0]             | 1     |
| 2         | 'b'  | [1, 1]             | 2     |
| 3         | 'a'  | [2, 1]             | 2     |
| 4         | 'b'  | [2, 2]             | 2     |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as the `cnt` array is fixed at size 26 regardless of the input size.

# Code
```cpp
class Solution {
public:
    int maxDistinct(string s) {
        int ans = 0;
        int cnt[26]{};
        for (char c : s) {
            if (++cnt[c - 'a'] == 1) {
                ++ans;
            }
        }
        return ans;
    }
};
```
