/**
 * Problem: Valid Sudoku (36)
 * Link: https://leetcode.com/problems/valid-sudoku/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
