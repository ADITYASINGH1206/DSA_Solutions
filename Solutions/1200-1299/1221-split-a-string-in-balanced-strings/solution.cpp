/**
 * Problem: Split a String in Balanced Strings (1221)
 * Link: https://leetcode.com/problems/split-a-string-in-balanced-strings/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int count = 0;
        for(char c:s){
            if(c == 'R'){
                count +=1;
            }else{
                count -= 1;
            }
            if(count == 0){
                ans+=1;
            }
        }
        return ans;
    }
};
