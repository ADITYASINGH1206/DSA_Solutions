# [37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `backtracking`, `matrix`, `algorithm-x`, `dancing-links`

---

## Problem Description
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy **all of the following rules**:

1. Each of the digits `1-9` must occur exactly once in each row.
2. Each of the digits `1-9` must occur exactly once in each column.
3. Each of the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.

The `'.'` character indicates empty cells.

**Example 1:**

```
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:
```

**Constraints:**

* `board.length == 9`
* `board[i].length == 9`
* `board[i][j]` is a digit or `'.'`.
* It is **guaranteed** that the input board has only one solution.

---

## Solution & Editorial
# Intuition
This problem can be modeled as a constraint satisfaction problem where empty cells need to be filled with digits from '1' to '9'. We can systematically explore all possible assignments using depth-first search with backtracking, validating each choice against Sudoku rules before committing.

# Approach
1. Iterate through every cell in the 9x9 `board` using nested loops (`row` from 0 to 8, `col` from 0 to 8).
2. When an empty cell containing `'.'` is encountered, try placing every digit `num` from `'1'` to `'9'` sequentially.
3. Check if placing `num` at `board[row][col]` is valid by ensuring it does not already exist in the current row, column, or corresponding 3x3 sub-grid using `isValid()`.
4. If valid, place the character and recursively call `solve()` to attempt filling the remaining board.
5. If the recursive call returns `true`, a valid complete solution is found, so propagate `true` upwards. Otherwise, backtrack by resetting the cell back to `'.'` and try the next digit.
6. If all digits fail for a given empty cell, return `false` to trigger backtracking in the caller.

# Complexity
- Time complexity: $$O(9^{N^2})$$ where $$N=9$$, as each of the empty cells can potentially branch into 9 different choices in the worst case.
- Space complexity: $$O(N^2)$$ due to the recursive call stack depth corresponding to the maximum number of empty cells on the board.

# Code
```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;
                            if (solve(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

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
};
```
