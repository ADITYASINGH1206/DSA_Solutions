# [1903. Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`, `greedy`

---

## Problem Description
You are given a string `num`, representing a large integer. Return *the **largest-valued odd** integer (as a string) that is a **non-empty substring** of* `num`*, or an empty string* `""` *if no odd integer exists*.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

```
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
```

**Example 2:**

```
Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
```

**Example 3:**

```
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
```

**Constraints:**

* `1 <= num.length <= 105`
* `num` only consists of digits and does not contain any leading zeros.

---

## Solution & Editorial
# Intuition
An integer is odd if and only if its last digit is odd. To find the largest odd substring of a given number string, we want to keep the longest possible prefix that ends in an odd digit. By scanning from the end of the string towards the beginning, the first odd digit we encounter marks the end of the longest possible odd substring.

# Approach
1. Iterate through the string `num` starting from the last index `n - 1` down to `0`.
2. For each character at index `i`, convert it to its integer value `c`.
3. Check if `c` is odd using the condition `c % 2 != 0`.
4. If an odd digit is found, the substring from index `0` to `i` (inclusive) is the largest odd number. Return `num.substr(0, i + 1)` immediately.
5. If the loop completes without finding an odd digit, return an empty string `""`.

### Visual Trace (Example: num = "35427")
| Iteration | Index (i) | Digit (num[i]) | Odd? | Action |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 4 | '7' | Yes | Return `num.substr(0, 5)` -> "35427" |

### Visual Trace (Example: num = "52")
| Iteration | Index (i) | Digit (num[i]) | Odd? | Action |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | '2' | No | Continue |
| 2 | 0 | '5' | Yes | Return `num.substr(0, 1)` -> "5" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. In the worst case, we traverse the entire string once.
- Space complexity: $$O(1)$$ (excluding the space required for the output string), as we only use a few integer variables for indexing and calculation.

# Code
```cpp
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int i = n - 1; i >= 0; --i) {
            int c = num[i] - '0';
            if (c%2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
```
