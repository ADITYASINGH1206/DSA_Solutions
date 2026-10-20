/**
 * Problem: Goal Parser Interpretation (1678)
 * Link: https://leetcode.com/problems/goal-parser-interpretation/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for(int i=0;i<command.size();i++){
            if(command[i] == 'G') ans+= "G";
            else if(command[i] == '('){
                if(command[i+1] == ')'){
                    ans += "o";
                    i++;
                }else{
                    ans += "al";
                    i+= 2;
                }
                
            }
        }
        return ans;
    }
};
