/**
 * Problem: Word Ladder (127)
 * Link: https://leetcode.com/problems/word-ladder/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        while(!q.empty()){
            string word = q.front().first;
            int ans = q.front().second;
            q.pop();
            if(word == endWord) return ans;
            for(int i = 0;i<word.size();i++){
                char original = word[i];
                for(char c = 'a' ; c<='z';c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,ans+1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};
