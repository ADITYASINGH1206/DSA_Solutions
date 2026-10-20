# [3856. Trim Trailing Vowels](https://leetcode.com/problems/trim-trailing-vowels/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given a string `s` that consists of lowercase English letters.

Return the string obtained by removing **all** trailing **vowels** from `s`.

The **vowels** consist of the characters `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

**Example 1:**

**Input:** s = "idea"

**Output:** "id"

**Explanation:**

Removing `"idea"`, we obtain the string `"id"`.

**Example 2:**

**Input:** s = "day"

**Output:** "day"

**Explanation:**

There are no trailing vowels in the string `"day"`.

**Example 3:**

**Input:** s = "aeiou"

**Output:** ""

**Explanation:**

Removing `"aeiou"`, we obtain the string `""`.

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists of only lowercase English letters.

---

## Solution & Editorial
# Intuition
To remove all trailing vowels, we only need to inspect the end of the string. Since vowels are defined as a specific set, we can repeatedly check the last character and remove it if it is a vowel, continuing until the string is empty or the last character is a consonant.

# Approach
1. Use a `while` loop to check the condition: is the string non-empty AND is the last character (`s.back()`) a vowel ('a', 'e', 'i', 'o', or 'u')?
2. If the condition is true, invoke `s.pop_back()` to remove the trailing character.
3. Repeat until the condition fails, then return the modified string.

### Visual Trace (Example 1: s = "idea")
| Iteration | String State | `s.back()` | Is Vowel? | Action |
| :--- | :--- | :--- | :--- | :--- |
| 0 | "idea" | 'a' | Yes | `pop_back()` |
| 1 | "ide" | 'e' | Yes | `pop_back()` |
| 2 | "id" | 'd' | No | Stop |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. In the worst case (e.g., "aeiou"), we perform $$N$$ pop operations.
- Space complexity: $$O(1)$$ auxiliary space, as we modify the string in-place (or $$O(N)$$ if considering the input string storage).

# Code
```cpp
class Solution {
public:
    string trimTrailingVowels(string s) {
        while (!s.empty() && (s.back() == 'a' || s.back() == 'e' || 
                              s.back() == 'i' || s.back() == 'o' || 
                              s.back() == 'u')) {
            s.pop_back(); 
        }
        return s;
    }
};
```
