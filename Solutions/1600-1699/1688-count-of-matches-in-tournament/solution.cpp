/**
 * Problem: Count of Matches in Tournament (1688)
 * Link: https://leetcode.com/problems/count-of-matches-in-tournament/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int& num,int& ans){
        while(num != 1){
            if(num%2 ==0){
                ans += num/2;
                num = num/2;
            }else{
                ans += num/2;
                num = num/2 +1;
            }
        }
    }
    int numberOfMatches(int n) {
        int ans = 0;
        helper(n,ans);
        return ans;
    }
};
