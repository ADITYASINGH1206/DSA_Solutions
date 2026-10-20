# [761. Special Binary String](https://leetcode.com/problems/special-binary-string/)
**Difficulty:** `Hard` | **Tags:** `string`, `divide-and-conquer`, `sorting`

---

## Problem Description
**Special binary strings** are binary strings with the following two properties:

* The number of `0`'s is equal to the number of `1`'s.
* Every prefix of the binary string has at least as many `1`'s as `0`'s.

You are given a **special binary** string `s`.

A move consists of choosing two consecutive, non-empty, special substrings of `s`, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

Return *the lexicographically largest resulting string possible after applying the mentioned operations on the string*.

**Example 1:**

```
Input: s = "11011000"
Output: "11100100"
Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
```

**Example 2:**

```
Input: s = "10"
Output: "10"
```

**Constraints:**

* `1 <= s.length <= 50`
* `s[i]` is either `'0'` or `'1'`.
* `s` is a special binary string.

---

## Solution & Editorial
# Intuition
Special binary strings are structurally identical to valid parenthesis strings (where '1' represents '(' and '0' represents ')'). The problem allows swapping adjacent special substrings, which is isomorphic to rearranging sub-trees in a tree or independent blocks at the same depth. To maximize the lexicographical order, we can decompose the string into its irreducible special components, recursively maximize each inner component, and then sort the resulting components in descending order.

# Approach
1. Iterate through the string `s` while maintaining a balance counter `cnt` ('1' adds +1, '0' adds -1).
2. Whenever `cnt` reaches 0, we have identified a primitive special substring spanning from index `j` to `i`.
3. Extract the inner substring from `j + 1` to `i - 1`, recursively call `makeLargestSpecial` on it, wrap it back with outer `'1'` and `'0'`, and push the resulting string into our vector `ans`.
4. Update `j = i + 1` to scan for the next primitive special substring.
5. Sort all collected components in `ans` in descending order using `greater<string>()` to ensure the lexicographically largest arrangement.
6. Concatenate all sorted components using `accumulate` and return the final string.

### Visual Walkthrough for Example 1: `s = "11011000"`
- Initial call `makeLargestSpecial("11011000")`:
  - Scans and finds first primitive special substring from index 0 to 7 (entire string because `cnt` hits 0 at the end).
  - Inner substring: `s.substr(1, 6)` -> `"101100"`.
  - Recursive call `makeLargestSpecial("101100")`:
    - Decomposes into two primitive blocks: `"10"` (indices 0..1) and `"1100"` (indices 2..5).
    - Recursively processes their inner contents (empty strings).
    - Collects `ans = {"10", "1100"}`.
    - Sorts descending: `ans = {"1100", "10"}`.
    - Concatenates to return `"110010"`.
  - Wraps with `'1'` and `'0'` to form `"11100100"`.

# Complexity
- Time complexity: $$O(N^2 \log N)$$ — In the worst case, splitting and string substring copies take $$O(N)$$ per level, with up to $$O(N)$$ recursion depth, and sorting at each level takes $$O(K \log K \cdot L)$$ where $K$ is the number of blocks and $L$ is their length.
- Space complexity: $$O(N^2)$$ — Required for storing substring copies across recursion stack frames and auxiliary vector containers.

# Code
```cpp
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s == "") return s;
        vector<string> ans;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                ans.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(ans.begin(), ans.end(), greater<string>{});
        return accumulate(ans.begin(), ans.end(), ""s);
    }
};
```
