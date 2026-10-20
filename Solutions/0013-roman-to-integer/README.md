# [13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `math`, `string`

---

## Problem Description
Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

* `I` can be placed before `V` (5) and `X` (10) to make 4 and 9.
* `X` can be placed before `L` (50) and `C` (100) to make 40 and 90.
* `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

**Example 1:**

```
Input: s = "III"
Output: 3
Explanation: III = 3.
```

**Example 2:**

```
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
```

**Example 3:**

```
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

**Constraints:**

* `1 <= s.length <= 15`
* `s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.
* It is **guaranteed** that `s` is a valid roman numeral in the range `[1, 3999]`.

---

## Solution & Editorial
# Intuition
Normally, Roman numerals are written from largest to smallest from left to right, meaning we simply add their values. However, when a smaller value appears before a larger value (like `IV` or `IX`), it indicates subtraction. By inspecting adjacent characters, we can instantly determine whether to add or subtract the current symbol's value.

# Approach
1. Initialize a hash map `d` to map each Roman numeral character (`I`, `V`, `X`, `L`, `C`, `D`, `M`) to its respective integer value.
2. Initialize the result variable `ans` with the value of the last character in the string `s`.
3. Iterate from the beginning of the string up to the second-to-last character (`i` from `0` to `s.length() - 2`).
4. For each character at index `i`, compare its value with the next character at `i + 1`. If `d[s[i]] < d[s[i + 1]]`, subtract its value; otherwise, add its value to `ans`.
5. Return the accumulated integer `ans`.

### Visual Trace (Example 3: `s = "MCMXCIV"`)
- Initial `ans = d['V'] = 5`
- `i = 0 ('M')`: `d['M'] (1000) >= d['C'] (100)` -> `ans += 1000` (ans = 1005)
- `i = 1 ('C')`: `d['C'] (100) < d['M'] (1000)` -> `ans -= 100` (ans = 905)
- `i = 2 ('M')`: `d['M'] (1000) >= d['X'] (10)` -> `ans += 1000` (ans = 1905)
- `i = 3 ('X')`: `d['X'] (10) < d['C'] (100)` -> `ans -= 10` (ans = 1895)
- `i = 4 ('C')`: `d['C'] (100) >= d['I'] (1)` -> `ans += 100` (ans = 1995)
- `i = 5 ('I')`: `d['I'] (1) < d['V'] (5)` -> `ans -= 1` (ans = 1994)
- Loop terminates. Final result: `1994`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string `s`. We perform a single pass over the string of maximum length 15.
- Space complexity: $$O(1)$$, as the hash map size is fixed at 7 entries regardless of the input string length.

# Code
```cpp
/**
 * @param {string} s
 * @return {number}
 */
const romanToInt = function (s) {
    const d = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };
    let ans = d[s[s.length - 1]];
    for (let i = 0; i < s.length - 1; ++i) {
        const sign = d[s[i]] < d[s[i + 1]] ? -1 : 1;
        ans += sign * d[s[i]];
    }
    return ans;
};
```
