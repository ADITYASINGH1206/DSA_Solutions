# [168. Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`

---

## Problem Description
Given an integer `columnNumber`, return *its corresponding column title as it appears in an Excel sheet*.

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
Input: columnNumber = 1
Output: "A"
```

**Example 2:**

```
Input: columnNumber = 28
Output: "AB"
```

**Example 3:**

```
Input: columnNumber = 701
Output: "ZY"
```

**Constraints:**

* `1 <= columnNumber <= 231 - 1`

---

## Solution & Editorial
# Intuition
This problem asks us to convert a 1-indexed decimal number into a 26-base system corresponding to Excel column titles (A = 1, B = 2, ..., Z = 26). Because indexing starts at 1 instead of 0, standard modulo operations do not map directly without adjustment.

# Approach
1. Initialize an empty string `ans` to accumulate characters.
2. Run a `while` loop as long as `columnNumber > 0`.
3. Decrement `columnNumber` by 1 at the start of each iteration to shift the 1-indexed range to a 0-indexed range (0 corresponds to 'A').
4. Compute the current character using `columnNumber % 26` offset from `'A'` and append it to `ans`.
5. Divide `columnNumber` by 26 to move to the next higher significance digit.
6. Finally, reverse the accumulated string `ans` because we generate characters from least significant to most significant digit, and return it.

### Visual Trace Walkthrough (Example 2: columnNumber = 28)
- Initial: `columnNumber = 28`, `ans = ""`
- Iteration 1:
  - `columnNumber` becomes `27`
  - `ch = 'A' + (27 % 26) = 'A' + 1 = 'B'`
  - `ans = "B"`
  - `columnNumber` becomes `27 / 26 = 1`
- Iteration 2:
  - `columnNumber` becomes `0`
  - `ch = 'A' + (0 % 26) = 'A' + 0 = 'A'`
  - `ans = "BA"`
  - `columnNumber` becomes `0 / 26 = 0`
- Loop terminates.
- Reverse `ans`: `"BA"` becomes `"AB"`.

# Complexity
- Time complexity: $$O(\log_{26} N)$$ — In each iteration, `columnNumber` is divided by 26, meaning the loop runs proportionally to the number of digits in base 26. Reversing the string takes time proportional to its length, which is also $$O(\log_{26} N)$$.
- Space complexity: $$O(1)$$ auxiliary space (excluding the output string storage).

# Code
```cpp
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber>0){
            columnNumber--;
            int ch = 'A'+columnNumber%26;
            ans+=ch;
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
```
