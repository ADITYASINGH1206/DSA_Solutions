# [4030. Check ASCII Palindromic](https://leetcode.com/problems/check-ascii-palindromic/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`, `bit-manipulation`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters.

Construct a **binary string** by replacing each character in `s` with the 8-bit binary representation of its ASCII value, **including leading zeros**, while preserving the original order of the characters.

Return `true` if the resulting binary string is a **palindrome**. Otherwise, return `false`.

**Example 1:**

**Input:** s = "ff"

**Output:** true

**Explanation:**

* The ASCII value of `f` is 102, whose 8-bit binary representation is `01100110`.
* Thus, the binary string is `0110011001100110`.
* Since this binary string is a **palindrome**, the output is `true`.

**Example 2:**

**Input:** s = "leet"

**Output:** false

**Explanation:**

* The ASCII values of `l`, `e`, `e`, and `t` are 108, 101, 101, and 116, respectively.
* Their 8-bit binary representations are `01101100`, `01100101`, `01100101`, and `01110100`.
* Thus, the binary string is `01101100011001010110010101110100`.
* Since this binary string is not a **palindrome**, the output is `false`.

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem requires checking if the concatenation of 8-bit binary representations of characters in a string forms a palindrome. Since the total length of the binary string is at most 800 bits (100 characters * 8 bits), we can explicitly construct the binary string and use a two-pointer approach to verify the palindromic property.

# Approach
1. Initialize an empty string `binary` to store the concatenated bits.
2. Iterate through each character `c` in the input string `s`. Convert the character to its ASCII integer value and use `std::bitset<8>` to generate its 8-bit binary representation string.
3. Append each 8-bit string to `binary`.
4. Use two pointers, `i` starting at the beginning (0) and `j` starting at the end (`binary.size() - 1`).
5. Compare `binary[i]` and `binary[j]`. If they differ, return `false`. Otherwise, increment `i` and decrement `j` until `i >= j`.
6. Return `true` if the loop completes without finding a mismatch.

### Visual Trace (Example: s = "ff")
- 'f' (102) -> "01100110"
- 'f' (102) -> "01100110"
- `binary` = "0110011001100110"
- Pointers:
  - i=0, j=15: '0' == '0'
  - i=1, j=14: '1' == '1'
  - ...
  - All match, return `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the input string. We iterate through the string once to build the binary representation ($$8N$$ operations) and once more to check the palindrome ($$4N$$ comparisons).
- Space complexity: $$O(N)$$, as we store the resulting binary string of length $$8N$$.

# Code
```cpp
class Solution {
public:
    bool isPalindromic(string s) {
        string binary = "";
        for (char c : s) {
            int ascii = int(c);
            string bin = bitset<8>(ascii).to_string();
            binary += bin;
        }
        int i = 0;
        int j = binary.size() - 1;

        while (i < j) {
            if (binary[i] != binary[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
```
