# [4021. Minimum Operations to Make a Rotated Palindrome I](https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/)
**Difficulty:** `Medium` | **Tags:** `math`, `string`, `enumeration`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters.

You can perform the following operations any number of times (including zero) and in any order:

* **Increment**: Choose any index `i` and replace `s[i]` with the next lowercase English letter. The letter after `'z'` is `'a'`.
* **Left rotate**: Move the first character of the string to the end.

Return the **minimum** number of operations required to make `s` a palindrome.

**Example 1:**

**Input:** s = "abc"

**Output:** 2

**Explanation:**

One optimal solution:

* Left rotate the string: `"abc" -> "bca"`.
* Increment `'a'` to `'b'`: `"bca" -> "bcb"`.
* `"bcb"` is a palindrome. Thus, the answer is 2.

**Example 2:**

**Input:** s = "yb"

**Output:** 3

**Explanation:**

* Increment the first character three times: `"yb" -> "zb" -> "ab" -> "bb"`.
* `"bb"` is a palindrome. Thus, the answer is 3.

**Constraints:**

* `2 <= s.length <= 2000`
* `s` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem allows for two operations: cyclic rotation and character increment. Since the string length is small ($N \le 2000$), we can iterate through all possible cyclic rotations of the string. For each rotation, the cost to make it a palindrome is the sum of the minimum character distances between symmetric positions $i$ and $N-1-i$. The minimum distance between two characters $a$ and $b$ is $\min(|a-b|, 26-|a-b|)$, accounting for the cyclic nature of the alphabet.

# Approach
1. Concatenate the string `s` with itself (`doubled = s + s`) to easily access any cyclic rotation of length $N$ using a sliding window starting at index $k$ (where $0 \le k < N$).
2. For each starting index $k$, calculate the cost to transform the substring `doubled[k...k+n-1]` into a palindrome:
   - Initialize `cur = k` (the cost of $k$ left rotations).
   - Use two pointers, `left` starting at $k$ and `right` at $k+n-1$.
   - While `left < right`, calculate the cost to make `doubled[left]` and `doubled[right]` equal: `min(diff, 26 - diff)` where `diff = abs(doubled[left] - doubled[right])`.
   - Add this cost to `cur` and move pointers inward.
3. Track the minimum `cur` across all $k$.

### Visual Trace (s = "abc")
- $N=3$, `doubled` = "abcabc"
- $k=0$ (string "abc"): cost = $0 + \min(|'a'-'c'|, 26-2) = 2$. Total = 2.
- $k=1$ (string "bca"): cost = $1 + \min(|'b'-'a'|, 26-1) = 1 + 1 = 2$. Total = 2.
- $k=2$ (string "cab"): cost = $2 + \min(|'c'-'b'|, 26-1) = 2 + 1 = 3$. Total = 3.
- Min is 2.

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the length of the string. We iterate $N$ possible rotations, and for each, we perform $O(N)$ work to compute the palindrome cost.
- Space complexity: $$O(N)$$ to store the doubled string.

# Code
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length(); 
        
        int ans = INT_MAX;
        string doubled = s + s;
        
        for (int k = 0; k < n; ++k) {
            int cur = k;
            int left = k;
            int right = k + n - 1;
            while (left < right) {
                int diff = abs(doubled[left] - doubled[right]);
                cur += min(diff, 26 - diff);
                left++;
                right--;
            }
            if (cur < ans) {
                ans = cur;
            }
        }
        
        return ans;
    }
};
```
