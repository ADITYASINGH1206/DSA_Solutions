/**
 * Problem: Battleships in a Board (419)
 * Link: https://leetcode.com/problems/battleships-in-a-board/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
