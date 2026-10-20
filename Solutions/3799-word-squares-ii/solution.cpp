/**
 * Problem: Word Squares II (3799)
 * Link: https://leetcode.com/problems/word-squares-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& words, vector<bool>& visited, vector<string>& current, vector<vector<string>>& ans) {
        if (current.size() == 4) {
            if (current[0][0] == current[1][0] && 
                current[0][3] == current[2][0] &&
                current[3][0] == current[1][3] &&
                current[3][3] == current[2][3]) {
                
                ans.push_back(current);
            }
            return;
        }

        for (int i = 0; i < words.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;          
                current.push_back(words[i]); 
                
                backtrack(words, visited, current, ans); 
                
                current.pop_back();         
                visited[i] = false;         
            }
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        vector<string> current;
        vector<bool> visited(words.size(), false);
        sort(words.begin(), words.end());
        backtrack(words, visited, current, ans);
        
        return ans;
    }
};
