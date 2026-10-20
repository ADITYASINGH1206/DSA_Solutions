/**
 * Problem: Number of Valid Words in a Sentence (2047)
 * Link: https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string s) {
        int hyphen = 0;
        int punc = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                return false;
            }

            if (s[i] == '-') {
                hyphen++;
                if (i == 0 || i == s.size() - 1 || hyphen > 1)
                    return false;

                if (!islower(s[i - 1]) || !islower(s[i + 1]))
                    return false;
            }
            if (s[i] == '!' || s[i] == '.' || s[i] == ',') {
                punc++;
                if (i != s.size() - 1 || punc > 1)
                    return false;
            }
        }
        return true;
    }

    int countValidWords(string sentence) {
        int count = 0;

        sentence.push_back(' ');

        string word = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ' && word != "") {
                if (check(word)) {
                    count++;
                    cout << word << endl;
                }
                word = "";
            } else {
                if (sentence[i] != ' ')
                    word += sentence[i];
            }
        }
        return count;
    }
};
