# [1768. Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`

---

## Problem Description
You are given two strings `word1` and `word2`. Merge the strings by adding letters in alternating order, starting with `word1`. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return *the merged string.*

**Example 1:**

```

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
```

**Example 2:**

```

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
```

**Example 3:**

```

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
```

**Constraints:**

* `1 <= word1.length, word2.length <= 100`
* `word1` and `word2` consist of lowercase English letters.

---

## Solution & Editorial
# Intuition
To merge two strings alternately, we can maintain two pointers representing the current index in each string. By iterating through both strings simultaneously until one is exhausted, we can build the result string character by character.

# Approach
1. Initialize two pointers `l` and `r` to 0, representing the indices for `word1` and `word2` respectively.
2. Use a `while` loop to append characters from `word1` and `word2` alternately as long as both pointers are within their respective string bounds.
3. After the loop, one string might still have remaining characters. Use two separate `while` loops to append the remaining suffix of either `word1` or `word2` to the result string `ans`.

### Visual Trace (Example 1: word1="abc", word2="pqr")
| Iteration | l | r | ans (current) | Action |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 0 | 0 | "" | Append word1[0], word2[0] |
| 1 | 1 | 1 | "ap" | Append word1[1], word2[1] |
| 2 | 2 | 2 | "apbq" | Append word1[2], word2[2] |
| End | 3 | 3 | "apbqcr" | Loop terminates |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the lengths of `word1` and `word2`. We traverse each string exactly once.
- Space complexity: $$O(N + M)$$ to store the resulting merged string.

# Code
```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int l = 0;
        int r = 0;
        int m = word1.size();
        int n = word2.size();
        while(l<=r && l < m && r < n){
            ans += word1[l];
            ans += word2[r];
            l++;
            r++;
        }
        while(l < m){
            ans += word1[l];
            l++;
        }
        while(r < n){
            ans+= word2[r];
            r++;
        }

        return ans;
    }
};
```
