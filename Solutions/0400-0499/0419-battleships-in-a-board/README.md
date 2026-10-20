# [419. Battleships in a Board](https://leetcode.com/problems/battleships-in-a-board/)
**Difficulty:** `Medium` | **Tags:** `array`, `depth-first-search`, `matrix`

---

## Problem Description
You are given an `m x n` matrix `board` where each cell is part of a battleship `'X'` or empty `'.'`, return the number of the **battleships** on `board`.

**Battleships** can only be placed horizontally or vertically on `board`. In other words, they can only be made of the shape `1 x k` (`1` row, `k` columns) or `k x 1` (`k` rows, `1` column), where `k` can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

**Example 1:**

```
Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2
```

**Example 2:**

```
Input: board = [["."]]
Output: 0
```

**Constraints:**

* `m == board.length`
* `n == board[i].length`
* `1 <= m, n <= 200`
* `board[i][j]` is either `'.'` or `'X'`.

**Follow up:** Could you do it in one-pass, using only `O(1)` extra memory and without modifying the values `board`?

---

## Solution & Editorial
# Intuition
The problem asks us to count the number of battleships on a grid, where battleships are placed either horizontally or vertically and are separated by at least one empty cell. We can solve this by traversing the grid and using Depth-First Search (DFS) to explore and mark all connected cells of a single battleship as visited, incrementing our counter each time we find a new unvisited battleship component.

# Code
```cpp
class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int row,int col,int&m,int&n){
        vis[row][col] =1;
        
        //Move right
        int nrowR = row;
        int ncolR = col+1;
        //Move down
        int nrowD = row+1;
        int ncolD = col;

        bool right = nrowR >=0 && ncolR >=0 && nrowR <m && ncolR <n && !vis[nrowR][ncolR] && board[nrowR][ncolR] == 'X';

        bool down = nrowD >=0 && ncolD >=0 && nrowD <m && ncolD <n && !vis[nrowD][ncolD] && board[nrowD][ncolD] == 'X';

        if(right && down) dfs(board,vis,nrowR,ncolR,m,n);
        else{
            if(right) dfs(board,vis,nrowR,ncolR,m,n);
            else if(down) dfs(board,vis,nrowD,ncolD,m,n);
        }

    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int ans = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    ans++;
                    dfs(board,vis,i,j,m,n);
                }
            }
        }

        return ans;
    }
};
```
