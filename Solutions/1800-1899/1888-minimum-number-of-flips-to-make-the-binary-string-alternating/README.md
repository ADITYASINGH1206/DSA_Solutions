# [1888. Minimum Number of Flips to Make the Binary String Alternating](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`, `sliding-window`

---

## Problem Description
You are given a binary string `s`. You are allowed to perform two types of operations on the string in any sequence:

* **Type-1: Remove** the character at the start of the string `s` and **append** it to the end of the string.
* **Type-2: Pick** any character in `s` and **flip** its value, i.e., if its value is `'0'` it becomes `'1'` and vice-versa.

Return *the **minimum** number of **type-2** operations you need to perform* *such that* `s` *becomes **alternating**.*

The string is called **alternating** if no two adjacent characters are equal.

* For example, the strings `"010"` and `"1010"` are alternating, while the string `"0100"` is not.

**Example 1:**

```
Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
```

**Example 2:**

```
Input: s = "010"
Output: 0
Explanation: The string is already alternating.
```

**Example 3:**

```
Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".
```

**Constraints:**

* `1 <= s.length <= 105`
* `s[i]` is either `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
To make a binary string alternating, it must follow one of two patterns: "0101..." or "1010...". Type-1 operations (cyclic shifts) effectively allow us to view the string as a circular buffer. By concatenating the string with itself (s + s), any cyclic shift of length N corresponds to a sliding window of size N.

# Approach
1. Define two target patterns: one starting with '0' (0101...) and one starting with '1' (1010...). Note that the number of flips needed for the second pattern is simply (N - flips for the first pattern).
2. Use a sliding window of size N over the string `s + s`. 
3. Maintain the count of mismatches between the current window and the target pattern "0101...".
4. As the window slides: 
   - Remove the influence of the character leaving the window.
   - Add the influence of the character entering the window.
   - Update the minimum flips required, considering both the "0101..." pattern and its inverse "1010...".

### Visual Trace (s = "111000", N=6)
| Window | Mismatches (vs 010101) | Flips (min(cnt, N-cnt)) |
| :--- | :--- | :--- |
| 111000 | 4 | min(4, 2) = 2 |
| 110001 | 3 | min(3, 3) = 3 |
| 100011 | 2 | min(2, 4) = 2 |

# Complexity
- Time complexity: $$O(N)$$, where N is the length of the string. We perform a single pass to initialize the window and a second pass to slide it across the string.
- Space complexity: $$O(1)$$, as we only store a few integer counters regardless of the input size (the string itself is not explicitly duplicated in memory).

# Code
```cpp
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string target = "01";
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i & 1]) {
                ++cnt;
            }
        }
        int ans = min(cnt, n - cnt);
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i & 1]) {
                --cnt;
            }
            if (s[i] != target[(i + n) & 1]) {
                ++cnt;
            }
            ans = min({ans, cnt, n - cnt});
        }
        return ans;
    }
};
```
