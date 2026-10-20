# [2828. Check if a String Is an Acronym of Words](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
Given an array of strings `words` and a string `s`, determine if `s` is an **acronym** of words.

The string `s` is considered an acronym of `words` if it can be formed by concatenating the **first** character of each string in `words` **in order**. For example, `"ab"` can be formed from `["apple", "banana"]`, but it can't be formed from `["bear", "aardvark"]`.

Return `true` *if* `s` *is an acronym of* `words`*, and* `false` *otherwise.*

**Example 1:**

```
Input: words = ["alice","bob","charlie"], s = "abc"
Output: true
Explanation: The first character in the words "alice", "bob", and "charlie" are 'a', 'b', and 'c', respectively. Hence, s = "abc" is the acronym.
```

**Example 2:**

```
Input: words = ["an","apple"], s = "a"
Output: false
Explanation: The first character in the words "an" and "apple" are 'a' and 'a', respectively. 
The acronym formed by concatenating these characters is "aa". 
Hence, s = "a" is not the acronym.
```

**Example 3:**

```
Input: words = ["never","gonna","give","up","on","you"], s = "ngguoy"
Output: true
Explanation: By concatenating the first character of the words in the array, we get the string "ngguoy". 
Hence, s = "ngguoy" is the acronym.
```

**Constraints:**

* `1 <= words.length <= 100`
* `1 <= words[i].length <= 10`
* `1 <= s.length <= 100`
* `words[i]` and `s` consist of lowercase English letters.

---

## Solution & Editorial
# Intuition
To determine if a string `s` is an acronym of a list of `words`, we simply need to verify that the length of the acronym matches the number of words and that each character at index `i` in `s` corresponds to the first character of the word at index `i` in the `words` array.

# Approach
1. First, check if the length of `s` is equal to the number of elements in `words`. If they differ, `s` cannot be an acronym, so return `false` immediately.
2. Iterate through the `words` array using a range-based for loop. For each `word`, extract the first character (`word[0]`) and append it to a temporary string `res`.
3. After constructing the full acronym, compare `res` with the input string `s` and return the result of the comparison.

### Visual Trace (Example 1: words = ["alice", "bob", "charlie"], s = "abc")
| Iteration | word | word[0] | res (accumulated) |
|-----------|------|---------|-------------------|
| 1         | alice| 'a'     | "a"               |
| 2         | bob  | 'b'     | "ab"              |
| 3         | charlie| 'c'   | "abc"             |

Final comparison: "abc" == "abc" returns `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of words in the array. We iterate through the array exactly once, performing constant-time operations at each step.
- Space complexity: $$O(N)$$, as we store the constructed acronym string `res` which has a length equal to the number of words.

# Code
```cpp
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res = "";
        int n = words.size();
        for(auto & word:words){
            res += word[0];
        }
        
        return res == s;
    }
};
```
