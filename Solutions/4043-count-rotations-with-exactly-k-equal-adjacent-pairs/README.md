# [4043. Count Rotations With Exactly K Equal Adjacent Pairs](https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/)
**Difficulty:** `Easy` | **Tags:** `string`, `sliding-window`, `enumeration`

---

## Problem Description
You are given a string `s` of length `n` and an integer `k`.

A **cyclic rotation** of `s` is obtained by choosing a prefix of `s` whose length is between 0 and `n - 1` (inclusive), and moving it to the end of the string while preserving the order of all characters.

For **every** cyclic rotation of `s`, let its **score** be the number of indices `i` such that `0 <= i < n - 1` and the characters at positions `i` and `i + 1` are equal.

Return the number of cyclic rotations of `s` whose score equals `k`.

**Example 1:**

**Input:** s = "aab", k = 1

**Output:** 2

**Explanation:**

The cyclic rotations of `s` are:

* `"aab"`: The characters at positions 0 and 1 are equal, so `score = 1`.
* `"aba"`: No two adjacent characters are equal, so `score = 0`.
* `"baa"`: The characters at positions 1 and 2 are equal, so `score = 1`.

Since `score` equals `k` for 2 cyclic rotations of `s`, the answer is 2.

**Example 2:**

**Input:** s = "abca", k = 0

**Output:** 1

**Explanation:**

The cyclic rotations of `s` are:

* `"abca"`: No two adjacent characters are equal, so `score = 0`.
* `"bcaa"`: The characters at positions 2 and 3 are equal, so `score = 1`.
* `"caab"`: The characters at positions 1 and 2 are equal, so `score = 1`.
* `"aabc"`: The characters at positions 0 and 1 are equal, so `score = 1`.

Since `score` equals `k` for only 1 cyclic rotation of `s`, the answer is 1.

**Constraints:**

* `2 <= n == s.length <= 100`
* `s` only consists of lowercase English letters.
* `0 <= k <= n - 1`

---

## Solution & Editorial
# Intuition
To solve this problem efficiently, we observe that a cyclic rotation shifts the string by one position. Instead of generating every rotation (which would be $O(N^2)$), we can analyze the total number of adjacent equal pairs in the circular string. Let $P$ be the number of adjacent equal pairs in the circular string (where index $n-1$ is adjacent to $0$). When we perform a cyclic shift, we essentially "break" one existing adjacent pair and "form" a new one, unless the characters at the boundary are identical.

# Approach
1. Calculate the total number of adjacent equal pairs in the circular string, `pairs`. This includes all $i$ from $0$ to $n-2$ where $s[i] == s[i+1]$, plus the check for $s[n-1] == s[0]$.
2. A cyclic rotation effectively moves the boundary. If we rotate the string, the number of adjacent equal pairs changes based on whether the characters at the cut point were equal.
3. Specifically, if the total circular pairs is `pairs`, any rotation will result in a score of either `pairs` or `pairs - 1` (if the boundary was an equal pair) or `pairs` (if it wasn't). 
4. The logic simplifies to: if the total circular pairs equals $k$, there are $n - pairs$ rotations with score $k$. If the total circular pairs is $k+1$, there are $pairs$ rotations with score $k$. Otherwise, the answer is 0.

### Visual Trace (s = "aab", k = 1)
- Circular pairs: (a,a) at index 0,1; (a,b) at 1,2; (b,a) at 2,0. Total `pairs` = 1.
- Since `pairs == k` (1 == 1), result is $n - pairs = 3 - 1 = 2$.

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the length of the string, as we iterate through the string once to count pairs.
- Space complexity: $$O(1)$$ as we only use a few integer variables.

# Code
```cpp
class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int pairs=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                pairs++;
            }
        }
        if(s[n-1]==s[0]){
            pairs++;
        }
        if(pairs==k){
            return n-pairs;
        }
        return pairs==k+1?pairs:0;
    }
};
```
