# [125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`

---

## Problem Description
A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` *if it is a **palindrome**, or* `false` *otherwise*.

**Example 1:**

```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

**Example 2:**

```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

**Example 3:**

```
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
```

**Constraints:**

* `1 <= s.length <= 2 * 105`
* `s` consists only of printable ASCII characters.

---

## Solution & Editorial
# Intuition
The problem requires us to determine if a string is a palindrome after ignoring non-alphanumeric characters and case differences. Instead of allocating extra memory to store a cleaned string, we can use two pointers moving inward from both ends of the string. This allows us to validate the palindrome property in-place with optimal time and constant space complexity.

# Approach
1. Initialize two pointers: `i` at the beginning of the string (`0`) and `j` at the end of the string (`s.size() - 1`).
2. Run a `while` loop as long as `i < j`.
3. If the character at `s[i]` is not alphanumeric using `isalnum`, increment `i` to skip it.
4. If the character at `s[j]` is not alphanumeric using `isalnum`, decrement `j` to skip it.
5. If both characters are alphanumeric, compare their lowercase forms using `tolower`. If they do not match, immediately return `false`.
6. If they match, increment `i` and decrement `j` to continue checking the next pair.
7. If the loop completes without mismatches, return `true`.

### Visual Walkthrough for Example 1
`s = "A man, a plan, a canal: Panama"`

| Step | `i` | `j` | `s[i]` | `s[j]` | Action / Description |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 30 | 'A' | 'a' | Alphanumeric match (ignoring case). Both pointers advance. (`i=1`, `j=29`) |
| 2 | 1 | 29 | ' ' | 'm' | `s[i]` is non-alphanumeric. Increment `i`. (`i=2`, `j=29`) |
| 3 | 2 | 29 | 'm' | 'm' | Alphanumeric match. Both pointers advance. (`i=3`, `j=28`) |
| ... | ... | ... | ... | ... | Processing remaining characters... |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string `s`. Each character is visited at most once by either pointer `i` or pointer `j`.
- Space complexity: $$O(1)$$, as we only use two integer pointers without allocating any auxiliary data structures.

# Code
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            } else if (!isalnum(s[j])) {
                --j;
            } else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};
```
