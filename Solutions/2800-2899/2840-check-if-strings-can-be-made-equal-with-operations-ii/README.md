# [2840. Check if Strings Can be Made Equal With Operations II](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `sorting`

---

## Problem Description
You are given two strings `s1` and `s2`, both of length `n`, consisting of **lowercase** English letters.

You can apply the following operation on **any** of the two strings **any** number of times:

* Choose any two indices `i` and `j` such that `i < j` and the difference `j - i` is **even**, then **swap** the two characters at those indices in the string.

Return `true` *if you can make the strings* `s1` *and* `s2` *equal, and*`false` *otherwise*.

**Example 1:**

```
Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
```

**Example 2:**

```
Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.
```

**Constraints:**

* `n == s1.length == s2.length`
* `1 <= n <= 105`
* `s1` and `s2` consist only of lowercase English letters.

---

## Solution & Editorial
# Intuition
The operation allows us to swap any two characters at indices `i` and `j` if `j - i` is even. This implies that characters at even indices can be freely rearranged among themselves, and characters at odd indices can be freely rearranged among themselves. The two sets of indices (even and odd) are completely independent.

# Approach
1. Since the sets of even-indexed and odd-indexed characters are independent, we can simply count the frequency of each character ('a'-'z') for both even and odd positions in both strings.
2. We maintain a 2D frequency array `cnt[2][26]`, where `cnt[0]` stores frequencies for even indices and `cnt[1]` for odd indices.
3. Iterate through the strings: increment the count for `s1` and decrement for `s2` based on the index parity.
4. If the strings can be made equal, the net frequency for every character at both even and odd positions must be zero.

### Visual Trace (Example 1: s1 = "abcdba", s2 = "cabdab")
| Index | s1[i] | Parity | s2[i] | Parity |
| :--- | :--- | :--- | :--- | :--- |
| 0 | a | 0 | c | 0 |
| 1 | b | 1 | a | 1 |
| 2 | c | 0 | b | 0 |
| 3 | d | 1 | d | 1 |
| 4 | b | 0 | a | 0 |
| 5 | a | 1 | b | 1 |

- Even indices (0, 2, 4): s1 has {a:1, c:1, b:1}, s2 has {c:1, b:1, a:1}. Match!
- Odd indices (1, 3, 5): s1 has {b:1, d:1, a:1}, s2 has {a:1, d:1, b:1}. Match!

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the strings, as we perform a single pass over the strings and a constant-time check over the alphabet size (26).
- Space complexity: $$O(1)$$, as the frequency array size is fixed at $$2 \times 26$$, which is constant regardless of input size.

# Code
```cpp
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> cnt(2, vector<int>(26, 0));
        for (int i = 0; i < s1.size(); ++i) {
            ++cnt[i & 1][s1[i] - 'a'];
            --cnt[i & 1][s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] || cnt[1][i]) {
                return false;
            }
        }
        return true;
    }
};
```
