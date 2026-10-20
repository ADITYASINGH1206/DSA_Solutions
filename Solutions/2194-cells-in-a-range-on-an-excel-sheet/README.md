# [2194. Cells in a Range on an Excel Sheet](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
A cell `(r, c)` of an excel sheet is represented as a string `"<col><row>"` where:

* `<col>` denotes the column number `c` of the cell. It is represented by **alphabetical letters**.
  + For example, the `1st` column is denoted by `'A'`, the `2nd` by `'B'`, the `3rd` by `'C'`, and so on.
* `<row>` is the row number `r` of the cell. The `rth` row is represented by the **integer** `r`.

You are given a string `s` in the format `"<col1><row1>:<col2><row2>"`, where `<col1>` represents the column `c1`, `<row1>` represents the row `r1`, `<col2>` represents the column `c2`, and `<row2>` represents the row `r2`, such that `r1 <= r2` and `c1 <= c2`.

Return *the **list of cells*** `(x, y)` *such that* `r1 <= x <= r2` *and* `c1 <= y <= c2`. The cells should be represented as **strings** in the format mentioned above and be sorted in **non-decreasing** order first by columns and then by rows.

**Example 1:**

```
Input: s = "K1:L2"
Output: ["K1","K2","L1","L2"]
Explanation:
The above diagram shows the cells which should be present in the list.
The red arrows denote the order in which the cells should be presented.
```

**Example 2:**

```
Input: s = "A1:F1"
Output: ["A1","B1","C1","D1","E1","F1"]
Explanation:
The above diagram shows the cells which should be present in the list.
The red arrow denotes the order in which the cells should be presented.
```

**Constraints:**

* `s.length == 5`
* `'A' <= s[0] <= s[3] <= 'Z'`
* `'1' <= s[1] <= s[4] <= '9'`
* `s` consists of uppercase English letters, digits and `':'`.

---

## Solution & Editorial
# Intuition
The problem requires generating all cell identifiers within a rectangular range defined by two corner cells. Since the output must be sorted first by column (alphabetical) and then by row (numerical), a nested loop structure naturally satisfies the ordering requirements.

# Approach
1. Extract the start and end column characters from `s[0]` and `s[3]`.
2. Extract the start and end row integers from `s[1]` and `s[4]` by subtracting the character `'0'`.
3. Use an outer loop to iterate through columns from `s[0]` to `s[3]`.
4. Use an inner loop to iterate through rows from `s[1]-'0'` to `s[4]-'0'`.
5. Construct the string for each cell by concatenating the current column character and the current row integer, then append it to the result vector.

### Visual Trace (Example 1: s = "K1:L2")
| Outer (ch) | Inner (i) | Result (res) | List State |
| :--- | :--- | :--- | :--- |
| 'K' | 1 | "K1" | ["K1"] |
| 'K' | 2 | "K2" | ["K1", "K2"] |
| 'L' | 1 | "L1" | ["K1", "K2", "L1"] |
| 'L' | 2 | "L2" | ["K1", "K2", "L1", "L2"] |

# Complexity
- Time complexity: $$O(C \times R)$$, where $$C$$ is the number of columns and $$R$$ is the number of rows in the range. Given the constraints, this is effectively constant time as the range is bounded by 'A'-'Z' and '1'-'9'.
- Space complexity: $$O(C \times R)$$ to store the resulting list of strings.

# Code
```cpp
class Solution {
public:
    vector<string> cellsInRange(string s) {
        
        vector<string>ans;
        
        for(char ch=s[0];ch<=s[3];ch++)
        {
            for(int i=s[1]-'0';i<=s[4]-'0';i++)
            {
                string res="";
                res+=ch;
                res+=to_string(i);
                ans.push_back(res);
               
            }
        }
        return ans;
    }
};
```
