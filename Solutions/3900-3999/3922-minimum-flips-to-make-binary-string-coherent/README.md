# [3922. Minimum Flips to Make Binary String Coherent](https://leetcode.com/problems/minimum-flips-to-make-binary-string-coherent/)
**Difficulty:** `Medium` | **Tags:** `string`

---

## Problem Description
You are given a binary string `s`.

A string is considered **coherent** if it does **not** contain `"011"` or `"110"` as subsequences.

In one operation, you can **flip** any character in `s` (`'0'` to `'1'` or `'1'` to `'0'`).

Return an integer denoting the **minimum** number of operations required to make `s` coherent.

**Example 1:**

**Input:** s = "1010"

**Output:** 1

**Explanation:**

Flip `s[0]` to get `"0010"`, which contains no `"011"` or `"110"` subsequences.

**Example 2:**

**Input:** s = "0110"

**Output:** 1

**Explanation:**

Flip `s[1]` to get `"0010"`, removing all forbidden subsequences `"011"` and `"110"`.

**Example 3:**

**Input:** s = "1000"

**Output:** 0

**Explanation:**

The string already has no `"011"` or `"110"` subsequences, so no flips are needed.

**Constraints:**

* `1 <= s.length <= 105`
* `s[i]` is either `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
A string is coherent if it avoids "011" and "110" as subsequences. This implies that all '1's must be grouped together, or all '0's must be grouped together, or the string must follow a specific pattern where '1's are either at the very beginning or the very end of the string to avoid sandwiching them between '0's.

# Approach
1. The forbidden subsequences "011" and "110" essentially force the string to have a structure where '1's cannot be separated by '0's in a way that creates these patterns. 
2. We calculate the cost to transform the string into a state where all '1's are at the start, all '1's are at the end, or all '1's are removed.
3. We evaluate three primary strategies:
   - Make the string all '0's (cost = number of '1's).
   - Make the string all '1's (cost = number of '0's).
   - Keep '1's at the ends: Calculate the cost to flip all internal '1's to '0's and ensure the boundaries are handled correctly.

### Visual Trace (s = "1010")
- Total '1's = 2, Total '0's = 2.
- Strategy 1 (All '0's): 2 flips.
- Strategy 2 (All '1's): 2 flips.
- Strategy 3 (Ends): Flip internal '1's. Here, the '1' at index 2 is internal. Cost = 1.
- Result: min(2, 2, 1) = 1.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the string, as we perform a single pass to count '1's and a constant number of arithmetic operations.
- Space complexity: $$O(1)$$ as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if (n <= 2) return 0;
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }
        
        int ans = min(ones, n - ones); 
        if (ones > 0) {
            ans = min(ans, ones - 1); 
        } else {
            ans = min(ans, 1);
        }
        int mid_ones = ones;
        if (s[0] == '1') mid_ones--;
        if (s[n - 1] == '1') mid_ones--;
        int cost_ends = (s[0] == '0' ? 1 : 0) + (s[n - 1] == '0' ? 1 : 0) + mid_ones;
        
        ans = min(ans, cost_ends);
        
        return ans;
    }
};
```
