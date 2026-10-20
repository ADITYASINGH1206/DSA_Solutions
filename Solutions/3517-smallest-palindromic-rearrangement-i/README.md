# [3517. Smallest Palindromic Rearrangement I](https://leetcode.com/problems/smallest-palindromic-rearrangement-i/)
**Difficulty:** `Medium` | **Tags:** `string`, `sorting`, `counting-sort`

---

## Problem Description
You are given a **palindromic** string `s`.

Return the **lexicographically smallest** palindromic permutation of `s`.

**Example 1:**

**Input:** s = "z"

**Output:** "z"

**Explanation:**

A string of only one character is already the lexicographically smallest palindrome.

**Example 2:**

**Input:** s = "babab"

**Output:** "abbba"

**Explanation:**

Rearranging `"babab"` → `"abbba"` gives the smallest lexicographic palindrome.

**Example 3:**

**Input:** s = "daccad"

**Output:** "acddca"

**Explanation:**

Rearranging `"daccad"` → `"acddca"` gives the smallest lexicographic palindrome.

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of lowercase English letters.
* `s` is guaranteed to be palindromic.

---

## Solution & Editorial
# Intuition
To form the lexicographically smallest palindrome, we must place the smallest available characters at the outermost positions (the beginning and the end of the string). Since a palindrome is symmetric, every character count must be halved to fill the left and right halves, with any remaining odd-count character placed in the center.

# Approach
1. Count the frequency of each character in the input string `s` using a frequency array of size 26.
2. Initialize an empty string `ans` of the same length as `s`.
3. Iterate through the frequency array from 'a' to 'z'. For each character, while its frequency is at least 2, place it at the current `left` and `right` pointers, then decrement the frequency by 2 and move the pointers inward.
4. If a character has a frequency of 1 remaining, place it at the exact middle index (`s.size() / 2`) of the `ans` string.

### Visual Trace (s = "daccad")
- Frequencies: {a: 2, c: 2, d: 2}
- Iteration 1 ('a'): freq[0]=2. `ans[0]='a'`, `ans[5]='a'`, `left=1`, `right=4`.
- Iteration 2 ('c'): freq[2]=2. `ans[1]='c'`, `ans[4]='c'`, `left=2`, `right=3`.
- Iteration 3 ('d'): freq[3]=2. `ans[2]='d'`, `ans[3]='d'`, `left=3`, `right=2`.
- Result: "acddca"

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We iterate through the string once to count frequencies and then iterate through the frequency array (constant 26) to construct the result.
- Space complexity: $$O(1)$$, as the frequency array is of fixed size 26, regardless of the input size.

# Code
```cpp
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        int n = s.size();
        string ans(n, ' ');

        int left = 0, right = n - 1;

        for (int i = 0; i < 26; i++) {
            while (freq[i] >= 2) {
                ans[left++] = char('a' + i);
                ans[right--] = char('a' + i);
                freq[i] -= 2;
            }

            if (freq[i] == 1) {
                ans[s.size() / 2] = char('a' + i);
            }
        }

        return ans;
    }
};
```
