/**
 * Problem: Word Ladder II (126)
 * Link: https://leetcode.com/problems/word-ladder-ii/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, int> mpp; 
    vector<vector<string>> ans;
    string beginW;

public:
    void dfs(string word, vector<string>& seq) {
        if (word == beginW) {
            vector<string> path = seq;
            reverse(path.begin(), path.end()); 
            ans.push_back(path);
            return;
        }
        
        int steps = mpp[word]; 
        
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                
                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); 
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        beginW = beginWord;
        
        q.push(beginWord);
        mpp[beginWord] = 1; 
        st.erase(beginWord);
        
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            
            if (word == endWord) break;
            
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word); 
                        mpp[word] = steps + 1; 
                    }
                }
                word[i] = original;
            }
        }
        
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        
        return ans;
    }
};
