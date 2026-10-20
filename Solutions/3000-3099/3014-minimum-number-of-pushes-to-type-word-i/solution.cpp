/**
 * Problem: Minimum Number of Pushes to Type Word I (3014)
 * Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n= word.size();
        int ans =0;
        for(int i=0;i<n;i++){
            if(i<8){
                ans++;
            }else if(i<16){
                ans+=2;
            }else if(i<24){
                ans+=3;
            }else{
                ans+=4;
            }
        }
        return ans;
    }
};
