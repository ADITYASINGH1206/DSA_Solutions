# [3120. Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`

---

## Problem Description
You are given a string `word`. A letter is called **special** if it appears **both** in lowercase and uppercase in `word`.

Return the number of**special** letters in`word`.

**Example 1:**

**Input:** word = "aaAbcBC"

**Output:** 3

**Explanation:**

The special characters in `word` are `'a'`, `'b'`, and `'c'`.

**Example 2:**

**Input:** word = "abc"

**Output:** 0

**Explanation:**

No character in `word` appears in uppercase.

**Example 3:**

**Input:** word = "abBCab"

**Output:** 1

**Explanation:**

The only special character in `word` is `'b'`.

**Constraints:**

* `1 <= word.length <= 50`
* `word` consists of only lowercase and uppercase English letters.

---

## Solution & Editorial
# Intuition
To determine if a character is "special," we need to verify the existence of both its lowercase and uppercase forms within the input string. Since the alphabet size is fixed at 26, we can efficiently track the presence of each character using a boolean array indexed by ASCII values.

# Approach
1. Initialize a boolean vector `s` of size `'z' + 1` (123) to keep track of characters present in `word`.
2. Iterate through each character `c` in `word` and set `s[c] = true`.
3. Iterate through the indices `0` to `25` representing the English alphabet. For each index `i`, check if both `s['a' + i]` (lowercase) and `s['A' + i]` (uppercase) are true.
4. Increment the counter `ans` whenever both conditions are met.

### Visual Trace (Example 1: "aaAbcBC")
| Char | 'a' | 'A' | 'b' | 'B' | 'c' | 'C' |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| `s` state | T | T | T | T | T | T |

- Index 0 ('a'): `s['a']` (T) && `s['A']` (T) -> `ans` = 1
- Index 1 ('b'): `s['b']` (T) && `s['B']` (T) -> `ans` = 2
- Index 2 ('c'): `s['c']` (T) && `s['C']` (T) -> `ans` = 3

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform one pass to populate the frequency array and one constant-time pass (26 iterations) to count special characters.
- Space complexity: $$O(1)$$, as the boolean vector size is fixed at 123, which is independent of the input size $$N$$.

# Code
```cpp
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> s('z' + 1);
        for (char& c : word) {
            s[c] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += s['a' + i] && s['A' + i];
        }
        return ans;
    }
};
```
