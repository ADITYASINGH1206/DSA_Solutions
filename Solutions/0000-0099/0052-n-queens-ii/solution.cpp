/**
 * Problem: N-Queens II (52)
 * Link: https://leetcode.com/problems/n-queens-ii/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

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
