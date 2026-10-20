# [2839. Check if Strings Can be Made Equal With Operations I](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given two strings `s1` and `s2`, both of length `4`, consisting of **lowercase** English letters.

You can apply the following operation on any of the two strings **any** number of times:

* Choose any two indices `i` and `j` such that `j - i = 2`, then **swap** the two characters at those indices in the string.

Return `true` *if you can make the strings* `s1` *and* `s2` *equal, and* `false` *otherwise*.

**Example 1:**

```
Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: We can do the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
- Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.
```

**Example 2:**

```
Input: s1 = "abcd", s2 = "dacb"
Output: false
Explanation: It is not possible to make the two strings equal.
```

**Constraints:**

* `s1.length == s2.length == 4`
* `s1` and `s2` consist only of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem allows swapping characters at indices `i` and `j` if `j - i = 2`. This means characters at even indices (0, 2) can be swapped with each other, and characters at odd indices (1, 3) can be swapped with each other. Because these two sets of indices are independent, the strings can be made equal if and only if the multiset of characters at even positions in `s1` matches those in `s2`, and the same holds for odd positions.

# Approach
1. Since the string length is fixed at 4, we can track the frequency of characters based on their index parity (even vs. odd).
2. We use a 2D frequency array `cnt[2][26]`, where `cnt[0]` stores counts for even indices and `cnt[1]` for odd indices.
3. Iterate through the strings: increment counts for `s1` and decrement for `s2` based on index parity (`i & 1`).
4. If the strings can be made equal, the net count for every character at both parity levels must be zero.

### Visual Trace (Example 1: s1="abcd", s2="cdab")
| Index | s1[i] | s2[i] | Parity | Action |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 'a' | 'c' | 0 | cnt[0]['a']++, cnt[0]['c']-- |
| 1 | 'b' | 'd' | 1 | cnt[1]['b']++, cnt[1]['d']-- |
| 2 | 'c' | 'a' | 0 | cnt[0]['c']++, cnt[0]['a']-- |
| 3 | 'd' | 'b' | 1 | cnt[1]['d']++, cnt[1]['b']-- |

After processing, all `cnt[0]` and `cnt[1]` values are 0, returning `true`.

# Complexity
- Time complexity: $$O(1)$$. We perform a constant number of operations (length is fixed at 4).
- Space complexity: $$O(1)$$. The frequency array size is fixed at 2x26.

# Code
```cpp
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
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
