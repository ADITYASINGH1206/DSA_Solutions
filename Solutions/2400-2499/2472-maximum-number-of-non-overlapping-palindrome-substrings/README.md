# [2472. Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/)
**Difficulty:** `Hard` | **Tags:** `two-pointers`, `string`, `dynamic-programming`, `greedy`

---

## Problem Description
You are given a string `s` and a **positive** integer `k`.

Select a set of **non-overlapping** substrings from the string `s` that satisfy the following conditions:

* The **length** of each substring is **at least** `k`.
* Each substring is a **palindrome**.

Return *the **maximum** number of substrings in an optimal selection*.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

```
Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.
```

**Example 2:**

```
Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.
```

**Constraints:**

* `1 <= k <= s.length <= 2000`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To maximize the number of non-overlapping palindromic substrings of length at least `k`, we should employ a greedy strategy. Whenever we find a valid palindrome, we should "take" it immediately and move our search pointer past the end of this palindrome. This works because picking the earliest possible ending palindrome leaves the maximum remaining string length for future candidates.

# Approach
1. Iterate through each index `i` of the string `s`, treating it as the center of a potential palindrome.
2. For each `i`, expand outwards using two pointers `l` and `r` to check for both odd-length (center `i`) and even-length (centers `i-1, i`) palindromes.
3. Maintain a variable `end` to track the end index of the last selected palindrome. Initialize `end = -1`.
4. During expansion, if `s[l] == s[r]` and the current substring length `r - l + 1 >= k`, and the start index `l` is greater than `end` (ensuring no overlap), we increment our count `ans`, update `end = r`, and break the inner loop to start searching for the next palindrome.

### Visual Trace (s = "abaccdbbd", k = 3)
| i | Center Type | Palindrome Found | end | ans |
|---|---|---|---|---|
| 0 | - | - | -1 | 0 |
| 1 | Odd (aba) | "aba" | 2 | 1 |
| 2 | - | - | 2 | 1 |
| 3 | - | - | 2 | 1 |
| 4 | - | - | 2 | 1 |
| 5 | - | - | 2 | 1 |
| 6 | Even (dbbd) | "dbbd" | 8 | 2 |

# Complexity
- Time complexity: $$O(N^2)$$, where $$N$$ is the length of the string. We iterate through each character as a center and expand outwards, resulting in at most $$N^2$$ operations.
- Space complexity: $$O(1)$$, as we only use a few integer variables to track indices and the answer.

# Code
```cpp
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), ans = 0, end = -1;
        for(int i = 0; i < n; i++){
            for(int l : {i - 1, i}){
                int r = i;
                while(l >= 0 && r < n && s[l] == s[r]){
                    if(r - l + 1 >= k && l > end){
                        ans++;
                        end = r;
                        break;
                    }
                    l--, r++;
                }
            }
        }
        return ans;
    }
};
```
