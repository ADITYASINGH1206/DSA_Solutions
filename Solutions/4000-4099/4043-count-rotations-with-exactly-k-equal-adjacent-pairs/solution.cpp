/**
 * Problem: Count Rotations With Exactly K Equal Adjacent Pairs (4043)
 * Link: https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int pairs=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                pairs++;
            }
        }
        if(s[n-1]==s[0]){
            pairs++;
        }
        if(pairs==k){
            return n-pairs;
        }
        return pairs==k+1?pairs:0;
    }
};
