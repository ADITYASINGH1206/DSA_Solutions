# [3121. Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`

---

## Problem Description
You are given a string `word`. A letter `c` is called **special** if it appears **both** in lowercase and uppercase in `word`, and **every** lowercase occurrence of `c` appears before the **first** uppercase occurrence of `c`.

Return the number of**special** lettersin`word`.

**Example 1:**

**Input:** word = "aaAbcBC"

**Output:** 3

**Explanation:**

The special characters are `'a'`, `'b'`, and `'c'`.

**Example 2:**

**Input:** word = "abc"

**Output:** 0

**Explanation:**

There are no special characters in `word`.

**Example 3:**

**Input:** word = "AbBCab"

**Output:** 0

**Explanation:**

There are no special characters in `word`.

**Constraints:**

* `1 <= word.length <= 2 * 105`
* `word` consists of only lowercase and uppercase English letters.

---

## Solution & Editorial
# Intuition
To determine if a character is "special," we need to verify two conditions: it must exist in both lowercase and uppercase, and every lowercase occurrence must precede the first uppercase occurrence. This implies that the *last* occurrence of the lowercase letter must appear before the *first* occurrence of the uppercase letter.

# Approach
1. We maintain two arrays, `first` and `last`, of size 123 (covering ASCII values up to 'z').
2. We iterate through the string once, recording the 1-based index of the first and last appearance of each character in the respective arrays.
3. After the pass, we iterate through the 26 English letters. For each letter, we check:
   - Does the lowercase version exist (`last['a' + i] > 0`)?
   - Does the uppercase version exist (`first['A' + i] > 0`)?
   - Is the last occurrence of the lowercase letter strictly before the first occurrence of the uppercase letter (`last['a' + i] < first['A' + i]`)?
4. If all conditions are met, increment the answer.

### Visual Trace (Example 1: "aaAbcBC")
| Char | Index (1-based) | first[] | last[] |
| :--- | :--- | :--- | :--- |
| 'a' | 1, 2 | first['a']=1 | last['a']=2 |
| 'A' | 3 | first['A']=3 | last['A']=3 |
| 'b' | 4 | first['b']=4 | last['b']=4 |
| 'c' | 5 | first['c']=5 | last['c']=5 |
| 'B' | 6 | first['B']=6 | last['B']=6 |
| 'C' | 7 | first['C']=7 | last['C']=7 |

Checking 'a': `last['a']` (2) < `first['A']` (3) → True.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single pass over the string and a constant-time loop (26 iterations).
- Space complexity: $$O(1)$$, as the `first` and `last` arrays have a fixed size of 123, independent of the input size.

# Code
```cpp
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> first('z' + 1);
        vector<int> last('z' + 1);
        for (int i = 1; i <= word.size(); ++i) {
            int j = word[i - 1];
            if (first[j] == 0) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (last['a' + i] && last['a' + i] < first['A' + i]) {
                ++ans;
            }
        }
        return ans;
    }
};
```
