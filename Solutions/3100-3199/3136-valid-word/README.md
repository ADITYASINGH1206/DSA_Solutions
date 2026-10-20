# [3136. Valid Word](https://leetcode.com/problems/valid-word/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
A word is considered **valid** if:

* It contains a **minimum** of 3 characters.
* It contains only digits (0-9), and English letters (uppercase and lowercase).
* It includes **at least** one **vowel**.
* It includes **at least** one **consonant**.

You are given a string `word`.

Return `true` if `word` is valid, otherwise, return `false`.

**Notes:**

* `'a'`, `'e'`, `'i'`, `'o'`, `'u'`, and their uppercases are **vowels**.
* A **consonant** is an English letter that is not a vowel.

**Example 1:**

**Input:** word = "234Adas"

**Output:** true

**Explanation:**

This word satisfies the conditions.

**Example 2:**

**Input:** word = "b3"

**Output:** false

**Explanation:**

The length of this word is fewer than 3, and does not have a vowel.

**Example 3:**

**Input:** word = "a3$e"

**Output:** false

**Explanation:**

This word contains a `'$'` character and does not have a consonant.

**Constraints:**

* `1 <= word.length <= 20`
* `word` consists of English uppercase and lowercase letters, digits, `'@'`, `'#'`, and `'$'`.

---

## Solution & Editorial
# Intuition
The problem requires verifying four distinct constraints on a string: length, character set, vowel presence, and consonant presence. Since the constraints are small (length up to 20), a single linear scan is sufficient to track these properties simultaneously.

# Approach
1. **Length Check**: Immediately return `false` if `word.size() < 3`.
2. **Iteration**: Iterate through each character `ch` in `word`.
3. **Character Validation**: Use `isalnum(ch)` to ensure the character is either a digit or a letter. If any character is not alphanumeric (e.g., '@', '#', '$'), return `false` immediately.
4. **Vowel/Consonant Tracking**: 
   - Check if `ch` is a vowel (case-insensitive). If so, set `vowel = true`.
   - If not a vowel but `isalpha(ch)` is true, it must be a consonant; set `cons = true`.
5. **Final Validation**: Return `true` only if both `vowel` and `cons` flags are `true`.

### Visual Trace (Example: "234Adas")
| Char | Alnum? | Vowel? | Consonant? | State (v, c) |
| :--- | :--- | :--- | :--- | :--- |
| '2' | Yes | No | No | (F, F) |
| '3' | Yes | No | No | (F, F) |
| '4' | Yes | No | No | (F, F) |
| 'A' | Yes | Yes | No | (T, F) |
| 'd' | Yes | No | Yes | (T, T) |
| 'a' | Yes | Yes | Yes | (T, T) |
| 's' | Yes | No | Yes | (T, T) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We traverse the string exactly once.
- Space complexity: $$O(1)$$, as we only use a few boolean flags regardless of input size.

# Code
```cpp
class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(n<3){
            return false;
        }
        bool vowel =false, cons=false;
        for(char ch:word){
            if(isalnum(ch)){
                if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U'){
                    vowel = true;
                }else if(isalpha(ch)){
                    cons = true;
                }
            }else{
                return false;
            }
        }
        return vowel&&cons;
    }
};
```
