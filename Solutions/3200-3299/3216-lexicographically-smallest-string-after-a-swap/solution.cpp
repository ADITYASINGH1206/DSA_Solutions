/**
 * Problem: Lexicographically Smallest String After a Swap (3216)
 * Link: https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        int l =0;
        int r = 1;
        while(r<n){
            int t1 = s[l];
            int t2 = s[r];
            if(t1%2==0){
                if(t2%2==0 && t1>t2){
                    swap(s[l],s[r]);
                    return s;
                }
            }else{
                if(t2%2!=0 && t1>t2){
                    swap(s[l],s[r]);
                    return s;
                }    
            }
            l++,r++;
        }
        return s;
    }
};
