# [171. Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`

---

## Problem Description
Given a string `columnTitle` that represents the column title as appears in an Excel sheet, return *its corresponding column number*.

For example:

```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
```

**Example 1:**

```
Input: columnTitle = "A"
Output: 1
```

**Example 2:**

```
Input: columnTitle = "AB"
Output: 28
```

**Example 3:**

```
Input: columnTitle = "ZY"
Output: 701
```

**Constraints:**

* `1 <= columnTitle.length <= 7`
* `columnTitle` consists only of uppercase English letters.
* `columnTitle` is in the range `["A", "FXSHRXW"]`.

---

## Solution & Editorial
# Intuition
This problem can be modeled identically to converting a number from a custom base-26 positional numeral system to base-10. Each character in the `columnTitle` corresponds to a digit from 'A' (1) to 'Z' (26), where the position of each character dictates its power of 26, exactly like decimal places represent powers of 10.

# Approach
1. Initialize a result variable `ans` to `0` to accumulate the total column number.
2. Iterate through each character of `columnTitle` from left to right using a standard `for` loop.
3. In each iteration, multiply the current `ans` by `26` to shift the existing accumulated value one place to the left (higher base weight).
4. Convert the current character `columnTitle[i]` to its numeric value by taking `columnTitle[i] - 'A' + 1` and add it to `ans`.
5. Return `ans` after processing all characters.

### Visual Walkthrough for Example 2: `columnTitle = "AB"`

| Iteration | Character (`columnTitle[i]`) | Numeric Value (`c - 'A' + 1`) | Calculation (`ans = ans * 26 + value`) | Updated `ans` |
| :--- | :--- | :--- | :--- | :--- |
| 1 | `'A'` | $1 - 0 + 1 = 1$ | $0 \times 26 + 1$ | `1` |
| 2 | `'B'` | $2 - 1 + 1 = 2$ | $1 \times 26 + 2$ | `28` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `columnTitle`. We iterate through the string of length up to 7 exactly once, performing constant-time arithmetic operations per character.
- Space complexity: $$O(1)$$. Only a single integer variable `ans` is maintained regardless of input length.

# Code
```cpp
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0 ;
        for(int i = 0 ; i < columnTitle.size();i++){
            ans= ans*26+(columnTitle[i]-'A'+1);
        }
        return ans;
    }
};
```
