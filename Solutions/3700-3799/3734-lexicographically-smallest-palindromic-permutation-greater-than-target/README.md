# [3734. Lexicographically Smallest Palindromic Permutation Greater Than Target](https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/)
**Difficulty:** `Hard` | **Tags:** `two-pointers`, `string`, `enumeration`

---

## Problem Description
You are given two strings `s` and `target`, each of length `n`, consisting of lowercase English letters.

Return the **lexicographically smallest string** that is **both** a **palindromic permutation** of `s` and **strictly** greater than `target`. If no such permutation exists, return an empty string.

**Example 1:**

**Input:** s = "baba", target = "abba"

**Output:** "baab"

**Explanation:**

* The palindromic permutations of `s` (in lexicographical order) are `"abba"` and `"baab"`.
* The lexicographically smallest permutation that is strictly greater than `target` is `"baab"`.

**Example 2:**

**Input:** s = "baba", target = "bbaa"

**Output:** ""

**Explanation:**

* The palindromic permutations of `s` (in lexicographical order) are `"abba"` and `"baab"`.
* None of them is lexicographically strictly greater than `target`. Therefore, the answer is `""`.

**Example 3:**

**Input:** s = "abc", target = "abb"

**Output:** ""

**Explanation:**

`s` has no palindromic permutations. Therefore, the answer is `""`.

**Example 4:**

**Input:** s = "aac", target = "abb"

**Output:** "aca"

**Explanation:**

* The only palindromic permutation of `s` is `"aca"`.
* `"aca"` is strictly greater than `target`. Therefore, the answer is `"aca"`.

**Constraints:**

* `1 <= n == s.length == target.length <= 300`
* `s` and `target` consist of only lowercase English letters.

---

## Solution & Editorial
# Intuition
To form a palindromic permutation, we must first ensure the character frequencies allow for a palindrome (at most one character with an odd count). Since we need the lexicographically smallest palindrome strictly greater than `target`, we can treat the first half of the string as the decision space. We attempt to match the `target` prefix as closely as possible, then look for the first position where we can place a larger character to make the resulting palindrome strictly greater.

# Approach
1. **Frequency Analysis**: Count character occurrences. If more than one character has an odd frequency, return `""` immediately.
2. **Prefix Matching**: Attempt to construct a palindrome using the first `n/2` characters of `target`. We track the remaining available characters in `freq`. If the resulting palindrome is already greater than `target`, we return it.
3. **Backtracking/Greedy Search**: If the prefix match fails, iterate backwards from the middle of the string (`i = n/2 - 1` down to `0`). At each position `i`, try to increment the character `target[i]` to a larger character `j` that is available in our `freq` pool. 
4. **Construction**: Once a valid larger character is found at index `i`, fill the remaining positions `i+1` to `n/2 - 1` with the smallest available characters to ensure the resulting palindrome is the lexicographically smallest possible.

### Visual Trace (Example 1: s="baba", target="abba")
- `freq`: {a:2, b:2}, `center`: 0, `half`: 2
- Initial check: `target[0..1]` is "ab". `freq` becomes {a:0, b:0}. Palindrome: "abba".
- "abba" is not > "abba".
- Backtrack to `i=1`: `target[1]` is 'b'. `freq` becomes {a:0, b:2}. Try `j > 'b'`: None.
- Backtrack to `i=0`: `target[0]` is 'a'. `freq` becomes {a:2, b:2}. Try `j > 'a'`: 'b'.
- Result: `result[0]` = 'b'. Remaining `freq`: {a:2, b:0}. Fill `result[1]` = 'a'.
- Final: "ba" + "ab" = "baab".

# Complexity
- Time complexity: $$O(N + \Sigma^2)$$, where $$N$$ is the string length and $$\Sigma=26$$. We iterate through the string once and perform constant-time frequency checks.
- Space complexity: $$O(N)$$ to store the resulting string and the frequency array of size 26.

# Code
```cpp
class Solution {
public:
    string lexPalindromicPermutation(string str, string target) {
        int freq[26] = {0};
        for (char s : str)
            freq[s - 'a']++;

        char center = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                if (center != 0)
                    return "";
                center = 'a' + i;
                freq[i]--;
            }
        }

        int sz = str.length();
        int half = sz / 2;
        for (int i = 0; i < half; i++)
            freq[target[i] - 'a'] -= 2;

        if (check(freq)) {
            string head = target.substr(0, half);
            string rev = head;
            reverse(rev.begin(), rev.end());
            string tail = "";
            if (center != 0)
                tail += center;
            tail += rev;
            if (tail > target.substr(half))
                return head + tail;
        }

        for (int i = half - 1; i >= 0; i--) {
            char w = target[i];
            freq[w - 'a'] += 2;
            if (!check(freq))
                continue;

            for (int j = (w - 'a') + 1; j < 26; j++) {
                if (freq[j] == 0)
                    continue;
                freq[j] -= 2;
                string result = target.substr(0, i + 1);
                result[i] = 'a' + j;

                for (int k = 0; k < 26; k++) {
                    int cnt = freq[k] / 2;
                    if (cnt > 0)
                        result.append(cnt, 'a' + k);
                }

                string part = result;
                reverse(part.begin(), part.end());
                if (center != 0)
                    result.push_back(center);
                result += part;
                return result;
            }
        }

        return "";
    }

    bool check(int f[]) {
        for (int i = 0; i < 26; i++)
            if (f[i] < 0)
                return false;
        return true;
    }
};
```
