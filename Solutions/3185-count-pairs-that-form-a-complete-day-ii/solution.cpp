/**
 * Problem: Count Pairs That Form a Complete Day II (3185)
 * Link: https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<ll,ll>count;
        ll ans = 0;
        for(int hour:hours){
            int remaining = hour%24;
            if(remaining==0){
                ans+=count[remaining];
            }else{
                ans+=count[24-remaining];
            }
            count[remaining]++;
        }
        return ans;
    }
};
