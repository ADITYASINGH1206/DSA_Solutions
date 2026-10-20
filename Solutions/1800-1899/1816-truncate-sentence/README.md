# [1816. Truncate Sentence](https://leetcode.com/problems/truncate-sentence/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
A **sentence** is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of **only** uppercase and lowercase English letters (no punctuation).

* For example, `"Hello World"`, `"HELLO"`, and `"hello world hello world"` are all sentences.

You are given a sentence `s`​​​​​​ and an integer `k`​​​​​​. You want to **truncate** `s`​​​​​​ such that it contains only the **first** `k`​​​​​​ words. Return `s`​​​​*​​ after **truncating** it.*

**Example 1:**

```
Input: s = "Hello how are you Contestant", k = 4
Output: "Hello how are you"
Explanation:
The words in s are ["Hello", "how", "are", "you", "Contestant"].
The first 4 words are ["Hello", "how", "are", "you"].
Hence, you should return "Hello how are you".
```

**Example 2:**

```
Input: s = "What is the solution to this problem", k = 4
Output: "What is the solution"
Explanation:
The words in s are ["What", "is", "the", "solution", "to", "this", "problem"].
The first 4 words are ["What", "is", "the", "solution"].
Hence, you should return "What is the solution".
```

**Example 3:**

```
Input: s = "chopper is not a tanuki", k = 5
Output: "chopper is not a tanuki"
```

**Constraints:**

* `1 <= s.length <= 500`
* `k` is in the range `[1, the number of words in s]`.
* `s` consist of only lowercase and uppercase English letters and spaces.
* The words in `s` are separated by a single space.
* There are no leading or trailing spaces.

---

## Solution & Editorial
# Intuition
Since the sentence consists of words separated by single spaces, we can identify the end of the $k$-th word by counting the number of spaces encountered. Once we have passed $k-1$ spaces, the next space (or the end of the string) marks the boundary of our truncated sentence.

# Approach
1. Initialize an empty string `ans` to store the result.
2. Iterate through the input string `s` character by character.
3. If the current character is a space, decrement the counter `k`.
4. If `k` reaches 0, it means we have processed the first $k$ words; terminate the loop immediately.
5. Otherwise, append the current character to `ans`.

### Visual Trace (Example 1: s = "Hello how", k = 2)
| Iteration | Char | k (before) | k (after) | ans |
|-----------|------|------------|-----------|-----|
| 0 | 'H' | 2 | 2 | "H" |
| 1 | 'e' | 2 | 2 | "He" |
| 2 | 'l' | 2 | 2 | "Hel" |
| 3 | 'l' | 2 | 2 | "Hell" |
| 4 | 'o' | 2 | 2 | "Hello" |
| 5 | ' ' | 2 | 1 | "Hello" |
| 6 | 'h' | 1 | 1 | "Hello h" |
| 7 | 'o' | 1 | 1 | "Hello ho" |
| 8 | 'w' | 1 | 1 | "Hello how" |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the string $s$. We perform a single pass over the string.
- Space complexity: $$O(N)$$, as we construct a new string that, in the worst case (where $k$ equals the total number of words), contains all characters of the original string.

# Code
```cpp
class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                k--;
            }
            if(k == 0){
                break;
            }
            ans+= s[i];
        }
        return ans;
    }
};
```
