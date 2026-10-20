/**
 * Problem: Word Search (79)
 * Link: https://leetcode.com/problems/word-search/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool combination(int row, int clm, vector<vector<char>>& board, string& word, int index) {
        if (index == word.size()) return true;

        if (row < 0 || row >= board.size() || clm < 0 || clm >= board[0].size() || board[row][clm] != word[index]) {
            return false;
        }

        char temp = board[row][clm];
        board[row][clm] = '#'; 

        bool found = combination(row + 1, clm, board, word, index + 1) || 
                     combination(row - 1, clm, board, word, index + 1) || 
                     combination(row, clm + 1, board, word, index + 1) || 
                     combination(row, clm - 1, board, word, index + 1);  

        board[row][clm] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (combination(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
};
