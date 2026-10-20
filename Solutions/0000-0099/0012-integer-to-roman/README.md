# [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `math`, `string`

---

## Problem Description
Seven different symbols represent Roman numerals with the following values:

| Symbol | Value |
| --- | --- |
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

* If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
* If the value starts with 4 or 9 use the **subtractive form** representing one symbol subtracted from the following symbol, for example, 4 is 1 (`I`) less than 5 (`V`): `IV` and 9 is 1 (`I`) less than 10 (`X`): `IX`. Only the following subtractive forms are used: 4 (`IV`), 9 (`IX`), 40 (`XL`), 90 (`XC`), 400 (`CD`) and 900 (`CM`).
* Only powers of 10 (`I`, `X`, `C`, `M`) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (`V`), 50 (`L`), or 500 (`D`) multiple times. If you need to append a symbol 4 times use the **subtractive form**.

Given an integer, convert it to a Roman numeral.

**Example 1:**

**Input:** num = 3749

**Output:** "MMMDCCXLIX"

**Explanation:**

```
3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
```

**Example 2:**

**Input:** num = 58

**Output:** "LVIII"

**Explanation:**

```
50 = L
 8 = VIII
```

**Example 3:**

**Input:** num = 1994

**Output:** "MCMXCIV"

**Explanation:**

```
1000 = M
 900 = CM
  90 = XC
   4 = IV
```

**Constraints:**

* `1 <= num <= 3999`

---

## Solution & Editorial
# Intuition
The problem requires converting a standard integer into its Roman numeral representation. Since Roman numerals are constructed from highest to lowest value—incorporating standard symbols as well as subtractive combinations like 400 (CD) and 90 (XC)—a greedy approach that processes values in descending order naturally constructs the correct result string.

# Approach
1. Define two parallel arrays: `symb` containing the Roman numeral string representations and `roman` containing their corresponding integer values in descending order from 1000 down to 1.
2. Initialize an empty result string `ans`.
3. Iterate through each element in the `roman` array using a loop variable `i`.
4. While the remaining `num` is greater than or equal to `roman[i]`, subtract `roman[i]` from `num` and append `symb[i]` to `ans`.
5. Return the accumulated string `ans` once `num` is reduced to 0.

### Visual Walkthrough for Example 1 (`num = 3749`)
| Iteration `i` | `roman[i]` | `symb[i]` | Action on `num` | `ans` appended | Remaining `num` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 1000 | "M" | Subtract 1000 (3 times) | "MMM" | 749 |
| 1 | 900 | "CM" | 749 < 900 (No-op) | "MMM" | 749 |
| 2 | 500 | "D" | Subtract 500 (1 time) | "MMMD" | 249 |
| 4 | 100 | "C" | Subtract 100 (2 times) | "MMMDCC" | 49 |
| 7 | 40 | "XL" | Subtract 40 (1 time) | "MMMDCCXL" | 9 |
| 9 | 9 | "IX" | Subtract 9 (1 time) | "MMMDCCXLIX" | 0 |

# Complexity
- Time complexity: $$O(1)$$ — The maximum input value is 3999, meaning the outer loop runs a fixed number of times (13 elements), and the inner `while` loop executes at most a constant number of times (at most 3 for 'M', etc.). Thus, the time complexity is strictly bounded by a constant.
- Space complexity: $$O(1)$$ — The space required is proportional to the size of the result string, which can have a maximum length of 15 characters (for "MMMDCCCLXXXXVIIII"). Auxiliary vectors take fixed constant space.

# Code
```cpp
class Solution {
public:
    string intToRoman(int num) {
        vector<string> symb = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> roman = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        for (int i = 0; i < symb.size(); ++i) {
            while (num >= roman[i]) {
                num -= roman[i];
                ans += symb[i];
            }
        }
        return ans;
    } 
};
```
