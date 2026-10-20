# [3280. Convert Date to Binary](https://leetcode.com/problems/convert-date-to-binary/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`

---

## Problem Description
You are given a string `date` representing a Gregorian calendar date in the `yyyy-mm-dd` format.

`date` can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in `year-month-day` format.

Return the **binary** representation of `date`.

**Example 1:**

**Input:** date = "2080-02-29"

**Output:** "100000100000-10-11101"

**Explanation:**

100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29 respectively.

**Example 2:**

**Input:** date = "1900-01-01"

**Output:** "11101101100-1-1"

**Explanation:**

11101101100, 1, and 1 are the binary representations of 1900, 1, and 1 respectively.

**Constraints:**

* `date.length == 10`
* `date[4] == date[7] == '-'`, and all other `date[i]`'s are digits.
* The input is generated such that `date` represents a valid Gregorian calendar date between Jan 1st, 1900 and Dec 31st, 2100 (both inclusive).

---

## Solution & Editorial
# Intuition
The problem requires converting three distinct integer components (year, month, day) of a date string into their binary representations. Since the input format is fixed as `yyyy-mm-dd`, we can parse these components using string slicing and convert each to binary using standard division-based base conversion.

# Approach
1. **Parsing**: Extract the year, month, and day substrings using `substr` and convert them to integers using `stoi`.
2. **Binary Conversion**: Implement a helper function `binary(int num)` that repeatedly takes the remainder of `num % 2` to build the binary string, then reverses it to correct the order.
3. **Concatenation**: Join the three binary strings with hyphens to form the final result.

### Visual Trace (Example 1: "2080-02-29")
| Component | Decimal | Binary Calculation | Binary String |
| :--- | :--- | :--- | :--- |
| Year | 2080 | 2080 -> 1040 -> 520 -> 260 -> 130 -> 65 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1 | 100000100000 |
| Month | 2 | 2 -> 1 | 10 |
| Day | 29 | 29 -> 14 -> 7 -> 3 -> 1 | 11101 |

**Result**: "100000100000-10-11101"

# Complexity
- Time complexity: $$O(1)$$. The input length is fixed at 10 characters. The maximum value for the year is 2100, which requires at most 11 bits, making the conversion process constant time.
- Space complexity: $$O(1)$$. We only store a few integer variables and the resulting binary string, which has a constant upper bound length.

# Code
```cpp
class Solution {
public:
    string binary(int num) {
        if (num == 0) return "0";
        
        string bin = "";
        while (num > 0) {
            bin += to_string(num % 2);
            num /= 2;
        }
        reverse(bin.begin(), bin.end());
        return bin;   
    }

    string convertDateToBinary(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        return binary(y) + "-" + binary(m) + "-" + binary(d);
    }
};
```
