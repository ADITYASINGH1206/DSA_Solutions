/**
 * Problem: Most Frequent Even Element (2404)
 * Link: https://leetcode.com/problems/most-frequent-even-element/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> freq; 
        for(int x: nums){
            if(x % 2 == 0){
                freq[x]++;
            }
        }

        int ans = -1;
        int maxFreq = 0;
        for(auto it : freq){
            int number = it.first;
            int count = it.second;

            if(count > maxFreq){
                ans = number;
                maxFreq = count;
            }

        }
        return ans;
    }
};
