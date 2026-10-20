# [3823. Reverse Letters Then Special Characters in a String](https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`, `simulation`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters and special characters.

Your task is to perform these **in order**:

* **Reverse** the **lowercase letters** and place them back into the positions originally occupied by letters.
* **Reverse** the **special characters** and place them back into the positions originally occupied by special characters.

Return the resulting string after performing the reversals.

**Example 1:**

**Input:** s = ")ebc#da@f("

**Output:** "(fad@cb#e)"

**Explanation:**

* The letters in the string are `['e', 'b', 'c', 'd', 'a', 'f']`:
  + Reversing them gives `['f', 'a', 'd', 'c', 'b', 'e']`
  + `s` becomes `")fad#cb@e("`
* ​​​​​​​The special characters in the string are `[')', '#', '@', '(']`:
  + Reversing them gives `['(', '@', '#', ')']`
  + `s` becomes `"(fad@cb#e)"`

**Example 2:**

**Input:** s = "z"

**Output:** "z"

**Explanation:**

The string contains only one letter, and reversing it does not change the string. There are no special characters.

**Example 3:**

**Input:** s = "!@#$%^&\*()"

**Output:** ")(\*&^%$#@!"

**Explanation:**

The string contains no letters. The string contains all special characters, so reversing the special characters reverses the whole string.

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists only of lowercase English letters and the special characters in `"!@#$%^&*()"`.

---

## Solution & Editorial
# Intuition
The problem requires independent reversal of two distinct character sets (lowercase letters and special characters) while maintaining their original relative positions. Since the relative order of each type is preserved, we can extract them into separate containers, reverse those containers, and then reconstruct the string by iterating through the original structure.

# Approach
1. **Extraction**: Iterate through the input string `s` once. Use two separate vectors, `letters` and `specials`, to store characters based on their type (`islower(c)`).
2. **Reconstruction**: Iterate through the original string `s` again. For each position, check if the original character was a letter or a special character. If it was a letter, append the next character from the end of the `letters` vector (effectively reversing it). If it was a special character, append from the end of the `specials` vector.

### Visual Trace (Example 1: `s = ")ebc#da@f("`) 
| Step | Original `s` | `letters` (extracted) | `specials` (extracted) |
| :--- | :--- | :--- | :--- |
| 1 | `)ebc#da@f(` | `['e','b','c','d','a','f']` | `[')','#','@','(']` |
| 2 | `)ebc#da@f(` | Reversed: `['f','a','d','c','b','e']` | Reversed: `['(','@','#',')']` |

**Reconstruction:**
- Index 0: `)` (special) -> take `specials[3]` = `(`
- Index 1: `e` (letter) -> take `letters[5]` = `f`
- ...and so on, resulting in `(fad@cb#e)`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform two linear passes: one to extract characters and one to reconstruct the result.
- Space complexity: $$O(N)$$, as we store all characters in auxiliary vectors to facilitate the reversal process.

# Code
```cpp
class Solution {
public:
    string reverseByType(string s) {
        string ans = "";
        vector<char> letters;
        vector<char> specials;
        for(char c: s){
            if(islower(c)){
                letters.push_back(c);
            }else{
                specials.push_back(c);
            }
        }
        int l = letters.size()-1;
        int r = specials.size()-1;

        for(char c:s){
            if(islower(c)){
                ans+= letters[l--];
            }else{
                ans+= specials[r--];
            }
        }
        return ans;
    }
};
```
