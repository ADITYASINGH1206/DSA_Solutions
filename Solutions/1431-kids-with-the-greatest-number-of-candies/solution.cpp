/**
 * Problem: Kids With the Greatest Number of Candies (1431)
 * Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maximum = candies[0];
        for(int i=1; i<candies.size();i++){
            maximum=max(candies[i],maximum);
        }
        for(int i:candies){
            if((i+extraCandies)>=maximum){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
