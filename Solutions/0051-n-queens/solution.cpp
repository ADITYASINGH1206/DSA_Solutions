/**
 * Problem: N-Queens (51)
 * Link: https://leetcode.com/problems/n-queens/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

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
