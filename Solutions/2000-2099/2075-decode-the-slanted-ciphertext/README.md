# [2075. Decode the Slanted Ciphertext](https://leetcode.com/problems/decode-the-slanted-ciphertext/)
**Difficulty:** `Medium` | **Tags:** `string`, `simulation`

---

## Problem Description
A string `originalText` is encoded using a **slanted transposition cipher** to a string `encodedText` with the help of a matrix having a **fixed number of rows** `rows`.

`originalText` is placed first in a top-left to bottom-right manner.

The blue cells are filled first, followed by the red cells, then the yellow cells, and so on, until we reach the end of `originalText`. The arrow indicates the order in which the cells are filled. All empty cells are filled with `' '`. The number of columns is chosen such that the rightmost column will **not be empty** after filling in `originalText`.

`encodedText` is then formed by appending all characters of the matrix in a row-wise fashion.

The characters in the blue cells are appended first to `encodedText`, then the red cells, and so on, and finally the yellow cells. The arrow indicates the order in which the cells are accessed.

For example, if `originalText = "cipher"` and `rows = 3`, then we encode it in the following manner:

The blue arrows depict how `originalText` is placed in the matrix, and the red arrows denote the order in which `encodedText` is formed. In the above example, `encodedText = "ch ie pr"`.

Given the encoded string `encodedText` and number of rows `rows`, return *the original string* `originalText`.

**Note:** `originalText` **does not** have any trailing spaces `' '`. The test cases are generated such that there is only one possible `originalText`.

**Example 1:**

```
Input: encodedText = "ch   ie   pr", rows = 3
Output: "cipher"
Explanation: This is the same example described in the problem description.
```

**Example 2:**

```
Input: encodedText = "iveo    eed   l te   olc", rows = 4
Output: "i love leetcode"
Explanation: The figure above denotes the matrix that was used to encode originalText. 
The blue arrows show how we can find originalText from encodedText.
```

**Example 3:**

```
Input: encodedText = "coding", rows = 1
Output: "coding"
Explanation: Since there is only 1 row, both originalText and encodedText are the same.
```

**Constraints:**

* `0 <= encodedText.length <= 106`
* `encodedText` consists of lowercase English letters and `' '` only.
* `encodedText` is a valid encoding of some `originalText` that **does not** have trailing spaces.
* `1 <= rows <= 1000`
* The testcases are generated such that there is **only one** possible `originalText`.

---

## Solution & Editorial
# Intuition
The problem describes a slanted transposition cipher where characters are read diagonally from top-left to bottom-right. Since the matrix is filled row-wise, the character at row `r` and column `c` is located at index `r * cols + c` in the `encodedText` string. By iterating through each starting column in the first row and moving diagonally, we can reconstruct the original string.

# Approach
1. Calculate the number of columns `cols` as `encodedText.length() / rows`.
2. Iterate through each starting column `j` from `0` to `cols - 1`.
3. For each `j`, traverse the diagonal by incrementing both the row index `x` and column index `y` simultaneously, starting from `x = 0` and `y = j`.
4. Append the character at `encodedText[x * cols + y]` to the result string `ans`.
5. After building the string, remove trailing spaces using `pop_back()` as the problem guarantees no trailing spaces in the original text.

### Visual Trace (Example 1: "ch   ie   pr", rows = 3)
- `cols` = 12 / 3 = 4
- `j = 0`: (0,0)='c', (1,1)='h', (2,2)=' ' -> "ch "
- `j = 1`: (0,1)='h', (1,2)=' ', (2,3)=' ' -> "ch h  "
- `j = 2`: (0,2)=' ', (1,3)='i' -> "ch h  i"
- `j = 3`: (0,3)=' ', (1,4)='e' -> "ch h  i e"
- Final cleanup removes trailing spaces to get "cipher".

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `encodedText`. Each character is visited exactly once.
- Space complexity: $$O(N)$$ to store the resulting decoded string.

# Code
```cpp
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans;
        int cols = encodedText.size() / rows;
        for (int j = 0; j < cols; ++j) {
            for (int x = 0, y = j; x < rows && y < cols; ++x, ++y) {
                ans += encodedText[x * cols + y];
            }
        }
        while (ans.size() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};
```
