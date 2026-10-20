# [36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `matrix`

---

## Problem Description
Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.

**Note:**

* A Sudoku board (partially filled) could be valid but is not necessarily solvable.
* Only the filled cells need to be validated according to the mentioned rules.

**Example 1:**

```
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```

**Example 2:**

```
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```

**Constraints:**

* `board.length == 9`
* `board[i].length == 9`
* `board[i][j]` is a digit `1-9` or `'.'`.

---

## Solution & Editorial
# Intuition
To determine if a Sudoku board is valid, we must verify that no number from `1` to `9` repeats in any row, column, or corresponding `3x3` sub-grid. We can achieve this efficiently by temporarily clearing the current cell's value, checking its validity against the rest of the board using simple coordinate sweeps, and then restoring it.

# Approach
1. Iterate through every cell `(i, j)` of the `9x9` board using nested loops in `isValidSudoku`.
2. If the current cell contains a digit (`board[i][j] != '.'`), store it in `num` and temporarily set `board[i][j] = '.'` to avoid self-collision.
3. Call the helper function `isValid(board, row, col, num)`, which checks:
   - Row `row` and column `col` for any duplicate occurrence of `num`.
   - The top-left corner of the `3x3` sub-box calculated as `sr = (row / 3) * 3` and `sc = (col / 3) * 3`, scanning the 9 cells within the sub-box.
4. If `isValid` returns `false`, immediately return `false`. Otherwise, restore `board[i][j] = num` and continue.
5. If all filled cells pass verification, return `true`.

### Visual Trace Walkthrough
For a cell at `(0, 0)` containing `'5'`, we temporarily set `board[0][0] = '.'`, then scan row 0, column 0, and the top-left `3x3` sub-box. Since no other `'5'` exists in these scopes, it is valid. We restore `board[0][0] = '5'` and proceed to the next cell.

# Complexity
- Time complexity: $$O(1)$$
  The board size is fixed at $$9 \times 9 = 81$$ cells. For each filled cell, we perform constant-time checks bounded by $$9 + 9 + 9 = 27$$ operations. Thus, both time and number of operations are strictly constant.
- Space complexity: $$O(1)$$
  No auxiliary data structures (like hash sets or bitmasks) are allocated; validation is performed directly on the input grid in-place using constant auxiliary stack space.

# Code
```cpp
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) return false;
        }
        int sr = (row / 3) * 3, sc = (col / 3) * 3;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    char num = board[i][j];
                    board[i][j] = '.'; 
                    if(isValid(board, i, j, num) == false) {
                        return false;
                    }
                    board[i][j] = num;
                }
            }
        }
        return true;
    }
};
```
