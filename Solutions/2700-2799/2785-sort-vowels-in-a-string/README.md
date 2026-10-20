# [2785. Sort Vowels in a String](https://leetcode.com/problems/sort-vowels-in-a-string/)
**Difficulty:** `Medium` | **Tags:** `string`, `sorting`

---

## Problem Description
Given a **0-indexed** string `s`, **permute** `s` to get a new string `t` such that:

* All consonants remain in their original places. More formally, if there is an index `i` with `0 <= i < s.length` such that `s[i]` is a consonant, then `t[i] = s[i]`.
* The vowels must be sorted in the **nondecreasing** order of their **ASCII** values. More formally, for pairs of indices `i`, `j` with `0 <= i < j < s.length` such that `s[i]` and `s[j]` are vowels, then `t[i]` must not have a higher ASCII value than `t[j]`.

Return *the resulting string*.

The vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`, and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

**Example 1:**

```
Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
```

**Example 2:**

```
Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists only of letters of the English alphabet in **uppercase and lowercase**.

---

## Solution & Editorial
# Intuition
The problem requires us to keep consonants in their original positions while permuting only the vowels in non-decreasing ASCII order. Since the relative order of consonants is fixed, we can extract all vowels, sort them, and then re-insert them into the original string at the positions where vowels were previously found.

# Approach
1. Define a helper function `checkVowel` to identify if a character is a vowel ('a', 'e', 'i', 'o', 'u' in both cases).
2. Iterate through the input string `s` and collect all characters that satisfy `checkVowel` into a dynamic array `vow`.
3. Sort the `vow` array using `std::sort`. This ensures the vowels are in non-decreasing ASCII order.
4. Iterate through the original string `s` again. Whenever a vowel position is encountered, replace the character with the next element from the sorted `vow` array using an index pointer `idx`.

### Visual Trace (Example 1: "lEetcOde")
- **Step 1 (Extraction)**: `vow` = ['E', 'O', 'e']
- **Step 2 (Sorting)**: `vow` = ['E', 'O', 'e'] (ASCII: 'E'=69, 'O'=79, 'e'=101)
- **Step 3 (Reconstruction)**:
  - Index 1 ('E'): Replace with `vow[0]` ('E')
  - Index 4 ('O'): Replace with `vow[1]` ('O')
  - Index 7 ('e'): Replace with `vow[2]` ('e')
- **Result**: "lEOtcede"

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the length of the string. The sorting of the extracted vowels takes $$O(V \log V)$$ where $$V \le N$$, and the two passes over the string take $$O(N)$$.
- Space complexity: $$O(N)$$, required to store the extracted vowels in the `vow` vector.

# Code
```cpp
class Solution {
public:
    bool checkVowel(char ch){
        char vowel[10]= {'a','e','i','o','u','A','E','I','O','U'};
        for(char c:vowel){
            if(c==ch) return true;
        }
        return false;
    }

    string sortVowels(string s) {
        vector<char> vow;
        for(char c:s){
            if(checkVowel(c)) vow.push_back(c);
        }
        sort(vow.begin(),vow.end());
        int idx = 0;
        for(char &c:s){
            if(checkVowel(c)){
                c = vow[idx++];
            }
        }
        return s;
    }
};
```
