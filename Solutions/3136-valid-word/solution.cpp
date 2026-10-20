/**
 * Problem: Valid Word (3136)
 * Link: https://leetcode.com/problems/valid-word/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(n<3){
            return false;
        }
        bool vowel =false, cons=false;
        for(char ch:word){
            if(isalnum(ch)){
                if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U'){
                    vowel = true;
                }else if(isalpha(ch)){
                    cons = true;
                }
            }else{
                return false;
            }
        }
        return vowel&&cons;
    }
};
