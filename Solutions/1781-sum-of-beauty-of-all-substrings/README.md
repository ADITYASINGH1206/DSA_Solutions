# [1781. Sum of Beauty of All Substrings](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `counting`

---

## Problem Description
The **beauty** of a string is the difference in frequencies between the most frequent and least frequent characters.

* For example, the beauty of `"abaacc"` is `3 - 1 = 2`.

Given a string `s`, return *the sum of **beauty** of all of its substrings.*

**Example 1:**

```
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
```

**Example 2:**

```
Input: s = "aabcbaa"
Output: 17
```

**Constraints:**

* `1 <= s.length <= 500`
* `s` consists of only lowercase English letters.

---

## Solution & Editorial
# Intuition
The beauty of a string is defined by the difference between the maximum and minimum character frequencies. Since the constraints on the string length are small ($N \le 500$), we can iterate through all possible substrings, calculate the frequency of each character within those substrings, and compute the beauty directly.

# Approach
1. We use two nested loops to generate every possible substring of `s`. The outer loop `i` marks the start index, and the inner loop `len` determines the length of the substring.
2. For each substring, we call the `beauty` helper function.
3. Inside `beauty`, we maintain a frequency array of size 26 to count occurrences of each character 'a'-'z'.
4. We iterate through the frequency array to find the maximum and minimum non-zero frequencies, then return their difference.

### Visual Trace (Example 1: s = "aab")
| Substring | Freqs (a,b,c) | Max | Min | Beauty |
| :--- | :--- | :--- | :--- | :--- |
| "a" | {1,0,0} | 1 | 1 | 0 |
| "aa" | {2,0,0} | 2 | 2 | 0 |
| "aab" | {2,1,0} | 2 | 1 | 1 |

# Complexity
- Time complexity: $$O(N^3)$$. We have $O(N^2)$ substrings, and for each, we iterate over the string of length $O(N)$ to compute frequencies and then iterate over the constant size alphabet (26).
- Space complexity: $$O(1)$$. We only use a fixed-size array of 26 integers regardless of the input string size.

# Code
```cpp
class Solution {
public:
    int beauty(string s){
        vector<int> freq(26,0);
        for(char c :s){
            freq[c-'a']++;
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i =0 ;i<26;i++){
            if(freq[i]>maxi){
                maxi = freq[i];
            }
            if(freq[i] != 0 && freq[i] <  mini){
                mini = freq[i];
            }
        }
        return maxi-mini;
    }
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) {
                ans += beauty((s.substr(i, len)));
            }
        }
        return ans;
    }
};
```
