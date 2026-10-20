/**
 * Problem: Largest Even Number (3798)
 * Link: https://leetcode.com/problems/largest-even-number/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestEven(string s) {
        string ans = "";
        int n= s.size();
        bool even = false;
        for(int i =n-1;i>=0;i--){
            int temp = s[i]-'0';
            if(even){
                ans+= s[i];
            }
            if(!even){
                int temp = s[i] -'0';
                if(temp%2 == 0){
                    even = true;
                    ans+= s[i];
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
