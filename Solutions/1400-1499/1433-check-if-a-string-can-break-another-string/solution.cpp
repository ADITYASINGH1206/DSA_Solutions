/**
 * Problem: Check If a String Can Break Another String (1433)
 * Link: https://leetcode.com/problems/check-if-a-string-can-break-another-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end(),[](char& a,char& b){
            return a-'a'<b-'a';
        });
        sort(s2.begin(),s2.end(),[](char& a,char&b){
            return a-'a'<b-'a';
        });
        int n = s1.size();
        bool ans1 = true;
        bool ans2 = true;
        for(int i = 0;i<n;i++){
            if(s1[i]-'a'>s2[i]-'a'){
                ans1 = false;
                break;
            }
        }
        for(int i = 0;i<n;i++){
            if(s1[i]-'a'<s2[i]-'a'){
                ans2 = false;
                break;
            }
        }
        return ans1 || ans2;
    }
};
