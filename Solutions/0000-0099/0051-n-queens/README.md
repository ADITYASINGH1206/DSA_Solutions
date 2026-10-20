# [51. N-Queens](https://leetcode.com/problems/n-queens/)
**Difficulty:** `Hard` | **Tags:** `array`, `backtracking`, `algorithm-x`

---

## Problem Description
The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return *all distinct solutions to the **n-queens puzzle***. You may return the answer in **any order**.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

**Example 1:**

```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
```

**Example 2:**

```
Input: n = 1
Output: [["Q"]]
```

**Constraints:**

* `1 <= n <= 9`

---

## Solution & Editorial
# Intuition
The N-Queens problem asks us to place $N$ queens on an $N \times n$ chessboard such that no two queens threaten each other. This naturally models as a depth-first search search space exploration where we place one queen per row. If a placement violates safety constraints, we backtrack and try alternative positions.

# Approach
1. Initialize an $N \times N$ grid (`board`) filled with `'.'` representing empty cells.
2. Use a recursive function `backtrack` starting from `row = 0` to try placing a queen in each column `i` of the current row.
3. Validate every potential placement via `queen`, which checks the row, column, and upper-left/upper-right diagonal directions for existing queens.
4. If the position is safe, place `'Q'`, recurse to `row + 1`, and backtrack by resetting the cell to `'.'`.
5. When `row == n`, push the current board configuration into the answer container `ans`.

### Visual Trace Walkthrough ($n = 4$)
```text
Row 0: Try col 1 -> Board: ".Q.."
  Row 1: Try col 3 -> Board: ".Q..", "...Q"
    Row 2: Try col 0 -> Board: ".Q..", "...Q", "Q..."
      Row 3: Try col 2 -> Valid Solution Found: [".Q..", "...Q", "Q...", "..Q."]
```

# Complexity
- Time complexity: $$O(N!)$$ — In the worst-case, the first row has $N$ choices, the second $N-2$, decreasing branch choices due to attack constraints, bounded tightly by $N!$.
- Space complexity: $$O(N^2)$$ — Required to store the board configurations and the recursion call stack up to depth $N$.

# Code
```cpp
class Solution {
public:
    bool queen(vector<string>& board,int row,int col,int n){
        //Check Row
        for(int i = 0;i<n;i++){
            if(board[row][i] == 'Q') return false;
        }
        //Check Col
        for(int i = 0;i<n;i++){
            if(board[i][col] == 'Q') return false;
        }
        //Check Diagnonal1
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        //Check Diagonal2
        for(int i=row,j=col;i>=0 && j>=0;i--,j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void backtrack(vector<vector<string>>& ans,vector<string>& board,int row,int col,int n){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(queen(board,row,i,n)){
                board[row][i] = 'Q';
                backtrack(ans,board,row+1,col,n);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        backtrack(ans,board,0,0,n);
        return ans;
    }
};
```
