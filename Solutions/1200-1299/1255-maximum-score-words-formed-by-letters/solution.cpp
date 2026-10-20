/**
 * Problem: Maximum Score Words Formed by Letters (1255)
 * Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<string>& words, vector<int>& count, vector<int>& score, int idx) {
        if (idx == words.size()) return 0;

        int res = maxScore(words, count, score, idx + 1);

        string& word = words[idx];
        bool canForm = true;
        int wordScore = 0;
        vector<int> tempCount = count;

        for (char c : word) {
            int charIdx = c - 'a';
            if (tempCount[charIdx] == 0) {
                canForm = false;
                break;
            }
            tempCount[charIdx]--;
            wordScore += score[charIdx];
        }

        if (canForm) {
            res = max(res, wordScore + maxScore(words, tempCount, score, idx + 1));
        }

        return res;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        for (char c : letters) count[c - 'a']++;
        return maxScore(words, count, score, 0);
    }
};
