# [1662. Check If Two String Arrays are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
Given two string arrays `word1` and `word2`, return`true` *if the two arrays **represent** the same string, and* `false` *otherwise.*

A string is **represented** by an array if the array elements concatenated **in order** forms the string.

**Example 1:**

```
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
```

**Example 2:**

```
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
```

**Example 3:**

```
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
```

**Constraints:**

* `1 <= word1.length, word2.length <= 103`
* `1 <= word1[i].length, word2[i].length <= 103`
* `1 <= sum(word1[i].length), sum(word2[i].length) <= 103`
* `word1[i]` and `word2[i]` consist of lowercase letters.

---

## Solution & Editorial
# Intuition
The problem asks us to determine if two arrays of strings, when concatenated in order, form the exact same sequence of characters. The most straightforward approach is to reconstruct the full string represented by each array and compare them directly.

# Approach
1. Initialize two empty strings, `w1` and `w2`.
2. Iterate through each string in `word1`, and for each string, iterate through its characters, appending each character to `w1`.
3. Repeat the same process for `word2`, appending all characters to `w2`.
4. Compare `w1` and `w2` using the equality operator.

### Visual Trace (Example 1)
`word1 = ["ab", "c"]`, `word2 = ["a", "bc"]`

| Step | Action | `w1` | `w2` |
| :--- | :--- | :--- | :--- |
| 1 | Process `word1[0]` ("ab") | "ab" | "" |
| 2 | Process `word1[1]` ("c") | "abc" | "" |
| 3 | Process `word2[0]` ("a") | "abc" | "a" |
| 4 | Process `word2[1]` ("bc") | "abc" | "abc" |
| 5 | Compare `w1 == w2` | Result: true | |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the total number of characters in `word1` and $$M$$ is the total number of characters in `word2$$. We visit each character exactly once to build the strings.
- Space complexity: $$O(N + M)$$ to store the concatenated strings `w1` and `w2`.

# Code
```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 = "";
        string w2 = "";
        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word1[i].size();j++){
                w1+= word1[i][j];
            }
        }
        for(int i=0;i<word2.size();i++){
            for(int j=0;j<word2[i].size();j++){
                w2+= word2[i][j];
            }
        }
        return w1 == w2 ;
    }
};
```
