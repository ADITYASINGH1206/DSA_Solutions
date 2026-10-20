# [3274. Check if Two Chessboard Squares Have the Same Color](https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`

---

## Problem Description
You are given two strings, `coordinate1` and `coordinate2`, representing the coordinates of a square on an `8 x 8` chessboard.

Below is the chessboard for reference.

Return `true` if these two squares have the same color and `false` otherwise.

The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first (indicating its column), and the number second (indicating its row).

**Example 1:**

**Input:** coordinate1 = "a1", coordinate2 = "c3"

**Output:** true

**Explanation:**

Both squares are black.

**Example 2:**

**Input:** coordinate1 = "a1", coordinate2 = "h3"

**Output:** false

**Explanation:**

Square `"a1"` is black and `"h3"` is white.

**Constraints:**

* `coordinate1.length == coordinate2.length == 2`
* `'a' <= coordinate1[0], coordinate2[0] <= 'h'`
* `'1' <= coordinate1[1], coordinate2[1] <= '8'`

---

## Solution & Editorial
# Intuition
On a standard 8x8 chessboard, the color of a square is determined by the parity of the sum of its column index and row index. By mapping 'a'-'h' to 0-7 and '1'-'8' to 0-7, we can calculate a numerical value for each coordinate. If the parities of these sums are identical, the squares share the same color.

# Approach
1. Convert the column character (e.g., 'a') to an integer index (0-7) by subtracting 'a'.
2. Convert the row character (e.g., '1') to an integer index (0-7) by subtracting '1'.
3. Sum these two indices for each coordinate to get `c1` and `c2`.
4. Compare the parity of `c1` and `c2` using the modulo operator (`% 2`). If `c1 % 2 == c2 % 2`, the squares are the same color.

### Visual Trace (Example 1: "a1", "c3")
| Coordinate | Col Index | Row Index | Sum | Parity (Sum % 2) |
| :--- | :--- | :--- | :--- | :--- |
| "a1" | 0 ('a'-'a') | 0 ('1'-'1') | 0 | 0 (Even) |
| "c3" | 2 ('c'-'a') | 2 ('3'-'1') | 4 | 0 (Even) |

Since 0 == 0, return `true`.

# Complexity
- Time complexity: $$O(1)$$. The calculation involves a constant number of arithmetic operations regardless of the input.
- Space complexity: $$O(1)$$. No auxiliary data structures are used.

# Code
```cpp
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int c1 = (coordinate1[0]-'a')+(coordinate1[1]-'1');
        int c2 = (coordinate2[0]-'a')+(coordinate2[1]-'1');
        return c1%2==c2%2 ? true:false;
    }
};
```
