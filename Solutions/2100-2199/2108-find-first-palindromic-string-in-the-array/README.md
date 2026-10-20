# [2108. Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`, `string`

---

## Problem Description
Given an array of strings `words`, return *the first **palindromic** string in the array*. If there is no such string, return *an **empty string*** `""`.

A string is **palindromic** if it reads the same forward and backward.

**Example 1:**

```
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
```

**Example 2:**

```
Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
```

**Example 3:**

```
Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
```

**Constraints:**

* `1 <= words.length <= 100`
* `1 <= words[i].length <= 100`
* `words[i]` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
To identify the first palindromic string, we must iterate through the array sequentially and verify each string's symmetry. A string is a palindrome if it reads identically from both ends, which can be efficiently verified using a two-pointer approach.

# Approach
1. Iterate through each string `word` in the `words` vector.
2. For each `word`, define two pointers: `l` starting at index 0 and `r` starting at the last index (`word.size() - 1`).
3. Compare characters at `word[l]` and `word[r]`. If they differ, the string is not a palindrome. If they match, increment `l` and decrement `r` until the pointers meet or cross.
4. Return the first string that satisfies the palindrome condition. If the loop completes without finding one, return an empty string.

### Visual Trace (Example 1: "abc", "car", "ada")
| Word | Pointers (l, r) | Comparison | Result |
| :--- | :--- | :--- | :--- |
| "abc" | (0, 2) | 'a' != 'c' | False |
| "car" | (0, 2) | 'c' != 'r' | False |
| "ada" | (0, 2) | 'a' == 'a' | Continue |
| "ada" | (1, 1) | l < r is false | True (Return "ada") |

# Complexity
- Time complexity: $$O(N \times M)$$, where $$N$$ is the number of strings and $$M$$ is the maximum length of a string. We visit each string at most once and perform a linear scan of its characters.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for pointer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    bool helper(string word){
        int m = word.size();
        int l = 0;
        int r = m-1;
        while(l<r){
            if(word[l]!= word[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(auto word : words){
            if(helper(word)) return word;
        }
        return "";
    }
};
```
