# [2063. Vowels of All Substrings](https://leetcode.com/problems/vowels-of-all-substrings/)
**Difficulty:** `Medium` | **Tags:** `math`, `string`, `dynamic-programming`, `combinatorics`

---

## Problem Description
Given a string `word`, return *the **sum of the number of vowels** (*`'a'`, `'e'`*,* `'i'`*,* `'o'`*, and* `'u'`*)* *in every substring of* `word`.

A **substring** is a contiguous (non-empty) sequence of characters within a string.

**Note:** Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.

**Example 1:**

```
Input: word = "aba"
Output: 6
Explanation: 
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6.
```

**Example 2:**

```
Input: word = "abc"
Output: 3
Explanation: 
All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
- "a", "ab", and "abc" have 1 vowel each
- "b", "bc", and "c" have 0 vowels each
Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3.
```

**Example 3:**

```
Input: word = "ltcd"
Output: 0
Explanation: There are no vowels in any substring of "ltcd".
```

**Constraints:**

* `1 <= word.length <= 105`
* `word` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
Instead of iterating through all possible substrings (which would be $O(N^2)$), we can count the contribution of each individual vowel to the total sum. A vowel at index `i` (0-indexed) appears in every substring that starts at or before `i` and ends at or after `i`.

# Approach
1. For each character at index `i` in the string `word` of length `n`:
   - If the character is a vowel ('a', 'e', 'i', 'o', 'u'), it contributes to the total count.
   - The number of possible starting positions for a substring containing `word[i]` is `(i + 1)` (indices `0` to `i`).
   - The number of possible ending positions for a substring containing `word[i]` is `(n - i)` (indices `i` to `n-1`).
   - By the rule of product, the total number of substrings containing `word[i]` is `(i + 1) * (n - i)`.
2. Accumulate these products into a `long long` variable `ans` to prevent overflow.

### Visual Trace (word = "aba")
- `n = 3`
- `i = 0`: `word[0] = 'a'` (vowel). Contribution: `(0 + 1) * (3 - 0) = 1 * 3 = 3`.
- `i = 1`: `word[1] = 'b'` (not a vowel). Contribution: `0`.
- `i = 2`: `word[2] = 'a'` (vowel). Contribution: `(2 + 1) * (3 - 2) = 3 * 1 = 3`.
- Total: `3 + 0 + 3 = 6`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single linear scan.
- Space complexity: $$O(1)$$, as we only use a few variables for accumulation.

# Code
```cpp
using ll = long long;
class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        ll ans = 0;
        for(int i =0;i<n;i++){
            char ch = word[i];
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                ans+=(ll)(i+1)*(n-i);
            }
        }
        return ans;
    }
};
```
