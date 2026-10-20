# [52. N-Queens II](https://leetcode.com/problems/n-queens-ii/)
**Difficulty:** `Hard` | **Tags:** `backtracking`, `algorithm-x`

---

## Problem Description
The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return *the number of distinct solutions to the **n-queens puzzle***.

**Example 1:**

```
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
```

**Example 2:**

```
Input: n = 1
Output: 1
```

**Constraints:**

* `1 <= n <= 9`

---

## Solution & Editorial
# Intuition
The n-queens puzzle requires placing $n$ non-attacking queens on an $n \times n$ chessboard. This can be efficiently solved using a backtracking strategy where we place queens row by row, validating column and diagonal safety before proceeding to the next row.

# Approach
1. Initialize a chessboard `board` of size $n \times n$ filled with '.' character representations.
2. Define a helper function `check` to verify if placing a queen at `board[row][col]` is safe from attacks. It validates the entire row, entire column, upper-left diagonal, and upper-right diagonal.
3. Define a recursive backtracking function `backtrack` that attempts to place a queen in every column of the current `row`.
4. If `row == n`, a valid complete configuration is found, so we increment `ans` and return.
5. Iterate through all columns `i` for the current `row`. If `check` passes, set `board[row][i] = 'Q'`, recurse to `row + 1`, and then backtrack by resetting `board[row][i] = '.'`.

### Visual Walkthrough for Example 1 ($n = 4$)
```text
Row 0: Try placing Q at (0, 1)
. Q . .

Row 1: Try placing Q at (1, 3)
. Q . .
. . . Q

Row 2: Try placing Q at (2, 0)
. Q . .
. . . Q
Q . . .

Row 3: Try placing Q at (2, 2) -> Fails
Result: 1 valid solution found for branch, continues search until total 2 solutions collected.
```

# Complexity
- Time complexity: $$O(N!)$$ — In the worst case, we explore $n$ choices for the first row, $n-1$ for the second, $n-2$ for the third, leading to bounded factorial permutations.
- Space complexity: $$O(N^2)$$ — Required to store the board of size $n \times n$ and the recursion stack depth of $O(N)$.

# Code
```cpp
class Solution {
public:
    bool check(vector<string>& board,int row,int col,int n){
        for(int i =0;i<n;i++){
            if(board[row][i] == 'Q') return false;
        }
        for(int i = 0;i<n;i++){
            if(board[i][col] == 'Q') return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void backtrack(vector<string>& board,int row,int col,int n,int& ans){
        if(row == n){
            ans++;
            return;
        }

        for(int i = 0;i<n;i++){
            if(check(board,row,i,n)){
                board[row][i] = 'Q';
                backtrack(board,row+1,col,n,ans);
                board[row][i] = '.';
            }
        }

    }
    int totalNQueens(int n) {
        int ans =0;
        vector<string> board(n,string(n,'.'));
        backtrack(board,0,0,n,ans);
        return ans;
    }
};
```
