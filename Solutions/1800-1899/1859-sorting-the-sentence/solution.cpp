/**
 * Problem: Sorting the Sentence (1859)
 * Link: https://leetcode.com/problems/sorting-the-sentence/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string>order(10,"");
        string temp;
        for(char ch :s){
            if(ch>='1' && ch<='9'){
                order[ch-'0']=temp;
                temp.clear();
            }
            if(isalpha(ch)){
                temp+=ch;
            }
        }
        string ans ;
        for(int i = 0;i<10;i++){
            if(order[i]!=""){
                ans+=order[i];
                ans+=" ";
            }
        }
        ans.pop_back();
        return ans;
    }
};
