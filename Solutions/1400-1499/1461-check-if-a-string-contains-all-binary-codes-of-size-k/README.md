# [1461. Check If a String Contains All Binary Codes of Size K](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `bit-manipulation`, `rolling-hash`, `hash-function`, `directed-acyclic-graph`

---

## Problem Description
Given a binary string `s` and an integer `k`, return `true` *if every binary code of length* `k` *is a substring of* `s`. Otherwise, return `false`.

**Example 1:**

```
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
```

**Example 2:**

```
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring.
```

**Example 3:**

```
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.
```

**Constraints:**

* `1 <= s.length <= 5 * 105`
* `s[i]` is either `'0'` or `'1'`.
* `1 <= k <= 20`

---

## Solution & Editorial
# Intuition
To determine if every binary code of length `k` exists in string `s`, we must identify all unique substrings of length `k`. Since there are exactly $2^k$ possible binary codes of length `k`, we can collect all unique substrings found in `s` using a hash set and check if the count reaches $2^k$.

# Approach
1. Calculate the total number of required binary codes, $m = 2^k$. If the string length $n$ is too short (specifically $n - k + 1 < m$), it is mathematically impossible to contain all $2^k$ unique codes, so we return `false` immediately.
2. Iterate through the string `s` using a sliding window of size `k`. For each starting position `i` from `0` to `n - k`, extract the substring of length `k`.
3. Insert each extracted substring into an `unordered_set<string>`. The set automatically handles duplicates.
4. After the loop, compare the size of the set with $m$. If `ss.size() == m`, all codes are present.

### Visual Trace (s = "00110", k = 2)
- $m = 2^2 = 4$. $n = 5$. $5 - 2 + 1 = 4 \ge 4$ (Proceed).
- $i=0$: substring "00", set = {"00"}
- $i=1$: substring "01", set = {"00", "01"}
- $i=2$: substring "11", set = {"00", "01", "11"}
- $i=3$: substring "10", set = {"00", "01", "11", "10"}
- Final size = 4. Return `true`.

# Complexity
- Time complexity: $$O(N \cdot K)$$, where $N$ is the length of string $s$. We iterate through the string once, and each substring extraction and hash set insertion takes $O(K)$ time.
- Space complexity: $$O(2^K \cdot K)$$, as the hash set stores at most $2^k$ unique strings, each of length $K$.

# Code
```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int m = 1 << k;
        if (n - k + 1 < m) {
            return false;
        }
        unordered_set<string> ss;
        for (int i = 0; i + k <= n; ++i) {
            ss.insert(move(s.substr(i, k)));
        }
        return ss.size() == m;
    }
};
```
