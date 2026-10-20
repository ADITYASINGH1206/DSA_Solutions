# [2047. Number of Valid Words in a Sentence](https://leetcode.com/problems/number-of-valid-words-in-a-sentence/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
A sentence consists of lowercase letters (`'a'` to `'z'`), digits (`'0'` to `'9'`), hyphens (`'-'`), punctuation marks (`'!'`, `'.'`, and `','`), and spaces (`' '`) only. Each sentence can be broken down into **one or more tokens** separated by one or more spaces `' '`.

A token is a valid word if **all three** of the following are true:

* It only contains lowercase letters, hyphens, and/or punctuation (**no** digits).
* There is **at most one** hyphen `'-'`. If present, it **must** be surrounded by lowercase characters (`"a-b"` is valid, but `"-ab"` and `"ab-"` are not valid).
* There is **at most one** punctuation mark. If present, it **must** be at the **end** of the token (`"ab,"`, `"cd!"`, and `"."` are valid, but `"a!b"` and `"c.,"` are not valid).

Examples of valid words include `"a-b."`, `"afad"`, `"ba-c"`, `"a!"`, and `"!"`.

Given a string `sentence`, return *the **number** of valid words in* `sentence`.

**Example 1:**

```
Input: sentence = "cat and  dog"
Output: 3
Explanation: The valid words in the sentence are "cat", "and", and "dog".
```

**Example 2:**

```
Input: sentence = "!this  1-s b8d!"
Output: 0
Explanation: There are no valid words in the sentence.
"!this" is invalid because it starts with a punctuation mark.
"1-s" and "b8d" are invalid because they contain digits.
```

**Example 3:**

```
Input: sentence = "alice and  bob are playing stone-game10"
Output: 5
Explanation: The valid words in the sentence are "alice", "and", "bob", "are", and "playing".
"stone-game10" is invalid because it contains digits.
```

**Constraints:**

* `1 <= sentence.length <= 1000`
* `sentence` only contains lowercase English letters, digits, `' '`, `'-'`, `'!'`, `'.'`, and `','`.
* There will be at least `1` token.

---

## Solution & Editorial
# Intuition
The problem requires parsing a sentence into individual tokens and validating each against a set of specific constraints regarding digits, hyphens, and punctuation. Since the constraints are local to each token, we can iterate through the sentence, extract tokens delimited by spaces, and apply a validation function to each.

# Approach
1. **Tokenization**: Append a space to the end of the `sentence` to ensure the final token is processed by the loop. Iterate through the string, accumulating characters into a `word` buffer until a space is encountered.
2. **Validation (`check` function)**:
   - **Digits**: If any character is a digit, the token is invalid.
   - **Hyphens**: Count occurrences. If more than one, return `false`. If present, ensure it is not at the start/end and is flanked by lowercase letters.
   - **Punctuation**: Count occurrences. If more than one, return `false`. If present, ensure it is only at the very end of the token.

### Visual Trace (Example 1: "cat and  dog")
| Token | Digit Check | Hyphen Check | Punc Check | Valid? |
| :--- | :--- | :--- | :--- | :--- |
| "cat" | Pass | Pass (0) | Pass (0) | Yes |
| "and" | Pass | Pass (0) | Pass (0) | Yes |
| "dog" | Pass | Pass (0) | Pass (0) | Yes |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the sentence. We traverse the string once to tokenize and once more to validate each character within the tokens.
- Space complexity: $$O(N)$$ in the worst case, as we store tokens in a buffer before validation.

# Code
```cpp
class Solution {
public:
    bool check(string s) {
        int hyphen = 0;
        int punc = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                return false;
            }

            if (s[i] == '-') {
                hyphen++;
                if (i == 0 || i == s.size() - 1 || hyphen > 1)
                    return false;

                if (!islower(s[i - 1]) || !islower(s[i + 1]))
                    return false;
            }
            if (s[i] == '!' || s[i] == '.' || s[i] == ',') {
                punc++;
                if (i != s.size() - 1 || punc > 1)
                    return false;
            }
        }
        return true;
    }

    int countValidWords(string sentence) {
        int count = 0;

        sentence.push_back(' ');

        string word = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ' && word != "") {
                if (check(word)) {
                    count++;
                    cout << word << endl;
                }
                word = "";
            } else {
                if (sentence[i] != ' ')
                    word += sentence[i];
            }
        }
        return count;
    }
};
```
